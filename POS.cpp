#pragma once
#include "POS.h"
// This is the default construtor
// This constrctor has no parameters
POS::POS()
{
	
}
// This is for the point of sale
// This shows the different selection of the menus
void POS::mainMenu()
{
	bool condition = true;
	do {
		int accountChoice;
		cout << "\n1> Administrator" << endl;
		cout << "2> Cashier" << endl;
		cout<< "0> EXit" << endl;
		cout << "your selection: ";
		cin >> accountChoice;
		string  administrator = "12", pass = "";
		if (accountChoice == 1)
		{
			//cout << "Enter Your Pass :";
			//cin >> pass;
			if (administrator == "12")
			{
				// This is the type of menus
				int choice;
				cout << "\n------: Main Menu : ----\n";
				cout << "1) Check out" << endl;
				cout << "2) Customer Menu" << endl;
				cout << "3) Item Menu" << endl;
				cout << "4) Employee Menu" << endl;
				cout << "5) EXIT" << endl;
				cin >> choice;

				if (choice == 1)
				{
					//to check out customer
					aCartToCheckOut.checkout();
					
				}
				//customer menu
				else if (choice == 2)
				{
					//customer class Menu
					allCustomersTable.customerMenu(accountChoice);
				
				
				}

				else if (choice == 3)
				{
					//item Menu

					allItemsTable.itemMenu(accountChoice);
					break;
				}
				else if (choice == 4)
				{
					// This Employee Menu
					allEmployeesTable.employeeMenu();
					

				}
				else if (choice == 5) {
					condition = false;
				}
				else
					cout << "not a valid choice" << endl;
			}// ending if for administrator
		}// ending adminitrator
		else if (accountChoice == 2)
		{
			// This is the main Menu
			// The customer picks the type of menu they want
			int choice;
			cout << "\n------: Main Menu : ----\n";
			cout << "1) Check out" << endl;
			cout << "2) Item Menu" << endl;
			cout << "3) Loyal Customer Menu" << endl;
			cout << "0 for Exit" << endl;
			// after they pick what type they can either Exit or add a different menu
			
			cin >> choice;

			if (choice == 1)
			{
				//to check out customer
				aCartToCheckOut.checkout();
			}
			else if (choice == 2)
			{
				// To item class menu
				allItemsTable.itemMenu(accountChoice);
				


			}
			else if (choice == 3)
			{
				// To check customer menu
				allCustomersTable.customerMenu(accountChoice);
				
			}
			else if (choice == 0)
			{
				condition = false;
			}

		}
		else

		{

			break;

		}//not a valid choice
	} while (condition);

}//main Menu



