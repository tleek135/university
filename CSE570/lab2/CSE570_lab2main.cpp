/* 	Name: Kyle Lee
	CSE570_lab2main.cpp
	CSE 570
	Spring 2017
	Lab 2
	Description: Write a program that calculates the FIRST sets for every terminal and nonterminal
	in a grammar and the FOLLOW sets for every nonterminal.
	
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

	To compile/run the code:
		A. Use the included makefile (type "make" without quotes into the terminal). The executable will
		be named lab2. To run the executable, type "./lab2" without quotes into the terminal.
	OR
		B. Type the following commands (in order) to compile and run:
		g++ -c Parser.cpp
		g++ -o lab2 CSE570_lab2main.cpp Parser.o
		./lab1

	A typescript that shows the compilation/execution of the program is included as the file "CSE570_lab2.lst".

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

	parse.print_grammar();

	return 0;
}
