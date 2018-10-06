#pragma once
#include "Node.h"

class Tree {
private:
	Node*root;
public:
	Tree();
	Tree(int value);
	void add(int value);
	void print();
	void del(int element);
	bool search(int element);
};
