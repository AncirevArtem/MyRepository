#include "stdafx.h"
#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree() {
	this->root = nullptr;
}

Tree::Tree(int value) {
	this->root = new Node(value);
}

void Tree::add(int value) {
	if (root == nullptr) {
		root = new Node(value);
	}
	else {
		Node*current = this->root;
		while (current != nullptr) {
			if (value <= current->getValue()) {
				if (current->getLeftSon() == NULL) {
					Node* newNode = new Node(value);
					current->setLeftSon(newNode);
					current = NULL;
				}
				else {
					current = current->getLeftSon();
				}
			}
			else {
				if (current->getRightSon() == NULL) {
					Node* newNode = new Node(value);
					current->setRightSon(newNode);
					current = NULL;
				}
				else {
					current = current->getRightSon();
				}
			}
		}
	}
}

void Tree::print() {
	this->root->print(root , 0);
}

void Tree::del(int element){
	if (root->getValue() == element)
	{
		Node*left_son = root->getLeftSon();
		Node*right_son = root->getRightSon();
		root->setLeftSon(NULL);
		root->setRightSon(NULL);
		delete root;
		if (right_son)
		{
			root = right_son;
			while (right_son->getLeftSon())
			{
				right_son = right_son->getLeftSon();
			}
			right_son->setLeftSon(left_son);
		}
		else
		{
			root = left_son;
		}
	}
	else {
		bool flag = false;
		Node*parent = root;
		Node*current = root;
		while (current&&!flag) {
			if (current->getValue() == element) {
				flag = true;
				int side = 0;
				Node*left_son = current->getLeftSon();
				Node*right_son = current->getRightSon();
				current->setLeftSon(NULL);
				current->setRightSon(NULL);
				if (current->getValue() > parent->getValue()) {
					side = 1;
				}
				delete current;
				if (side == 1) {
					if (right_son) {
						parent->setRightSon(right_son);
						while (right_son->getLeftSon())
						{
							right_son = right_son->getLeftSon();
						}
						right_son->setLeftSon(left_son);
					}
					else {
						parent->setRightSon(left_son);
					}
				}
				else {
					if (right_son) {
						parent->setLeftSon(right_son);
						while (right_son->getLeftSon())
						{
							right_son = right_son->getLeftSon();
						}
						right_son->setLeftSon(left_son);
					}
					else {
						parent->setLeftSon(left_son);
					}
				}
			}
			else if(current->getValue() < element){
				parent = current;
				current = current->getRightSon();
			}
			else {
				parent = current;
				current = current->getLeftSon();
			}
		}
		if (!flag) {
			cout << "I can`t find element = " << element << endl;
		}

	}
}

bool Tree::search(int element){
	Node*hellper = root;
	while (hellper != NULL)
	{
		if (hellper->getValue() == element)
		{
			return true;
		}
		else if (hellper->getValue() > element)
		{
			hellper = hellper->getLeftSon();
		}
		else
		{
			hellper = hellper->getRightSon();
		}
	}
	return false;
}
