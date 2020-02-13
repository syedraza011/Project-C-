#pragma once
#include "CustomerTable.h"
#include<fstream>
#include <algorithm>
#include<sstream>
#include<string>
#include <iostream>
using namespace std;
CustomerTable::CustomerTable()
{
	// This is for the file called storeCustomer
	ifstream inData("storeCustomer.txt");
	
	string tempVariable;
	Customer tempCustomer;
	stringstream stoD;
	double tVariable = 0.0;
	while (!inData.eof())
	// This is the information that is going to be in the file
	// This is also going to be able to remove,add, edit the informtion of the customer file
	{
		string tempVariable="";
		getline(inData, tempVariable,';');
		tempVariable.erase(std::remove(tempVariable.begin(), tempVariable.end(), '\n'), tempVariable.end());
		tempCustomer.setId(tempVariable);
		getline(inData, tempVariable, ';');
		tempCustomer.setName(tempVariable);
		getline(inData, tempVariable, ';');
		tempCustomer.setAddress(tempVariable);
		getline(inData, tempVariable, ';');
		tempCustomer.setPhone(tempVariable);
		getline(inData, tempVariable, ';');
		std::istringstream iss(tempVariable);
		iss >> tVariable;
		tempCustomer.setSpending(tVariable);
		VectorOfAllCustomers.push_back(tempCustomer);
	}
	

}
// This takes getcustomr and give back a vector
vector<Customer>  CustomerTable::getCustomers()
{
	vector<Customer> allCustomers;
	return  allCustomers;
}

void CustomerTable::file()
{
	for (int i = 0; i < VectorOfAllCustomers.size()-1; i++)
	{
		VectorOfAllCustomers[i].print();
	}
}
// This is for the customer file  
void CustomerTable::writeToFile(Customer newCustomer)
{
	// This checks the information in the file of storeCustomer
	ofstream newFile;
	newFile.open("storeCustomer.txt", ios::app);
	VectorOfAllCustomers.end();
	newFile<<"\n"<< newCustomer.getId()<< ';' << newCustomer.getName() << ';' << newCustomer.getAddress() << ';' 
										<< newCustomer.getPhone() << ';'<<newCustomer.getSpending()<<";";
	newFile.close();

}
// This adds information to the file
bool CustomerTable::add(Customer tempVariable)
{
	
	
		VectorOfAllCustomers.push_back(tempVariable);
		//add to file. text need to write that code
		writeToFile(tempVariable);
		return true;
	
	
}
// This edit the information in the file
bool CustomerTable::edit(Customer tempCustomer)
{
	bool result = false;
	
	for (int i = 0; i < VectorOfAllCustomers.size(); i++)
	{
		if (tempCustomer.getId() == VectorOfAllCustomers[i].getId())
		{
			VectorOfAllCustomers[i] = tempCustomer;
			result = true;
		}
	}
	// This is the information that will be add, removed , or edit
			ofstream newFile;
			newFile.open("storeCustomer.txt");
			for (int i = 0; i < VectorOfAllCustomers.size() - 1; ++i)
			{
				if (i == 0)
				{
					newFile << VectorOfAllCustomers[i].getId() << ';' << VectorOfAllCustomers[i].getName()
						<< ';' << VectorOfAllCustomers[i].getAddress() << ';' << VectorOfAllCustomers[i].getPhone()
						<< ';' << VectorOfAllCustomers[i].getSpending() << ';';
				}

				else
				{
					newFile << "\n" << VectorOfAllCustomers[i].getId() << ';' << VectorOfAllCustomers[i].getName()
						<< ';' << VectorOfAllCustomers[i].getAddress() << ';' << VectorOfAllCustomers[i].getPhone()
						<< ';' << VectorOfAllCustomers[i].getSpending() << ';';
				}
			}
			newFile.close();

		
	return result;
}
// This Removes the infomration from the customer file
bool CustomerTable::remove(Customer tempCustomer)
{
	bool result = false;
	search(tempCustomer.getId());
	for (int i = 0; i < VectorOfAllCustomers.size()-1; i++)
	{
		if (tempCustomer.getId() == VectorOfAllCustomers[i].getId())
		{
			VectorOfAllCustomers.erase(VectorOfAllCustomers.begin() + (i));
			file();
			
			ofstream newFile;
			newFile.open("storeCustomer.txt");
			for (int i = 0; i < VectorOfAllCustomers.size()-1; ++i)
			{
				if (i == 0)
				{
					newFile << VectorOfAllCustomers[i].getId() << ';' << VectorOfAllCustomers[i].getName()
						<< ';' << VectorOfAllCustomers[i].getAddress() << ';' << VectorOfAllCustomers[i].getPhone()
						<< ';' << VectorOfAllCustomers[i].getSpending() << ';';
				}
				
				else
				{
					newFile << "\n" << VectorOfAllCustomers[i].getId() << ';' << VectorOfAllCustomers[i].getName()
						<< ';' << VectorOfAllCustomers[i].getAddress() << ';' << VectorOfAllCustomers[i].getPhone()
						<< ';' << VectorOfAllCustomers[i].getSpending() << ';';
				}
			}
			newFile.close();
			result = true;
		}
	}

	return result;
}
// This is the make the search for the information in the file
int CustomerTable::search(string tempid)
{

	for (int i = 0; i < VectorOfAllCustomers.size(); i++)
	{
		if (tempid == VectorOfAllCustomers[i].getId())
		{
			return i;
		}

	}

	return -1;
}
// This is for the input of customer
Customer CustomerTable::inputCustomer()
{
	double tempCus;
	Customer tempCustomer;
	string tCustomer;
	cin.ignore();
	cout << "Id :";
	getline(cin, tCustomer);
	tempCustomer.setId(tCustomer);
	cout << "Name :";
	getline(cin, tCustomer);
	tempCustomer.setName(tCustomer);

	cout << "Address :";
	getline(cin, tCustomer);
	tempCustomer.setAddress(tCustomer);
	cout << "Phone :";
	getline(cin, tCustomer);
	tempCustomer.setPhone(tCustomer);
	cout << "Spending :";
	getline(cin, tCustomer);
	std::istringstream iss(tCustomer);
	iss >> tempCus;
	tempCustomer.setSpending(tempCus);
	
	/*getline(cin, tCustomer);
	tempCustomer.setSpending(stod(tCustomer));*/
	return tempCustomer;
}
// This keeps track of the spending of customer
bool CustomerTable::updateSpendings(int index, double spendings)
{
	spendings += VectorOfAllCustomers[index].getSpending();
		VectorOfAllCustomers[index].setSpending(spendings);
		//cout << "\nSpendings updates" << VectorOfAllCustomers[index].getSpending();
		edit(VectorOfAllCustomers[index]);
	return true;
}
// This for the customer spendings
void CustomerTable::customerSpendings()
{
	int result= -1;
	Customer t;
	string searchID;
	cin.ignore();
	cout << "Please enter the Customer's id: ";
	getline(cin,searchID);
	 result=search(searchID);
	if (result !=-1)
	{
		cout << "\n The Customer"<<" \""<< VectorOfAllCustomers[result].getName() <<" \"'s spendings ="<<" $"
									<< VectorOfAllCustomers[result].getSpending() << endl;
		
	}
	else
	{
		cout << "Customer does not Exist in DataBase" << endl;
		
	}
}
// This is what in the customer menu
void CustomerTable::customerMenu(int user)
{
	if (user == 1)
	{
		int choice;
		cout << "\n------: Customer Menu :-----\n" << endl;
		cout << "1> Add New Customer" << endl;
		cout << "2> Remove a Customer " << endl;
		cout << "3> edit custmoer " << endl;
		cout << "4> lookup spending " << endl;
		cout << "5> Search a Customer" << endl;
		cout << "6> View all Registered Customer" << endl;
		cout << "0>       ExIT   " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
		{
			break;
		}

		//to add item to database
		case 1:
		{
			char uChoice = 'y';
			Customer tempCustomer;
			while (uChoice == 'y')
			{
				tempCustomer = inputCustomer();
				add(tempCustomer);
				//file();
				cout << "\ndo you want to add more y/n :";
				cin >> uChoice;
				tolower(uChoice);
			}// Ending while for repeating the Menu
			break;
		}// ending case 1



		//case 2: to remove item form the database
		case 2:
		{
			char uChoice = 'y';
			string tempcustomerId;
			Customer ItemToDelete;
			int result = -1;
			while (uChoice == 'y')
			{
				cout << "Please enter an Item's Id to remove:";
				cin >> tempcustomerId;
				result = search(tempcustomerId);
				if (result != -1)
				{
					Customer temp;
					for (int i = 0; i < VectorOfAllCustomers.size() - 1; i++)
					{
						if (tempcustomerId == VectorOfAllCustomers[i].getId())
						{
							temp = VectorOfAllCustomers[i];
						}
						else
						{

						}
					}
					remove(temp);
					cout << "\nFound & Able to delete \n" << endl;

				}
				else
				{
					cout << "\nCustomer not Found \n" << endl;
				}

				cin >> uChoice;
				tolower(uChoice);

			}// ending loop for repeatition}
			break;

		}// ending case 2
		// case 3 to edit a customer's info
		case 3:
		{
			string tempId;
			int result = -1;
			cin.ignore();
			cout << "please enter a Customer's ID :";
			getline(cin, tempId);
			result = search(tempId);
			if (result != -1)
			{
				bool returned = false;
				Customer temp = inputCustomer();
				returned=edit(temp);
				if(returned==true)
				{
					cout << "\nCutsomer's Info has been Successfully Edited..!!";
				}
				
			}
			else
			{
				cout << "\nCustomer does not exist in the System\n";
			}

			break;



		}//ending case 3
		// case 4 lookup spendings
		case 4:
		{
			customerSpendings();
			cout << endl;
			break;
		}//ending case 4
		//search for a customer
		case 5:
		{
			int result = -1;
			string tempId;
			cin.ignore();
			cout << "please enter a Customer's ID :";
			getline(cin, tempId);
			result = search(tempId);

			if (result != -1)
			{
				cout << "\nContact does Exists\n";
				VectorOfAllCustomers[result].print();
			}
			else
			{
				cout << "\nContact does not Exists\n" << endl;

			}
			break;
		}//ending case 5
		case 6:
		{
			file();
			break;
		}//ending case 5
		default:
		{
			cout << "\nplease make a valid choice\n";
		}// ending default
		}// ending switch statement
	}//ending if statement of user
	else if (user == 2)
	{
		int choice;
		cout << "\n------: Customer Menu :-----\n" << endl;
		cout << "1> Add New Customer" << endl;
		cout << "2> Remove a Customer " << endl;
		cout << "3> edit custmoer " << endl;
		cout << "4> lookup spending " << endl;
		cout << "5> Search a Customer" << endl;
		cout << "6> View all Registered Customer" << endl;
		cout << "0>       ExIT   " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
		{
			break;
		}

		//to add item to database
		case 1:
		{
			char uChoice = 'y';
			Customer tempCustomer;
			while (uChoice == 'y')
			{
				tempCustomer = inputCustomer();
				add(tempCustomer);
				//file();
				cout << "\ndo you want to add more y/n :";
				cin >> uChoice;
				tolower(uChoice);
			}// Ending while for repeating the Menu
			break;
		}// ending case 1



		//case 2: to remove item form the database
		case 2:
		{
			cout << "\nNot an authorized user \n" << endl;
			break;

		}// ending case 2
		// case 3 to edit a customer's info
		case 3:
		{
			string tempId;
			int result = -1;
			cin.ignore();
			cout << "please enter a Customer's ID :";
			getline(cin, tempId);
			result = search(tempId);
			if (result != -1)
			{
				Customer temp = inputCustomer();
				edit(temp);
				break;
			}
			else
			{
				cout << "\nCustomer does not exist in the System\n";
			}

			break;



		}//ending case 3
		// case 4 lookup spendings
		case 4:
		{
			customerSpendings();
			cout << endl;
			break;
		}//ending case 4
		//search for a customer
		case 5:
		{
			int result = -1;
			string tempId;
			cin.ignore();
			cout << "please enter a Customer's ID :";
			getline(cin, tempId);
			result = search(tempId);

			if (result != -1)
			{
				cout << "\nContact does Exists\n";
			}
			else
			{
				cout << "\nContact does not Exists\n" << endl;

			}
			break;
		}//ending case 5
		case 6:
		{
			cout << "\nOption is not available\n";
			break;
		}//ending case 6
		default:
		{
			cout << "\nplease make a valid choice\n";
		}// ending default
		}// ending switch statement
	}//ending else if statement of user

}//ending customer menu