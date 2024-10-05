#ifndef RENTALAGREEMENT_H
#define RENTALAGREEMENT_H

#include <istream>
#include <ostream>
using namespace std;
class RentalAgreement
{
private:
    int rental_period;
    double rental_rate;
    double rental_charges;

    double insurance_charges;
public:
    // Constructor
    RentalAgreement();

    // Getters
    int getRentalPeriod() const;
    double getRentalRate() const;
    double getInsuranceCharges() const;
    double getRentalCharges() const;

    // Setters
    void setRentalPeriod(int period);
    void setRentalRate(double rate);
    void setInsuranceCharges(double insurance);
    void setRentalCharges(double rental);

    //other
    RentalAgreement operator+(const RentalAgreement& other) const;
    RentalAgreement operator-(const RentalAgreement& other) const;
    bool operator==(const RentalAgreement& other) const ;
    friend ostream& operator<<(ostream& os, const RentalAgreement& agreement);

};

#endif // RENTALAGREEMENT_H
