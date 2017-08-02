//Program written by: Kyle Lee (005054981)
//Lab 9, Exercise 1

#include <iostream>
#include <cstdlib>

using namespace std;

char space[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void drawBoard(){
	for (int i = 0; i <= 6; i += 3){
		cout << "--|-----|-----|-----|--\n";
		cout << "  |  " << space[i] << "  |  " << space[i+1] << "  |  " << space[i+2] << "  |  \n";
		cout << "  |	|     |     |  \n";
		if (i == 6)
			cout << "--|-----|-----|-----|--\n";
	}

}

int checkWin(){
	int win = 0;
	
	if (   (space[0] == space[1] && space[1] == space[2])
            || (space[3] == space[4] && space[4] == space[5])
	    || (space[6] == space[7] && space[7] == space[8])
	    || (space[0] == space[3] && space[3] == space[6])
	    || (space[1] == space[4] && space[4] == space[7])
            || (space[2] == space[5] && space[5] == space[8])
	    || (space[0] == space[4] && space[4] == space[8])
            || (space[2] == space[4] && space[4] == space[6])
	   ){
		win = 1;
		return win;
 	}

	else if(   (space[0] != '1' && space[1] != '2' && space[2] != '3')
		&& (space[3] != '4' && space[4] != '5' && space[5] != '6')
		&& (space[6] != '7' && space[7] != '8' && space[8] != '9')){
		win = -1;
		return win;
	}
	else
		return win;
}	

int main(){
	srand(time(0));
	char marker[] = {'O', 'X'};
	bool humanToComputer = true;
	char drawMove = marker[1];
	int chooseSpace;
	int result;
	

	cout << "Welcome to Tic-Tac-Toe!\n";
	cout << "You will be playing against the computer.\n";
	cout << "First player will be X, second player will be O.\n";
	cout << "The first player will be decided randomly.\n";
	cout << "Deciding players...\n";

	if (rand() % 2 == 1) {
		cout << "You have been chosen to go first.\n";
		cout << "You will be using X.\n";
   	} else {
		humanToComputer = false;
		cout << "The computer will go first.\n";
		cout << "You will be using O.\n";
	}
	
	do{
		
		if (humanToComputer){
			drawBoard();
			cout << "\n\nPlease select a number from 1-9 to place your marker: ";
			cin >> chooseSpace;
			--chooseSpace;

			while (space[chooseSpace] == 'X' || space[chooseSpace] == 'O'){
				cout << "That space has already been occupied.\n"
				     << "Please choose a different space: ";
				cin >> chooseSpace;
				--chooseSpace;
			}

			space[chooseSpace] = drawMove;
			result = checkWin();
			drawBoard();
			
			if (result == 1){
				cout << "You win!\n";
				break;
			}
		
			humanToComputer = false;
		}
		else{
			cout << "It is the computer's turn. The computer is selecting "
			     << "a space...\n\n";
			
			do{
				chooseSpace = rand() % 9;
			}while (space[chooseSpace] == 'X' || space[chooseSpace] == 'O');

			space[chooseSpace] = drawMove;
			drawBoard();
			result = checkWin();
			
			if (result == 1){ 
				cout << "The computer wins!\n";
				break;
			}				
			
			humanToComputer = true;
		}

		if (result == -1){
			cout << "The game is a tie!\n";
			break;
		}

		drawMove = (drawMove == marker[1])? marker[0] : marker[1];

	}while (result == 0);

}
			
			
			
			

			


