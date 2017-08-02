//Program written by: Kyle Lee (005054981)
//Lab 4, Exercise 3

#include <iostream>
#include <cstdlib>

using namespace std;

int RandNum;

void randColor(){
	
	for (int NumPrint = 0; NumPrint < 6; NumPrint++){
		RandNum = rand() % 16;
			
		if (RandNum == 10)
			cout << 'A';
		else if (RandNum == 11)
			cout << 'B';
		else if (RandNum == 12)
			cout << 'C';
		else if (RandNum == 13)
			cout << 'D';
		else if (RandNum == 14)
			cout << 'E';
		else if (RandNum == 15)
			cout << 'F';
		else
			cout << RandNum;
	}
}

int main(int argc, char * args[]){
	srand(time(0));
	
	cout << "This program will generate 100 random RBG color values.\n";

	for (int LoopCount = 0; LoopCount < 100; LoopCount++){
		randColor();
		cout << endl;
	}
	
	cout << "The list has finished generating.\n";

}
