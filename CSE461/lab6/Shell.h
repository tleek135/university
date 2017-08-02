/*
 * Name: Kyle Lee
 * Date: April 26, 2017
 * Class: CSE 461
 * Term: Spring 2017
 * Lab 6
 */

#include "Filesys.h"

using namespace std;

#ifndef SHELL_H
#define SHELL_H

class Shell: public Filesys
{
public:
	Shell(string filename, int blocksize, int numberofblocks);
    int dir();// lists all files
    int add(string file);// add a new file using input from the keyboard
    int del(string file);// deletes the file
    int type(string file);//lists the contents of file
    int copy(string file1, string file2);//copies file1 to file2
};

#endif
