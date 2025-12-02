#include "squirrel.hpp"

#include <string>

Squirrel::Squirrel(std::string name): name_(name) {}

std::string Squirrel::getName() const
{
	return name_;
}
