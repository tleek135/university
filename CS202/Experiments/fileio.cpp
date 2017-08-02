#include <fstream>
#include <string>
#include <iostream>

using namespace std;

main()
{
    ifstream first, second;
    ofstream third;
    string s, t;

    first.open("one");
    second.open("two");
    third.open("three");

    while (!first.eof() and !second.eof()) {
        getline(first, s);
        third << s << '\n';
        getline(second, t);
        third << t << '\n';
    }

    while (!first.eof()) {
        getline(first, s);
        third << s << '\n';
    }
    while (!second.eof()) {
        getline(second, t);
        third << t << '\n';
    }

    first.close();
    second.close();
    third.close();

}
