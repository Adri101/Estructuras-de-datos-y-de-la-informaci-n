/*
 * Via.cpp
 *
 *  Created on: 1 mar. 2017
 *      Author: adri
 */

#include "Via.h"
#include "Coords.h"

Via::Via() {
	this->nameVia = "";
	this->codeVia = 0;
	this->typeVia = "";
	this->longitud = 0.0;
	this->neigh = NULL;
	this->coordInitial = new Coords(0.0, 0.0);
	this->coordMiddle = new Coords(0.0, 0.0);
	this->coordFinal = new Coords(0.0, 0.0);
	this->lamps = new IList<Lamp*>();
}
Via::Via(string name, int code, string type, float longitude, Neighborhood *n,
		float laI, float lonI, float laM, float lonM, float laF, float lonF) {
	this->nameVia = name;
	this->codeVia = code;
	this->typeVia = type;
	this->longitud = longitude;
	this->neigh = n;
	this->coordInitial = new Coords(laI, lonI);
	this->coordMiddle = new Coords(laM, lonM);
	this->coordFinal = new Coords(laF, lonF);
	this->lamps = new IList<Lamp*>();

}
Via::Via(string _name) :
		neigh() {
	this->nameVia = _name;
	this->codeVia = 0;
	this->typeVia = "";
	this->longitud = 0.0;
	this->coordInitial = new Coords(0.0, 0.0);
	this->coordMiddle = new Coords(0.0, 0.0);
	this->coordFinal = new Coords(0.0, 0.0);
	this->lamps = new IList<Lamp*>();
}
Via::Via(const Via & via) {
	cout << "Copy constructor of Via class is called" << endl;
	this->nameVia = via.nameVia;
	this->codeVia = via.codeVia;
	this->typeVia = via.typeVia;
	this->longitud = via.longitud;
	this->coordInitial = new Coords(via.coordInitial->getLatitude(),
			via.coordInitial->getLongitude());
	this->coordMiddle = new Coords(via.coordMiddle->getLatitude(),
			via.coordMiddle->getLongitude());
	this->coordFinal = new Coords(via.coordFinal->getLatitude(),
			via.coordFinal->getLongitude());
	this->neigh = NULL;
	this->lamps = new IList<Lamp*>();
}
void Via::setnameVia(string _name) {
	this->nameVia = _name;
}
string Via::getnameVia() const {
	return this->nameVia;
}
void Via::setTypeVia(string _tipo) {
	this->typeVia = _tipo;
}
string Via::getTypeVia() const {
	return this->typeVia;
}
void Via::setCodeVia(int _codigo) {
	this->codeVia = _codigo;

}
int Via::getCodeVia() const {
	return this->codeVia;
}

void Via::show() {
	cout << this->getnameVia() + "   " << this->getLongitudeVia()
			<< this->getTypeVia() << this->getCodeVia()
			<< this->coordInitial->getLatitude()
			<< this->coordInitial->getLongitude()
			<< this->coordMiddle->getLatitude()
			<< this->coordMiddle->getLatitude()
			<< this->coordFinal->getLatitude()
			<< this->coordFinal->getLongitude()
			<< this->neigh->getNameNeighborhood() << endl;
}

void Via::setInitialCoord(float latitude, float longitude) {
	if (this->coordInitial == NULL) {
		this->coordInitial = new Coords(latitude, longitude);
	} else {
		this->coordInitial->setLatitude(latitude);
		this->coordInitial->setLongitude(longitude);
	}
}
void Via::setMiddleCoord(float latitude, float longitude) {
	if (this->coordMiddle == NULL) {
		this->coordMiddle = new Coords(latitude, longitude);
	} else {

		this->coordMiddle->setLatitude(latitude);
		this->coordMiddle->setLongitude(longitude);
	}
}
void Via::setFinalCoord(float latitude, float longitude) {
	if (this->coordFinal == NULL) {
		this->coordFinal = new Coords(latitude, longitude);
	} else {
		this->coordFinal->setLatitude(latitude);
		this->coordFinal->setLongitude(longitude);
	}
}
float Via::getLongitudeVia() const {
	return this->longitud;
}
void Via::setLongitude(float lon) {
	this->longitud = lon;
}

string Via::getNameNeighborhood() const {
	return this->neigh->getNameNeighborhood();
}

void Via::setNeighborhood(Neighborhood *n) {
	this->neigh = n;
}
float Via::distanceTo(Via *one) {

	return this->coordMiddle->distanceTo(one->coordMiddle);
}
float Via::distanceToLampCoordInitial(Coords *c) {
	return this->coordInitial->distanceTo(c);
}
float Via::distanceToLampCoordMiddle(Coords *c) {
	return this->coordMiddle->distanceTo(c);
}
float Via::distanceToLampCoordFinal(Coords *c) {
	return this->coordFinal->distanceTo(c);
}
bool Via::operator ==(const Via &v) {

	if (this->getnameVia() == v.getnameVia()) {
		cout << "Equals" << endl;
		return true;

	} else {
		cout << "Different" << endl;
		return false;
	}

}
void Via::insertLamp(Lamp *l) {

	this->lamps->insert(l);
}
float Via::countLamps() {
	float cont = 0.0;
	this->lamps->moveToBegin();
	while (!this->lamps->end()) {
		cont++;
		this->lamps->next();
	}
	return cont;
}
bool Via::searchTypeOfLampInVia(string type) {
	Lamp *aux;
	bool enc = false;
	this->lamps->moveToBegin();
	while (!this->lamps->end() && !enc) {
		this->lamps->consult(aux);
		if (aux->getTypeOfLamp() == type)
			enc = true;
		this->lamps->next();
	}
	return enc;
}
int Via::countLampsOfAType(string type) {
	Lamp *aux;
	int cont = 0;
	this->lamps->moveToBegin();
	while (!this->lamps->end()) {
		this->lamps->consult(aux);
		if (aux->getTypeOfLamp() == type) {
			cont++;
		}
		this->lamps->next();

	}
	return cont;
}
void Via::calculateThePowerOfLamps(double &pow) {
	Lamp *aux;
	double po = 0.0;

	this->lamps->moveToBegin();
	while (!this->lamps->end()) {
		this->lamps->consult(aux);
		po = aux->getPower();
		pow += po * 8 * 0.12149;

		this->lamps->next();
	}

}
bool Via::getThePowerOfASepecificTypeOfLamp(string type, double &power) {
	Lamp *aux = NULL;
	bool enc = false;
	if (this->lamps->empty()) {
		cout << "the lamps are empty , load again the data " << endl;
	} else {
		while (!this->lamps->end()) {
			this->lamps->consult(aux);
			if ((aux->getTypeOfLamp() == type)) {
				power = aux->getPower();
				enc = true;
			}
			this->lamps->next();
		}
	}
	return enc;
}
double Via::countTheNumberToPowerSaving(string type) {
	double power = 0.0;
	Lamp*aux;
	this->lamps->moveToBegin();
	while (!this->lamps->end()) {
		this->lamps->consult(aux);
		if (aux->getTypeOfLamp() == type) {
			power++;

		}
		this->lamps->next();
	}
	return power;
}

Via::~Via() {
	if (this->coordInitial != NULL)
		delete this->coordInitial;
	if (this->coordFinal != NULL)
		delete this->coordFinal;
	if (this->coordMiddle != NULL)
		delete this->coordMiddle;
	while (!this->lamps->end()) {
		this->lamps->remove();
	}
	if (this->neigh != NULL)
		delete this->neigh;
}
