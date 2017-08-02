/* 	Name: Kyle Lee
	CSE570_lab3main.cpp
	CSE 570
	Spring 2017
	Lab 3
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
	for (set_it itr = terminal.begin(); itr != terminal.end(); itr++) {
		set<char> temp;
		temp.insert(*itr);
		first[*itr] = temp;
	}

	while (changed) {
		changed = false;
		int count;
		for (prod_it iter_prod = production.begin(); iter_prod != production.end(); iter_prod++) {
			for (rhs_it iter_sec = (iter_prod->second).begin(); iter_sec != (iter_prod->second).end(); iter_sec++) {
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

//closure starts with an LR(0) item (a production with a dot to indicate
//the progression of the parser or the read position) or a group of these items (known as the kernel) and generates the 
//rest of the items in that LR(0) set
map<char, set<string> > Parser::closure(map<char, set<string> > kernel)
{
	map<char, set<string> > set_of_items = kernel;
	bool changed;
	do {
		changed = false;
		for (prod_it itr1 = set_of_items.begin(); itr1 != set_of_items.end(); itr1++) {
			for (rhs_it itr2 = (itr1->second).begin(); itr2 != (itr1->second).end(); itr2++) {
				string buffer = *itr2;
				int dot_position = buffer.find('.');
				if (dot_position == buffer.length()-1)
					continue;
				char lhs = buffer[dot_position+1];
				if (nonterm.count(lhs) == 0) 
					continue;
				else if (nonterm.count(lhs) == 1) {
					prod_it production_row = production.find(lhs);
					for (rhs_it itr3 = (production_row->second).begin(); itr3 != (production_row->second).end(); itr3++) {
						string temp = *itr3;
						if (temp == "e") { //if the RHS of a production has only epsilon (empty production)
							temp = ".";
						}
						else {
							temp.insert(temp.begin(), '.');
						}
						prod_it in_set_of_items = set_of_items.find(lhs);
						if (in_set_of_items == set_of_items.end()) {
							set<string> temp_set; 
							temp_set.insert(temp);
							set_of_items[lhs] = temp_set;
							changed = true;
						}
						else {
							int start_size = (in_set_of_items->second).size();
							(in_set_of_items->second).insert(temp);
							int end_size = (in_set_of_items->second).size();
							if (end_size != start_size)
								changed = true;
						}

					}
				}
			}
		}
	} while (changed);

	return set_of_items;
}

//Like closure, the _goto() function also generates sets of LR(0) items; however, it has
//an extra parameter that indicates the char that is after a dot in an item. From a set
//generated by a closure, goto builds the set of items that that parser will "goto" from 
//that set depending on the char that follows the dot
map<char, set<string> > Parser::_goto(map<char, set<string> > set_of_items, char after_dot)
{
	map<char, set<string> > output_set;
	bool found;
	for (prod_it itr1 = set_of_items.begin(); itr1 != set_of_items.end(); itr1++) {
		found = false;
		set<string> add_to_output_set;
		for (rhs_it itr2 = (itr1->second).begin(); itr2 != (itr1->second).end(); itr2++) {
			int dot_position = itr2->find('.');
			if (dot_position != string::npos) {
				if ((*itr2)[dot_position+1] == after_dot) {
					found = true;
					string temp = *itr2;
					swap(temp[dot_position], temp[dot_position+1]);
					add_to_output_set.insert(temp);
				}
			}
		}
		if (found)
			output_set.insert(make_pair(itr1->first, add_to_output_set));
	}
	return closure(output_set);
}

//this function calls both closure and _goto in order to build the entire collection
//of LR(0) sets; it also assigns state numbers to each of the sets in the collection
void Parser::build_LR0_sets()
{
	map<char, set<string> > temp;
	prod_it start = production.find(starting_nonterm);
	set<string> adding_dots;
	string holder;
	for (rhs_it itr =(start->second).begin(); itr != (start->second).end(); itr++) {
		holder = *itr;
		holder.insert(holder.begin(), '.');
		adding_dots.insert(holder);
	}

	temp.insert(make_pair(start->first, adding_dots));

	int state_number = 0;
	collection_of_LR0_sets[make_pair(state_number, starting_nonterm)] = closure(temp);
	
	set<char> all_grammar_symbols = terminal;
	all_grammar_symbols.insert(nonterm.begin(), nonterm.end());

	bool added;
	do {
		added = false;
		for (map<pair<int, char>, map<char, set<string> > >::iterator itr = collection_of_LR0_sets.begin(); itr != collection_of_LR0_sets.end(); itr++) {
			for (set_it itr2 = all_grammar_symbols.begin(); itr2 != all_grammar_symbols.end(); itr2++) {
				map<char, set<string> > grabbed = _goto(itr->second, *itr2);
				if (!grabbed.empty()) {
					map<pair<int, char>, map<char, set<string> > >::iterator itr3 = collection_of_LR0_sets.begin();
					for (; itr3 != collection_of_LR0_sets.end(); itr3++) {
						if (itr3->second == grabbed)
							break;
					}
					if (itr3 == collection_of_LR0_sets.end()) {
						collection_of_LR0_sets[make_pair(++state_number, *itr2)] = grabbed;
						added = true;
					}
				}
			}
		}
	} while (added);

}

//prints important grammar information
void Parser::print_grammar()
{
	cout << "List of Productions:\n";
	print_productions(production);

	cout << endl;

	cout << "The set of terminals is:\n";
	for (set_it it = terminal.begin(); it != terminal.end(); it++) {
		cout << *it << endl;
	}

	cout << endl;
	cout << "The set of non-terminals is:\n";
	for (set_it it = nonterm.begin(); it != nonterm.end(); it++) {
		cout << *it << endl;
	}

	cout << endl;
	for (map_it it = first.begin(); it != first.end(); it++) {
		cout << "The FIRST set for " << it->first << " is ";
		for (set_it it1 = (it->second).begin(); it1 != (it->second).end(); it1++) { 
			cout << (*it1) << " ";
		}
		cout << endl;
	}

	cout << endl;
	for (map_it it = follow.begin(); it != follow.end(); it++) {
		cout << "The FOLLOW set for " << it->first << " is ";
		for (set_it it1 = (it->second).begin(); it1 != (it->second).end(); it1++) { 
			cout << (*it1) << " ";
		}
		cout << endl;
	}

	cout << endl << endl;

	cout << "The canonical LR(0) sets for the grammar are: " << endl;
	for (map<pair<int, char>, map<char, set<string> > >::iterator itr = collection_of_LR0_sets.begin(); itr != collection_of_LR0_sets.end(); itr++) {
		cout << "State I" << (itr->first).first << ", reached with char " << (itr->first).second << ": \n";
		print_productions(itr->second);
	}
}

//prints all productions
void Parser::print_productions(map<char, set<string> > production_list)
{
	for (prod_it it = production_list.begin(); it != production_list.end(); it++) {
		for (rhs_it it1 = (it->second).begin(); it1 != (it->second).end(); it1++) { 
			cout << it->first << "->" << (*it1) << endl;
		}
	}
}
