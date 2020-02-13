#pragma once
#include "Employee.h"
class EmployeeTable
{
	// Public data members
	public:
	// General constructor
	EmployeeTable();
	// The function declaration for employeeInput
	Employee employeeInput();
	// The function declaration for viewEmployee
	void viewEmployee();
	vector <Employee> getAllStoreEmployees();
	// The function declaration for employeeMenu
	void employeeMenu();
	// The function declaration for search with one parameter
	int search(string tempId);
	// The function for add Employee
	virtual bool add(Employee tempEmployee);
	// The function for edit Employee
	virtual bool edit(Employee tempEmployee);
	// The function for remove Employee
	virtual bool remove(Employee tempEmployee);
	// Private data members
private:
	vector <Employee> allStoreEmployees;
	void writeEmployeeToFile(Employee newEmployee);
};

