/* 	Name: Kyle Lee
	CSE570_lab1.cpp
	CSE 570
	Spring 2017
	Lab 1
	Description: Write a program that creates a deterministic finite
	automaton (DFA) and uses it to test whether or not strings inputted by 
	the user are in the regular language represented by this DFA.
	
	Implementation: I represented a DFA by writing a DFA class (header file
	is dfa.h and implementation file is dfa.cpp). The class contain sets that
	store the total number of states in the DFA, the accepting states, and the
	alphabet (set of characters) that the language uses. The transition table
	for the DFA is represented by a map. The map's keys are pairs of states
	and characters; the values are the next states in the transition. For example,
	if the key is <1, a> and the value is 2, this means that you would transition to 
	state 2 from state 1 if the letter "a" is read from input. 
		The main() function below populates the data in the DFA class by reading from a
	file. This file stores all of the information about a certain DFA, such as all of the state
	numbers, the accepting states, etc. The format of the file MUST be as follows: 
	First Row: All state numbers in the DFA, separated by spaces (no negative state numbers
	allowed). The first state listed MUST be the starting state, and the states must be listed
	in ascending order. 
	Second Row: All accepting states, separated by spaces. 
	Third Row: All characters in the alphabet, separated by spaces.
	Fourth Row: For each state listed in the first row, list the transition states for 
	each character, separated by spaces. For example, if the first state in the first row is 0, 
	the alphabet is {a, b}, and 0 goes to 1 on a and 2 on b, then the first two values in 
	the fourth row would be: 1 2
	If there is no transition for a certain character from a certain state, use -1 as the state
	value.
		Once all of the data has been read from the file, an instance of the DFA class is
	created and populated with this data. The user can now enter strings to check 
	whether or not these strings belong to the language specified by the DFA from the file.
	(To check the empty string, type "empty" (without quotes) when prompted for an input string.)
	The boolean string_in_language() function of the DFA class is called. It returns true if
	the string is in the language and false otherwise.
		In this lab, we were required to test the language L=(a|b)*abb. The DFA for this language
	is in the example.txt file included with this program.

	To compile/run the code:
		A. Use the included makefile (type "make" without quotes into the terminal). The executable will
		be named lab1. To run the executable, type "./lab1" without quotes into the terminal.
	OR
		B. Type the following commands (in order) to compile and run:
		g++ -c dfa.cpp
		g++ -o lab1 CSE570_lab1.cpp dfa.o
		./lab1

    A typescript showing program compilation/execution is included as "CSE570_lab1.lst".
*/

#include "dfa.h"
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream file;
    istringstream data_reader;
    string filename;
    string data;
    int state;
    char c;

    set<int> total_states;
    set<int> accepting_states;
    set<char> alphabet;
    vector<int> next_states;

    cout << "Please enter the name of the file containing the DFA data: ";
    cin >> filename;

    file.open(filename.c_str());

    while(!file.is_open()) {
        cout << "Please enter a valid filename: ";
        cin >> filename;
        file.open(filename.c_str());
    }

    getline(file, data);
    data_reader.str(data);

    while(data_reader >> state)
        total_states.insert(state);

    getline(file, data);
    data_reader.clear();
    data_reader.str(data);

    while(data_reader >> state)
        accepting_states.insert(state);
    
    getline(file, data);
    data_reader.clear();
    data_reader.str(data);

    while(data_reader >> c)
        alphabet.insert(c);

    getline(file, data);
    data_reader.clear();
    data_reader.str(data);

    while(data_reader >> state)
        next_states.push_back(state);

    file.close();

    DFA dfa(total_states, accepting_states, alphabet, next_states);
    
    cout << "Please enter a string to test (type \"empty\" w/o quotes for empty string): ";
    cin >> data;

    while(!cin.eof()) {
        if (dfa.string_in_language(data))
            cout << data << " is in the language!\n";
        else
            cout << data << " is NOT in the language.\n";

        cout << "Please enter another string, or type Ctrl-D (eof) to quit: ";
        cin >> data;
    }
}
