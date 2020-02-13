#pragma once
#include <vector>
#include<string>
#include "Person.h"
using namespace std;
#pragma once
//inheritance from class Person 
class Employee : public Person
{
	//public data Members
public:
	//default Constructor
	Employee();
	//Default constructor with parameters
	Employee(string id, string name, string address, string phone, string sSecurity, double Salary);
	//setter function decleration 
	string getSSecurity();

	double getSalary();
	//setter function decleration to Set Social Security 
	void setSSecurity(string sSecurity);
	////setter function decleration  for Slaary of en Employee
	void setSalary(double salary);
	// print function for class Employee
	void print() const;
	//private Data Members
private:
	
	string sSecurity;
	double salary;
	
};
