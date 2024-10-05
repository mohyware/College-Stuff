#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

class CommissionEmployee : public Employee
{

public:
    double target;
    double rate;

    // constructor
    CommissionEmployee();
    // Setters
    void setTarget(double target);
    void setRate(double rate);

    // Getters
    double getTarget() const;
    double getRate() const;

    // Other method
    double getSalary() override;
    double calculatePay() override;
    void inputData() override;
    void editData() override;
    string getDetails() override;

};


#endif // COMMISSIONEMPLOYEE_H


