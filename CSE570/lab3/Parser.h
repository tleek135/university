#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

#ifndef PARSER_H
#define PARSER_H

typedef set<char>::iterator set_it;
typedef set<string>::iterator rhs_it;
typedef map<char, set<char> >::iterator map_it;
typedef map<char, set<string> >::iterator prod_it;

class Parser
{

private:
	set<char> terminal;
	set<char> nonterm;
	map<char, set<char> > first;
	map<char, set<char> > follow;
	map<char, set<string> > production;
	char starting_nonterm;
	//holds entire canonical collection of LR(0) sets; the int in the pair represents
	//the state number; the char respresents the char that must be processed
	//in order to "goto" that state
	map<pair<int, char>, map<char, set<string> > > collection_of_LR0_sets;

public:
	Parser(string);
	void generate_first();
	void generate_follow();
	void print_grammar();
	map<char, set<string> > closure(map<char, set<string> >);
	void build_LR0_sets();
	map<char, set<string> > _goto(map<char, set<string> >, char);
	void print_productions(map<char, set<string> >);
};
#endif
		

