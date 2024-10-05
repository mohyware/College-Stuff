#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include "Employee.h"
#include <iostream>
#include <string>

using namespace std;

class HourlyEmployee: public Employee
{
private:
    double hoursWorked;
    double rate;

public:
    // constructor
    HourlyEmployee();
    // Getters
    double getHoursWorked() const;
    double getRate() const;

    // Setters
    void setHoursWorked(double hoursWorked);
    void setRate(double rate);

    // Other methods
    double getSalary() override;
    double calculatePay() override;
    void inputData() override;
    void editData() override;
    string getDetails() override;

    void addHours(int moreHours);
};



#endif // HOURLYEMPLOYEE_H
