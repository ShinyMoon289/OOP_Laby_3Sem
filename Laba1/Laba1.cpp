#include <iostream>
#include"Classes.h"
using namespace std;

int main()
{
    Student* students = new Student[2]();
    Worker* workers = new Worker[2]();
    WorkingStudent* workstudents = new WorkingStudent[2]();

    students[1].setName("Anatoliy");
    students[1].setSurname("Korenichkin");
    students[1].setAge(25);
    students[1].setCourse(4);
    students[1].setUniName("BSUIR");

    workers[1].setName("Evgeny");
    workers[1].setSurname("Ponasenkov");
    workers[1].setAge(37);
    workers[1].setSalary(300000);

    workstudents[1].setName("Igor");
    workstudents[1].setSurname("Bogdanoff");
    workstudents[1].setSalary(300);
    workstudents[1].setCourse(2);
    workstudents[1].setUniName("BSUIR");

    for (unsigned short i = 0; i < 2; i++)
    {
        
        cout << students[i].getName() << " " <<
            students[i].getSurname() << " " <<
            students[i].getAge() << " " <<
            students[i].getCourse() << " " <<
            students[i].getUniName() << endl <<

            workers[i].getName() << " " <<
            workers[i].getSurname() << " " <<
            workers[i].getAge() << " " <<
            workers[i].getSalary() << endl <<

            workstudents[i].getName() << " " <<
            workstudents[i].getSurname() << " " <<
            workstudents[i].getSalary() << " " <<
            workstudents[i].getCourse() << " " <<
            workstudents[i].getUniName() << endl<<endl;
    }


    delete [] students, workers, workstudents;
}

