/* 	Name: Kyle Lee
	dfa.cpp
	CSE 570
	Spring 2017
	Lab 1
*/

#include "dfa.h"

using namespace std;

//constructs transition table for the DFA from data read in from file in main()
DFA::DFA(set<int> total, set<int> accepting, set<char> chars, vector<int> next_states):
total_states(total), accepting_states(accepting), alphabet(chars)
{
    if (next_states.size() != (total_states.size()*alphabet.size())) {
        cout << "Invalid input.\n";
        exit(0);
    }

    set<int>::iterator it1 = total_states.begin();
    set<char>::iterator it2;
    vector<int>::iterator it3 = next_states.begin();

    for (; it1 != total_states.end(); it1++) {
        for (it2 = alphabet.begin(); it2 != alphabet.end(); it2++, it3++) {
            transition temp(*it1, *it2);
            table[temp] = *it3;
        }
    }

}

//adds another entry to the transition table
void DFA::add_row(int state, char c, int next)
{
    transition temp(state, c);
    table[temp] = next;
}

//returns true if string is in the language. or false otherwise
bool DFA::string_in_language(string test)
{
    int current_state = *(total_states.begin());
    transition temp;
    map<transition, int>::iterator it;

    //checks if empty string is accepted
    if (test == "empty") {
    	if (accepting_states.count(current_state))
    		return true;
    	return false;
    }

    for (int i = 0; i < test.length(); i++) {
        temp = make_pair(current_state, test[i]);
        it = table.find(temp);
        if (it == table.end())
            return false;
        current_state = (*it).second;
    }

    if (accepting_states.count(current_state))
        return true;
    return false;    
}


