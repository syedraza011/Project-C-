#pragma once
#include <vector>
#include <string>
#include "person.h"
using namespace  std;
class Customer : public Person 
{
	// public data members
	public:
	/*default Constructor*/
	Customer();
	//constructor Initializer with parameters
	Customer(string id, string name, string address, string phone, double spending);
	// menu function declaration
	void menu();
	// print function declaration
	void print() const;
	// setter to set the spendings of customer
	void setSpending(double spending);
	// getter to get the spendings of customer
	double getSpending() const;
	// private data members
	private:

	double spending;
	vector <Customer> allCustomer;

};


