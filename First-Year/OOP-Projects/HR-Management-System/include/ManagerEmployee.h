#ifndef MANAGEREMPLOYEE_H
#define MANAGEREMPLOYEE_H

#include "SalariedEmployee.h"
#include <iostream>
#include <string>
using namespace std;

class ManagerEmployee :public SalariedEmployee
{
private:
    double bonus;
public:
    // constructor
    ManagerEmployee();
    // Getters
    double getBonus();
    // Setters
    void setBonus(double newBonus);

    // Other method
    double getSalary() override;
    double calculatePay() override;
    void inputData() override;
    void editData() override;
    string getDetails() override;

    void addBonus(double moreBonus);

};

#endif // MANAGEREMPLOYEE_H
