/* 	Name: Kyle Lee
	CSE570_lab2main.cpp
	CSE 570
	Spring 2017
	Lab 2
*/
	
#include "Parser.h"

using namespace std;

//constructor that reads grammar from a file
//and populates sets of terminals and nonterminals
Parser::Parser(string filename)
{
	ifstream input;
	string line;
	input.open(filename.c_str());

	if (!input.is_open()) {
		cout << filename << " not found!\n";
		exit(1);
	}

	getline(input, line);
	while(line != "$") {
		terminal.insert(line[0]);
		getline(input, line);
	}

	bool at_start = true;
	getline(input, line);
	while(line != "$") {
		nonterm.insert(line[0]);
		if (at_start) {
			starting_nonterm = line[0];
			at_start = false;
		}
	 	int pos = line.find('>');
		string rhs = line.substr(pos+1);
		prod_it iter = production.find(line[0]);
		if (iter == production.end()) {
			set<string> temp_set;
			temp_set.insert(rhs);
			production[line[0]] = temp_set;
		}
		else
			(iter->second).insert(rhs);
		
		getline(input, line);
	}

	input.close();

	for (set_it iter = nonterm.begin(); iter != nonterm.end(); iter++)
		first[*iter] = set<char>();
	for (set_it iter = nonterm.begin(); iter != nonterm.end(); iter++)
		follow[*iter] = set<char>();
}

//generates the FIRST sets for every terminal and nonterminal;
//for a nonterminal on the LHS of a production, if the first character on the right-hand side of
//a production is a terminal, it is added to the FIRST set of that 
//nonterminal; otherwise, it adds the FIRST set of the nonterminal
//that is the first character of the RHS of a production to the FIRST set
//of the nonterminal on the LHS of the production
void Parser::generate_first()
{
	bool changed = true;
	//int pass = 0;
	//The FIRST set for every terminal is itself
	for (set_it itr = terminal.begin(); itr != terminal.end(); itr++) {
		set<char> temp;
		temp.insert(*itr);
		first[*itr] = temp;
	}

	//creates the FIRST sets for every nonterminal
	while (changed) {
		changed = false;
		//int count;
		//cout << "Pass #: " << pass << endl;
		for (prod_it iter_prod = production.begin(); iter_prod != production.end(); iter_prod++) {
			//count = 0;
			for (rhs_it iter_sec = (iter_prod->second).begin(); iter_sec != (iter_prod->second).end(); iter_sec++) {
				//cout << "Count # for " << iter_prod->first << " : " << count << endl;
				map_it row_of_first;
				if (terminal.count((*iter_sec)[0])) {
					row_of_first = first.find(iter_prod->first);
					int set_size = (row_of_first->second).size();
					(row_of_first->second).insert((*iter_sec)[0]);
					int new_set_size = (row_of_first->second).size();
					if (new_set_size != set_size)
						changed = true;
				}
				else {
					map_it concat = first.find(iter_prod->first);
					int set_size = (concat->second).size();
					if ((*iter_sec)[0] == 'e') {
						(concat->second).insert('e');
					}
					else {
						row_of_first = first.find((*iter_sec)[0]);
						(concat->second).insert((row_of_first->second).begin(), (row_of_first->second).end());
					}
					int new_set_size = (concat->second).size();
					if (new_set_size != set_size)
						changed = true; 
				}
				//count++;
			}
		}
	}
}

//generates the FOLLOW sets for every nonterminal;
//reads the RHS of a production from right to left;
//1. in a rule A -> aB or a rule A -> ABb where FIRST(b) has epsilon
//then all of FOLLOW(A) will be in FOLLOW(B)
//2. in a rule A -> aBc, everything in FIRST(c) except epsilon is in FOLLOW(B)
//3. Put $ (end of input) in the FOLLOW set of the starting nonterminal
void Parser::generate_follow()
{
	for (set_it itr = nonterm.begin(); itr != nonterm.end(); itr++) {
		follow[*itr] = set<char>();
	}

	map_it init = follow.find(starting_nonterm);
	(init->second).insert('$');

	bool changed;
	do {
		changed = false;
		for (prod_it iter_prod = production.begin(); iter_prod != production.end(); iter_prod++) {
			for (rhs_it iter_sec = (iter_prod->second).begin(); iter_sec != (iter_prod->second).end(); iter_sec++) {
				map_it builder = follow.find(iter_prod->first);
				set<char> temp = builder->second;
				string buffer = (*iter_sec);
				for (int i = buffer.length()-1; i >= 0; i--) {
					if (nonterm.count(buffer[i])) {
						int initial_size = ((follow.find(buffer[i]))->second).size();
						((follow.find(buffer[i]))->second).insert(temp.begin(), temp.end());
						int new_size = ((follow.find(buffer[i]))->second).size();
						if (new_size != initial_size)
							changed = true;
						if (((first.find(buffer[i]))->second).find('e') != ((first.find(buffer[i]))->second).end()) {
							temp.insert(((first.find(buffer[i]))->second).begin(), ((first.find(buffer[i]))->second).end());
							temp.erase('e');
						}
						else {
							temp = (first.find(buffer[i]))->second;
						}
					}
					else {
						temp = (first.find(buffer[i]))->second;
					}
				}
				
			}
		}
	} while (changed);
}

//prints out important grammar information
void Parser::print_grammar()
{
	cout << "List of Productions:\n";
	for (prod_it it = production.begin(); it != production.end(); it++) {
		for (rhs_it it1 = (it->second).begin(); it1 != (it->second).end(); it1++) { 
			cout << it->first << "->" << (*it1) << endl;
		}
	}

	cout << "The set of terminals is:\n";
	for (set_it it = terminal.begin(); it != terminal.end(); it++) {
		cout << *it << endl;
	}

	cout << "The set of non-terminals is:\n";
	for (set_it it = nonterm.begin(); it != nonterm.end(); it++) {
		cout << *it << endl;
	}

	
	for (map_it it = first.begin(); it != first.end(); it++) {
		cout << "The FIRST set for " << it->first << " is ";
		for (set_it it1 = (it->second).begin(); it1 != (it->second).end(); it1++) { 
			cout << (*it1) << " ";
		}
		cout << endl;
	}

	for (map_it it = follow.begin(); it != follow.end(); it++) {
		cout << "The FOLLOW set for " << it->first << " is ";
		for (set_it it1 = (it->second).begin(); it1 != (it->second).end(); it1++) { 
			cout << (*it1) << " ";
		}
		cout << endl;
	}
}
