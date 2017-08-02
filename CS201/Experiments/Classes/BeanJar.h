#pragma once 


/*
+-----------------------------------------+

		BeanJar
+-----------------------------------------+

- maxBeans : int 
- beans : int

+-----------------------------------------+

+ BeanJar(maxBeans : int, beans : int)
+ getBeans() : int
+ addBeans(beans : int) : bool
+ removeBeans(beans : int) : bool

+-----------------------------------------+
*/

class BeanJar
{
public:
	BeanJar(int maxBeans, int beans);
	int getBeans() const;
	bool addBeans(int beans);
	bool removeBeans(int beans);

private:
	int maxBeans;
	int beans;
};
