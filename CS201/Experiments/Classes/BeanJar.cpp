#include "BeanJar.h"

BeanJar::BeanJar(int maxBeans, int beans){ //the double colons indicate that the BeanJar function is a member of the BeanJar class
	this->maxBeans = maxBeans;
	this->beans = beans;
}

int BeanJar::getBeans() const {
	return beans; //Don't need this pointer here; no parameter variable named beans, so compiler assumes it is class var.
}

bool BeanJar::addBeans(int beansToAdd) {
	if (beans + beansToAdd <= maxBeans){
		beans += beansToAdd;
		return true;
	}
	else
		return false;
}

bool BeanJar::removeBeans(int beansToMinus){
	if (beans - beansToMinus >= 0){
		beans -= beansToMinus;	
		return true;
	}
	else
		return false;
}
