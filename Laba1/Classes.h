#pragma once
#include<string>

class Person
{
protected:
	std::string Name,Surname;
	unsigned short int Age;

public:
	std::string getName();
	std::string getSurname();
	unsigned short int getAge();

	void setName(std::string);
	void setSurname(std::string);
	void setAge(unsigned short int);

};

class Student: public virtual Person 
{
protected:
	std::string UniName;
	unsigned short int Course;
public:
	Student();
	Student(std::string, std::string, unsigned short int, unsigned short int);
	~Student(){}
	std::string getUniName();
	void setUniName(std::string);

	
	unsigned short int getCourse();
	void setCourse(unsigned short int);
};


class Worker :public virtual Person
{
protected:
	unsigned short int Salary;
public:
	Worker();
	Worker(std::string, std::string, unsigned short int, unsigned int);
	~Worker(){}
	unsigned int getSalary();
	void setSalary(unsigned int);
};

class WorkingStudent: public Student, public Worker
{

public:
	WorkingStudent();
	WorkingStudent(std::string, std::string, unsigned short int, unsigned short int, unsigned int);
	~WorkingStudent(){}


};