#pragma once
class Node {
private:
	Node*leftSon;
	Node*rightSon;
	int value;
public:
	Node(int value);
	void setLeftSon(Node *leftSon);
	void setRightSon(Node *rightSon);
	void setValue(int value);
	Node*getLeftSon();
	Node*getRightSon();
	int getValue();
	void print(Node *root,int level);
};

