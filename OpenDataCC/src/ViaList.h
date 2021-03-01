/*
 * ViaList.h
 *
 *  Created on: 19 abr. 2017
 *      Author: Adrián Fernández Ramos
 */

#ifndef VIALIST_H_
#define VIALIST_H_
#include"Ilist.h"
#include"Via.h"
#include "TreeManager.h"
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>

class ViaList {
private:
	IList<Via*> *vias;
	IList<Via*> *copyvias;
	IList<string> *viasAdj;
	TreeManager *viasTree;
public:
	/*
	 * Constructor of the Class
	 *PRE:
	 *POST:
	 *COMPLEXITY:O(1)
	 */
	ViaList();
	/*
	 * Insert the elements and ordering while it's inserting
	 * PRE:Create the list and the objects correctly
	 * POST:The list is ordered alphabetically
	 * COMPLEXITY: O(n/2)
	 */
	void insertOrderByName(Via *v);
	/*
	 *Search the Vias related to a neighborhood
	 *PRE:Create the lists correctly
	 *POST:Show the vias related to the neighborhood introduced as a parameter
	 *COMPLEXITY:O(n)
	 */
	void searchNeighAndShowVias(string name);

	/*
	 *Search the Vias related to a neighborhood
	 *PRE:Create the lists correctly
	 *POST:Calls to another method to write the files in the via
	 *COMPLEXITY:O(n)
	 */
	void searchNeighAndWriteToFile(string name);
	/*
	 *
	 *PRE:The via that it is introduced ass a parameter must be created in a correctly way
	 *POST:Write in a file a via
	 *COMPLEXITY:O(1)
	 */
	void writeViasInFile(Via *v);
	/*
	 *Relates a lamp to a via that have the less distance
	 *PRE:create the list correctly
	 *POST:Returns the via with the less distance
	 *COMPLEXITY:O(n)
	 */
	void searchViaWithCoords(Lamp *l, Via *&v);
	/*
	 *Calculates the minimum of three numbers
	 *PRE:
	 *POST:Returns the minimum distance
	 *COMPLEXITY:O(1)
	 */
	float minimumOfThreeDistances(float d1, float d2, float d3);
	/*
	 *Returns the via with the most gathering (Most via / distance)
	 *PRE:Create the lists correctly
	 *POST:Returns the via with the most gathering (Most via / distance)
	 *COMPLEXITY:O(n)
	 */
	void gatheringOfLamps(Via *&v);
	/*
	 *Simple operation of division between two variables
	 *PRE:
	 *POST:Returns the result of the division
	 *COMPLEXITY:O(1)
	 */
	float getGathering(float numberOfLamps, float longitude);
	/*
	 *Travels all the lamps and if the variable search it is true the write the lamps in the file
	 *PRE:Create all the data structures correctly with their objects
	 *POST:If search = true calls to a another method
	 *COMPLEXITY:O(n)
	 */
	void searchTypeOfLamp(string type);
	/*
	 *
	 *PRE:The via must be created correctly
	 *POST:Writes in the file the specific vias
	 *COMPLEXITY:O(1)
	 */
	void writeViasWithLamps(Via *v, string type);
	/*
	 *
	 *PRE:The vias bust be created correctly
	 *POST:Show in the screen the vias that are contiguos(less than 75.00 mts)
	 *COMPLEXITY:O(n)
	 */
	void showContiguous(string name, Via *v);
	/*
	 *Search all the vias of a specific neighborhood
	 *PRE:The data must be created correctly
	 *POST:Travels the data structure
	 *COMPLEXITY:O(n)
	 */
	void searchNeighToAdjacent(string name);
	/*
	 *Move the data to an auxiliar data structure
	 *PRE:Create the data correctly
	 *POST:Copy the content on one list to the other
	 *COMPLEXITY:O(n)
	 */
	void copyInTheOtherList();
	/*
	 *Verifies if the One neighborhood is adjacent to other
	 *PRE:Create the object correctly*PRE:
	 *POST:Returns if a neighborhood is in the list of strings
	 *COMPLEXITY:O(n)
	 */
	bool isAdjacent(string name);
	/*
	 *Delete all the names , if you are going to execute the algorithm again
	 *PRE:Create the object correctly
	 *POST:Deletes all the strings in the list
	 *COMPLEXITY:O(n)
	 */
	void deleteAllTheAdjacents();
	/*
	 *
	 *PRE:The vias must be created correctly
	 *POST:insert in the vias tree
	 *COMPLEXITY:O(n)
	 */
	void insertViasInTree();
	/*
	 *
	 *PRE:The tree must be created correctly
	 *POST:Calls to a method in the Tree Manager
	 *COMPLEXITY:O(1)
	 */
	void partialSearchOfAVia(const string &name);
	/*
	 *
	 *PRE:The vias must be created correctly
	 *POST:Show all the via if they beginning is equal by the name of the parameter
	 *COMPLEXITY:O(n)
	 */
	void partialSearchOfAViaWithList(const string &name);
	/*
	 *
	 *PRE:The vias must be created correctly
	 *POST:Accumulates the power consumption of each via
	 *COMPLEXITY:O(n)
	 */
	void searchNeighToPower(string name, double &pow);
	/*
	 *The same method but now it is going to do the traversal in the tree
	 *PRE:The tree must be created correctly
	 *POST:Calls to a method of the Tree  Manager
	 *COMPLEXITY:O(1)
	 */
	void powerConsumptionWithVias(string name, double &pow);
	/*
	 *Count all the lamps of a specific type and then calculate the power saving comparing to the power of the another type
	 *PRE:The vias must be created correctly
	 *POST:Returns the value of the power saving
	 *COMPLEXITY:O(n)
	 */
	void calculateTheSavingMoney(string typeLamp1, string typeLamp2,
			double power1, double power2);
	/*
	 *
	 *PRE:The vias must be created correctly
	 *POST:Returns the value of the power of a specific type of lamp
	 *COMPLEXITY:O(n/2)
	 */
	void getThePowerOfATypeOfLamp(string type, double &power);
	/*
	 *Travels all the vias to find the Via
	 *PRE:The vias must be created correctly
	 *POST:Set the name of via if it has been searched
	 *COMPLEXITY:O(n/2)
	 */
	void changeTheNameOfAVia(string name, string name2);
	/*
	 *Calls to a method in the Tree
	 *PRE:Create the Tree correctly
	 *POST:Invoke a method of the Tree Manager
	 *COMPLEXITY:O(1)
	 */
	void changeTheNameOfAViaWithTree(string name, string name2);
	/*
	 *
	 *PRE:The vias must be created correctly
	 *POST:Move the POI to the next Via
	 *COMPLEXITY:O(1)
	 */
	void moveToBeginVias();
	/*
	 *
	 *PRE:The vias must be created correctly
	 *POST:Returns true if you are at the end of the list
	 *COMPLEXITY:O(1)
	 */
	bool endVias();
	/*
	 *
	 *PRE:The vias must be created correctly
	 *POST:Remove the data that is pointed by the POI
	 *COMPLEXITY:O(1)
	 */
	void removeVias();
	/*Search the via
	 * PRE:The vias must be inserted correctly
	 * POST:Returns true if the via is founded
	 * COMPLEXITY:O(n/2)
	 */
	bool searchBooleanVia(Via *&v);
	/*
	 *Search a via
	 *PRE:Create the Tree correctly
	 *POST:Returns true of the via is searched
	 *COMPLEXITY:O(1)
	 */
	bool existVia(Via *&v);
	/*
	 * PRE:Create the tree correctly
	 *POST: Show all the elements on the tree
	 *COMPLEXITY:O(1)
	 */
	void showTheTree();
	/*
	 * Destructor
	 *PRE:
	 *POST:
	 *COMPLEXITY:O(1)
	 */
	~ViaList();
};

#endif /* VIALIST_H_ */
