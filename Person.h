#pragma once
#include <iostream>
#include <string>
using namespace std;
class Person
{
	//Public data Members
public:
	//general Constructor
	Person(); 
	//constructor Initilizer
	Person(string id, string name, string address, string phone);
	//print function decleration
	 void print() const;
	 //setter to set the id of a person
	void setId(string id);
	//setter to set the Name of a person
	void setName(string name);
	//setter to set the Address of a person
	void setAddress(string address);
	//setter to set the Phone of a person
	void setPhone(string phone);
	//getter to get the ID of the person 
	string getId();
	//getter to get the Name of the person 
	string getName();
	//getter to get the Address of the person 
	string getAddress();
	//getter to get the Phone # of the person 
	string getPhone();
	//private data Members
private:
	string id;
	string name;
	string address;
	string phone;
	
	
};