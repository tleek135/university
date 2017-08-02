/*
 * Name: Kyle Lee
 * Date: April 26, 2017
 * Class: CSE 461
 * Term: Spring 2017
 * Lab 3
 * Note: For lab 3, we were only required to implemnt the Filesys constructor
 * and fssynch()
 */

#include "Filesys.h"

using namespace std;

Filesys::Filesys(string diskname, int numberofblocks, int blocksize): Sdisk(diskname, numberofblocks, blocksize)
{
	rootsize = getblocksize()/11;
	fatsize = (getnumberofblocks()*5)/getblocksize() + 1;
	
	string temp;
	getblock(1, temp);

	//indicates that filesystem does not exist
	if (temp[0] == '#') {
		ostringstream output;
		string build;
		//build ROOT first
		for (int i = 0; i < rootsize; ++i) {
			output << "XXXXX" << " " << 0 << " ";
			filename.push_back("XXXXX");
			firstblock.push_back(0);
		}
		build = output.str();
		while (build.length() < getblocksize())
			build += '#';

		putblock(1, build);

		//build FAT
		output.str("");
		output.clear();

		output << fatsize + 2 << " ";
		fat.push_back(fatsize + 2);
		for (int i = 1; i < fatsize + 2; ++i) {
			output << 0 << " ";
			fat.push_back(0);
		}

		for (int i = fatsize + 2; i < getnumberofblocks()-1; ++i) {
			output << i + 1 << " ";
			fat.push_back(i+1);
		}
		output << 0 << " ";
		fat.push_back(0);

		build = output.str();
		while (build.length() % getblocksize() != 0)
			build += '#';

		putblock(2, build);
	}
	//if filesystem already exists on disk, read it into memory 
	else {
		istringstream input;
		string file;
		int blockone, fatblock;
		input.str(temp);

		//read ROOT
		for (int i = 0; i < rootsize; ++i) {
			input >> file >> blockone;
			filename.push_back(file);
			firstblock.push_back(blockone);
		}

		//read FAT
		string extract_fat;

		/*since getblock() gets characters from block i
		and pushes them back into extract_fat, extract_fat
		will contain the entire contents of the FAT after
		the loop has terminated.*/
		for (int i = 2; i < fatsize + 2; ++i) 
			getblock(i, extract_fat); 
		
		input.clear();
		input.str(extract_fat);

		for (int i = 0; i < getnumberofblocks(); ++i) {
			input >> fatblock;
			fat.push_back(fatblock);
		}
	}
}

int Filesys::fssynch()
{
	if (filename.empty() or firstblock.empty() or fat.empty()) {
		cout << "Cannot sync. No records of ROOT/FAT in memory.\n";
		return 0;
	}

	ostringstream output;
	//get ROOT from memory and write to disk
	for (int i = 0; i < rootsize; ++i) 
		output << filename[i] << " " << firstblock[i] << " ";

	string buffer = output.str();
	while (buffer.length() < getblocksize())
		buffer += '#';

	putblock(1, buffer);

	//get FAT from memory and write to disk
	output.str("");
	output.clear();

	for (int i = 0; i < fat.size(); ++i) 
		output << fat[i] << " ";

	buffer = output.str();
	//pad buffer string until it fits in blocks
	while (buffer.length() % getblocksize() != 0)
		buffer += '#';

	putblock(2, buffer);
	return 1;
}
		
		
