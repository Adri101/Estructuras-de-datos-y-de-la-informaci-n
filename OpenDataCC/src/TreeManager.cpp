/*
 * TreeManager.cpp
 *
 *  Created on: 24 may. 2017
 *      Author: adri
 */

#include "TreeManager.h"

TreeManager::TreeManager() {

	this->bst = new BSTree<Via*, ComparePtrVias>();
}
BSTree<Via *, ComparePtrVias> * TreeManager::similarities(
		BSTree<Via *, ComparePtrVias> *bst, const string &name) {
	BSTree<Via *, ComparePtrVias> *aux = NULL;
	BSTree<Via *, ComparePtrVias> *aux2;

	if (bst->root()->getnameVia().find(name) == 0) //search for the first element with your name
		aux = bst;
	else {
		if (name < bst->root()->getnameVia()) {
			aux2 = bst->left();
			if (aux2 != NULL)
				aux = similarities(aux2, name);

		} else {
			aux2 = bst->right();
			if (aux2 != NULL)
				aux = similarities(aux2, name);

		}
	}
	return aux;
}
void TreeManager::filterInOrder(BSTree<Via *, ComparePtrVias> *bst,
		const string &name) {
	BSTree<Via *, ComparePtrVias> * aux = NULL;
	if (bst->root()->getnameVia().find(name) == 0) { //seacrhing in your subtree with the previous root
		bst->root()->show();
	}
	aux = bst->right();
	if (aux != NULL) {
		filterInOrder(aux, name);
	}

	aux = bst->left();
	if (aux != NULL) {
		filterInOrder(aux, name);

	}

}
void TreeManager::matchings(const string &name) {

	BSTree<Via *, ComparePtrVias> *bst;

	if (!this->bst->empty()) {

		bst = this->similarities(this->bst, name);
		if (bst != NULL) {
			cout << "Showing matchings of: " << name << endl;
			filterInOrder(bst, name);
		} else {
			cout << "No Via begins with: " << name << endl;
		}
	}
}
void TreeManager::insertVia(Via *v) {
	this->bst->insert(v);
}
void TreeManager::showInOrderTree(BSTree<Via *, ComparePtrVias> *bst) {

	BSTree<Via*, ComparePtrVias> *aux;
	if (!bst->empty()) {
		aux = bst->left();
		if (aux != NULL) {
			showInOrderTree(aux);
		}
		bst->root()->show();
		aux = bst->right();
		if (aux != NULL) {
			showInOrderTree(aux);
		}
	}

}

void TreeManager::show() {
	this->showInOrderTree(this->bst);
}

void TreeManager::powerOfAVia(BSTree<Via*, ComparePtrVias> *bstVias,
		string name, double &pow) {
	BSTree<Via*, ComparePtrVias> *aux;
	double po = 0.0;
	if (!bstVias->empty()) {
		aux = bstVias->left();
		if (aux != NULL) {
			powerOfAVia(aux, name, pow);
		}
		if (bstVias->root()->getNameNeighborhood() == name) {
			bstVias->root()->calculateThePowerOfLamps(po);
			pow += po;
			po = 0.0;
		}
		aux = bstVias->right();
		if (aux != NULL) {
			powerOfAVia(aux, name, pow);
		}
	} else {
		cout << "The tree is empty" << endl;
	}

}
void TreeManager::callToPowerOfAVia(string name, double &pow) {
	this->powerOfAVia(this->bst, name, pow);
}
void TreeManager::searchInTreeToChangeName(BSTree<Via *, ComparePtrVias> *bst,
		string name, Via* &v, string name2) {

	BSTree<Via*, ComparePtrVias> *b;
	Via *aux = NULL;
	if (bst->empty()) {
		v = NULL;
		cout << "the Tree of vias is empty please load again the data" << endl;
	} else {
		aux = bst->root();
		if (aux->getnameVia() == name) {
			v = aux;
			v->setnameVia(name2);

			cout
					<< "The via " + name + " has been succesfully changed to : "
							+ v->getnameVia() << endl;

		} else if (aux->getnameVia() > name) {
			b = bst->left();
			if (b != NULL)
				searchInTreeToChangeName(b, name, v, name2);

		} else {
			b = bst->right();
			if (b != NULL)
				searchInTreeToChangeName(b, name, v, name2);
		}
	}

}
void TreeManager::callToChangeTheNameOfAVia(string name, string name2) {
	Via *v = NULL;

	this->searchInTreeToChangeName(this->bst, name, v, name2);

}
bool TreeManager::existVia(Via *&v) {
	return this->bst->exist(v);
}

TreeManager::~TreeManager() {
	Via *aux;
	while (!this->bst->empty()) {
		aux = bst->root();
		this->bst->remove(aux);
	}
	delete bst;
	delete aux;
}

