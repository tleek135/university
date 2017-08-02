/*
 * Name: Kyle Lee
 * Date: April 26, 2017
 * Class: CSE 461
 * Term: Spring 2017
 * Lab 5
 * In Lab 5, we implemented the checkblock, readblock,
 * writeblock, and nextblock functions.
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

int Filesys::newfile(string file)
{
	int index;
	for (index = 0; index < filename.size(); ++index) {
		if (file == filename[index]) {
			cout << "newfile(): " << file << " already exists.\n";
			return 0;
		}
		if (filename[index] == "XXXXX")
			break;
	}

	if (index == filename.size()) {
		cout << "newfile(): No room in ROOT directory.\n";
		return 0;
	}

	filename[index] = file;
	firstblock[index] = 0;

	fssynch();
	return 1;

}

int Filesys::rmfile(string file)
{
	int index;
	for (index = 0; index < filename.size(); ++index) {
		if (file == filename[index]) {
			if (firstblock[index] != 0) {
				cout << "rmfile(): " << file << " is not empty.\n";
				return 0;
			} 
			else break;
		}
	}

	if (index == filename.size()) {
		cout << "rmfile(): " << file << " does not exist.\n";
		return 0;
	}

	filename[index] = "XXXXX";
	fssynch();
	return 1;
}

int Filesys::getfirstblock(string file)
{
	int index;
	for (index = 0; index < filename.size(); ++index) {
		if (file == filename[index])
			return firstblock[index];
	}

	if (index == filename.size()) {
		cout << "getfirstblock(): " << file << " does not exist.\n";
		return -1;
	}
}

int Filesys::addblock(string file, string block)
{
	int first = getfirstblock(file);
	int allocate = fat[0];
	if (first == -1) {
		cout << "addblock(): " << file << " does not exist.\n";
		return 0;
	}
	if (allocate == 0) {
		cout << "addblock(): No free blocks available.\n";
		return -1;
	}

	//update list of free blocks
	fat[0] = fat[allocate];
	fat[allocate] = 0;

	//if file exists but is empty
	if (first == 0) {
		for (int i = 0; i < filename.size(); ++i) {
			if (filename[i] == file) {
				firstblock[i] = allocate;
				break;
			}
		}
	}
	else {
		while (fat[first] != 0)
			first = fat[first];
		fat[first] = allocate;
	}

	fssynch();
	putblock(allocate, block);
	return allocate;

}

int Filesys::delblock(string file, int blocknumber)
{
	int first = getfirstblock(file);
	if (first == -1) {
		cout << "delblock(): " << file << " does not exist.\n";
		return 0;
	}
	if (first == 0) {
		cout << "delblock(): " << file << " is empty.\n";
		return 0;
	}

	if (first == blocknumber) {
		for (int i = 0; i < filename.size(); ++i) {
			if (file == filename[i]) {
				firstblock[i] = fat[blocknumber];
				break;
			}
		}
		fat[blocknumber] = fat[0];
		fat[0] = blocknumber;
	}
	else {
		while (fat[first] != 0 and fat[first] != blocknumber)
			first = fat[first];

		if (fat[first] == 0) {
			cout << "delblock(): Block number " << blocknumber << " is not in " << file << ".\n";
			return 0;
		}

		fat[first] = fat[blocknumber];
		fat[blocknumber] = fat[0];
		fat[0] = blocknumber;
	}

	fssynch();
	return 1;
}

int Filesys::readblock(string file, int blocknumber, string& buffer)
{
    if (!checkblock(file, blocknumber)) {
        cout << "readblock(): cannot read block " << blocknumber << " from " << file << endl;
        return 0;
    }

	getblock(blocknumber, buffer);
	return 1;
}

int Filesys::writeblock(string file, int blocknumber, string buffer)
{
    if (!checkblock(file, blocknumber)) {
        cout << "writeblock(): cannot write to block " << blocknumber << " in " << file << endl;
        return 0;
    }

	putblock(blocknumber, buffer);
	return 1;
}

int Filesys::nextblock(string file, int blocknumber)
{
    if (!checkblock(file, blocknumber)) {
        cout << "nextblock(): could not find next block.\n";
        return -1;
    }
	//The return statement will return 0 if blocknumber is the last block in file;
	//otherwise, it will return the number of the block following blocknumber
	return fat[blocknumber];
}

bool Filesys::checkblock(string file, int blocknumber)
{
    int check = getfirstblock(file);
    if (check == 0 or check == -1)
        return false;

    while (check != 0) {
        if (check == blocknumber)
            return true;
        check = fat[check];
    }

    return false;
}
		
		
