/*
 * OpenDataCC.h
 *
 *  Created on: 26 abr. 2017
 *      Author: Adrián Fernández Ramos
 */

#ifndef OPENDATACC_H_
#define OPENDATACC_H_
#include"DistrictsList.h"
#include"NeighborhoodList.h"
#include"ViaList.h"
#include"timer.h"
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>

class OpenDataCC {
private:
	DistrictsList *distsList;
	NeighborhoodList *neighsList;
	ViaList *viasList;
public:
	/*
	 * Constructor of the Class OpenDataCC
	 *PRE:
	 *POST:Create the object correctly
	 *COMPLEXITY:O(1)
	 */
	OpenDataCC();
	/*
	 *Load all the Districts
	 *PRE:Create the file correctly
	 *POST:Creates the objects and insert the objects to the lists
	 *COMPLEXITY:O(n)
	 */
	void loadDistricts(DistrictsList *dl);
	/*
	 *Load all the neighborhoods and relates to the District to know which Neighborhood belongs to a specific District
	 *PRE:Create the file correctly
	 *POST:Creates the objects and insert the objects to the lists
	 *COMPLEXITY:O(n)
	 */
	void loadNeighborhoods(DistrictsList *dl, NeighborhoodList *nl);
	/*
	 *Load all the Vias and relates to the Neighborhood to know which Via belongs to a specific Neighborhood
	 *PRE:Create the file correctly
	 *POST:Creates the objects and insert the objects to the lists
	 *COMPLEXITY:O(n)
	 */
	void loadVias(NeighborhoodList *nl, ViaList *vl);
	/*
	 *Load all the Lamps and relates to the Vias to know which Lamp belongs to a specific Via
	 *PRE:Create the file correctly
	 *POST:Creates the objects and insert the objects to the lists
	 *COMPLEXITY:O(n)
	 */
	void loadLamps(ViaList *vl);
	/*
	 * Execute the interface of the application
	 *PRE:
	 *POST:
	 *COMPLEXITY:O(1)
	 */
	void execute();
	/*
	 *Erase all the data of the program
	 *PRE:
	 *POST:
	 *COMPLEXITY:O(1)
	 */
	void finalize();
	/*
	 *Show the options that we can choose
	 *PRE:
	 *POST:
	 *COMPLEXITY:O(1)
	 */
	int menu();
	/*
	 *Destructor
	 *PRE:
	 *POST:
	 *COMPLEXITY:O(1)
	 */
	~OpenDataCC();
};

#endif /* OPENDATACC_H_ */
