/*
 * Neighborhood.cpp
 *
 *  Created on: 1 mar. 2017
 *      Author: adri
 */

#include "Neighborhood.h"


Neighborhood::Neighborhood() {
	this->district = NULL;
	this->nameNeigh = "";

}
Neighborhood::Neighborhood(string _name, District *dist) {
	this->nameNeigh = _name;
	this->district = dist;
}

string Neighborhood::getDistrict() const {
	return this->district->getNameDistrict();
}
void Neighborhood::setDistrict(District *d) {
	this->district = d;
}
string Neighborhood::getNameNeighborhood() const {
	return this->nameNeigh;
}
void Neighborhood::setNameNeighborhood(string _name) {
	this->nameNeigh = _name;

}
bool Neighborhood::operator==(const Neighborhood &a) {
	bool equals = false;
	if (this->getNameNeighborhood() == a.getNameNeighborhood()) {
		equals = true;
	}
	return equals;
}

void Neighborhood::show() {
	cout << this->getNameNeighborhood() << this->getDistrict() << endl;

}
Neighborhood::~Neighborhood() {
delete district;
}

