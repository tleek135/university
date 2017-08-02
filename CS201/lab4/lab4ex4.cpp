//Program written by: Kyle Lee (005054981)
//Lab 4, Exercise 4

#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

string randColor(){
	int RandNum;
	string ColorStorage;
	
	for (int NumPrint = 0; NumPrint < 6; NumPrint++){

		RandNum = rand() % 16;
		stringstream NumConvert;
	
		if (RandNum == 10)
			ColorStorage += "A";
		else if (RandNum == 11)
			ColorStorage += "B";
		else if (RandNum == 12)
			ColorStorage += "C";
		else if (RandNum == 13)
			ColorStorage += "D";
		else if (RandNum == 14)
			ColorStorage += "E";
		else if (RandNum == 15)
			ColorStorage += "F";
		else{
			NumConvert << RandNum;
			ColorStorage += NumConvert.str();
		}
	}

	return ColorStorage;

}

int main(int argc, char * args[]){
	srand(time(0));
	string hexColor;
	
	cout << "<html>\n"
	     << "  <head>\n"
	     << "    <title>Lab 4 Exercise 4</title>\n"
	     << "  </head>\n"
	     << "  <body>\n"
	     << "    <ol>\n";
	
	for (int LoopCount = 0; LoopCount < 100; LoopCount++){
		hexColor = randColor();
		cout << "      <li style=\"color: #" << hexColor
		     << "\">" << hexColor << "</li>\n";
	}
	
	cout << "    </ol>\n"
	     << "  </body>\n"
	     << "</html>\n";

}
