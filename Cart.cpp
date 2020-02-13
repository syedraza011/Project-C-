#pragma onc
#include "Cart.h"
#include <iostream>
#include "ItemTable.h"
#include<fstream>
#include <string>
#include<cmath>
#include<ctime>
using namespace std;
// This is the Default Constructor
// This does not take parameters
Cart::Cart()
{
}
// This takes the vectorOfAllItems and gives a vector
vector<Item> Cart::vectorOfAllItems()
{
	vector<Item> allStoreItems;
	return allStoreItems;
}
// This is to checkout the cart 
// with the item that the customer wants to buy
void Cart::checkout()
{
	// This is for the customer when he picks the item
	cout << "\n----: Check out Menu :----\n";
	
	string ID;
	char uChoice = 'y';
	int search=-1;
	Customer temp;
	double spending;
	// This while loop is if the customer says yes 
	// The customer puts the item id 
	while (uChoice=='y')
	{
		
		cout << "Please enter an Item's ID : ";
		cin >> ID;
		search = aTable.search(ID);
		if (search !=-1)
		{
			addToCart(search);
			aTable.updateQunatity(search);
		}
		else
		{
			cout << "\nWrong id entered\n";
			continue;

		}
		cout << "to continue press y/n : ";
		cin >> uChoice;

		tolower(uChoice);
		
	}
	// This is for if the customer has an id
	// if its yes then the program will go through the if statement
	cout << "Does the customer has an ID?? y/n : ";
	cin >> uChoice;
	tolower(uChoice);
	if (uChoice == 'y')
	{
		// This prints out the customer id and the cout statement
		cout << "Please enter Customer's ID : ";
		cin >> ID;
		spending = aCartTotal();
		search = allCustomers.search(ID);
		if (search != -1)
		{
			// This keeps track of the customer spendings
			bool returned = false;
			returned=allCustomers.updateSpendings(search, spending);
			if (returned == true)
			{
				cout << "\nSuccessfully added for Reward Points\n";
				//cout << "Name" << allCustomers.getCustomers[search].getName()<<" Spenidngs"<< allCustomers.getCustomers[search].getSpending()<<endl;
			}
			//temp = allCustomers.[search];
		}
	}
	else {
		aCartTotal();
	}
	
}
// This to show how much is the total of all the items the customer is buying
double Cart::aCartTotal()
{
	system("cls");

	// This prints out the customer information 
	double total = 0.0;
	//system("cls");
	cout << "\n\t\t\t!!The Virtual Systems!!"<<endl;
	cout << "\t\t2800 Victory BLVD Staten Island 10314" << endl;
				dateAndTime();
	// This prints out the item informations
	cout << "\n\nQuantity Item Name\tUnit Price\tTotal"<<endl;
	for (map<Item, int>::iterator it = aCartMap.begin(); it != aCartMap.end(); ++it)
	{

		cout <<" "<< it->second << "\t" << it->first.getName() << "\t\tx$" << it->first.getSellPrice() <<"\t\t"
								<< "$" << it->second*it->first.getSellPrice() << endl;
		total += it->second*it->first.getSellPrice();

	}
	// This gives the total information
	cout << "\n\n"<<endl;
	cout << "\tTotal Amount due is: $" << total << endl;
	cout << "\tThank you for shopping!!!" << endl;
	cout << "\n\n";
	
	return total;
}
// This shows the date and time when the customer check out
void Cart::dateAndTime()
{
	#pragma warning(disable : 4996).
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	cout << "\t\t" << "Date: " << (timePtr->tm_mon) + 1  << "/" << (timePtr->tm_mday) << "/" << (timePtr->tm_year) + 1900 ;
	cout <<"\t"<< "Time: " << (timePtr->tm_hour) << ":" << (timePtr->tm_min) << ":" << (timePtr->tm_sec) << endl;
}
// This is to add more items to the cart if the customer wants to add more items
void Cart::addToCart(int index)
{
	Item temp = aTable.getAllStoreItems()[index];

	int counter = 0;
	string name;
	if (aCartMap.find(temp) == aCartMap.end())
	{
		aCartMap[temp] = 1; //initilaize with one while inserting to map
	}
	else
	{
		counter=aCartMap[temp];
		counter++; //update counter if the word alresdy existed 
		aCartMap[temp] = counter; //update the Item count the value of the map
	}

	cout << "\n" << endl;

	//map iterator initialized to treverse through
	for (map<Item, int>::iterator it = aCartMap.begin(); it != aCartMap.end(); ++it)
	{

		cout << it->second<< "   " << it->first.getName() << "\tX " << it->first.getSellPrice() << " \n" << endl;

	}// ending iterator loop which is being used to print
	
}
