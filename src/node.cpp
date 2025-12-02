#include "node.hpp"
#include "squirrel.hpp"

Node::Node(Squirrel* squirrel): squirrel_(squirrel), left_(nullptr), right_(nullptr) {}

void Node::setRight(Node* node)
{
	right_ = node;
}

void Node::setLeft(Node* node)
{
	left_ = node;
}

Node* Node::right() const
{
	return right_;
}

Node* Node::left() const
{
	return left_;
}

Squirrel* Node::getData() const
{
	return squirrel_;
}
