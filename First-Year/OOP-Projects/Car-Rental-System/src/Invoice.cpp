#include "Invoice.h"

// Constructor
Invoice::Invoice()
{
    rental_charges=0;
    taxes=0;
    total_amount_due=0;
}

// Getters
double Invoice::getRentalCharges() const
{
    return rental_charges;
}
double Invoice::getTaxes() const
{
    return taxes;
}
double Invoice::getTotalAmountDue() const
{
    return total_amount_due ;
}

// Setters
void Invoice::setRentalCharges(double rental)
{
    rental_charges = rental;
}
void Invoice::setTaxes(double tax)
{
    taxes = tax;
}
void Invoice::setTotalAmountDue(double total)
{
    total_amount_due = total;
}

// Other
Invoice Invoice::operator+(const Invoice& other) const
{
    Invoice result;
    result.rental_charges = rental_charges + other.rental_charges;
    result.taxes = taxes + other.taxes;
    result.total_amount_due = total_amount_due + other.total_amount_due;
    return result;
}

Invoice Invoice::operator-(double amount) const
{
    Invoice result = *this; // Make a copy of the current object
    result.total_amount_due = rental_charges + taxes;
    result.total_amount_due -= amount;
    return result;
}

bool Invoice::operator==(const Invoice& other) const
{
    return (rental_charges == other.rental_charges &&
            taxes == other.taxes &&
            total_amount_due == other.total_amount_due);
}

ostream& operator<<(ostream& os, const Invoice& inv)
{
    os << "------> Status: " << (inv.total_amount_due ? "Not Paid" : "Paid") << endl;
    os << "Rental charges: " << inv.rental_charges << "\n";
    os << "Taxes: " << inv.taxes << "\n";
    os << "Total amount due: " << inv.total_amount_due << "\n";
    return os;
}
