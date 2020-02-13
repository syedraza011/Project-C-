#pragma once
#include<map>
#include <vector>
#include <string>
using namespace std;
class Item {
	// Public data members
public:
	// General constructor
	Item();
	//constructor Initializer
	Item(string id, string name, double costPrice, double sellPrice, int quantity);
	// The Function declaration for searchAnItems with on parameter
	void searchAnItem(string tempItem);
	// The function declaration for allTheItems
	void allTheItems();
	// print function declaration
	void print() const;
	// menu function declaration
	void menu();
	// getter to get the name of the item
	string getName() const;
	// getter to get the id of the item
	string getId() const;
	// The function declaration for getSellprice of item
	double getSellPrice() const;
	// The function declaration for getCostprice of item
	double getCostPrice() const;
	// The function declaration for getQuantity of item
	int getQuantity()const;
	// setter to set the id of item
	void setId(string id);
	// setter to set the name of item
	void setName(string name);
	// setter to set the CostPrice of item
	void setCostPrice(double costPrice);
	// setter to set the SellPrice of item
	void setSellPrice(double sellprice);
	// setter to set the Quantity of item
	void setQuantity(int quantity);
	bool operator< (const Item& itemObj) const;
	// Private data members
private:
	string id;
	string name;
	double costPrice;
	double sellPrice;
	int quantity;


};

