#include "BeanJar.h"
#include <iostream>
#include <cassert>

using namespace std;

int main(){
	BeanJar jar1(100, 50);

	assert(jar1.getBeans() == 50);
	assert(jar1.addBeans(10));
	assert(jar1.getBeans() == 60);

	assert(jar1.addBeans(40));
	assert(!jar1.addBeans(1));
	assert(jar1.getBeans() != 101);
	assert(jar1.getBeans() == 100);

	assert(jar1.removeBeans(70));
	assert(!jar1.removeBeans(31));
	assert(jar1.getBeans() == 30);

	cout << "All tests passed." << endl;

}
