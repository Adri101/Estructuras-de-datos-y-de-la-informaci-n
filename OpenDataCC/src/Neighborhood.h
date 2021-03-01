/*
 * Neighborhood.h
 *
 *  Created on: 1 mar. 2017
 *      Author: Adrián Fernández Ramos
 */

#ifndef NEIGHBORHOOD_H_
#define NEIGHBORHOOD_H_
#include<iostream>
#include "District.h"

using namespace std;
class Neighborhood {
private:
	District *district;
	string nameNeigh;
public:
	/*
	 *Default constructor
	 *PRE:
	 *POST:Object initialized (nameNeigh="")
	 * COMPLEXITY:O(1)
	 */
	Neighborhood();
	/*

	 * Parametrized constructor
	 * PRE:
	 * POST:object initialized with the parameter values
	 * COMPLEXITY: O(1)
	 *
	 */
	Neighborhood(string _name, District *dist);
	/*
	 * Getter of District
	 * PRE:
	 * POST:Returns our attribute district
	 * COMPLEXITY:O(1)
	 */
	string getDistrict() const;
	/*
	 *Setter of District
	 * PRE:
	 * POST:Modify our District with the parameter value
	 * COMPLEXITY:O(1)
	 *
	 */
	void setDistrict(District *d);
	/*
	 *Getter of the name of the Neighborhood
	 *PRE:
	 *POST:Obtains the name of the Neighborhood
	 *COMPLEXITY:O(1)
	 */
	string getNameNeighborhood() const;
	/*
	 *Setter of the name of the Neighborhood
	 *PRE:
	 *POST:Put the name of the Neighborhood with the parameter
	 *COMPLEXITY:O(1)
	 */
	void setNameNeighborhood(string _name);
	/*
	 * Equal operation
	 * PRE:Create the objects
	 * POST:Return true if the are equals are return false if not are equals
	 * COMPLEXITY: O(1)
	 */
	bool operator==(const Neighborhood &a);
	/*
	 *
	 * PRE:Create the object correctly
	 * POST:Show all the attributes of the object
	 */
	void show();
	/*
	 * Destructor of the class Neighborhood
	 * PRE:Create the class correctly
	 * POST:Erase all
	 */
	~Neighborhood();
};

#endif /* NEIGHBORHOOD_H_ */
