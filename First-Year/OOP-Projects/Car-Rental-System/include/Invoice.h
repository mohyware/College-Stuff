#ifndef INVOICE_H
#define INVOICE_H
#include <istream>
#include <ostream>
using namespace std;

class Invoice
{
private:
    double rental_charges;
    double taxes;
    double total_amount_due;
public:
    // Constructor
    Invoice();

    // Getters
    double getRentalCharges()const ;
    double getTaxes() const;
    double getTotalAmountDue() const;

    // Setters
    void setRentalCharges(double rental);
    void setTaxes(double tax);
    void setTotalAmountDue(double total);

    // Other
    Invoice operator+(const Invoice& other) const;
    Invoice operator-(double amount) const;
    bool operator==(const Invoice& other) const;
    friend ostream& operator<<(ostream& os, const Invoice& inv);

};



#endif // INVOICE_H
