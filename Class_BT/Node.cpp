#include "stdafx.h"
#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(int value) {
	this->value = value;
	this->leftSon = nullptr;
	this->rightSon = nullptr;
}

int Node::getValue() {
	return this->value;
}

Node *Node::getLeftSon() {
	return this->leftSon;
}

Node *Node::getRightSon() {
	return this->rightSon;
}

void Node::setLeftSon(Node *leftSon) {
	this->leftSon = leftSon;
}

void Node::setRightSon(Node *rightSon) {
	this->rightSon = rightSon;
}

void Node::setValue(int value) {
	this->value = value;
}

void Node::print(Node *root, int level) {
	if (root != nullptr)
	{
		root->print(root->getRightSon(), level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << root->getValue() << endl;
		root->print(root->getLeftSon(), level + 1);
	}
}
