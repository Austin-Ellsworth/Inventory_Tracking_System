#ifndef Inventory_H
#define Inventory_H

#include <string>
using namespace std;

class Inventory {
private:
	string partNumber;
	string name;
	string location;
	double price;
public:
	Inventory();
	Inventory(string partNumber, string name, double price, string location);
	void setPartNumber(string);
	void setName(string);
	void setLocation(string);
	void setPrice(double);
	string getPartNumber();
	string getName();
	string getLocation();
	double getPrice();
};
#endif