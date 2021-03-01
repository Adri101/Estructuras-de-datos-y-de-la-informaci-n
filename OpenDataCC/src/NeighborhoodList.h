/*
 * NeighborhoodList.h
 *
 *  Created on: 19 abr. 2017
 *      Author: Adrián Fernández Ramos
 */

#ifndef NEIGHBORHOODLIST_H_
#define NEIGHBORHOODLIST_H_
#include"Ilist.h"

#include"Neighborhood.h"

#include"ViaList.h"

class NeighborhoodList {
private:
	IList<Neighborhood*> *neighs;
public:
	/*
	 * Constructor of the class
	 *PRE:
	 *POST:Creates the object correctly
	 *COMPLEXITY:O(1)
	 */
	NeighborhoodList();
	/*
	 * Insert the elements and ordering while it's inserting
	 * PRE:Create the list and the objects correctly
	 * POST:The list is ordered alphabetically
	 * COMPLEXITY: O(n/2)
	 */
	void insertOrderByName(Neighborhood *n);
	/*
	 *Search the neighborhood to assign the district to a specific Neighborhood
	 * PRE:Create the neighborhood list correctly
	 * POST:Returns the neighborhood of the specific name
	 * COMPLEXITY: O(n/2)
	 */

	void searchNeighborhood(string name, Neighborhood *&n);
	/*
	 * Search the specific neighborhoods that have a pointer to a District and if the name of the district is equal to the
	 * name calls to the method to write it in the file
	 *PRE:Create and load the neighborhoods correctly
	 *POST:Search all the districts that satisfied the conditions
	 *COMPLEXITY:O(n)
	 */
	void searchDistrictsToFile(string name, ViaList *vl);
	/*
	 * Search all the neighborhoods that have a name district equal to the name parameter
	 *PRE:Create and load the neighborhoods correctly
	 *POST:Calls to another method if the name is equal
	 *COMPLEXITY:O(n)
	 */
	void searchNeighborhoodToDistrict(string name, double &pow, ViaList *vl);
	/*
	 *  Search all the neighborhoods that have a name district equal to the name paramete
	 *PRE:Create and load the neighborhoods correctly
	 *POST:Calls to another method if the name is equal
	 *COMPLEXITY:O(n)
	 */
	void searchNeighborhoodPowerWithTrees(string name, double &pow,
			ViaList *vl);
	/*
	 *
	 *PRE:Create the list and insert the objects correctly
	 *POST:Move to the next element
	 *COMPLEXITY:O(1)
	 */
	void moveToBeginNeighs();
	/*
	 *
	 *PRE:Create the list and insert the objects correctly
	 *POST:Returns true if the POI is in the end and false if not
	 *COMPLEXITY:O(1)
	 */
	bool endNeighs();
	/*
	 *
	 *PRE:Create the list and insert the objects correctly
	 *POST:Remove the object that is pointed by the POI
	 *COMPLEXITY:O(1)
	 */
	void removeNeighs();
	/*PRE:Create the list correctly
	 * POST:Return true if the Neighborhood is searched
	 *COMPLEXITY:O(N/2)
	 */
	bool searchNeighborhoodBoolean(Neighborhood *&n);
	/*
	 * Destructor of the class
	 *PRE:
	 *POST:
	 *COMPLEXITY:O(1)
	 */
	~NeighborhoodList();
};

#endif /* NEIGHBORHOODLIST_H_ */
