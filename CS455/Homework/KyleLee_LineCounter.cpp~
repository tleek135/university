// Class: CSE 455
// Term: Winter 2016
// Instructor: Dr. Concepcion
// Name: Kyle Lee
// PSP Assignment #1
// Title: File Line Counter

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Accepts input file and counts lines of file
class LineCounter
{
private:
	ifstream inputFile;
	string filename, temp;
	int numberOfLines;

public:
	//Default constructor
	LineCounter(): temp(""), numberOfLines(0)
	{
	}
	

	void set_filename(string s)
	{
		filename = s;
	}

	string get_filename() const
	{
		return filename;
	}

	int count() 
	{
		inputFile.open(filename.c_str());

		if (!(inputFile.good()))
		{
			cout << "Invalid file. Please enter a different file name: ";
			cin >> filename;
			inputFile.open(filename.c_str());
		}

		getline(inputFile, temp);

		while (!inputFile.eof())
		{
			if ((temp[0] == '/' and temp[1] == '/') or temp == "")
			{
				getline(inputFile, temp);
				cout << temp << endl;
			}
			else 
				numberOfLines++;
		}

		return numberOfLines;
	}

	void closeFile()
	{
		inputFile.close();
	}

};

main()
{
	string file;
	LineCounter linecounter;

	cout << "Please enter the name of a file: ";
	cin >> file;
	linecounter.set_filename(file);

	cout << "Number of lines (excluding whitespace and comments): " << linecounter.count() << endl;
	cout << "Filename: " << linecounter.get_filename() << endl;
	
	linecounter.closeFile();
}





	
