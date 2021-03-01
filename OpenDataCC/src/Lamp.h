/*
 * Lamp.h
 *
 *  Created on: 27 mar. 2017
 *      Author: Adrián Fernández Ramos
 */

#ifndef LAMP_H_
#define LAMP_H_
#include<iostream>
#include "Coords.h"

using namespace std;

class Lamp {
private:
	string performance;
	string typeOfLight;
	double power;
	string typeOfLamp;
	int circuits;
	Coords *coordinates;

public:
	/*
	 *Default constructor of the class
	 *PRE:
	 *POST:Create the object correctly
	 *COMPLEXITY:O(1)
	 */
	Lamp();
	/*
	 *Parameterized constructor of the class
	 *PRE:
	 *POST:Create the object correctly with the parameter values
	 *COMPLEXITY:O(1)
	 */
	Lamp(int cir, Coords *c, double power, string type, string type1);
	/*
	 * Getter
	 *PRE:Create the object correctly
	 *POST:Returns the value of the attribute
	 *COMPLEXITY:O(1)
	 */

	string getPerformance() const;
	/*
	 * Setter
	 *PRE:Create the object correctly
	 *POST:Modify the value of the specific attribute
	 *COMPLEXITY:O(1)
	 */
	void setPerformance(string _performance);
	/*
	 * Getter
	 *PRE:Create the object correctly
	 *POST:Returns the value of the attribute
	 *COMPLEXITY:O(1)
	 */

	string getTypeOfLight() const;
	/*
	 * Setter
	 *PRE:Create the object correctly
	 *POST:Modify the value of the specific attribute
	 *COMPLEXITY:O(1)
	 */

	void setTypeOfLight(string _light);
	/*
	 * Getter
	 *PRE:Create the object correctly
	 *POST:Returns the value of the attribute
	 *COMPLEXITY:O(1)
	 */

	double getPower() const;
	/*
	 * Setter
	 *PRE:Create the object correctly
	 *POST:Modify the value of the specific attribute
	 *COMPLEXITY:O(1)
	 */

	void setPower(double _power);
	/*
	 * Getter
	 *PRE:Create the object correctly
	 *POST:Returns the value of the attribute
	 *COMPLEXITY:O(1)
	 */

	string getTypeOfLamp() const;
	/*
	 * Setter
	 *PRE:Create the object correctly
	 *POST:Modify the value of the specific attribute
	 *COMPLEXITY:O(1)
	 */

	void setTypeOfLamp(string _lamp);
	/*
	 * Getter
	 *PRE:Create the object correctly
	 *POST:Returns the value of the attribute
	 *COMPLEXITY:O(1)
	 */

	int getCircuits() const;
	/*
	 * Setter
	 *PRE:Create the object correctly
	 *POST:Modify the value of the specific attribute
	 *COMPLEXITY:O(1)
	 */

	void setCircuits(int _circuits);
	/*
	 * Setter
	 *PRE:Create the object correctly
	 *POST:Modify the value of the specific attribute
	 *COMPLEXITY:O(1)
	 */

	void setCoords(float lat, float lon);
	/*
	 * Getter
	 *PRE:Create the object correctly
	 *POST:Returns the value of the attribute
	 *COMPLEXITY:O(1)
	 */

	void getCoords(float &lat, float &lon);
	/*
	 * Getter
	 *PRE:Create the object correctly
	 *POST:Returns the value of the attribute
	 *COMPLEXITY:O(1)
	 */

	Coords* getCoordinates() const;
	/*
	 * Setter
	 *PRE:Create the object correctly
	 *POST:Modify the value of the specific attribute
	 *COMPLEXITY:O(1)
	 */

	void setCoordinates(Coords *c);
	/*
	 *
	 *PRE: Create the coords correctly
	 *POST:Returns the distance between two coordinates
	 *COMPLEXITY:O(1)
	 */
	float distanceToVia(Coords *c);
	/*
	 *
	 *PRE:Create the object correctly
	 *POST:Show all the attributes of the Class
	 *COMPLEXITY:O(1)
	 */
	void show();
	/*
	 * Destructor of the class
	 *PRE:
	 *POST:
	 *COMPLEXITY:O(1)
	 */
	~Lamp();
};

#endif /* LAMP_H_ */
