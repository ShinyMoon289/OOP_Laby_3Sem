#include<iostream>
#include"Classes.h"
#include"Exceptions.h"
#include<limits>
#include<fstream>

using namespace std;

int main()
{
	set_terminate(termFunc);
	cout << "Enter plane's name: ";
	string name;
	getline(cin,name);
	try
	{
		checkForForbiddenSymbols(name);
	}
	catch (string err)
	{
		cerr << err << " has foribidden symbols!"<<endl;
	}
	cout << "Enter number of crew:";
	unsigned int crew=0;
	cin >> crew;
	try
	{
		checkForNegatives(crew);
	}
	catch(int err)
	{
		cerr << err << " not allowed!"<<endl;
	}
	cout << "Enter number of passengers: ";
	unsigned int pass=0;
	cin >> pass;
	try
	{
		checkForNegatives(pass);
	}
	catch(int)
	{
		cout << "The number of passengers is negative!"<<endl;
	}
	try
	{
		CommAirLiner* b747 = new CommAirLiner(name, crew, pass);
		
	}
	catch (bad_alloc& exept)
	{
		cerr << exept.what()<<endl;
	}

	CommAirLiner* b747 = new CommAirLiner(name, crew, pass);
	Flight<CommAirLiner>flight(54, *b747 , 6.657654);
	Plane plane;
	
	ofstream writer;
	writer.open("PlanesAndFlights.txt", ofstream::);
	if (!writer.is_open())
		cout << "File not found!";
	else
	{
		writer << flight.getPlaneType().getName() << endl;
		writer << flight.getPlaneType().getPassengers()<<" "<<flight.getPlaneType().getCrew() << endl;
		writer << flight.getNum();

	}
	writer.close();
	ifstream reader;
	reader.open("PlanesAndFlights.txt", ifstream::in);
	if (!reader.is_open())
	{
		cout << "File not found!";
	}
	else
	{
		string name;
		int passengers, crew;
		try
		{
			getline(reader, name);
			reader >> passengers >> crew;
			if (reader.bad())
				throw("Incorrect reading!");
		}
		catch (string e)
		{
			cerr << e;
		}

		
		
		cout << name << endl << passengers << endl << crew;
	}
	
	reader.close();

}

