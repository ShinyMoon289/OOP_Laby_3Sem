#pragma once
#include<iostream>
#include<memory>


template<class ptrType>
class Status
{
public:
	ptrType* ptr;
};

template<class Temp> class SmartPointer
{
private:
	Status<Temp>* smartPointer;
public:
	SmartPointer(Temp* ptr);
	SmartPointer(const SmartPointer& obj);
	~SmartPointer();
	SmartPointer& operator=(const SmartPointer& obj);
	Temp* operator->() const;

};

template <class Temp>
SmartPointer<Temp>::SmartPointer(Temp* ptr) {
	if (!ptr)
		smartPointer = NULL;
	else 
	{
		smartPointer = new Status<Temp>();
		smartPointer->ptr = ptr;
	}
}

template <class Temp>
SmartPointer<Temp>::SmartPointer(const SmartPointer& obj) : smartPointer(obj.smartPointer) 
{ }

template <class Temp>
SmartPointer<Temp>::~SmartPointer() {
	if (smartPointer) 
	{
		delete smartPointer->ptr;
		delete smartPointer;
	}
}

template <class Temp>
Temp* SmartPointer<Temp>::operator->() const 
{
	if (smartPointer) return smartPointer->ptr;
	else return NULL;
}

template <class Temp>
SmartPointer<Temp>& SmartPointer<Temp>::operator=(const SmartPointer& obj) 
{
	smartPointer = obj.smartPointer;//присваивание нового адреса указателю
		return *this;
}


template<class Temp> class Transaction
{
private:
	Temp* currState;
	Temp* prevState;
public:
	void showStates();
	unsigned int beginTransaction(std::string newname, unsigned int size);
	void commit();
	void revertTransac();
	Temp* operator->();
	Transaction<Temp> operator=(const Transaction<Temp>& newTransc);
	Transaction() : prevState(NULL), currState(new Temp){}
	Transaction(const Transaction& newTransc):
		currState(new Temp(*(newTransc.currState))), prevState(NULL) {}

	~Transaction() { delete currState; delete prevState; }
	
};

#include"Transaction.h"

using std::cout;

template<class Temp>
Transaction<Temp> Transaction<Temp>::operator=(const Transaction<Temp>& newTransc)
{
	if (this != &newTransc)
	{
		delete currState;
		currState = new Temp(*(newTransc.currState));
	}
	return *this;
}

template<class Temp>
Temp* Transaction<Temp>::operator->()
{
	return currState;
}

template<class Temp>
void Transaction<Temp>::showStates()
{
	std::cout << "Object status: "<<std::endl;
	

	if (prevState)cout << "Previous state: " << prevState->getName()<<" "<<prevState->getSize() << std::endl;
	else cout << "previous state was not saved." << std::endl;

	cout << "Current state is " << currState->getName() <<". Size: "<<currState->getSize()<< std::endl;
}

template<class Temp>
unsigned int Transaction<Temp>::beginTransaction(std::string newname,unsigned int newsize)
{
	delete prevState;
	prevState = currState;
	currState = new Temp(*prevState);
	if (!currState) return 0;
	currState->setName(newname);
	currState->setSize(newsize);
	for (int i = 0; i < 30; i++)cout << "-";
	cout << std::endl;
	cout << "Transaction completed successfully!" << std::endl;
	for (int i = 0; i < 30; i++)cout << "-";
	cout << std::endl;
	return 1;
}

template<class Temp>
void Transaction<Temp>::commit()
{
	delete prevState;
	prevState = NULL;

	for (int i = 0; i < 30; i++)cout << "-";
	cout << std::endl;
	cout << "Changes commited!" << std::endl;
	for (int i = 0; i < 30; i++)cout << "-";
	cout << std::endl;

}

template<class Temp>
void Transaction<Temp>::revertTransac()
{
	if (prevState != NULL)
	{
		delete currState;
		currState = prevState;
		prevState = NULL;
	}
	for (int i = 0; i < 30; i++)cout << "-";
	cout << std::endl;
	cout << "Transaction REVERTED successfully!" << std::endl;
	for (int i = 0; i < 30; i++)cout << "-";
	cout << std::endl;
	
}

