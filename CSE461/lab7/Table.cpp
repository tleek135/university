
/*
 * Name: Kyle Lee
 * Date: May 29, 2017
 * Class: CSE 461
 * Term: Spring 2017
 * Lab 7
 * Note: For lab 7, we were only required to write the constructor
 * and build_table functions.
 */

#include "Table.h"
using namespace std;

//breaks buffer into blocks of size b
vector<string> block(string buffer, int b)
{
	vector<string> blocks;
	int numberofblocks = 0;

	if (buffer.length() % b == 0)
		numberofblocks = buffer.length()/b;
	else
		numberofblocks = buffer.length()/b + 1;

	string tempblock;
	for (int i = 0; i < numberofblocks; ++i) {
		tempblock = buffer.substr(b*i, b);
		blocks.push_back(tempblock);
	}

	int lastblock = blocks.size()-1;

	for (int i = blocks[lastblock].length(); i < b; ++i)
		blocks[lastblock] += '#';

	return blocks;
}

Table::Table(string diskname, int numberofblocks, int blocksize, string flatfile, string indexfile)
: Filesys(diskname, 256, 128)
{
    this->flatfile = flatfile;
    this->indexfile = indexfile;

    newfile(flatfile);
    newfile(indexfile);
}

int Table::build_table(string inputfile)
{
	ifstream input;
	string read;
	input.open(inputfile.c_str());

	if (!input.is_open()) {
		cout << "Could not open " << inputfile << endl;
		return 0;
	}

	for (int i = 1; i <= 18; i++) {
		vector<string> key;
		vector<int> blkid;
		for (int j = 1; j <= 10; j++) {
			string temp;
			getline(input, temp);
			string date = temp.substr(0, 5);
			vector<string> blocks = block(temp, 128);
			int firstblock = addblock(flatfile, blocks[0]);
			key.push_back(date);
			blkid.push_back(firstblock);
		}

		ostringstream output;
		for (int k = 0; k < key.size(); k++)
			output << key[k] << " " << blkid[k] << " ";

		string buffer = output.str();
		vector<string> blocks = block(buffer, 128);
		addblock(indexfile, blocks[0]);
	}
	input.close();
	return 1;
}
