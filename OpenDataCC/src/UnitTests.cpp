/*
 * UnitTests.cpp
 *
 *  Created on: 24 may. 2017
 *      Author: Adrián Fernández Ramos
 */

#include "OpenDataCC.h"
void Tests() {
	District *d13;
	Neighborhood *n1, *n2;
	Via *v1, *v2, *v3, *v4;
	DistrictsList *ListOfDistrict = new DistrictsList();
	NeighborhoodList *ListOfNeighs = new NeighborhoodList();
	ViaList *viasList = new ViaList();
	cout << "Creating and inserting the objects " << endl;
	d13 = new District("District Thirteen", "https://github.com");
	ListOfDistrict->insertOrderByName(d13);
	n1 = new Neighborhood("San Antonio", d13);
	n2 = new Neighborhood("La Avenida ", d13);
	cout << "Inserting the neighs " << endl;
	ListOfNeighs->insertOrderByName(n1);
	ListOfNeighs->insertOrderByName(n2);
	cout << "inserting the vias " << endl;
	v1 = new Via("Extremadura", 10, "Calle", 100, n1, 145, 146, 232, 325, 222,
			111);

	v2 = new Via("Láctea", 11, "Plaza", 120, n2, 155, 196, 242, 328, 223, 112);
	v3 = new Via("Michelin", 8, "Calle", 50, n1, 154, 3.2, 3250.1, 555, 147,
			145);
	v4 = new Via("Marte ", 9, "Calle", 25, n1, 123, 552, 1749, 56, 74, 45);
	viasList->insertOrderByName(v1);
	viasList->insertOrderByName(v2);
	viasList->insertOrderByName(v3);
	viasList->insertOrderByName(v4);
	cout
			<< "---------------------------TEST 1 ----------------------------------"
			<< endl;
	cout << "We are going to search the first neighborhood : San Antonio "
			<< endl;
	if (ListOfNeighs->searchNeighborhoodBoolean(n1)) {
		cout << "The Neighborhood is founded correctly" << endl;
	} else {
		cout << "the neighborhood doesn't exist" << endl;
	}
	cout
			<< "---------------------------TEST 1 ----------------------------------"
			<< endl;
	cout
			<< "---------------------------TEST 2 ----------------------------------"
			<< endl;
	if (viasList->searchBooleanVia(v1) && viasList->searchBooleanVia(v2)
			&& viasList->searchBooleanVia(v3)
			&& viasList->searchBooleanVia(v4)) {
		cout << "The data is inserted correctly " << endl;
		v1->show();
		v2->show();
		v3->show();
		v4->show();

	} else {
		cout << "The Data don't exist" << endl;
	}
	cout
			<< "---------------------------TEST 2 ----------------------------------"
			<< endl;
	cout
			<< "---------------------------TEST 3 ----------------------------------"
			<< endl;
	cout << "Testing if they are inserted and searching by the root name"
			<< endl;
	viasList->insertViasInTree();
	if (viasList->existVia(v1) && viasList->existVia(v2)
			&& viasList->existVia(v3) && viasList->existVia(v4)) {
		cout << "Showing the tree to check if they are correct the results"
				<< endl;
		viasList->showTheTree();
		cout << "the vias exist " << endl;
		viasList->partialSearchOfAVia("M");

	} else {
		cout << "The vias are not inserted " << endl;
	}
	cout
			<< "---------------------------TEST 3 ----------------------------------"
			<< endl;
	cout
			<< "---------------------------TEST 4 ----------------------------------"
			<< endl;
	if (viasList->existVia(v1) && viasList->existVia(v2)
			&& viasList->existVia(v3) && viasList->existVia(v4)) {
		viasList->showTheTree();
		viasList->changeTheNameOfAViaWithTree("Extremadura", "Canarias");
		viasList->showTheTree();
	} else {
		cout << "The vias dont exist" << endl;
	}
	cout
			<< "---------------------------TEST 4 ----------------------------------"
			<< endl;
}
/*int main() {
	Tests();
	return 0;
}*/

