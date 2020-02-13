#include "ItemTable.h"

using namespace std;
ItemTable::ItemTable()
{
	// This is to open the the text file
	// That’s called storeinvetory
	Item tempItem;
	fstream inData("storeInvetory.txt");
	string tempVariable;
	double tempV = 0.0;
	int tVariable = 0;
	while (!inData.eof())
	{
		// This is the information that will be in the file
		inData >> tempVariable;
		tempItem.setId(tempVariable);
		inData >> tempVariable;
		tempItem.setName(tempVariable);
		inData >> tempV;
		tempItem.setCostPrice(tempV);
		inData >> tempV;
		tempItem.setSellPrice(tempV);
		inData >> tVariable;
		tempItem.setQuantity(tVariable);
		allStoreItems.push_back(tempItem);
	}
}
// This takes allstoreitems and gives back a vector
vector<Item> ItemTable::getAllStoreItems()
{
	return allStoreItems;
}
// This is for the newitem 
// In the file of storeInvetory
void ItemTable::writeToFile(Item newItem)
{
	ofstream newFile;
	newFile.open("storeInvetory.txt", ios::app);
	allStoreItems.end();
	newFile << "\n" << newItem.getId() << ' ' << newItem.getName() << ' ' << newItem.getCostPrice()
		<< ' ' << newItem.getSellPrice() << ' ' << newItem.getQuantity();

	newFile.close();

}
// This is to see the function viewitem
void ItemTable::viewItems()
{

	for (int i = 0; i < allStoreItems.size(); i++)
	{
		allStoreItems[i].print();
	}
}
// This is the add function declaration for item that has one parameter
bool ItemTable::add(Item tempItem)
{
	allStoreItems.push_back(tempItem);
	writeToFile(tempItem);
	return true;
}
// This is the edit function declaration for item that has one parameter
bool ItemTable::edit(Item tempItem)
{
	bool result = false;
	ofstream newFile;
	newFile.open("storeInvetory.txt");

	for (int i = 0; i < allStoreItems.size(); i++)
	{
		if (tempItem.getId() == allStoreItems[i].getId())
		{
			allStoreItems[i] = tempItem;

			result = true;
		}
		if (i == 0)
		{
			// This is for edit function
			// This is the information the will be edit if need to
			newFile << allStoreItems[i].getId() << ' ' << allStoreItems[i].getName() << ' ' << allStoreItems[i].getCostPrice()
				<< ' ' << allStoreItems[i].getSellPrice() << ' ' << allStoreItems[i].getQuantity();
		}
		else
		{
			newFile << "\n" << allStoreItems[i].getId() << ' ' << allStoreItems[i].getName() << ' ' << allStoreItems[i].getCostPrice()
				<< ' ' << allStoreItems[i].getSellPrice() << ' ' << allStoreItems[i].getQuantity();
		}
	}
	newFile.close();
	return result;
}
// This is the remove function declaration for item that has one parameter
bool ItemTable::remove(Item tempItem)
{
	ofstream newFile;
	newFile.open("storeInvetory.txt");
	bool result = false;
	// This is going check for the size of the item
	for (int i = 0; i < allStoreItems.size() - 1; i++)
	{
		if (tempItem.getId() == allStoreItems[i].getId())
		{
			// This is going to check the viewitems 
			allStoreItems.erase(allStoreItems.begin() + (i));
			viewItems();

		}//ending if
	}//ending for loop 
	for (int i = 0; i < allStoreItems.size() - 1; ++i)
	{
		if (i == 0)
		{
			// This is going to be The information in the file
			// The program will get these information form the file for items
			newFile << allStoreItems[i].getId() << ' ' << allStoreItems[i].getName() << ' ' << allStoreItems[i].getCostPrice()
				<< ' ' << allStoreItems[i].getSellPrice() << ' ' << allStoreItems[i].getQuantity();
		}
		else
		{
			newFile << "\n" << allStoreItems[i].getId() << ' ' << allStoreItems[i].getName() << ' ' << allStoreItems[i].getCostPrice()
				<< ' ' << allStoreItems[i].getSellPrice() << ' ' << allStoreItems[i].getQuantity();
		}
	}
	newFile.close();
	result = true;


	return result;


}
// This to search for the item that has one parameter
// This searches for the item by the id of the item
int ItemTable::search(string tempid)
{
	int result = -1;

	// This is to search for the item
	// After is goes through the for loop
	for (int i = 0; i < allStoreItems.size(); i++)
	{
		if (tempid == allStoreItems[i].getId())
		{
			// This prints that search for the item
			allStoreItems[i].print();
			result = i;
		}
	}

	return result;
}
// This is to keep track of the Quantity of the item
bool ItemTable::updateQunatity(int index)
{
	// This Sees of how many numbers of the same item that the customer is buying
	allStoreItems[index].setQuantity(allStoreItems[index].getQuantity() - 1);
	edit(allStoreItems[index]);


	return true;
}
// This is to show the item input
Item ItemTable::itemInput()
{
	// This is the information that the program is going to be asking for
	string tempVariable;
	Item tempItem;
	double tempV;
	int tVariable;
	cin.ignore();
	cout << "Id :";
	getline(cin, tempVariable);
	tempItem.setId(tempVariable);
	cout << "Name :";
	getline(cin, tempVariable);
	tempItem.setName(tempVariable);
	cout << "Cost :";
	cin >> tempV;
	tempItem.setCostPrice(tempV);
	cout << "Sell :";
	cin >> tempV;
	tempItem.setSellPrice(tempV);
	cout << "Quantity :";
	cin >> tVariable;
	tempItem.setQuantity(tVariable);
	return tempItem;
}
// This is for the item Menu
// The menu has different options of the menu
void ItemTable::itemMenu(int user)
{
	if (user == 1)
	{
		// This is what the menu will have when the program runs
		int choice;
		cout << "\n------: Item Menu :-----\n" << endl;
		cout << "1> add an Item" << endl;
		cout << "2> Edit an item " << endl;
		cout << "3> remove an item " << endl;
		cout << "4> price of an Item" << endl;
		cout << "5> search an Item; if exists" << endl;
		cout << "6> view available Items" << endl;
		cout << "0> Exit" << endl;
		cin >> choice;
		switch (choice)
			// Before the customer wants to add more item of not 
			// They can choose to exit the menu 
		{
			//to add item to database
		case 0:
		{

			break;
		}
		// add items 
		case 1:
		{

			char uChoice = 'y';
			Item tempItem;
			while (uChoice == 'y')
			{
				// The program will go through the if statement before adding an item
				Item temp = itemInput();
				bool result = add(temp);
				if (result == true)
				{
					// This is going to print of the adding the item was success
					cout << "\nSuccess with adding Item !!\n";
				}
				else
				{
					// This is going to print if the adding the wasn’t successful
					cout << "Not Successful";
				}
				// This asks if you want to add more items
				// You choose either y/n for yes or no
				cout << "\ndo you want to add more y/n :";
				cin >> uChoice;
				tolower(uChoice);
			}// Ending while for repeating the Menu
			break;
		}// ending case 1
		//case 2: to Edit item form the database
		case 2:
		{
			// This will ask the program for the id number of the item
			string tempId;
			bool returned = false;
			int result = -1;
			cin.ignore();
			cout << "please enter an Item's ID :";
			getline(cin, tempId);
			result = search(tempId);
			if (result != -1)
			{
				Item temp = itemInput();
				returned = edit(temp);
				if (returned == true)
				{
					// This is going to print of the editing the item was success
					cout << "\nSuccesfully Edited the Item\n";
				}
			}
			else
			{
				cout << "\nItem does not exist in the System\n";
			}
			break;



		}// ending case 2
		// case 3 to Remove 
		case 3:
		{
			char uChoice = 'y';
			string tempItemId;
			int result = -1;
			while (uChoice == 'y')
			{
				// For this you have to put the id of the item for it to be able removed
				cout << "Please enter an Item's Id to remove:";
				cin >> tempItemId;
				// This makes that search for that id of the item
				result = search(tempItemId);
				if (result != -1)
				{
					bool returned = false;
					returned = remove(allStoreItems[result]);
					if (returned == true)
					{
						// This prints the item and deletes it 
						cout << "\nFound the Item and able to delete\n";
					}

				}
				else
				{
					// This prints of the item was not found 
					cout << "Item was not Found " << endl;
				}
				// This asks if you want to remove a contact 
				// By choosing y/n for yes or no
				cout << "\ndo you want to remove another contact y/n :";
				cin >> uChoice;
				tolower(uChoice);
			}// ending loop for repeatition}
			break;





		}//ending case 3
		//check Price of an item
		case 4:
		{
			int result = -1;
			string ID = "";
			cin.ignore();
			cout << "please Enter the Item's ID to check the Price :";
			getline(cin, ID);
			result = search(ID);
			if (result != -1)
			{
				cout << "\nThe Price of " << "\"" << allStoreItems[result].getName() << "\"" << " is : $" << allStoreItems[result].getSellPrice() << endl;
			}
			else
			{
				cout << "\nSorry, The Item's Price is not available..!!" << endl;
				cout << "Please ask Manager on the Floor" << endl;
			}
			break;


		}//ending case 4
		// check if item is available in stores

		case 5:
		{

			int output = -1;
			string tempId;
			cin.ignore();
			cout << "please enter an Item :";
			getline(cin, tempId);
			output = search(tempId);
			if (output != -1)
			{
				cout << "\nItem does Exists" << endl;
				//allStoreItems[output].print();
			}
			else
			{

				cout << "\nItem does not Exists\n";

			}
			break;
		}//ending case 5
		// view all items
		case 6:
		{
			system("cls");
			viewItems();
			break;
		}
		default:
		{
			cout << "\nplease make a valid choice\n";
		}// ending default
		}// ending switch statement
	}//ending if 
	else if (user == 2)
	{
		// This for the customer if he wants to add more items or edit the items or remove the item
		int choice;
		cout << "\n------: Item Menu :-----\n" << endl;
		cout << "1> add an Item" << endl;
		cout << "2> Edit an item " << endl;
		cout << "3> remove an item " << endl;
		cout << "4> price of an Item" << endl;
		cout << "5> search an Item; if exists" << endl;
		cout << "6> view available Items" << endl;
		cout << "0> Exit" << endl;
		cin >> choice;
		switch (choice)
		{
			//to add item to database
		case 0:
		{

			break;
		}
		// add items 
		case 1:
		{

			char uChoice = 'y';
			Item tempItem;
			while (uChoice == 'y')
			{
				Item temp = itemInput();
				bool result = add(temp);
				if (result == true)
				{
					// This sees if adding the item was success 
					cout << "\nSuccess with adding Item !!\n";
				}
				else
				{
					// This prints if it’s not succesfull
					cout << "Not Succesfull";
				}
				// This is for if you want to add more items
				cout << "\ndo you want to add more y/n :";
				cin >> uChoice;
				tolower(uChoice);
			}// Ending while for repeating the Menu
			break;
		}// ending case 1
		//case 2: to Edit item form the database
		case 2:
		{
			cout << "\nOption not available, ask your Manager\n";
			break;
		}// ending case 2
		// case 3 to Remove 
		case 3:
		{

			cout << "\nPlease ask the floor Manager\n";
			break;
		}//ending case 3
		//check Price of an item
		case 4:
		{
			// This is for item name and the price of the item
			int result = -1;
			string ID = "";
			cin.ignore();
			cout << "please Enter the Item's ID to check the Price :";
			getline(cin, ID);
			result = search(ID);
			if (result != -1)
			{
				cout << "\nThe Price of " << "\"" << allStoreItems[result].getName() << "\"" << " is : $" << allStoreItems[result].getSellPrice() << endl;
			}
			else
			{
				cout << "\nSorry, The Item's Price is not available..!!" << endl;
				cout << "Please ask Manager on the Floor" << endl;
			}
			break;


		}//ending case 4
		// check if item is available in stores

		case 5:
		{
			// This is to enter the item that customer wants
			int output = -1;
			string tempId;
			cin.ignore();
			cout << "please enter an Item :";
			getline(cin, tempId);
			output = search(tempId);
			if (output != -1)
			{
				// This prints if the item does exists in the store
				cout << "\nItem does Exists" << endl;
				allStoreItems[output].print();
			}
			else
			{
				// This prints if the item does not exists in the store
				cout << "\nItem does not Exists\n";

			}
			break;
		}//ending case 5
		// view all items
		case 6:
		{
			cout << "\nSorry, The Item's Price is not available..!!" << endl;
			cout << "Please ask Manager on the Floor" << endl;
			break;
		}
		default:
		{
			cout << "\nplease make a valid choice\n";
		}// ending default
		}// ending switch statement
	}//ending else if 


}//ending Item menu

