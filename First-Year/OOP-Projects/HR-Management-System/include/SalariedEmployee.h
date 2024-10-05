#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H
#include "Employee.h"

#include <iostream>
#include <string>

using namespace std;

class SalariedEmployee: public Employee
{

public:

    double salary;

    // constructor
    SalariedEmployee();

    // Getter

    // Setter
    void setSalary(double salary);

    // Other method
    double getSalary() override;
    double calculatePay() override;
    void inputData() override;
    void editData() override;
    string getDetails() override;

};


#endif // SALARIEDEMPLOYEE_H
