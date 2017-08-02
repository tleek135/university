/* 	Name: Kyle Lee
	CSE570_lab4main.cpp
	CSE 570
	Spring 2017
	Lab 4
	Description: Write a program that calculates the FIRST sets for every terminal and nonterminal
	in a grammar and the FOLLOW sets for every nonterminal. It also builds the canonical collection of
	LR(0) sets for that grammar.
	In addition, it also builds the SLR parsing table (the ACTION and GOTO tables) and displays them.
	If there are shift/reduce or reduce/reduce conflicts, the program should show it.
	
	For lab 4, we essentially had to use our completed program from lab 5 to test 3 grammars and see if they
	were SLR:
	1. Strings of 0's and 1's with unequal numbers of 0's and 1's.
	2. Strings of 0's and 1's that are palindromes (the second
	   half of the string is the reverse of the first half.
	3. Strings of 0's and 1's of the form xx
	The above grammars are located in gram1.in, gram2.in, and gram3.in, respectively.
	
	Implementation: The program prompts the user for the file that contains the grammar. The file must be 
	formatted as follows:
	terminals
	...
	$
	productions
	...
	$

	Some example grammars (g417 and g419) are included in this lab directory. Note that the character
	'e' represents epsilon.
	An instance of the Parser class is created, and then the functions generate_first() and generate_follow()
	are called in order to create the FIRST and FOLLOW sets. More info on these functions can be found in Parser.cpp.
	In addition, build_LR0_sets() is also called in order to build all of the sets of LR(0) items. Internally, 
	this function calls the closure() and _goto() functions in order to build each set, which corresponds to a 
	state.
	The generate_parsing_table() function builds the ACTION and GOTO tables that make up the SLR parsing table.
	In the output, shift/reduce or reduce/reduce conflicts are shown in the ACTION portion of the parsing table.
	If a cell contains both an "s" (shift) and "r" character, then there is a shift/reduce conflict. Two "r" chars
	in the same cell show a reduce/reduce conflict. 
	The number next to an "s" in the table indicates the state number of the state that is being shifted to. The 
	number after an "r" indicates the number of the production by which the reduction will take place (the RHS of production
	will be popped off stack and replaced with LHS). The output also shows the list of productions, as well as their numbers.

	To compile/run the code:
		A. Use the included makefile (type "make" without quotes into the terminal). The executable will
		be named lab4. To run the executable, type "./lab4" without quotes into the terminal.
	OR
		B. Type the following commands (in order) to compile and run:
		g++ -c -std=c++11 Parser.cpp
		g++ -std=c++11 -o lab4 CSE570_lab4main.cpp Parser.o
		./lab4

	A typescript that shows the compilation/execution of the program is included as the file "CSE570_lab4.lst".

	For each of the above grammars, answer the question, is the grammar SLR?
	If not, indicate at least one conflict. 
	Grammar 1: NOT SLR (see CSE570_lab4.lst for locations of conflicts)
	Grammar 2: NOT SLR (see CSE570_lab4.lst for locations of conflicts)
	Grammar 3: NOT SLR (see CSE570_lab4.lst for locations of conflicts)
*/
#include "Parser.h"

using namespace std;

int main()
{
	string file;
	cout << "Please enter the name of the grammar file: ";
	cin >> file;

	Parser parse(file);

	parse.generate_first();
	parse.generate_follow();
	parse.build_LR0_sets();
	parse.generate_parsing_table();

	parse.print_grammar();

	return 0;
}
