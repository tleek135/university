/*
 * Name: Kyle Lee
 * Date: April 26, 2017
 * Class: CSE 461
 * Term: Spring 2017
 * Lab 6
 */

#include "Shell.h"

using namespace std;

Shell::Shell(string filename, int numberofblocks, int blocksize): Filesys(filename, numberofblocks, blocksize) { }

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

int Shell::dir()
{
    vector<string> flist = ls();
    if (flist.empty())
        return 0;
    for (int i = 0; i < flist.size(); i++)
        cout << flist[i] << endl;

    return 1;
}

int Shell::add(string file)
{
    if (newfile(file) == 0) {
        cout << "add: Cannot add a new file to the disk.\n";
        return 0;
    }

    string data;
    //cout.clear();
    //cin.clear();
    cout << "Please enter the data for this file. Use the ^ character to indicate end of input: ";
    getline(cin, data, '^');

    vector<string> temp = block(data, getblocksize());

    for (int i = 0; i < temp.size(); i++) {
        if (addblock(file, temp[i]) == -1) {
            cout << "add: Warning! Size of input data exceeds available storage capacity!\n";
            cout << "Truncating data to fit...\n";
        }
    }
    return 1;
}

int Shell::del(string file)
{
    int first = getfirstblock(file);
    if (first == -1) {
        cout << "del: Error: file does not exist.\n";
        return 0;
    }

    while (first != 0) {
        delblock(file, first);
        first = getfirstblock(file);
    }

    rmfile(file);
    return 1;
}

int Shell::type(string file)
{
    string output;
    int current_block = getfirstblock(file);
    if (current_block == 0) {
        cout << "type: Error: file is empty.\n";
        return 0;
    }
    else if (current_block == -1) {
        cout << "type: Error: file does not exist.\n";
        return 0;
    }

    while (readblock(file, current_block, output))
        current_block = nextblock(file, current_block);

    cout << output << endl;

    return 1;
}

int Shell::copy(string file1, string file2)
{
    int current_block_first = getfirstblock(file1);
    if (current_block_first == -1) {
        cout << "copy: Error: " << file1 << " does not exist.\n";
        return 0;
    }
    
    //counts the number of blocks in file1
    int temp = getfirstblock(file1);
    int file1_block_count = 0;
    while (temp != 0) {
        file1_block_count++;
        temp = nextblock(file1, temp);
    }

    //if the number of blocks in file1 exceeds the number of free blocks,
    //then there is not enough space to make a copy
    if (file1_block_count > get_number_of_free_blocks()) {
        cout << "copy: Error: cannot make copy due to insufficient disk space.\n";
        return 0;
    }

    int current_block_second = getfirstblock(file2);
    //if file2 does not exist, create it
    if (current_block_second == -1) {
        if (newfile(file2) == 0) {
            cout << "copy: Error: cannot create destination file.\n";
            return 0;
        }
    }
    //otherwise, delete existing list of blocks from file2's file record
    else {
        while (current_block_second != 0) {
            delblock(file2, current_block_second);
            current_block_second = getfirstblock(file2);
        }
    }
    
    string buffer;
    //read data from file1 and copy it to free blocks for file2
    while (current_block_first != 0) {
        readblock(file1, current_block_first, buffer);
        addblock(file2, buffer);
        buffer = "";
        current_block_first = nextblock(file1, current_block_first);
    }

    return 1;
}    
