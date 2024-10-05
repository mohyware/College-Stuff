#ifndef HEALTHBENEFIT_H
#define HEALTHBENEFIT_H

#include "Benefit.h"
#include <iostream>
#include <string>

using namespace std;

class HealthBenefit: public Benefit
{
private:
    string info;
    string coverage;

public:
    // Constructor
    HealthBenefit();

    // Getters
    string getInfo() const;
    string getCoverage() const;

    // Setters
    void setInfo(string info);
    void setCoverage(string coverage);

    // Other methods
    double calculateBenefit() override;
    string getDetails() override;
    void inputData() override;
    void editData() override;
};


#endif // HEALTHBENEFIT_H
