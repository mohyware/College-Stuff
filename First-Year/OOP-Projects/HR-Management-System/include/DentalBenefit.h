#ifndef DENTALBENEFIT_H
#define DENTALBENEFIT_H

#include "Benefit.h"
#include <iostream>
#include <string>

using namespace std;

class DentalBenefit: public Benefit
{
private:
    string info;

public:
    // Constructor
    DentalBenefit();

    // Getter
    string getInfo() const;

    // Setter
    void setInfo(string info);

    // Other methods
    double calculateBenefit() override;
    string getDetails() override;
    void inputData() override;
    void editData() override;

};

#endif // DENTALBENEFIT_H
