#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Department.h"
#include "Benefit.h"
#include "DentalBenefit.h"
#include "HealthBenefit.h"
#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    Benefit **benefitList;
    int Benefit_count;
    int Benefit_size;

    Department *department;
protected:
    string name;
    string phone;
    string email;
    string jobTitle;

public:
    // Default constructor
    Employee();

    // Getters
    string getName() const;
    string getPhone() const;
    string getEmail() const;
    string getJobTitle() const;
    Department* getDepartment();

    int getBenefit_count() const;

    // Setters
    void setName(string name);
    void setPhone(string phone);
    void setEmail(string email);
    void setJobTitle(string jobTitle);
    void setDepartment(Department* dept);

    // Other methods

    string displayDetails();

    virtual double calculatePay();
    virtual double getSalary();
    virtual string getDetails();
    virtual void inputData();
    virtual void editData();

    double calcBenefits();
    void addBenefits();
    void EditBenefit();
    void delBenefit(int delIndx);
    void printAllBenefits();
};


#endif // EMPLOYEE_H
