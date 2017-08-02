/**********************************************************************
 * Kyle Lee
 * Workers.h
 * May 24, 2015
 * CSE 202 (Wednesday lab)
 * Description: Create a class representing a worker, and then create
   and test two other types of worker classes based on the original 
   class.
 * Solution: Define the HourlyWorker and SalariedWorker classes as 
   derived classes of the base class Worker by using inheritance. 
   Define compute_pay function as virtual in order for the program
   to choose which function to run at runtime. 
 * Percent complete: 100%
**********************************************************************/

#include <string>
#include <iostream>

using namespace std;

class Worker
{
protected:
	string name;
	double salary_rate;
public:
	Worker(): name(""), salary_rate(0) { }
	Worker(string n, double r): name(n), salary_rate(r) { }
	string get_name() { return name; } 
	double get_rate() { return salary_rate; }
	virtual double compute_pay(int hours)
	{
		double weekly_pay = hours * salary_rate;
		return weekly_pay;
	}
};

class HourlyWorker : public Worker
{
private:
	double weekly_wages;
public:
	HourlyWorker(): Worker(), weekly_wages(0) { }
	HourlyWorker(string n, double r): Worker(n, r), weekly_wages(0) { }
	virtual double compute_pay(int hours)
	{
		double overtime_rate = salary_rate * 1.5;
		
		if (hours <= 40) {
			weekly_wages = Worker::compute_pay(hours);
		} else {
			int overtime_hours = hours - 40;
			weekly_wages = Worker::compute_pay(40) + (overtime_hours * overtime_rate);
		}

		return weekly_wages;
	}
};

class SalariedWorker : public Worker
{
private:
	double weekly_salary;
public:
	SalariedWorker(): Worker(), weekly_salary(0) { }
	SalariedWorker(string n, double r): Worker(n, r), weekly_salary(0) { }
	virtual double compute_pay(int hours)
	{
		weekly_salary = Worker::compute_pay(40);
		return weekly_salary;
	}
};


		
	
			
			
		
			
		
		
	
		
