#include<exception>
#include<stdexcept>
#include<limits>
#pragma once

void checkForNegatives(int value)
{
	if (value <= 0)
	{
		throw(value);
	}
}

void termFunc()
{
	std::cout << "Error found, terminating program...";
	exit(-1);
}

template<class Temp>
void checkForOverwhelm(Temp value)
{
	
	if (value > std::numeric_limits<Temp>::max()) throw;

}

void checkForForbiddenSymbols(std::string value)
{
	for (unsigned int i = 0; i < value.length(); i++)
	{
		if (value[i] < 'A' || value[i]>'Z' && value[i] < '0' ||value[i]>'9' && value[i] < 'a' && value[i]>'z')
		{
			throw(value);
		}
	}
}

class myexception: public std::exception
{
public:
	myexception()
	{

	}
	~myexception() noexcept
	{

	}
	virtual const char* what() const noexcept
	{
		return "Inappropriate value detected!";
	}
};
