#include "stdafx.h"
#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
	Tree*root = new Tree(5);
	root->add(10);
	root->add(3);
	root->add(4);
	root->add(2);
	root->add(12);
	root->add(8);
	root->add(7);
	root->add(9);
	root->add(1);
	root->add(5);
	root->add(15);
	root->add(11);
	root->print();
	cout << endl << endl << endl;
	root->del(10);
	root->print();
	cout << endl << endl << endl;
	cout << "Searching 100" << " - " << root->search(100) << endl;
	system("pause");
	return 0;
}
