#include "inventory.h"

Inventory::Inventory() {
	setPartNumber("00 - 0000 - 00");
	setName("Default");
	setLocation("None");
	setPrice(0);
}

Inventory::Inventory(string partNum, string name, double price, string location) {
	setPartNumber(partNum);
	setName(name);
	setLocation(location);
	setPrice(price);
}

void Inventory::setPartNumber(string partNum) {
	partNumber = partNum;
}

void Inventory::setName(string nameOfItem) {
	name = nameOfItem;
}

void Inventory::setLocation(string loc) {
	location = loc;
}

void Inventory::setPrice(double priceOfItem) {
	price = priceOfItem;
}

string Inventory::getPartNumber() {
	return partNumber;
}

string Inventory::getName() {
	return name;
}

string Inventory::getLocation() {
	return location;
}

double Inventory::getPrice() {
	return price;
}