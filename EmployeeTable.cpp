#include "EmployeeTable.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <algorithm>

using namespace std;

EmployeeTable::EmployeeTable()
{
	// This is calling the information of the Employee from the file 
	// Thats called storeEmployee
	double tVariable;
	ifstream inData("storeEmployee.txt");
	Employee tempEmployee;
	while (!inData.eof())
	{
		// This gets all the informations from the file storeEmployee
		// This also removes, adds, and edits the informtions in the text file
		string tempVariable="";
		getline(inData, tempVariable, ';');
		tempVariable.erase(std::remove(tempVariable.begin(),tempVariable.end(),'\n'), tempVariable.end());
		tempEmployee.setId(tempVariable);
		getline(inData, tempVariable, ';');
		tempEmployee.setName(tempVariable);
		getline(inData, tempVariable, ';');
		tempEmployee.setAddress(tempVariable);
		getline(inData, tempVariable, ';');
		tempEmployee.setPhone(tempVariable);
		getline(inData, tempVariable, ';');
		tempEmployee.setSSecurity(tempVariable);
		getline(inData, tempVariable, ';');
		std::istringstream iss(tempVariable);
		iss >> tVariable;
		tempEmployee.setSalary(tVariable);
		allStoreEmployees.push_back(tempEmployee);
	
	}
}
// This takes a getAllstoreEmployees and it gives back vector Employee
vector <Employee>  EmployeeTable::getAllStoreEmployees()
{
	vector<Employee> allStoreEmployees;
	return  allStoreEmployees;
}
// This views the allstoreEmployee
void EmployeeTable::viewEmployee()
{
	for (int i = 0; i < allStoreEmployees.size()-1; ++i)
	{
		allStoreEmployees[i].print();
	}
	
}// This shows the input for the employee
Employee EmployeeTable::employeeInput()
{
	Employee tempEmployee;
	string tEmp;
	double temp = 0.0;
	cin.ignore();
	cout << "Id :";
	getline(cin, tEmp);
	tempEmployee.setId(tEmp);
	cout << "Name :";
	getline(cin, tEmp);
	tempEmployee.setName(tEmp);
	cout << "Address :";
	getline(cin,tEmp);
	tempEmployee.setAddress(tEmp);
	cout << "Phone :";
	getline(cin, tEmp);
	tempEmployee.setPhone(tEmp);
	cout << "Social Security :";
	getline(cin, tEmp);
	tempEmployee.setSSecurity(tEmp);
	cout << "Salary :";
	cin >> temp;
	tempEmployee.setSalary(temp);
	return tempEmployee;
	//break;
}
// This adds new information to the employee file
bool EmployeeTable::add(Employee tempEmployee)
{
			//tempEmployee=employeeInput();
	allStoreEmployees.push_back(tempEmployee);
		//add to file. text need to write that code
		writeEmployeeToFile(tempEmployee);
		
	
	return true;
}
// This edit the information in the employee file
bool EmployeeTable::edit(Employee  tempEmployee)
{
	bool result = false;
	
	for (int i = 0; i < allStoreEmployees.size() - 1; i++)
	{
		if (tempEmployee.getId() == allStoreEmployees[i].getId())
		{
			allStoreEmployees[i] = tempEmployee;
			result = true;
		}
	}
	// This is to open the file 
	// This is also to read the information from the file
	// The file is called storeEmployee
	ofstream newFile;
	newFile.open("storeEmployee.txt");
	for (int i = 0; i < allStoreEmployees.size() - 1; i++)
	{
		if (i == 0)
		{
			newFile << allStoreEmployees[i].getId() << ';' << allStoreEmployees[i].getName()
				<< ';' << allStoreEmployees[i].getAddress() << ';' << allStoreEmployees[i].getPhone()
				<< ';' << allStoreEmployees[i].getSSecurity() << ';' << allStoreEmployees[i].getSalary() << ';';
		}

		else
		{
			newFile << "\n" << allStoreEmployees[i].getId() << ';' << allStoreEmployees[i].getName()
				<< ';' << allStoreEmployees[i].getAddress() << ';' << allStoreEmployees[i].getPhone()
				<< ';' << allStoreEmployees[i].getSSecurity() << ';' << allStoreEmployees[i].getSalary() << ';';
		}
	}
			newFile.close();
			result = true;
			return result;
}
// This remove the information from the file for employee
bool EmployeeTable::remove( Employee tempEmployee)
{
	bool result = false;
	
	for (int i = 0; i < allStoreEmployees.size() - 1; i++)
	{
		if (tempEmployee.getId() == allStoreEmployees[i].getId())
		{
			allStoreEmployees.erase(allStoreEmployees.begin() + (i));
			//viewEmployee();

			ofstream newFile;
			newFile.open("storeEmployee.txt");
			for (int i = 0; i < allStoreEmployees.size() - 1; ++i)
			{
				if (i == 0)
				{
					newFile << allStoreEmployees[i].getId() << ';' << allStoreEmployees[i].getName()<< ';' << allStoreEmployees[i].getAddress() 
					<< ';' << allStoreEmployees[i].getPhone()<< ';' << allStoreEmployees[i].getSSecurity() << ';' << allStoreEmployees[i].getSalary() << ';';
				}
				else
				{
					newFile <<"\n"<< allStoreEmployees[i].getId() << ';' << allStoreEmployees[i].getName()<< ';' << allStoreEmployees[i].getAddress()
						<< ';' << allStoreEmployees[i].getPhone()<< ';' << allStoreEmployees[i].getSSecurity() << ';' << allStoreEmployees[i].getSalary() << ';';
				}
			}
			newFile.close();
			result = true;
		}
	}

	return result;


}
// This opens The file
void EmployeeTable::writeEmployeeToFile(Employee newEmployee)
{
	ofstream newFile;
	newFile.open("storeEmployee.txt", ios::app);


	allStoreEmployees.end();
		newFile <<"\n"<< newEmployee.getId() << ';' << newEmployee.getName() << ';' << newEmployee.getAddress()
		<< ';' << newEmployee.getPhone()<<';'<< newEmployee.getSSecurity() << ';' << newEmployee.getSalary()<<';';

	newFile.close();

}
// This searches the file for the employee id
int EmployeeTable::search(string tempid)
{
	int result = -1;
	for (int i = 0; i < allStoreEmployees.size()-1; i++)
	{
		if (tempid == allStoreEmployees[i].getId())
		{
			result=i;
		}
	}
	// Thi gives id of the Employee
	return result;
}
// This for the Employee Menu
void EmployeeTable::employeeMenu()
{
	// This is the employee menu 
	// In this menu you can add or remove or edit an employee 
	// You can also search for employee and you can view the list of employee
	int choice;
	cout << "\n------: Employee Menu :-----\n" << endl;
	cout << "1> Add an Employee" << endl;

	cout << "2> Remove an Employee " << endl;
	cout << "3> Search an Employee" << endl;
	cout << "5> Edit Employee info" << endl;
	cout << "4> View the Employee List" << endl;
	cout << "0> Main Menu" << endl;

	cin >> choice;
	switch (choice)
	{
		//to add item to database
	case 1:
	{
		
		char uChoice = 'y';
		while (uChoice == 'y')
		{
			Employee tempEmloyee;
			string tEmp;
			double temp = 0.0;
			cin.ignore();
			cout << "Id :";
			getline(cin, tEmp);
			tempEmloyee.setId(tEmp);
			cout << "Name :";
			getline(cin, tEmp);
			tempEmloyee.setName(tEmp);
			cout << "Address :";
			getline(cin, tEmp);
			tempEmloyee.setAddress(tEmp);
			cout << "Phone :";
			getline(cin, tEmp);
			tempEmloyee.setPhone(tEmp);
			cout << "Social Security :";
			getline(cin, tEmp);
			tempEmloyee.setSSecurity(tEmp);
			cout << "Salary :";
			cin >> temp;
			tempEmloyee.setSalary(temp);
			add(tempEmloyee);
				//add(employeeInput());
				uChoice = 'x';
			
			cout << "\ndo you want to add more y/n :";
			cin >> uChoice;
			tolower(uChoice);
		}// Ending while for repeating the Menu
		break;
	}// ending case 1

	//case 2: to remove Emloyee form the database
	case 2:
	{
		char uChoice = 'y';
		string tempEmployeeID;
		int result = -1;
		while (uChoice == 'y')
		{
			cout << "Please enter an Employee's Id to remove:";
			cin >> tempEmployeeID;
			result = search(tempEmployeeID);
			if (result != -1)
			{
				bool returned = false;
				
				returned=remove(allStoreEmployees[result]);
				if (returned == true)
				{
					cout << "\nEmployee removed Successfully\n";
				}
			}
			else
			{
				cout << "\nThe contact does not exist in the list..!!\n";
			}
			cout << " to remove another employee press y/n:";
			cin >> uChoice;
			tolower(uChoice);
			

		}// ending loop for repeatition}
		break;
	}// ending case 2
	// case 3 to check if the contact exists
	case 3:
	{
		char xChoice = 'n';
		int result = -1;
		string tempID;
		cout << "please enter an Employee's ID :";
		cin >> tempID;
		result=search(tempID);
		if (result !=-1)
		{
			cout << "\nThe Employee does exist in the list..!!"<<endl;
			allStoreEmployees[result].print();
		}
		else
		{
			cout << "\nThe Employee does not exist in the list..!!" << endl;
		}
		break;
	}//ending case 3
	case 4:
	{
		viewEmployee();
		break;
	}//ending case 4
	case 5:
	{
		string tempId;
		int result = -1;
		cin.ignore();
		cout << "please enter a Employee's ID :";
		getline(cin, tempId);
		result = search(tempId);
		if (result != -1)
		{
			bool output = false;
			Employee tempEmloyee;
			string tEmp;
			double temp = 0.0;
			cin.ignore();
			cout << "Id :";
			getline(cin, tEmp);
			tempEmloyee.setId(tEmp);
			cout << "Name :";
			getline(cin, tEmp);
			tempEmloyee.setName(tEmp);
			cout << "Address :";
			getline(cin, tEmp);
			tempEmloyee.setAddress(tEmp);
			cout << "Phone :";
			getline(cin, tEmp);
			tempEmloyee.setPhone(tEmp);
			cout << "Social Security :";
			getline(cin, tEmp);
			tempEmloyee.setSSecurity(tEmp);
			cout << "Salary :";
			cin >> temp;
			tempEmloyee.setSalary(temp);
			//Employee temp = employeeInput();
		 output=edit(tempEmloyee);
		 if (output == true)
		 {
			 cout << "\nSuccessfully Edited\n";
		 }
		 else
		 {
			 cout << "\nUnsuccessfull\n";
		 }
		}
		else
		{
			cout << "\nEmployee does not exist in the System\n";
		}
			break;
	}//ending case 5
	default:
	{
		cout << "please make a valid choice";
		break;
	}// ending default
	}// ending switch statement
}//ending Employee Menu	