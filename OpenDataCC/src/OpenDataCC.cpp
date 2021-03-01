/*
 * OpenDataCC.cpp
 *
 *  Created on: 26 abr. 2017
 *      Author: adri
 */

#include "OpenDataCC.h"

OpenDataCC::OpenDataCC() {
	this->distsList = new DistrictsList;
	this->neighsList = new NeighborhoodList;
	this->viasList = new ViaList;
}

void OpenDataCC::loadDistricts(DistrictsList *dl) {
	ifstream ifs;
	ifs.open("Districts.csv", ios::in);
	string nameDist, nameUri;
	District *d;
	if (!ifs.is_open()) {
		cout << "The file is not open" << endl;
	} else {
		while (!ifs.eof()) {
			getline(ifs, nameDist, ',');
			getline(ifs, nameUri);
			if (!ifs.eof()) {

				d = new District;

				d->setNameDistrict(nameDist);
				d->setNameUri(nameUri);
				dl->insertOrderByName(d);
			}

		}

	}
	ifs.close();

}

void OpenDataCC::loadNeighborhoods(DistrictsList *dl, NeighborhoodList *nl) {
	ifstream ifs;
	string name, distName;
	Neighborhood *n;
	District *d;

	ifs.open("Neighborhood.csv", ios::in);
	if (!ifs.is_open()) {
		cout << "The file is not open" << endl;
	} else {
		while (!ifs.eof()) {

			getline(ifs, name, ',');
			getline(ifs, distName);

			if (!ifs.eof()) {
				n = new Neighborhood();
				n->setNameNeighborhood(name);
				dl->searchDistrict(distName, d);
				n->setDistrict(d);
				nl->insertOrderByName(n);
			}

		}

	}
	ifs.close();

}
void OpenDataCC::loadVias(NeighborhoodList *nl, ViaList *vl) {
	ifstream ifs;
	string name, longitude, neigh, type, code, lat1, lat2, lat3, lon1, lon2,
			lon3;
	Via *v;
	Neighborhood *n;
	float longi, lati1, lati2, lati3, longi1, longi2, longi3;
	int codeint;

	ifs.open("Via.csv", ios::in);
	if (!ifs.is_open()) {
		cout << "The file is not open" << endl;
	} else {
		while (!ifs.eof()) {
			getline(ifs, name, ',');

			getline(ifs, longitude, ',');
			longi = atof(longitude.c_str());

			getline(ifs, type, ',');

			getline(ifs, code, ',');
			codeint = atoi(code.c_str());

			getline(ifs, lon1, ',');
			longi1 = atof(lon1.c_str());

			getline(ifs, lat1, ',');
			lati1 = atof(lat1.c_str());

			getline(ifs, lat2, ',');
			lati2 = atof(lat2.c_str());

			getline(ifs, lon2, ',');
			longi2 = atof(lon2.c_str());

			getline(ifs, lat3, ',');
			lati3 = atof(lat3.c_str());

			getline(ifs, lon3, ',');
			longi3 = atof(lon3.c_str());
			getline(ifs, neigh);

			if (!ifs.eof()) {
				v = new Via();
				v->setnameVia(name);
				v->setLongitude(longi);
				v->setTypeVia(type);
				v->setCodeVia(codeint);
				v->setInitialCoord(lati1, longi1);
				v->setMiddleCoord(lati2, longi2);
				v->setFinalCoord(lati3, longi3);
				nl->searchNeighborhood(neigh, n);
				v->setNeighborhood(n);
				vl->insertOrderByName(v);
			}

		}
		ifs.close();
	}

}
void OpenDataCC::loadLamps(ViaList *vl) {
	ifstream ifs;
	Lamp *l;
	Via *v;

	ifs.open("Lamp.csv", ios::in);

	if (!ifs.is_open()) {
		cout << "The file is not open" << endl;
	} else {
		string per, light, pow, type, scir, slon, slat;
		int circuits;
		float lat, lon;
		double power;
		while (!ifs.eof()) {
			l = new Lamp();
			getline(ifs, per, ',');
			getline(ifs, light, ',');
			getline(ifs, slon, ',');
			lon = atof(slon.c_str());
			getline(ifs, pow, ',');
			power = atof(pow.c_str());
			getline(ifs, type, ',');
			getline(ifs, slat, ',');
			lat = atof(slat.c_str());
			getline(ifs, scir);
			circuits = atoi(scir.c_str());
			if (!ifs.eof()) {
				l->setPerformance(per);
				l->setTypeOfLight(light);
				l->setCoords(lat, lon);
				l->setPower(power);
				l->setTypeOfLamp(type);
				l->setCircuits(circuits);
				vl->searchViaWithCoords(l, v);
				v->insertLamp(l);

			}

		}
		ifs.close();
	}

}
void OpenDataCC::finalize() {

	this->distsList->moveToBeginDists();
	while (!this->distsList->endDists()) {
		this->distsList->removeDists();
	}
	this->neighsList->moveToBeginNeighs();
	while (!this->neighsList->endNeighs()) {
		this->neighsList->removeNeighs();
	}
	this->viasList->moveToBeginVias();
	while (!this->viasList->endVias()) {
		this->viasList->removeVias();
	}
}
void OpenDataCC::execute() {

	int opt;
	string neighborhood, district, neighborhood2, typeLamp, typeLamp2, via,
			name1, name2;

	double t_start, t_end, power1, power2;
	power1 = 0.0;
	power2 = 0.0;
	Via *aux;
	bool finish = false;

	do {
		opt = menu();

		switch (opt) {
		case 1:
			cout << "Loading data , please wait ... " << endl;
			loadDistricts(this->distsList);
			loadNeighborhoods(this->distsList, this->neighsList);
			loadVias(this->neighsList, this->viasList);
			loadLamps(this->viasList);
			this->viasList->insertViasInTree();
			cout << "Load finished." << endl;
			break;
		case 2:
			cout << "Please, enter neighborhood you want" << endl;
			getline(cin, neighborhood);
			cout << "The vias related to the neighborhood are: " << endl;
			this->viasList->searchNeighAndShowVias(neighborhood);
			cout << "The search is finished" << endl;
			break;
		case 3:
			cout << "Please, enter the district you want" << endl;
			getline(cin, district);
			this->neighsList->searchDistrictsToFile(district, this->viasList);

			break;
		case 4:
			cout << "Please, introduce the neighborhood you want" << endl;
			getline(cin, neighborhood2);
			this->viasList->copyInTheOtherList();
			this->viasList->searchNeighToAdjacent(neighborhood2);
			this->viasList->deleteAllTheAdjacents();

			break;
		case 5:
			this->viasList->gatheringOfLamps(aux);
			cout << "The via with the greatest gathering of lamps is: "
					<< aux->getnameVia() << endl;

			break;
		case 6:

			cout << "Please enter the type of lamp you want" << endl;
			getline(cin, typeLamp);
			this->viasList->searchTypeOfLamp(typeLamp);

			break;
		case 7:

			cout << "Please enter the beginning of the via you want to search"
					<< endl;
			getline(cin, via);
			cout
					<< "---------------------------With Trees--------------------------"
					<< endl;
			t_start = Timer::getTime();
			this->viasList->partialSearchOfAVia(via);
			t_end = Timer::getTime();
			cout
					<< "---------------------------With Trees--------------------------"
					<< endl;
			cout << "Found it in t = " << std::fixed << std::setprecision(6)
					<< t_end - t_start << " secs." << endl;
			t_start = 0.0;
			t_end = 0.0;
			cout
					<< "---------------------------With Iterator List--------------------------"
					<< endl;
			t_start = Timer::getTime();
			this->viasList->partialSearchOfAViaWithList(via);
			t_end = Timer::getTime();
			cout
					<< "---------------------------With Iterator List--------------------------"
					<< endl;
			cout << "Found it in t = " << std::fixed << std::setprecision(6)
					<< t_end - t_start << " secs." << endl;
			break;
		case 8:
			t_start = 0.0;
			t_end = 0.0;

			cout
					<< "---------------------------With Trees--------------------------"
					<< endl;
			t_start = Timer::getTime();
			this->distsList->powerOfADistrictWithTrees(this->neighsList,
					this->viasList);

			t_end = Timer::getTime();
			cout << "Found it in t = " << std::fixed << std::setprecision(6)
					<< t_end - t_start << " secs." << endl;
			cout
					<< "---------------------------With Trees--------------------------"
					<< endl;
			t_start = 0.0;
			t_end = 0.0;
			cout
					<< "---------------------------With Iterator List--------------------------"
					<< endl;
			t_start = Timer::getTime();
			this->distsList->powerOfADistrict(this->neighsList, this->viasList);
			t_end = Timer::getTime();
			cout
					<< "---------------------------With Iterator List--------------------------"
					<< endl;
			cout << "Found it in t = " << std::fixed << std::setprecision(6)
					<< t_end - t_start << " secs." << endl;
			break;
		case 9:

			cout
					<< "Please enter the type of Lamp you want to calculate the energy saving "
					<< endl;
			getline(cin, typeLamp);
			this->viasList->getThePowerOfATypeOfLamp(typeLamp, power1);
			cout
					<< "Please enter the other type of Lamp you want to calculate the energy saving "
					<< endl;
			getline(cin, typeLamp2);
			this->viasList->getThePowerOfATypeOfLamp(typeLamp2, power2);

			this->viasList->calculateTheSavingMoney(typeLamp, typeLamp2, power1,
					power2);
			break;
		case 10:
			cout << "Please enter the name of a via that exist" << endl;
			getline(cin, name1);
			cout << "Now enter the new name yo want" << endl;
			getline(cin, name2);
			t_start = 0.0;
			t_end = 0.0;
			cout
					<< "---------------------------With Iterator List--------------------------"
					<< endl;
			t_start = Timer::getTime();
			this->viasList->changeTheNameOfAVia(name1, name2);
			t_end = Timer::getTime();
			cout << "Found it in t = " << std::fixed << std::setprecision(6)
					<< t_end - t_start << " secs." << endl;
			cout
					<< "---------------------------With Iterator List--------------------------"
					<< endl;
			t_start = 0.0;
			t_end = 0.0;
			cout
					<< "---------------------------With Trees--------------------------"
					<< endl;
			t_start = Timer::getTime();
			this->viasList->changeTheNameOfAViaWithTree(name1, name2);
			t_end = Timer::getTime();
			cout << "Found it in t = " << std::fixed << std::setprecision(6)
					<< t_end - t_start << " secs." << endl;
			cout
					<< "---------------------------With Trees--------------------------"
					<< endl;

			break;
		case 0:
			this->finalize();
			cout << "All the data has been erased " << endl;
			finish = true;
			break;
		default:
			cout << "ERROR: in the option selected" << endl;
			break;
		}

	} while (!finish);
}
int OpenDataCC::menu() {
	int opt;

	do {
		cout << endl;
		cout << "__________________  MAIN MENU  ________________" << endl
				<< endl;

		cout << "   1.  Load data                                  " << endl;
		cout << "   2.  Show vias of a neighborhood                " << endl;
		cout << "   3.  Generate file with vias of a District      " << endl;
		cout << "   4.  Contiguous neighborhoods                   " << endl;
		cout << "   5.  Via with a greater number/length of lamps  " << endl;
		cout << "   6.  Generate a file for a type of lamps        " << endl;
		cout << "   7.  Search for a via starting with ...         " << endl;
		cout << "   8.  Power consumption per District             " << endl;
		cout << "   9.  Report of energy savings                   " << endl;
		cout << "  10.  Change the name of a via                   " << endl;
		cout << endl;
		cout << "   0. Finish.                                     " << endl;
		cout << "Option:  ";
		cin >> opt;
		cin.ignore();

	} while ((opt < 0) || (opt > 11));

	return opt;
}

OpenDataCC::~OpenDataCC() {
	delete distsList;
	delete neighsList;
	delete viasList;
}
/***********************************************THE MAIN IS HERE *******************************************************/
int main() {
	OpenDataCC op;
	op.execute();
	return 0;
}

