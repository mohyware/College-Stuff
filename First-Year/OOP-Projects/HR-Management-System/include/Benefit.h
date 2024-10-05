#ifndef BENEFIT_H
#define BENEFIT_H

#include <iostream>
#include <string>
using namespace std;
class Benefit
{
protected:
    string planType;
    double amount;

public:
    // Constructor
    Benefit();

    // Getters
    string getPlanType()const ;
    double getAmount() const ;

    // Setters
    void setPlanType(string planType);
    void setAmount(double amount);

    // Other methods
    string displayBenefit();

    virtual double calculateBenefit() ;
    virtual string getDetails() ;
    virtual void inputData() ;
    virtual void editData() ;
};


#endif // BENEFIT_H
