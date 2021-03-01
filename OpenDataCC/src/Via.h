/*
 * Via.h
 *
 *  Created on: 1 mar. 2017
 *      Author: Adrián Fernández Ramos
 */

#ifndef VIA_H_
#define VIA_H_
#include <iostream>
#include "Coords.h"
#include "Neighborhood.h"
#include "Lamp.h"
#include "Ilist.h"
using namespace std;

class Via {

private:
	string nameVia;
	string typeVia;
	int codeVia;
	float longitud;
	Neighborhood *neigh;
	IList<Lamp*> *lamps;
	Coords *coordInitial;
	Coords *coordMiddle;
	Coords *coordFinal;

public:
	/*
	 * Default Constructor
	 * PRE:
	 * POST: object initialized (name = type = "";code=0;laI = lonI = laM = lonM = laF = lonF = 0.0)
	 * COMPLEXITY: O(1)
	 */
	Via();

	/*
	 * Parametrized Constructor
	 * PRE:
	 * POST:object initialized with the parameter values
	 * COMPLEXITY: O(1)
	 */
	Via(string name, int code, string type, float longitude, Neighborhood *n,
			float laI, float lonI, float laM, float lonM, float laF,
			float lonF);
	/*
	 * Paremtrized Contructor but only with the name
	 * PRE:
	 * POST: Object initialized with the parameter values
	 * COMPLEXITY: O(1)
	 */
	Via(string _name);
	/*
	 * Constructor
	 * PRE:Create the object in a correct way
	 * POST:Object initialized with the parameter values
	 * COMPLEXITY: O(1)
	 */
	Via(const Via &via);
	/*
	 * Put the name of the via with the parameter
	 * PRE:
	 * POST:Object initialized with the parameter values
	 * COMPLEXITY: O(1)
	 */
	void setnameVia(string _name);
	/*
	 * Returns the name of the Via
	 * PRE:
	 * POST:Obtains the the name of the via
	 * COMPLEXITY:O(1)
	 */
	string getnameVia() const;
	/*
	 * Put the type of the via
	 * PRE:
	 * POST:Object initialized with the parameter values
	 * COMPLEXITY: O(1)
	 */
	void setTypeVia(string _tipo);
	/*
	 * Returns the type of the Via
	 * PRE:
	 * POST:Obtains the the type of the via
	 * COMPLEXITY:O(1)
	 */
	string getTypeVia() const;
	/*
	 *Put the code of the Via
	 *PRE:
	 *POST:Object initialized with the parameter values
	 *COMPLEXITY:O(1)
	 */
	void setCodeVia(int _codigo);
	/*
	 *PRE:
	 *POST:Obtains the code of the Via
	 *COMPLEXITY:O(1)
	 *
	 */
	int getCodeVia() const;
	/*
	 *Put the values of our initial coordinate
	 *PRE:
	 *POST:Object initialized with the parameter values
	 *COMPLEXITY:O(1)
	 *
	 */
	void setInitialCoord(float latitude, float longitude);
	/*
	 *
	 *Put the values of our middle coordinate
	 *PRE:
	 *POST:Object initialized with the parameter values
	 *COMPLEXITY:O(1)
	 */
	void setMiddleCoord(float latitude, float longitude);
	/*
	 * Put the values of our final coords
	 *PRE
	 *POST:Object initialized with the parameter values
	 *COMPLEXITY:O(1)
	 */
	void setFinalCoord(float latitude, float longitude);
	/*
	 *Getter
	 *PRE:Create the object correctly
	 *POST:Returns the value of the attribute
	 *COMPLEXITY:O(1)
	 */
	float getLongitudeVia() const;
	/*
	 *Getter
	 *PRE:Create the object correctly
	 *POST:Returns the value of the attribute
	 *COMPLEXITY:O(1)
	 */
	string getNameNeighborhood() const;
	/*
	 *Setter
	 *PRE:Create the object correctly
	 *POST:Modify the attribute with the parameter
	 *COMPLEXITY:O(1)
	 */
	void setNeighborhood(Neighborhood *n);
	/*
	 *Setter
	 *PRE:Create the object correctly
	 *POST:Modify the attribute with the parameter
	 *COMPLEXITY:O(1)
	 */
	void setLongitude(float lon);
	/*
	 *Distance between two coordinates
	 *PRE:Create the pointers to coordinates correctly
	 *POST:Returns the distance between the two coordinates
	 *COMPLEXITY:O(1)
	 */
	float distanceTo(Via* one);
	/*
	 *Show all the attributes of the vias.
	 *PRE:Create the objects correctly
	 *POST:
	 *COMPLEXITY:O(1)
	 */
	void show();
	/*
	 *Comparator operation
	 *PRE:Create the objects correctly
	 *POST:Returns which one is greater
	 *COMPLEXITY:O(1)
	 */
	bool operator==(const Via &v);
	/*
	 *
	 *PRE:Create the the object correctly
	 *POST:Insert the lamp in the list
	 *COMPLEXITY:O(1)
	 */
	void insertLamp(Lamp *l);
	/*
	 *Distance between two coordinates
	 *PRE:Create the pointers to coordinates correctly
	 *POST:Returns the distance between the two coordinates
	 *COMPLEXITY:O(1)
	 */

	float distanceToLampCoordInitial(Coords *c);
	/*
	 *Distance between two coordinates
	 *PRE:Create the pointers to coordinates correctly
	 *POST:Returns the distance between the two coordinates
	 *COMPLEXITY:O(1)
	 */

	float distanceToLampCoordMiddle(Coords *c);
	/*
	 *Distance between two coordinates
	 *PRE:Create the pointers to coordinates correctly
	 *POST:Returns the distance between the two coordinates
	 *COMPLEXITY:O(1)
	 */

	float distanceToLampCoordFinal(Coords *c);
	/*
	 *Count the lamps of a specific type
	 *PRE:Create the lamps correctly
	 *POST:Returns the number of lamps
	 *COMPLEXITY:O(n)
	 */
	float countLamps();
	/*
	 *Search the first Lamp with a specific type
	 *PRE:Create the lamps correctly
	 *POST:Return true if is searched false if not
	 *COMPLEXITY:O(n)
	 */
	bool searchTypeOfLampInVia(string type);
	/*
	 *Count the lamps of a specific type
	 *PRE:Create the lamps correctly
	 *POST:Return the number of a specific type
	 *COMPLEXITY:O(n)
	 */
	int countLampsOfAType(string type);
	/*
	 *Calculate the power of all the lamps that belongs to the via
	 *PRE:Create the lamps correctly
	 *POST:Returns the value of the power of each via
	 *COMPLEXITY:O(n)
	 */
	void calculateThePowerOfLamps(double &pow);
	/*
	 * Search the power of a specific type of Lamp
	 *PRE:Create all the lamps correctly
	 *POST:Returns the power of the Lamp
	 *COMPLEXITY:O(n/2)
	 */

	bool getThePowerOfASepecificTypeOfLamp(string type, double &power);
	/*
	 *Count the number of a specific type of lamp
	 *PRE:Create the lamps correctly
	 *POST:Returns the numbers od lamps that are equal to the type
	 *COMPLEXITY:O(n)
	 */

	double countTheNumberToPowerSaving(string type);

	/*
	 * Destructor
	 * PRE:
	 * POST:
	 * COMPLEXITY: O(1)
	 */
	~Via();

};

class ComparePtrVias {
public:
	/*
	 * PRE:Create the vias correctly
	 * POST:Compare Two vias and return which it's bigger smaller o equal if their are equal
	 * COMPLEXITY: O(1)
	 */
	int operator()(const Via *v1, const Via *v2) const {
		if (v1->getnameVia() < v2->getnameVia())
			return -1;
		if (v1->getnameVia() > v2->getnameVia())
			return 1;
		if (v1->getnameVia() == v2->getnameVia()) {
			return 0;
		}
		return 0;

	}
};
#endif /* VIA_H_ */
