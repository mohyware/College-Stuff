#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

using namespace std;
class Car
{
private:
    string name;
    string model;
    int year;
    bool availability;

    double taxes;
    double rental_rate;
    double insurance_charges;

public:
    Car();

    //getters
    string getName() const;
    string getModel() const;
    int getYear() const;
    bool isAvailable() const;
    double getTaxes() const;
    double getRentalRate() const;
    double getInsuranceCharges() const;
    //setters
    void setName(const string& newName);
    void setModel(const string& newModel);
    void setYear(int newYear);
    void setAvailability(bool newAvailability);
    void setTaxes(double newTaxes);
    void setRentalRate(double newRentalRate);
    void setInsuranceCharges(double newInsuranceCharges);
    //other
    void inputData();
    void editData();
    friend ostream& operator<<(ostream& os, const Car& car) ;
    bool operator==(const Car& other) const ;

};


#endif // CAR_H
