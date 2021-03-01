/*
 * Coords.cpp
 *
 *  Created on: 8 mar. 2017
 *      Author: Adrián Fernández Ramos
 */

#include "Coords.h"

#include <math.h>
#include <iostream>
using namespace std;

Coords::Coords() {
	this->latitude = 0.0;
	this->longitude = 0.0;
}

Coords::Coords(float latitude, float longitude) {
	this->latitude = latitude;
	this->longitude = longitude;
}
void Coords::setLatitude(float _latitude) {

	this->latitude = _latitude;

}
float Coords::getLatitude() {
	return this->latitude;
}
void Coords::setLongitude(float _longitude) {

	this->longitude = _longitude;


}
float Coords::getLongitude() {
	return this->longitude;
}
float Coords::distanceTo(Coords *c) {


	float d = 0.0;

	float dlon = (c->longitude - this->longitude) * (PI / 180.0);
	float dlat = (c->latitude - this->latitude) * (PI / 180.0);
	float tmplong = sin(dlat / 2) * sin(dlat / 2);
	float tmplat = sin(dlon / 2) * sin(dlon / 2);
	float a = tmplong + cos(this->latitude) * cos(c->latitude) * tmplat;
	float cx = 2 * atan2(sqrt(a), sqrt(1 - a));
	float R = 6367.0; // (where R is the radius of the Earth)

	d = R * cx * 1000.0;

	return d;
}

float Coords::distanceTo(float latitude, float longitude) {

	Coords *tmp = new Coords(latitude, longitude);
	float d = this->distanceTo(tmp);
	delete tmp;
	return d;
}

Coords::~Coords() {
	// Empty
}

