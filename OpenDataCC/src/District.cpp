/*
 * Districts.cpp
 *
 *  Created on: 1 mar. 2017
 *      Author: adri
 */

#include "District.h"


District::District() {
	this->Uri = "";
	this->nameDistrict = "";

}
District::District(string _nameCity, string _nameDistrict) {
	this->Uri = _nameCity;
	this->nameDistrict = _nameDistrict;
}
District::District(District & district) {
	cout << "Copy constructor of Districts class is called" << endl;
	this->Uri = district.Uri;
	this->nameDistrict = district.nameDistrict;
}
string District::getNameUri() const {
	return this->Uri;
}
void District::setNameUri(string _nameCity) {
	this->Uri = _nameCity;
}
string District::getNameDistrict() const {
	return this->nameDistrict;
}
void District::setNameDistrict(string _nameDistricts) {
	this->nameDistrict = _nameDistricts;
}
bool District::operator==(const District &a) {
	bool equals = false;
	if (this->getNameDistrict() == a.getNameDistrict()) {
		equals = true;
	}
	return equals;
}
void District::show() {
cout << this->getNameDistrict() << this->Uri << endl;
}

District::~District() {
//Empty
}

