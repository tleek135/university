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

//adding aliases for iterators for simplification
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

public:
	Parser(string);
	void generate_first();
	void generate_follow();
	void print_grammar();
};
#endif
		

