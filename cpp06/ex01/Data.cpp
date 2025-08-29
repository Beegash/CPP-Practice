#include "Data.hpp"

Data::Data() : value(0), name("")
{
}

Data::Data(int v, const std::string &n) : value(v), name(n)
{
}

Data::Data(const Data &other) : value(other.value), name(other.name)
{
}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
	{
		value = other.value;
		name = other.name;
	}
	return *this;
}

Data::~Data()
{
}
