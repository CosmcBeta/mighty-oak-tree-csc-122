#pragma once

#include <string>

class Squirrel
{
public:
	Squirrel(std::string name);

	std::string getName() const;

private:
	std::string name_;
};
