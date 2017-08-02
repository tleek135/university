/*
 * Name: Kyle Lee
 * Date: April 11, 2017
 * Class: CSE 461
 * Term: Spring 2017
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#ifndef SDISK_H
#define SDISK_H

using namespace std;

class Sdisk
{
public:
    Sdisk(string diskname, int numberofblocks, int blocksize);
    int getblock(int blocknumber, string& buffer);
    int putblock(int blocknumber, string buffer);
    int getnumberofblocks();
    int getblocksize();
private:
    string diskname;    //file name of software-disk
    int numberofblocks; //number of blocks on disk
    int blocksize;      //block size in bytes
};
#endif
