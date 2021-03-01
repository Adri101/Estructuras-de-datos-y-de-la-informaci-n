/*
 Lamp.cpp
 *
 *  Created on: 27 mar. 2017
 *      Author: adri
 */

#include "Lamp.h"

Lamp::Lamp() {
	this->circuits = 0;
	this->coordinates = new Coords();
	this->power = 0.0;
	this->typeOfLamp = "";
	this->typeOfLight = "";

}

Lamp::Lamp(int cir, Coords *c, double power, string type, string type1) {
	this->circuits = cir;
	this->coordinates = c;
	this->power = power;
	this->typeOfLamp = type;
	this->typeOfLight = type1;

}
string Lamp::getPerformance() const {
	return this->performance;
}
void Lamp::setPerformance(string _performance) {
	this->performance = _performance;
}
string Lamp::getTypeOfLamp() const {
	return this->typeOfLamp;
}
void Lamp::setTypeOfLamp(string _lamp) {
	this->typeOfLamp = _lamp;
}
string Lamp::getTypeOfLight() const {
	return this->typeOfLight;
}
void Lamp::setTypeOfLight(string _light) {

	this->typeOfLight = _light;
}
void Lamp::setCoords(float lat, float lon) {
	this->coordinates = new Coords(lat, lon);
}
void Lamp::setCircuits(int _circuits) {
	this->circuits = _circuits;
}
void Lamp::getCoords(float &lat, float &lon) {
	lat = this->coordinates->getLatitude();
	lon = this->coordinates->getLongitude();

}

int Lamp::getCircuits() const {
	return this->circuits;
}
void Lamp::setPower(double _power) {
	this->power = _power;
}
double Lamp::getPower() const {
	return this->power;
}
Coords* Lamp::getCoordinates() const {
	return this->coordinates;
}
void Lamp::setCoordinates(Coords *c) {
	this->coordinates = c;
}
float Lamp::distanceToVia(Coords *c) {
	return this->coordinates->distanceTo(c);
}

void Lamp::show() {
	cout << this->getPerformance() << this->getTypeOfLight()
			<< this->coordinates->getLongitude() << this->getPower()
			<< this->getTypeOfLamp() << this->coordinates->getLatitude()
			<< this->getCircuits() << endl;
}

Lamp::~Lamp() {
	if (this->coordinates != NULL)
		delete this->coordinates;
}

