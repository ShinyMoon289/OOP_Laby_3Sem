#include"Classes.h"
#include<iostream>
Freighter::Freighter(std::string newname, unsigned int newcrew, double newCargo)
{
	name = newname;
	crew = newcrew;
	cargoWeight = newCargo;
}
Freighter::Freighter(const Freighter& obj)
{
	name = obj.name;
	crew = obj.crew;
	cargoWeight = obj.cargoWeight;
}

unsigned int Plane::getCrew()
{
	return crew;

	
}
void Plane::setCrew(unsigned int value)
{
	try
	{
		if (value < 0) throw(value);
		else crew = value;
	}
	catch (int err)
	{
		std::cerr << err << " is negative!";
	}
	
}

std::string Plane::getName()
{
	return name;
}
void Plane::setName(std::string value)
{
	for (unsigned int i = 0; i < value.length(); i++)
	{
		if (value[i] < 'A' || value[i]>'Z' && value[i] < '0' || value[i]>'9' && value[i] < 'a' && value[i]>'z')
		{
			throw(value);
		}
	}
	name = value;
}

double Freighter::getCargoWeight()
{
	return cargoWeight;
}

void Freighter::setCargoWeight(double value)
{
	if (value < 0) throw(value);
	cargoWeight = value;
}

CommAirLiner::CommAirLiner(std::string newname, unsigned int newcrew, unsigned int pass)
{
	name = newname;
	crew = newcrew;
	passengers = pass;

}
CommAirLiner::CommAirLiner(const CommAirLiner& obj)
{
	name = obj.name;
	crew = obj.crew;
	passengers = obj.passengers;
}

unsigned int CommAirLiner::getPassengers()
{
	return passengers;
}

void CommAirLiner::setPassengers(unsigned int value)
{
	passengers = value;
}

PrivateJet::PrivateJet(std::string newname, unsigned int newcrew, double newprice)
{
	name = newname;
	crew = newcrew;
	price = newprice;
}
PrivateJet::PrivateJet(const PrivateJet&obj)
{
	name = obj.name;
	crew = obj.crew;
	price = obj.price;
}

double PrivateJet::getPrice()
{
	return price;
}

void PrivateJet::setPrice(double value)
{
	price = value;
}

