// Class: CSE 455
// Term: Winter 2016
// Instructor: Dr. Concepcion
// Name: Kyle Lee
// PSP Assignment #2
// Title: Object LOC Counter

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Accepts input file and counts lines of file
class LineCounter
{
private:
	ifstream inputFile;
	string filename, temp;
	int numberOfLines, objectLines, numberOfMethods;

public:

	vector<string> objectNames;

	//Default constructor
	LineCounter();
	void set_filename(string);
	string get_filename() const;
	int totalLineCount();
	void findObjectName();
	int objectLineCount();
	void countMethods();
	int methodLineCount();
	
};

LineCounter::LineCounter()
{
	temp = "";
	numberOfLines = 0;
	objectLines = 0;
	numberOfMethods = 0;
}

void LineCounter::set_filename(string s)
	{
		filename = s;
	}

string LineCounter::get_filename() const
	{
		return filename;
	}

int LineCounter::totalLineCount() 
{
	inputFile.open(filename.c_str());

	if (!(inputFile.good()))
	{
		cout << "Invalid file. Please enter a different file name: ";
		cin >> filename;
		inputFile.open(filename.c_str());
	}

	while (getline(inputFile, temp))
	{
		findObjectName();
		if (!objectNames.empty())
			countMethods();

		numberOfLines++;

		if ((temp[0] == '/' and temp[1] == '/') or temp == "")
			numberOfLines--;
	}

	return numberOfLines;

	inputFile.close();
}

//Identify classes and their names, and count object lines
void LineCounter::findObjectName()
{
	size_t found = temp.find("class");
	if (found != string::npos) 
		objectNames.push_back(temp.substr(6, temp.size()-1));

	size_t found2 = temp.find("main");
	if (found2 !=  string::npos)
		objectLines = numberOfLines;
}

int LineCounter::objectLineCount()
{
	return objectLines;
}

void LineCounter::countMethods()
{
	size_t methodSearch = temp.find(objectNames[0]);
	size_t doubleColonSearch = temp.find("::");
	if (methodSearch != string::npos and doubleColonSearch != string::npos)
		numberOfMethods++;
}

int LineCounter::methodLineCount()
{
	return numberOfMethods;
}

main()
{
	string file;
	LineCounter linecounter;

	cout << "Please enter the name of a file: ";
	cin >> file;
	linecounter.set_filename(file);

	cout << "Total number of lines (excluding whitespace and comments): " << linecounter.totalLineCount() << endl;
	cout << "Filename: " << linecounter.get_filename() << endl << endl;
	cout << "Object Name: " << linecounter.objectNames[0] << endl;
	cout << "Number of Methods: " << linecounter.methodLineCount() << endl;
	cout << "Object LOC: " << linecounter.objectLineCount() << endl;
}
