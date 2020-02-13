#pragma once
#include "ItemTable.h"
#include "CustomerTable.h"
#include<map>
#include <vector>
#include "Item.h"
class Cart
{
	// public data members
	public:
	//default Constructor
	Cart();
	vector<Item>vectorOfAllItems();
	// The addtocart function data members that has one parameter
	void addToCart(int index);
	// aCartTotal function declaration
	double aCartTotal();
	// The function declaration for checkout of cart
	void checkout();
	// dateAndTime function declaration
	void dateAndTime();
	// Private data members	
private:
	ItemTable aTable;
	CustomerTable allCustomers;
	map <Item, int> aCartMap;

};
