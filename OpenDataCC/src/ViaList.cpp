/*
 * ViaList.cpp
 *
 *  Created on: 19 abr. 2017
 *      Author: adri
 */

#include "ViaList.h"

ViaList::ViaList() {
	this->vias = new IList<Via*>();
	this->copyvias = new IList<Via*>();
	this->viasAdj = new IList<string>();
	this->viasTree = new TreeManager();

}
void ViaList::insertOrderByName(Via *v) {
	Via *aux;
	bool insert = false;
	if (this->vias->empty())
		this->vias->insert(v);
	else {
		this->vias->moveToBegin();
		while (!this->vias->end() && !insert) {
			this->vias->consult(aux);
			if (aux->getnameVia() > v->getnameVia()) {
				this->vias->insert(v);
				insert = true;
			}
			this->vias->next();
		}

	}
	if (this->vias->end())
		this->vias->insert(v);
}

void ViaList::searchNeighAndShowVias(string name) {
	Via *aux;
	bool enc = false;
	if (this->vias->empty()) {
		cout << "The lists of neighs is empty, please load again the data"
				<< endl;
	} else {
		this->vias->moveToBegin();
		while (!this->vias->end()) {
			this->vias->consult(aux);
			if (aux->getNameNeighborhood() == name) {
				cout << aux->getnameVia() << endl;
				enc = true;
			}
			this->vias->next();
		}
		if (!enc) {
			cout
					<< "There are not vias related to string that you have introduced , please try with another one"
					<< endl;
		}
	}
}
void ViaList::searchNeighAndWriteToFile(string name) {
	Via *aux = NULL;
	if (this->vias->empty()) {
		cout << "The vias are empty load again the data" << endl;
	} else {
		this->vias->moveToBegin();

		while (!this->vias->end()) {

			this->vias->consult(aux);
			if (aux->getNameNeighborhood() == name) {

				writeViasInFile(aux);
			}
			this->vias->next();
		}
	}
}
void ViaList::writeViasInFile(Via *v) {
	ofstream ViasToDistricts;

	ViasToDistricts.open("ViasToDistricts.csv", ios::out | ios::app);
	if (ViasToDistricts.fail() == true) {
		cout << "The file csv  has not been open correctly" << endl;
	} else {
		if (!ViasToDistricts.eof()) {
			ViasToDistricts << v->getnameVia() << ',' << v->getCodeVia() << ','
					<< v->getLongitudeVia() << ',' << v->getTypeVia() << ','
					<< v->getNameNeighborhood() << ',' << endl;
		}
	}
	ViasToDistricts.close();
}
void ViaList::searchNeighToAdjacent(string name) {
	Via *aux;
	bool enc = false;
	if (this->vias->empty()) {
		cout << "the vias are empty , load again the data " << endl;
	} else {
		this->vias->moveToBegin();
		while (!this->vias->end()) {
			this->vias->consult(aux);
			if (aux->getNameNeighborhood() == name) {
				this->showContiguous(name, aux);
				enc = true;

			}
			this->vias->next();
		}
		if (!enc) {
			cout
					<< "The neighborhood doesn't exist please try with another one "
					<< endl;
		}
	}
}
void ViaList::showContiguous(string name, Via *v) {
	Via *aux;
	string auxstr;
	this->copyvias->moveToBegin();
	while (!this->copyvias->end()) {
		this->copyvias->consult(aux);
		if ((aux->distanceTo(v) <= 75.00) && (aux->distanceTo(v) > 0.0)
				&& (aux->getNameNeighborhood() != name)
				&& !this->isAdjacent(aux->getNameNeighborhood())) {
			auxstr = aux->getNameNeighborhood();
			this->viasAdj->insert(auxstr);

			cout
					<< "The neighborhoods " + v->getNameNeighborhood()
							+ " and  " + aux->getNameNeighborhood()
							+ " are contigous" << endl;
		}
		this->copyvias->next();

	}
}

void ViaList::searchViaWithCoords(Lamp *l, Via *&v) {
	Via *aux = NULL;
	float dIinitial, dMiddle, dFinal, dMin, dMinFinal;
	dMinFinal = 100000;
	this->vias->moveToBegin();

	while (!this->vias->end()) {
		this->vias->consult(aux);
		dIinitial = aux->distanceToLampCoordInitial(l->getCoordinates());
		dMiddle = aux->distanceToLampCoordMiddle(l->getCoordinates());
		dFinal = aux->distanceToLampCoordFinal(l->getCoordinates());
		dMin = this->minimumOfThreeDistances(dIinitial, dMiddle, dFinal);
		if (dMin < dMinFinal) {
			dMinFinal = dMin;
			v = aux;
		}
		this->vias->next();

	}

}
float ViaList::minimumOfThreeDistances(float d1, float d2, float d3) {
	float total = 0.0;
	if (d1 < d2 && d1 < d3 && d1 != 0)
		total = d1;
	if (d2 < d1 && d2 < d3 && d2 != 0)
		total = d2;
	if (d3 < d1 && d3 < d2 && d3 != 0)
		total = d3;
	return total;

}

void ViaList::gatheringOfLamps(Via *&v) {
	float gathe = 0.0;
	Via *aux;
	if (this->vias->empty()) {
		cout << "the vias are empty , load again the data " << endl;
	} else {
		this->vias->moveToBegin();
		while (!this->vias->end()) {
			this->vias->consult(aux);
			if (getGathering(aux->countLamps(), aux->getLongitudeVia()) > gathe
					&& aux->getLongitudeVia() != 0) {
				gathe = getGathering(aux->countLamps(), aux->getLongitudeVia());
				v = aux;
			}
			this->vias->next();
		}

	}
}
float ViaList::getGathering(float numberOfLamps, float longitude) {
	return numberOfLamps / longitude;

}
void ViaList::searchTypeOfLamp(string type) {
	Via *aux;
	bool search = false;
	if (this->vias->empty()) {
		cout << "the vias are empty , load again the data " << endl;
	} else {
		this->vias->moveToBegin();
		while (!this->vias->end()) {
			this->vias->consult(aux);
			search = aux->searchTypeOfLampInVia(type);
			if (search) {
				this->writeViasWithLamps(aux, type);
			}
			this->vias->next();
		}
		cout
				<< "If you want to see the results please look up the file ViasWithLamps.csv "
				<< endl;
	}
}
void ViaList::writeViasWithLamps(Via *v, string type) {
	ofstream ViasWithLamps;

	ViasWithLamps.open("ViasWithLamps.csv", ios::out | ios::app);
	if (ViasWithLamps.fail()) {
		cout << "The file csv  has not been open correctly" << endl;
	} else {
		if (!ViasWithLamps.eof()) {
			ViasWithLamps << v->getnameVia() << ',' << v->getCodeVia() << ','
					<< "There are: " << v->countLampsOfAType(type)
					<< "Lamps of type: " + type << ',' << endl;
		}
	}
	ViasWithLamps.close();
}
void ViaList::copyInTheOtherList() {
	Via *aux;
	if (this->vias->empty()) {
		cout << "the vias are empty , load again the data " << endl;
	} else {
		this->vias->moveToBegin();
		while (!this->vias->end()) {
			this->vias->consult(aux);
			this->copyvias->insert(aux);
			this->vias->next();
		}
	}
}
bool ViaList::isAdjacent(string name) {
	string aux;
	bool enc = false;

	this->viasAdj->moveToBegin();
	while (!this->viasAdj->end()) {
		this->viasAdj->consult(aux);
		if (name == aux)
			enc = true;
		this->viasAdj->next();
	}
	return enc;
}
void ViaList::deleteAllTheAdjacents() {
	this->viasAdj->moveToBegin();
	while (!this->viasAdj->end()) {
		this->viasAdj->remove();
	}
}
void ViaList::insertViasInTree() {
	Via *aux;
	this->vias->moveToBegin();
	while (!this->vias->end()) {
		this->vias->consult(aux);
		this->viasTree->insertVia(aux);
		this->vias->next();
	}

}
void ViaList::partialSearchOfAVia(const string &name) {
	this->viasTree->matchings(name);
}
void ViaList::partialSearchOfAViaWithList(const string &name) {
	Via *aux;
	bool enc = false;
	if (this->vias->empty()) {
		cout << "the vias are empty , load again the data " << endl;
	} else {
		this->vias->moveToBegin();
		while (!this->vias->end()) {
			this->vias->consult(aux);
			if (aux->getnameVia().find(name) == 0) {
				aux->show();
				enc = true;
			}
			this->vias->next();
		}
		if (!enc) {
			cout << "No via begins with : " + name << endl;
		}
	}
}
void ViaList::searchNeighToPower(string name, double &pow) {
	Via *aux;
	double po;
	if (this->vias->empty()) {
		cout << "the vias are empty , load again the data " << endl;
	} else {
		this->vias->moveToBegin();
		while (!this->vias->end()) {
			this->vias->consult(aux);
			if (aux->getNameNeighborhood() == name) {
				aux->calculateThePowerOfLamps(po);
				pow += po;
				po = 0.0;

			}
			this->vias->next();
		}
	}
}

void ViaList::powerConsumptionWithVias(string name, double &pow) {
	this->viasTree->callToPowerOfAVia(name, pow);
}
void ViaList::calculateTheSavingMoney(string typeLamp1, string typeLamp2,
		double power1, double power2) {
	Via *aux;
	double numberOfLampsOfType1 = 0.0;
	double pow1 = 0.0;
	double pow2 = 0.0;
	if (this->vias->empty()) {
		cout << "the vias are empty , load again the data " << endl;
	} else {
		this->vias->moveToBegin();
		while (!this->vias->end()) {
			this->vias->consult(aux);
			numberOfLampsOfType1 += aux->countTheNumberToPowerSaving(typeLamp1);
			this->vias->next();

		}
		if (power1 > power2) {
			pow1 = power1 * numberOfLampsOfType1;
			pow2 = power2 * numberOfLampsOfType1;
			cout
					<< "The power saving if we put lamps of type : " + typeLamp2
							+ " instead of : " + typeLamp1 + " is "
					<< (pow1 - pow2) << " Watios  " << endl;
		} else {
			cout
					<< "Your second power is bigger than the first one so yo are not going to get any saving , please try again "
					<< endl;
		}
	}

}
void ViaList::getThePowerOfATypeOfLamp(string type, double &power) {
	Via *aux;
	bool enc = false;
	if (this->vias->empty()) {
		cout << "the vias are empty , load again the data " << endl;
	} else {
		this->vias->moveToBegin();
		while (!this->vias->end() && !enc) {
			this->vias->consult(aux);
			enc = aux->getThePowerOfASepecificTypeOfLamp(type, power);
			this->vias->next();
		}
		if (!enc) {
			cout << "The lamp " + type + " doesn't exist " << endl;
		}
	}
}
void ViaList::changeTheNameOfAVia(string name, string name2) {
	Via *aux;
	bool enc = false;
	if (this->vias->empty()) {
		cout << "the vias are empty , load again the data " << endl;
	} else {
		this->vias->moveToBegin();
		while (!this->vias->end() && !enc) {
			this->vias->consult(aux);
			if (aux->getnameVia() == name) {
				aux->setnameVia(name2);
				cout << "The new Via is " << aux->getnameVia() << endl;
				enc = true;
			}
			this->vias->next();
		}
		if (!enc) {
			cout << "No via has the name " + name << endl;
		}
		aux->setnameVia(name);
		//I put again the via , because if you change the name then the Tree can't search the via because the name has been modified
		//so the pointer has a new name now and I if search with the last name the Via is not going to  be searched
	}
}
void ViaList::changeTheNameOfAViaWithTree(string name, string name2) {
	this->viasTree->callToChangeTheNameOfAVia(name, name2);

}
void ViaList::moveToBeginVias() {
	this->vias->moveToBegin();
}
bool ViaList::endVias() {
	return this->vias->end();
}
void ViaList::removeVias() {
	this->vias->remove();
}
bool ViaList::searchBooleanVia(Via *&v) {
	bool enc = false;
	Via *aux;
	this->vias->moveToBegin();
	while (!this->vias->end() && !enc) {
		this->vias->consult(aux);
		if (aux->getnameVia() == v->getnameVia()) {
			enc = true;
		}
		this->vias->next();
	}
	return enc;
}
bool ViaList::existVia(Via *&v) {
	return this->viasTree->existVia(v);

}
void ViaList::showTheTree() {
	this->viasTree->show();
}
ViaList::~ViaList() {
	this->copyvias->moveToBegin();
	while (!this->copyvias->end()) {
		this->copyvias->remove();
	}
	this->vias->moveToBegin();
	while (!this->vias->end()) {
		this->vias->remove();
	}
	this->viasAdj->moveToBegin();
	while (!this->viasAdj->end()) {
		this->viasAdj->remove();
	}
	delete viasTree;
	delete copyvias;
	delete viasAdj;
	delete vias;
}

