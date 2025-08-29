#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
	int			value;
	std::string	name;
	
	Data();
	Data(int v, const std::string& n);
	Data(const Data& other);
	Data& operator=(const Data& other);
	~Data();
};

#endif 
