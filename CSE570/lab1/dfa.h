/* 	Name: Kyle Lee
	dfa.h
	CSE 570
	Spring 2017
	Lab 1
*/

#ifndef DFA_H
#define DFA_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>

using namespace std;

typedef pair<int, char> transition;

class DFA {
private:
    map<transition, int> table;
    set<int> total_states;
    set<int> accepting_states;
    set<char> alphabet;
public:
    DFA(set<int>, set<int>, set<char>, vector<int>);
    void add_row(int, char, int);
    bool string_in_language(string);
};
#endif
