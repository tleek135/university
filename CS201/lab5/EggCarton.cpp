//Program written by: Kyle Lee (005054981)
//Lab 5, Exercise 3

#include "EggCarton.h"

EggCarton::EggCarton(int brownEggs, int whiteEggs){
	this->brownEggs = brownEggs;
	this->whiteEggs = whiteEggs;
}

bool EggCarton::addBrownEggs(int n){
	if (n + brownEggs + whiteEggs <= 12){
		brownEggs += n;
		return true;
	}
	else
		return false;
}

bool EggCarton::addWhiteEggs(int n){
	if (n + brownEggs + whiteEggs <= 12){
		whiteEggs += n;
		return true;
	}
	else
		return false;
}

int EggCarton::getTotalEggs(){
	return (brownEggs + whiteEggs);
}
