/*
 * Name: Kyle Lee
 * Date: April 11, 2017
 * Class: CSE 461
 * Term: Spring 2017
 */

#include "Sdisk.h"

using namespace std;

Sdisk::Sdisk(string diskname, int numberofblocks, int blocksize)
{
    this->diskname = diskname;
    this->numberofblocks = numberofblocks;
    this->blocksize = blocksize;

    ifstream input;
    ofstream output;
    
    input.open(diskname.c_str());
    //if file does not exist, create it and write # to it
    if (!input.is_open()) {
        output.open(diskname.c_str());
        for (int i = 0; i < numberofblocks*blocksize; ++i)
            output << '#';
        output.close();
    } else {    //if file does exist, check its size in bytes to see if it matches parameters
        char temp;
        int filesize = 0;
        input.get(temp);
        while (!input.eof()) {
            ++filesize;
            input.get(temp);
        }
        if (filesize != (numberofblocks*blocksize)) {
            cout << "Error, filesize does not match!\n";
			input.close();
			exit(0);
        }

        input.close();
    }
}

int Sdisk::getblock(int blocknumber, string& buffer)
{
    //if blocknumber is greater than the last block number,
    //getblock operation will be unsuccessful
    if (blocknumber > (numberofblocks-1))
        return 0;

    ifstream input;
    char temp;
    input.open(diskname.c_str());
    if (!input.is_open())
        return 0;

    //place get pointer at beginning of specified block
    input.seekg(blocknumber*blocksize);

    for (int i = 0; i < blocksize; ++i) {
        input.get(temp);
        buffer.push_back(temp);
    }

    input.close();
    return 1;
}

int Sdisk::putblock(int blocknumber, string buffer)
{
    //if blocknumber is greater than the last block number,
    //putblock operation will be unsuccessful
    if (blocknumber > (numberofblocks-1))
        return 0;

    fstream output;
    //open file in a way that prevents clobber of existing file
    output.open(diskname.c_str(), ios::in | ios::out);

    if(!output.is_open())
        return 0;

    //place put pointer at beginning of specified block
    output.seekp(blocknumber*blocksize);

    for (int i = 0; i < buffer.length(); ++i) 
        output.put(buffer[i]);
    
    output.close();
    return 1;
}

int Sdisk::getnumberofblocks()
{
    return numberofblocks;
}

int Sdisk::getblocksize()
{
    return blocksize;
}

