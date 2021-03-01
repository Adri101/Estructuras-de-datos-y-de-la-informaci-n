/*
 * DistrictsList.h
 *
 *  Created on: 20 abr. 2017
 *      Author: Adrián Fernández Ramos
 */

#ifndef DISTRICTSLIST_H_
#define DISTRICTSLIST_H_
#include "District.h"
#include "NeighborhoodList.h"
#include"Ilist.h"
class DistrictsList {
private:
	IList<District*> *dists;
public:
	/*
	 *Constructor of the DistrictList;
	 * PRE:Create The object correctly
	 * POST:A object created
	 * COMPLEXITY:O(1)
	 */
	DistrictsList();
	/*
	 * Insert the elements and ordering while it's inserting
	 * PRE:Create the list and the objects correctly
	 * POST:The list is ordered alphabetically
	 * COMPLEXITY: O(n/2)
	 */
	void insertOrderByName(District *d);
	/*
	 *Search the district to assign the district to a specific Neighborhood
	 * PRE:Create the district list correctly
	 * POST:Returns the district of the specific name
	 * COMPLEXITY: O(n/2)
	 */

	void searchDistrict(string name, District*&d);
	/*
	 * Travels all the districts to  get the power of each district
	 * PRE:Create the districts correctly
	 * POST:Show in the screen the power consumption of each district
	 * COMPLEXITY: O(n)
	 */

	void powerOfADistrict(NeighborhoodList *nl, ViaList *vl);
	/*
	 * Travels all the districts to  get the power of each district
	 * PRE:Create the districts correctly
	 * POST:Show in the screen the power consumption of each district
	 * COMPLEXITY: O(n)
	 */

	void powerOfADistrictWithTrees(NeighborhoodList *nl, ViaList *vl);
	/*
	 *
	 * PRE:Create the districts correctly
	 * POST:The POI is pointing to the first element
	 * COMPLEXITY:O(1)
	 *
	 */
	void moveToBeginDists();
	/*
	 * Remove a District
	 * PRE:Create the Districts correctly
	 * POST:Erase the pointer that is pointing the POI
	 * COMPLEXITY:O(1)
	 *
	 */
	void removeDists();
	/*
	 *
	 * PRE:Create the Districts correctly
	 * POST:Returns true if you are at the end of the list or false if not
	 * COMPLEXITY:O(1)
	 *
	 */
	bool endDists();
	/*
	 * Destructor of the class DistrictsList
	 * PRE:
	 * POST:
	 * COMPLEXITY: O(1)
	 */
	~DistrictsList();
};

#endif /* DISTRICTSLIST_H_ */
