#include"Classes.h"

//defining methods of Student

Student::Student()
{
	Name = "Vasya";
	Surname = "Krasilnikov";
	Age = 19;
	Course = 2;
}

Student::Student(std::string newName, std::string newSurname, unsigned short int newAge, unsigned short int newCourse)
{
	Name = newName;
	Surname = newSurname;
	Age = newAge;
	Course = newCourse;
}

std::string Student::getUniName()
{
	return UniName;
}
void Student::setUniName(std::string newUniName)
{
	UniName = newUniName;
}

std::string Person::getName()
{
	return this->Name;
}
std::string Person::getSurname()
{
	return Surname;
}
unsigned short int Person::getAge()
{
	return Age;
}
unsigned short int Student::getCourse()
{
	return Course;
}

void Person::setName(std::string newName)
{
	Name = newName;
}
void Person::setSurname(std::string newSurname)
{
	Surname = newSurname;
}
void Person::setAge(unsigned short int newAge)
{
	Age = newAge;
}
void Student::setCourse(unsigned short int newCourse)
{
	Course = newCourse;
}

//Defining methods of Worker

Worker::Worker()
{
	Name = "Vasya";
	Surname = "Krasilnikov";
	Age = 19;
	Salary = 300;
}

Worker::Worker(std::string newName, std::string newSurname, unsigned short int newAge, unsigned int newSalary)
{
	Name = newName;
	Surname = newSurname;
	Age = newAge;
	Salary = newSalary;
}


unsigned int Worker::getSalary()
{
	return Salary;
}

void Worker::setSalary(unsigned int newSalary)
{
	Salary = newSalary;
}


//Defining working students
WorkingStudent::WorkingStudent()
{
	Name = "Vasya";
	Surname = "Krasilnikov";
	Age = 19;
	Course = 2;
	Salary = 300;

}
WorkingStudent::WorkingStudent(std::string newName, std::string newSurname, unsigned short int newAge, unsigned short int newCourse, unsigned int newSalary)
{
	Name = newName;
	Surname = newSurname;
	Age = newAge;
	Course = newCourse;
	Salary = newSalary;
}