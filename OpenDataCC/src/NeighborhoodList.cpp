/*
 * NeighborhoodList.cpp
 *
 *  Created on: 19 abr. 2017
 *      Author: adri
 */

#include "NeighborhoodList.h"
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>

NeighborhoodList::NeighborhoodList() {
	this->neighs = new IList<Neighborhood*>();
}
void NeighborhoodList::insertOrderByName(Neighborhood *n) {
	Neighborhood *aux;
	bool insert = false;
	if (this->neighs->empty())
		this->neighs->insert(n);
	else {
		this->neighs->moveToBegin();
		while (!this->neighs->end() && !insert) {
			this->neighs->consult(aux);
			if (aux->getNameNeighborhood() > n->getNameNeighborhood()) {
				this->neighs->insert(n);
				insert = true;
			}
			this->neighs->next();
		}

	}
	if (this->neighs->end())
		this->neighs->insert(n);

}

void NeighborhoodList::searchNeighborhood(string name, Neighborhood *&n) {
	Neighborhood *aux;
	bool enc = false;
	this->neighs->moveToBegin();
	while (!this->neighs->end() && !enc) {
		this->neighs->consult(aux);
		if (aux->getNameNeighborhood() == name) {
			enc = true;
			n = aux;
		}
		this->neighs->next();

	}
}
void NeighborhoodList::searchDistrictsToFile(string name, ViaList *vl) {
	bool enc = false;
	Neighborhood *aux;
	if (this->neighs->empty()) {
		cout << "The neighs are empty please load again the data" << endl;
	} else {
		this->neighs->moveToBegin();
		while (!this->neighs->end()) {
			this->neighs->consult(aux);
			if (aux->getDistrict() == name) {
				enc = true;
				vl->searchNeighAndWriteToFile(aux->getNameNeighborhood());

			}
			this->neighs->next();
		}
		if (!enc) {
			cout
					<< "The name of the district that you have been introduced doesn't exist please try again "
					<< endl;
		} else {
			cout
					<< "If you want to see the results please look up the file ViasToDistricts.csv "
					<< endl;
		}
	}
}
void NeighborhoodList::searchNeighborhoodToDistrict(string name, double &pow,
		ViaList *vl) {
	Neighborhood *aux;
	double po;
	if (this->neighs->empty()) {
		cout << "the neighs are empty , load again the data " << endl;
	} else {
		this->neighs->moveToBegin();
		while (!this->neighs->end()) {
			this->neighs->consult(aux);
			if (aux->getDistrict() == name) {

				vl->searchNeighToPower(aux->getNameNeighborhood(), po);
				pow += po;
				po = 0.0;
			}

			this->neighs->next();
		}
	}
}
void NeighborhoodList::searchNeighborhoodPowerWithTrees(string name,
		double &pow, ViaList *vl) {
	Neighborhood *aux;
	double po;
	if (this->neighs->empty()) {
		cout << "the neighs are empty , load again the data " << endl;
	} else {

		this->neighs->moveToBegin();
		while (!this->neighs->end()) {
			this->neighs->consult(aux);
			if (aux->getDistrict() == name) {

				vl->powerConsumptionWithVias(aux->getNameNeighborhood(), po);
				pow += po;
				po = 0.0;
			}

			this->neighs->next();
		}
	}

}
void NeighborhoodList::moveToBeginNeighs() {
	this->neighs->moveToBegin();
}
void NeighborhoodList::removeNeighs() {
	this->neighs->remove();
}
bool NeighborhoodList::endNeighs() {
	return this->neighs->end();
}
bool NeighborhoodList::searchNeighborhoodBoolean(Neighborhood *&n) {
	bool enc = false;
	Neighborhood *aux;
	this->neighs->moveToBegin();
	while (!this->neighs->end()) {
		this->neighs->consult(aux);
		if (aux->getNameNeighborhood() == n->getNameNeighborhood()) {
			enc = true;
		}
		this->neighs->next();

	}
	return enc;
}
NeighborhoodList::~NeighborhoodList() {
	this->neighs->moveToBegin();
	while (!this->neighs->end()) {
		this->neighs->remove();
	}
	delete neighs;
}

