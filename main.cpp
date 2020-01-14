#include <iostream>
#include <fstream>
#include <vector>
#include "inventory.h"
#include <iomanip>

using namespace std;

int main() {
	string partNumber, name, location;
	double price;
	bool stop = false, recordFound;
	int selection, recordNumber;

	vector<Inventory> partList;
	ifstream inputFile;
	inputFile.open("items.txt");

	if (!inputFile) {
		cerr << "Unable to open file items.txt";
		exit(1);   // call system to stop
	}

	while(inputFile) {
		inputFile >> partNumber;
		inputFile >> name;
		inputFile >> price;
		inputFile >> location;
		partList.push_back(Inventory(partNumber, name, price, location));
	}
	partList.pop_back();
	
	cout << "\n\t***********************\n\t** Current Inventory **\n\t***********************\n";
	for (int i = 0; i < partList.size(); i++) {
		cout << fixed << setprecision(2)  << "Record Number: " << i + 1 << setw(8) << left << "   " << setw(12) << left << partList[i].getPartNumber() << "   " << setw(12) << left <<
			partList[i].getName() << "   " << setw(12) << left << partList[i].getPrice() << "   " << partList[i].getLocation() << endl;
	}
	
	while (!stop) {
		cout << "\n\nWhat action would you like to perform?\n 1. Add a record\n 2. Edit a record\n 3. Delete a record\n 4. Search a record\n 5. Print all records\n 6. Save and quit\n";
		cin >> selection;
		switch (selection) {
			case 1: //add a record
				cout << "You've selected to add a record..\nPlease enter the inventory number: ";
				cin >> partNumber;
				cout << "Please enter the name of the item (as one word): ";
				cin >> name;
				cout << "Please enter the cost of the item: ";
				cin >> price;
				cout << "Please enter the location of the item: ";
				cin >> location;
				cout << "\n*Confirm addition of record: " << partNumber << " " << name << " " << price << " " << location << endl << "Press 1 to add\nPress 0 to cancel";
				cin >> selection;
				if (selection == 1) {
					partList.push_back(Inventory(partNumber, name, price, location));
				}
				else {
					cout << "\nRecord was not added.";
				}
				break;
			case 2: //edit a record
				cout << "\nYou've selected to edit a record..\nSelect the number of the record you would like to edit: ";
				cin >> recordNumber;
				cout << "You've selected record number: " << recordNumber;
				cout << "\nPress 1 to edit the inventory number\nPress 2 to edit the name of the item\nPress 3 to edit the cost of the item\nPress 4 to edit the location of the item\n";
				cin >> selection;
				if (selection == 1) {
					cout << "Please enter the new inventory number: ";
					cin >> partNumber;
					partList[recordNumber - 1].setPartNumber(partNumber);
				}
				else if (selection == 2) {
					cout << "Please enter the new item name: ";
					cin >> name;
					partList[recordNumber - 1].setName(name);
				}
				else if (selection == 3) {
					cout << "Please enter the new item price: ";
					cin >> price;
					partList[recordNumber - 1].setPrice(price);
				}
				else if (selection == 4) {
					cout << "Please enter the new item location: ";
					cin >> location;
					partList[recordNumber - 1].setLocation(location);
				}
				break;
			case 3: //remove a record
				cout << "\nYou've selected to delete a record..\nSelect the number of the record you would like to delete: ";
				cin >> recordNumber;
				cout << "\nYou've selected: ";
				cout << fixed << setprecision(2) << "Record Number: " << recordNumber << "   " << partList[recordNumber - 1].getPartNumber() << "   " <<
					partList[recordNumber - 1].getName() << "   " << partList[recordNumber - 1].getPrice() << "   " << partList[recordNumber - 1].getLocation() << endl;
				cout << "\nConfirm Deletion\nPress 1 for yes\nPress 0 for no\n";
				cin >> selection;
				if (selection == 1) {
					partList.erase(partList.begin() + recordNumber - 1);
				}
				else {
					cout << "Deletion canceled\n";
				}
				break;
			case 4: //search a record
				cout << "You've selected to search for a record..\nPlease enter the inventory of the record using the format (XX-XXXX-XX): ";
				cin >> partNumber;
				recordFound = false;
				for (int i = 0; i < partList.size(); i++) {
					if (partList[i].getPartNumber() == partNumber) {
						cout << "This record exists: \n" << fixed << setprecision(2) << "Record Number: " << i + 1 << "   " << partList[i].getPartNumber() << "   " <<
							partList[i].getName() << "   " << partList[i].getPrice() << "   " << partList[i].getLocation() << endl;
						recordFound = true;
					}
					if (recordFound == false && (i + 1) == partList.size()) {
						cout << "\nThere was no record for this inventory number";
					}
				}
				break;
			case 5: //print all records
				cout << "\n\t***********************\n\t** Current Inventory **\n\t***********************\n";
				for (int i = 0; i < partList.size(); i++) {
					cout << fixed << setprecision(2) << "Record Number: " << i + 1 << setw(8) << left << "   " << setw(12) << left << partList[i].getPartNumber() << "   " << setw(12) << left <<
						partList[i].getName() << "   " << setw(12) << left << partList[i].getPrice() << "   " << partList[i].getLocation() << endl;
				}
				break;
			case 6: //save and quit
				ofstream outFile("items.txt");
				for (int i = 0; i < partList.size(); i++) {
					outFile << partList[i].getPartNumber() << " ";
					outFile << partList[i].getName() << " ";
					outFile << fixed << setprecision(2) << partList[i].getPrice() << " ";
					outFile << partList[i].getLocation() << endl;
				}
				stop = true;
				break;
		}
	}

	return 0;
}