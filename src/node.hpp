#pragma once

#include "squirrel.hpp"

class Node
{
public:
	Node(Squirrel* squirrel);

	void setRight(Node* node);
	void setLeft(Node* node);

	Node* right() const;
	Node* left() const;

	Squirrel* getData() const;

private:
	Squirrel* squirrel_;
	Node* left_;
	Node* right_;
};
