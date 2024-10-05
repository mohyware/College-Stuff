#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <iostream>

using namespace std ;


class Department
{
private:
    int departiD;
    string departName;

public:
    //Constructor
    Department();

    //setters
    void setDepartiD(int id);
    void setDepartName(const string& name);

    //getters
    string getDepartName() const;
    int getDepartiD() const;

    //other
    void Print() const;
    void inputData();
    void editData();
};


#endif // DEPARTMENT_H
