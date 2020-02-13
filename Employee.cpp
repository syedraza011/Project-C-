#pragma once
#include "Employee.h"
#include<iostream>
#include<fstream>
#include <vector>
using namespace std;
//definition of Default constructor with out parameters
Employee::Employee()
{
	sSecurity = "1234";
	salary = 0.00;
}
//definition of Default constructor with parameters 
Employee::Employee(string id,string name,string address, string phone, string sSecurity, double Salary): Person(id,name,address,phone)
{
	
	this->sSecurity = sSecurity;
	this->salary = salary;
}
//definition of get Social of an Employee
string Employee::getSSecurity()
{
	return sSecurity;
}
//definition of get Salary of an Employee
double Employee::getSalary()
{
	return salary;
}
//definition of Set Social of an Employee
void Employee::setSSecurity(string sSecurity)
{
	this->sSecurity = sSecurity;
}
//definition of get Salary of an Employee
void Employee::setSalary(double salary)
{
	this->salary = salary;
}
//Print function definition to print private data members
void Employee::print() const
{
	Person::print();
	cout << "\nSocial: " << sSecurity << "\nSalary:  $" << salary <<"\n"<< endl;;
}
