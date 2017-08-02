#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

#ifndef PARSER_H
#define PARSER_H

//make it easier to define iterators (instead of typing entire iterator name)
typedef set<char>::iterator set_it;
typedef set<string>::iterator rhs_it;
typedef map<char, set<char> >::iterator map_it;
typedef map<char, set<string> >::iterator prod_it;
typedef map<pair<int, char>, map<char, set<string> > >::iterator LR0_set_it;

class Parser
{

private:
	set<char> terminal;
	set<char> nonterm;
	map<char, set<char> > first;
	map<char, set<char> > follow;
	map<char, set<string> > production;
	//needed to write "reduce" rules to SLR parsing table; the indices
	//of the vector correspond to the production numbers
	vector<string> production_numbers;
	//represents the "action table" portion of the parsing table
	vector<map<char, string> > ACTION;
	//represents the "goto table" portion of the parsing table
	vector<map<char, int> > GOTO; 
	char starting_nonterm;
	//this holds all LR(0) sets
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
	void generate_parsing_table(); //creates ACTION and GOTO tables
};
#endif
		

