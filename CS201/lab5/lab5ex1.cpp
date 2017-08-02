//Program written by: Kyle Lee (005054981)
//Lab 5, Exercise 1

#include <iostream>
#include <cassert>
#include "Number.h"

using namespace std;

int main(int argc, char * argv[])
{
    Number nine(9);
    assert(!nine.isPrime());
    assert( nine.isDivisibleBy(1));
    assert(!nine.isDivisibleBy(2));
    assert( nine.isDivisibleBy(3));
    assert(!nine.isDivisibleBy(8));
    assert( nine.isDivisibleBy(9));

    Number seven(7);
    assert( seven.isPrime());
    assert( seven.isDivisibleBy(1));
    assert(!seven.isDivisibleBy(2));
    assert(!seven.isDivisibleBy(3));
    assert( seven.isDivisibleBy(7));

    Number seventySeven(77);
    assert(!seventySeven.isPrime());

    Number seventyThree(73);
    assert(seventyThree.isPrime());

    Number twentySeven(27);
    assert(!twentySeven.isPrime());
    assert(!twentySeven.isDivisibleBy(2));
    assert(twentySeven.isDivisibleBy(3));
    assert(twentySeven.isDivisibleBy(9));

    cout << "All tests passed.\n";

}
