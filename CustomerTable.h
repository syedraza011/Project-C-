#pragma once
#include "DataBase.h"
#include "Customer.h"
//public inheritance from Database class
class CustomerTable : public DataBase <Customer>
{
	
public:
	
	//general constructor
	CustomerTable();
	vector<Customer> getCustomers();
	// The function for add customer
	virtual bool add(Customer tempVariable);
	// The function for edit customer
	virtual bool edit(Customer tempVariable);
	// The function for remove customer
	virtual bool remove(Customer tempVaribale);
	// The function to update spending for customer
	bool updateSpendings(int index, double tempSpendings);
	// The function declaration for search with one parameter
	int search(string tempid);
	// The function declaration for customer menu with one parameter
	void customerMenu(int user);
	// The function declaration for input of the customer
	Customer inputCustomer();
	// The function declaration for customer spending
	void customerSpendings();
	// File function declaration
	void file();
	// Private data members
private:
	vector <Customer> VectorOfAllCustomers;
	void writeToFile(Customer newCustomer);
};
