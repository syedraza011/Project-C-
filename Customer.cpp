#include "Customer.h"
#include <string>
#include <vector>
using namespace std;
// Default constructor
Customer::Customer()
{
	spending= 0.00;
}
// //definition of Default constructor with parameters 
Customer::Customer (string id, string name, string address,string phone, double spending):Person(id,name,address,phone)
{
	
	this->spending = spending;
}
// This sets the spending of customer
void Customer::setSpending(double spending)
{
	this->spending = spending;
}
// This gets the spending of customer
double Customer::getSpending() const
{
	return spending;
}
// This Prints the spending of customer
void Customer::print() const
{
	Person::print();
	cout << "\nSpending: $" << spending<<"\n"<<endl;
}

