#include "RentalAgreement.h"


    // Constructor
    RentalAgreement::RentalAgreement()
    {
        rental_period =0;
        rental_rate=0 ;
        rental_charges=0;
        insurance_charges=0;
    }

    // Getters
    int RentalAgreement::getRentalPeriod() const
    {
        return rental_period;
    }
    double RentalAgreement::getRentalRate() const
    {
        return rental_rate;
    }
    double RentalAgreement::getInsuranceCharges() const
    {
        return insurance_charges;
    }
    double RentalAgreement::getRentalCharges() const
    {
        return rental_period*rental_rate;
    }

    // Setters
    void RentalAgreement::setRentalPeriod(int period)
    {
        rental_period = period;
    }
    void RentalAgreement::setRentalRate(double rate)
    {
        rental_rate = rate;
    }
    void RentalAgreement::setInsuranceCharges(double insurance)
    {
        insurance_charges = insurance;
    }
    void RentalAgreement::setRentalCharges(double rental)
    {
        rental_charges = rental;
    }

    //other
    RentalAgreement RentalAgreement::operator+(const RentalAgreement& other) const
    {
        RentalAgreement result;
        result.rental_charges = rental_charges + other.rental_charges;
        result.insurance_charges = insurance_charges + other.insurance_charges;
        return result;
    }

    RentalAgreement RentalAgreement::operator-(const RentalAgreement& other) const
    {
        RentalAgreement result;
        result.rental_charges = rental_charges - other.rental_charges;
        result.insurance_charges = insurance_charges - other.insurance_charges;
        return result;
    }
    bool RentalAgreement::operator==(const RentalAgreement& other) const {
        return rental_period == other.rental_period &&
               rental_rate == other.rental_rate &&
               rental_charges == other.rental_charges &&
               insurance_charges == other.insurance_charges;
    }

    ostream& operator<<(ostream& os, const RentalAgreement& agreement) {
        os << "Rental Period: " << agreement.rental_period << endl;
        os << "Rental Rate: " << agreement.rental_rate << endl;
        os << "Rental Charges: " << agreement.rental_charges << endl;
        os << "Insurance Charges: " << agreement.insurance_charges << endl;
        return os;
    }
