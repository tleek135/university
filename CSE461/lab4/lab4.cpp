/*
 * Name: Kyle Lee
 * Date: April 26, 2017
 * Class: CSE 461
 * Term: Spring 2017
 * Lab 4
 */

#include "Filesys.h"

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

int main()
{
 	Sdisk disk1("disk1",256,128);
	Filesys fsys("disk1",256,128);
    fsys.newfile("file1");
    fsys.newfile("file2");

    string bfile1;
    string bfile2;

    for (int i=1; i<=1024; i++) {
       	bfile1+="1";
    }

  	vector<string> blocks=block(bfile1,128); 

  	int blocknumber = 0;

  	for (int i=0; i< blocks.size(); i++) {
       	blocknumber=fsys.addblock("file1",blocks[i]);
    }

  	fsys.delblock("file1",fsys.getfirstblock("file1"));

  	for (int i=1; i<=2048; i++) {
       bfile2+="2";
    }

  	blocks=block(bfile2,128); 

  	for (int i=0; i< blocks.size(); i++) {
       blocknumber=fsys.addblock("file2",blocks[i]);
    }

  	fsys.delblock("file2",blocknumber);

}