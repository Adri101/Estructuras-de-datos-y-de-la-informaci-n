/*
 * Coords.h
 *
 *  Created on: 8 mar. 2017
 *      Author: adri
 */
#ifndef COORDS_H_
#define COORDS_H_

const float PI = 3.14159265;

class Coords {

private:
	/*
	 * Attributes of type float that means de longitude and the latitude of the coordinate
	 */
	float latitude;
	float longitude;

public:

	/*
	 * Default Constructor
	 * PRE:
	 * POST: object initialized (latitude = longitude = 0.0)
	 * COMPLEXITY: O(1)
	 */
	Coords();

	/*
	 * Parametrized Constructor
	 * PRE:
	 * POST:object initialized with the parameter values
	 * COMPLEXITY: O(1)
	 */
	Coords(float latitude, float longitude);

	/*
	 * PRE: {c != NULL}
	 * POST:  Distance in meters from current object to c
	 * COMPLEXITY: O(1)
	 */
	float distanceTo(Coords *c);

	/*
	 * PRE:
	 * POST:  Distance in meters between current object and the point identified
	 *        by coordinates in the parameters.
	 * COMPLEXITY: O(1)
	 */
	float distanceTo(float latitude, float longitude);

	/*
	 * PRE:
	 * POST: Put the value of the latitude by the parameter
	 * COMPLEXITY: O(1)
	 */
	void setLatitude(float _latitude);
	/*
	 *PRE:
	 *POST:Returns the value of the latitude
	 *COMPLEXITY: O(1)
	 *
	 */
	float getLatitude();
	/*
	 *PRE:
	 *POST:Put the value of the longitude of the coordinate with the parameter
	 *COMPLEXITY: O(1)
	 *
	 */
	void setLongitude(float _logitude);
	/*
	 * PRE:
	 * POST:Returns the value of the longitude
	 *COMPLEXITY: O(1)
	 *
	 */
	float getLongitude();
	/*
	 * Destructor
	 * PRE:
	 * POST:
	 * COMPLEXITY: O(1)
	 */

	~Coords();
};

#endif /* COORDS_H_ */
