#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	
	int RandNum;
	int UserNum;
	char Response;
	srand(time(0));
	
	do{	

		RandNum = rand() % 10 + 1;
		cout << "Try to guess my number (between 1-10): ";
		cin >> UserNum;

		for (int chance = 3; chance >= 1; chance--){
			if (UserNum == RandNum && chance == 3){
				cout << "Congrats! You got it right on the first try!\n";
				break;
			}

			else if (UserNum == RandNum){
				cout << "Correct! Good job!\n";
				break;
			}
		
			else if (chance == 1 && UserNum != RandNum){
				cout << "Sorry, you're out of chances. You lose!\n";
				cout << "My number was: " << RandNum << endl;
			}

			else if (UserNum != RandNum){
				cout << "Nope, wrong number! You have "
			     	     << chance - 1 << " chance(s) remaining: ";
				cin >> UserNum;
			}
		}

	cout << "Would you like to play again? Type Y for yes, or any other key for no: ";
	cin >> Response;
	}while (Response == 'Y' || Response == 'y');

}
				
		
