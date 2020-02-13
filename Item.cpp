#include "Item.h"
#include "ItemTable.h"
#include <vector>
#include<iostream>
#include<iterator>
#include<fstream>
#include <string>
using namespace std;
//general constructor's definition without parameter
Item::Item()
{
	id="0000";
	name="John Doe";
	costPrice= 0.00;
	sellPrice= 0.00;
	quantity= 0;

}
//general constructor's definition with parameter
Item::Item(string id, string name, double costPrice, double sellPrice, int quantity)
{
	this->name = name;
	this->id = id;
	this->costPrice = costPrice;
	this->sellPrice = sellPrice;
	this->quantity = quantity;
}
//getter to get the id of an item
string Item::getId() const
{
	return id;
}
//getter to get the Name of an item
string Item::getName() const
{
	return name;
}
//getter to get the cost price of an item
double Item::getCostPrice() const
{
	return costPrice;
}
//getter to get the sell Price of an item
double Item::getSellPrice() const
{
	return sellPrice;
}
//getter to get the quantity of an item
int Item::getQuantity()const
{
	return quantity;
}
//setter to set the id of an item
void Item::setId(string id)
{
	this->id = id;
}
//setter to set the name of an item
void Item::setName(string name)
{
	this->name = name;
}
//setter to set the cost price of an item
void Item::setCostPrice(double costPrice)
{
	this->costPrice = costPrice;
}
//setter to set the sell price of an item
void Item::setSellPrice(double sellPrice)
{
	this->sellPrice = sellPrice;
}
//setter to set the quantity of an item
void Item::setQuantity(int quantity)
{
	this->quantity = quantity;
}
//print function for private data members
void Item::print() const
{
	cout << "ID: " << id << "\nName : " << name << "\nCost Price: $" << costPrice 
		<< "\nSale Price :$" << sellPrice <<"\nQuantity: " << quantity<<"\n"<< endl;

}
bool Item :: operator< (const Item& itemObj) const
{
	if (itemObj.id < this->id)
		return true;
}
