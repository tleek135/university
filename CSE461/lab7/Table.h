/*
 * Name: Kyle Lee
 * Date: May 29, 2017
 * Class: CSE 461
 * Term: Spring 2017
 * Lab 7
 * Note: For lab 7, we were only required to write the constructor
 * and build_table functions.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Filesys.h"

using namespace std;

#ifndef TABLE_H
#define TABLE_H

class Table : public Filesys
{
public: 
	Table(string diskname, int numberofblocks, int blocksize, string flatfile, string indexfile);
	int build_table(string inputfile);
    int search(string value);
private:
    string flatfile;
    string indexfile;
    int indexsearch(string value);
};
#endif
