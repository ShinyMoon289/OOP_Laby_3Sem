#include<string>
#pragma once

class Plane
{
protected:
	std::string name{ "random" };
	unsigned int crew{5};
public:
	std::string getName();
	void setName(std::string value);

	unsigned int getCrew();
	void setCrew(unsigned int value);
	
};

class Freighter :public Plane
{
public:
	Freighter(){}
	Freighter(std::string,unsigned int, double);
	Freighter(const Freighter&);
	double getCargoWeight();
	void setCargoWeight(double value);
protected:
	double cargoWeight{6.345};
};

class CommAirLiner:public Plane
{
protected:
	unsigned int passengers{ 10 };
public:
	CommAirLiner(){}
	CommAirLiner(std::string, unsigned int, unsigned int);
	CommAirLiner(const CommAirLiner&);
	unsigned int getPassengers();
	void setPassengers(unsigned int value);
};

class PrivateJet :public CommAirLiner
{
private:
	double price{ 150000 };
public:
	PrivateJet(){}
	PrivateJet(std::string, unsigned int, double);
	PrivateJet(const PrivateJet&);
	double getPrice();
	void setPrice(double value);
};

template<class planeType>
class Flight
{
private:
	double distancekm{ 1000 };
	planeType planetype;
	unsigned int flNumber{ 123 };
public:
	Flight(unsigned int, const planeType&, double);
	Flight(const Flight&);
	void setDistance(double value);
	double getDistance();

	void setNum(unsigned int);
	unsigned int getNum();

	planeType getPlaneType();
	void setPlaneType(planeType value);

};

template<class planeType>
void Flight<planeType>::setDistance(double value)
{
	distancekm = value;
}

template<class planeType>
double Flight<planeType>::getDistance()
{
	return distancekm;
}

template<class planeType>
planeType Flight<planeType>::getPlaneType()
{
	return planetype;
}

template<class planeType>
void Flight<planeType>::setPlaneType(planeType value)
{
	planetype = value;
}

template<class planeType>
Flight<planeType>::Flight(unsigned int num, const planeType& type, double dist)
{
	flNumber = num;
	planetype = type;
	distancekm = dist;
}

template<class planeType>
Flight<planeType>::Flight(const Flight& obj)
{
	flNumber = obj.flNumber;
	planetype = obj.planetype;
	distancekm = obj.distancekm;

}

template<class planeType>
void Flight<planeType>::setNum(unsigned int num)
{
	flNumber = num;
}

template<class planeType>
unsigned int Flight<planeType> ::getNum()
{
	return flNumber;
}