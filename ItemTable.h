#pragma once
#include<fstream>
#include <iostream>
#include "DataBase.h"
#include "Item.h"
class ItemTable : public DataBase <Item>
{
	// Public data members
public:
	// The general constructor
	ItemTable();
	// The function declaration for itemInput
	Item itemInput();
	// The function declaration for viewitems  
	void viewItems();
	vector<Item> getAllStoreItems();
	// The function for add item
	virtual bool add(Item tempItem);
	// The function for edit item
	virtual bool edit(Item tempItem);
	// The function for remove item
	virtual bool remove(Item tempItem);
	// The function for to update the quantity of item 
	bool updateQunatity(int index);
	// The function declaration for item menu with one parameter
	void itemMenu(int user);
	// The function deleraction for search that has one parameter
	int search(string tempid);
	// Private data members	
private:
	vector <Item> allStoreItems;
	void writeToFile(Item newItem);

};
