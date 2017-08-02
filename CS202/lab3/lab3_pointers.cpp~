/******************************************************
 * Kyle Lee
 * lab3_pointers.cpp
 * April 22, 2015
 * CSE 202 (Wednesday lab)
 * Description: Using pointers in functions to return 
   information about a char array.
 * Solution: use pointer variables in place of array
   names, because array names are themselves pointers 
   to beginning of array
 * Percent complete: 100%
******************************************************/

#include <iostream>

using namespace std;

//Returns the length of a string
/*unsigned int strlen(const char s[])
{
	unsigned int n;

	for (n = 0; s[n]; n++);

	return n;
}*/

//Same as above, but with pointers
unsigned int strlen(const char * s)
{
	unsigned int n;
	
	for (n = 0; *(s+n); n++);

	return n;
}

//Copies contents of one string to another
/*void strcpy(char t[], const char s[])
{
	for (int i = 0; t[i] = s[i]; i++);
}*/

//Same as above, but with pointers
void strcpy(char * t, const char * s)
{
	for ( ; *t++ = *s++; );
}

//Copies a portion of one string to another
/*void strncpy(char t[], const char s[], const unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n and s[i]; i++)
		t[i] = s[i];
	t[i] = '\0';
}*/

//Same as above, but with pointers
void strncpy(char * t, const char * s, const unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n and (*(t+i) = *(s+i)); i++);
	t[i] = '\0';
}

//Appends one string to the end of another
/*void strcat(char t[], const char s[])
{
	unsigned int i;

	for (i = 0; t[i]; i++);
	strcpy(t+i, s);
}*/

//Same as above, but with pointers
void strcat(char * t, const char * s)
{
	unsigned int i;

	for (i = 0; *(t+i); i++);
	strcpy(t+i, s);
}

//Compares two strings; returns 0 if strings are
//identical, a - number if target < source, and
//a + number if target > source
int strcmp(const char * t, const char * s)
{
	int difference, i;

	for (i = 0; *(t+i) == *(s+i) and *(s+i) != '\0'; i++); 
	
	difference = *(t+i) - *(s+i);
	return difference;
} 
	
main()
{
	char one[] = "Jonas";

	cout << "Jonas is " << strlen(one) << " characters long.\n";

	char two[] = "Bob";
	char three[4];

	cout << "Copying " << two <<" to a second array...\n";
	strcpy(three, two);
	cout << "The second array now has " << three << endl;

	char four[] = "Billy Bob";
	char five[6];
	char six[] = " Thornton";
	
	cout << "Copying part of " << four << " to another array...\n";
	strncpy(five, four, 5);
	cout << "The other array now has " << five << endl;

	cout << "Appending" << six << " to " << four << "...\n";
	strcat(four, six);
	cout << "The new concatenated string is now " << four << endl;

	cout << "\n";
	char str1[20] = "abcd", str2[20] = "efg";

    cout << "str1=" << str1<< " str2=" << str2 << endl;
    cout << "strlen(str1)=" << strlen(str1)<< " strlen(str2)=" << strlen(str2) << endl;

    strcpy(str1, str2);
    cout << "str1=" << str1 << endl;

    strcat(str1, str2);
    cout << "str1=" << str1 << endl;

    cout << "strcmp(str1, str2)=" << strcmp(str1, str2) << endl;
    cout << "strcmp(str2, \"efh\")=" << strcmp(str2, "efh") << endl;

    strncpy(str2, "hi jkl", 2);
    cout << "str2=" << str2 << endl;

    strncpy(str2, "hi jkl", 12);
    cout << "str2=" << str2 << endl;
}

	



