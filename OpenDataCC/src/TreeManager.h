/*
 * TreeManager.h
 *
 *  Created on: 24 may. 2017
 *      Author:Adrián Fernández Ramos
 */

#ifndef TREEMANAGER_H_
#define TREEMANAGER_H_
#include "bstree.h"
#include"Via.h"

class TreeManager {
private:
	BSTree<Via*, ComparePtrVias> *bst;
	//Show the elements beginning with...
	BSTree<Via *, ComparePtrVias> * similarities(
			BSTree<Via *, ComparePtrVias> *bst, const string &name);
	//Show the elements beginning with...
	void filterInOrder(BSTree<Via *, ComparePtrVias> *bst, const string &name);
	//Search a element to change the name of the element
	void searchInTreeToChangeName(BSTree<Via *, ComparePtrVias> *bst,
			string name, Via *&v, string name2);
	//Accumulates the power of each via
	void powerOfAVia(BSTree<Via*, ComparePtrVias> *bstVias, string name,
			double &pow);
	//Show the tree in order
	void showInOrderTree(BSTree<Via *, ComparePtrVias> *bst);

public:
	/*
	 * Constructor
	 *PRE:
	 *POST:Create the tree correctly
	 *COMPLEXITY:O()
	 */
	TreeManager();
	/*
	 *
	 *Show the via that begging with a specific root of the name
	 *PRE:Create the vias in the tree correctly
	 *POST:Show in the screen the vias with the root
	 *COMPLEXITY:O(n)
	 */
	void matchings(const string &name);
	/*
	 *Insert a via
	 *PRE:
	 *POST:Creates the tree
	 *COMPLEXITY:O(1)
	 */
	void insertVia(Via *v);
	/*
	 *Show all the elements in order
	 *PRE:Create the tree correctly
	 *POST:Show all the elements
	 *COMPLEXITY:O()
	 */
	void show();
	/*
	 *Calculate the power of all the vias
	 *PRE:Create the vias correctly
	 *POST:Returns the total power of the vias that belongs to the name (Neighborhood)
	 *COMPLEXITY:O(n)
	 */
	void callToPowerOfAVia(string name, double &pow);
	/*
	 *Change the name of a specific via
	 *PRE:Create the vias correctly
	 *POST:Set a new name in the via (name2)
	 *COMPLEXITY:O(log2 n)
	 */
	void callToChangeTheNameOfAVia(string name, string name2);
	/*
	 *Search a via
	 *PRE:Create the Tree correctly
	 *POST:Returns true of the via is searched
	 *COMPLEXITY:O(1)
	 */
	bool existVia(Via *&v);
	/*
	 * Desctructor
	 *PRE:
	 *POST:
	 *COMPLEXITY:O()
	 */
	~TreeManager();
};

#endif /* TREEMANAGER_H_ */
