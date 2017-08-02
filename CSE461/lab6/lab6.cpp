/*
 * Name: Kyle Lee
 * Date: April 26, 2017
 * Class: CSE 461
 * Term: Spring 2017
 * Lab 6
 */

#include "Shell.h"

using namespace std;

int main()
{
 //
 //This main program inputs commands to the shell.
 //It inputs commands as : command op1 op2
 //You should modify it to work for your implementation.
 //
    string s;
    string command="go";
    string op1,op2;
    Shell shell("disk1", 8, 64); //format for constructor: diskname, numberofblocks, blocksize)

    while (command != "quit") {
        command.clear();
        op1.clear();
        op2.clear();
        cout << "$ ";
        getline(cin,s);
        int firstblank=s.find(' ');
        if (firstblank < s.length()) s[firstblank]='#';
        int secondblank=s.find(' ');
        command=s.substr(0,firstblank);
        if (firstblank < s.length())
            op1=s.substr(firstblank+1,secondblank-firstblank-1);
        if (secondblank < s.length())
            op2=s.substr(secondblank+1);
        if (command=="dir") {
            shell.dir();
        }
        else if (command=="add") {
            cout << "op1: " << op1 << endl;
            shell.add(op1);
        }
        else if (command=="del") {
            shell.del(op1);
        }
        else if (command=="type") {
            shell.type(op1);
        }
        else if (command=="copy") {
            shell.copy(op1, op2);
        }
        else if (command != "quit" and !s.empty()) {
            cout << "custom_shell: " << command << ": command not found.\n";
        }
    }

    return 0;
}
