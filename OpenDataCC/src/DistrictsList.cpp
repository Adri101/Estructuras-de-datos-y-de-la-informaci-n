/*
 * DistrictsList.cpp
 *
 *  Created on: 20 abr. 2017
 *      Author: adri
 */

#include "DistrictsList.h"

DistrictsList::DistrictsList() {
	this->dists = new IList<District*>();

}

void DistrictsList::insertOrderByName(District *d) {
	District *aux;
	bool insert = false;
	if (this->dists->empty()) {
		this->dists->insert(d);
	} else {
		this->dists->moveToBegin();
		while (!this->dists->end() && !insert) {
			this->dists->consult(aux);
			if (aux->getNameDistrict() > d->getNameDistrict()) {
				this->dists->insert(d);
				insert = true;
			}
			this->dists->next();
		}

	}
	if (this->dists->end())
		this->dists->insert(d);

}

void DistrictsList::searchDistrict(string name, District*&d) {
	District *aux = NULL;
	bool enc = false;
	this->dists->moveToBegin();
	while (!this->dists->end() && !enc) {
		this->dists->consult(aux);
		if (aux->getNameDistrict() == name) {
			enc = true;
			d = aux;
		}
		this->dists->next();

	}
}
void DistrictsList::powerOfADistrict(NeighborhoodList *nl, ViaList *vl) {
	District *aux;
	double pow = 0.0;
	if (this->dists->empty()) {
		cout << "the Districts  are empty , load again the data " << endl;
	} else {
		this->dists->moveToBegin();
		while (!this->dists->end()) {
			this->dists->consult(aux);
			nl->searchNeighborhoodToDistrict(aux->getNameDistrict(), pow, vl);
			cout
					<< "The district " + aux->getNameDistrict()
							+ " has a power consumption : " << pow << " euros  "
					<< endl;
			pow = 0.0;
			this->dists->next();

		}
	}
}
void DistrictsList::powerOfADistrictWithTrees(NeighborhoodList *nl,
		ViaList *vl) {
	District *aux;
	double pow = 0.0;
	if (this->dists->empty()) {
		cout << "the Districts  are empty , load again the data " << endl;
	} else {
		this->dists->moveToBegin();
		while (!this->dists->end()) {
			this->dists->consult(aux);

			nl->searchNeighborhoodPowerWithTrees(aux->getNameDistrict(), pow,
					vl);
			cout
					<< "The district " + aux->getNameDistrict()
							+ " has a power consumption : " << pow << " euros  "
					<< endl;
			pow = 0.0;
			this->dists->next();

		}
	}
}
void DistrictsList::moveToBeginDists() {
	this->dists->moveToBegin();
}
void DistrictsList::removeDists() {
	this->dists->remove();
}
bool DistrictsList::endDists() {
	return this->dists->end();
}
DistrictsList::~DistrictsList() {
	this->dists->moveToBegin();
	while (!this->dists->end()) {
		this->dists->remove();
	}
	delete dists;
}

