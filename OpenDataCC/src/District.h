/*
 * Districts.h
 *
 *  Created on: 1 mar. 2017
 *      Author: Adrián Fernández Ramos
 */

#ifndef DISTRICT_H_
#define DISTRICT_H_
#include<iostream>

using namespace std;

class District {
private:
	/*
	 * Attributes of the Class District
	 */
	string Uri;
	string nameDistrict;

public:

	/*
	 * Default Constructor
	 * PRE:
	 * POST: object initialized (nameCity = nameDistrict = " ")
	 * COMPLEXITY: O(1)
	 */
	District();
	/*
	 * Parametrized Constructor
	 * PRE:
	 * POST:object initialized with the parameter values
	 * COMPLEXITY: O(1)
	 */
	District(string _nameCity, string _nameDistrics);
	/*
	 * Another constructor for testing
	 *
	 */
	District(District & district);
	/*
	 *PRE:
	 *POST:Returns the name of the nameCity
	 *COMPLEXITY: O(1)
	 */
	string getNameUri() const;
	/*
	 *PRE:
	 *POST:Put the name of the City with the parameter
	 *COMPLEXITY: O(1)
	 */
	void setNameUri(string _nameUri);
	/*
	 *PRE:
	 *POST:Returns the name of the district
	 *COMPLEXITY: O(1)
	 */
	string getNameDistrict() const;
	/*
	 *PRE:
	 *POST:Put the name of the district with the parameter
	 *COMPLEXITY: O(1)
	 */
	void setNameDistrict(string _nameDistrics);
	/*
	 * PRE:Equal operation comparing their names
	 * POST:Returns true if are equals false if not are equals
	 * COMPLEXITY:O(1)
	 */
	bool operator==(const District &a);
	/*
	 *
	 * PRE:Create the object
	 * POST:Show all the attributes of the object
	 * COMPLEXITY:O(1)
	 */
	void show();
	/*
	 * Destructor
	 * PRE:
	 * POST:
	 * COMPLEXITY: O(1)
	 */
	~District();
};

#endif /* DISTRICTS_H_ */
