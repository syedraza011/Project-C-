
#pragma once
#include "Cart.h"
#include "EmployeeTable.h"
#include "ItemTable.h"
#include "CustomerTable.h"
#include <string>
#include <vector>
using namespace std;
class POS {
public:
	//default constructor
	POS();
	//main menu for the pos system
	void mainMenu();
	//private dara members
private:
	ItemTable allItemsTable;
	vector<Item> allItems = allItemsTable.getAllStoreItems();
	EmployeeTable allEmployeesTable;
	CustomerTable allCustomersTable;
	Cart aCartToCheckOut;
};