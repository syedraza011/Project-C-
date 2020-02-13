#pragma once
#include "Person.h"
//default Constructor
Person::Person()
{
	id = "000000";
	name = "john doe";
	address = "house address Brooklyn NY";
	phone = "1234567890";
}
//default constructor with Parametters
Person::Person(string id, string name, string address, string phone)
{
	this->id = id;
	this->phone = phone;
	this->name = name;
	this->address = address;
}
//function to get ID
string Person::getId() 
{
	return id;

}
// //function to get Name
string Person::getName()
{
	return name;
}
// function to get Address
string Person::getAddress()
{
	return address;
}
// function to get Phone
string Person::getPhone()
{
	return phone;
}
//function definition to set ID
void Person::setId(string id)
{
	this->id = id;
}
//function definition to set Name
void Person::setName(string name)
{
	this->name = name;
}
//function definition to set Address
void Person::setAddress(string address)
{
	this->address = address;
}
//function definition to set Phone
void Person::setPhone(string phone)
{
	this->phone = phone;
}
//definition of function print
void Person::print() const
{
	cout << "ID :" << id;
	cout<<"\n"<< "Name: " <<name << "\n" <<"Address: "<<address << "\n" <<"Phone: "<<phone;
}
