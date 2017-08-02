//Program written by: Kyle Lee (005054981)
//Lab 5, Exercise 3

#include <iostream>
#include <cassert>
#include "EggCarton.h"

using namespace std;

int main(int argc, char * args[]){
	EggCarton package(3, 4);

	assert(package.addBrownEggs(2));
	assert(!package.addBrownEggs(4));

	assert(package.addWhiteEggs(3));
	assert(!package.addWhiteEggs(1));

	assert(package.getTotalEggs() == 12);
	assert(package.getTotalEggs() != 11);

	cout << "All egg tests completed successfully.\n";

}



