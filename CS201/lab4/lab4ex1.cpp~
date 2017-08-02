//Program written by: Kyle Lee (005054981)
//Lab 4, Exercise 1

/*
Test Cases	Prime?
----------	------
2		yes
5		yes
13		yes
23		yes
31		yes

4		no
9		no
16		no
54		no
63		no
*/


#include <iostream> 
#include <cassert>

using namespace std;

bool is_prime(int n){
	assert(n > 1);
  	for (int Divisor = 2; Divisor <= n; Divisor++){
		if (n == 2 || (n % Divisor != 0 && Divisor == n - 1))
			return true;
		else if (n % Divisor == 0)
			return false;
	}
}

int main(int argc, char * args[]){

	assert(is_prime(2));
	assert(is_prime(5));	
	assert(is_prime(13));
	assert(is_prime(23));
	assert(is_prime(31));

	assert(!is_prime(4));
	assert(!is_prime(9));
	assert(!is_prime(16));
	assert(!is_prime(54));
	assert(!is_prime(63));

	cout << "All tests completed successfully.\n";

}
