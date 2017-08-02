//Program written by: Kyle Lee (005054981)
//Lab 5, Exercise 3

class EggCarton
{

private:
	int brownEggs;
	int whiteEggs;

public:
	EggCarton(int brownEggs, int whiteEggs);
	bool addBrownEggs(int n);
	bool addWhiteEggs(int n);
	int getTotalEggs();

};
