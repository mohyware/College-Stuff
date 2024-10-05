#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
#include <iostream>
#include "Car.h"
#include "Customer.h"
#include "RentalAgreement.h"
#include "Invoice.h"
#include <string>
using namespace std;

class Reservation
{
private:
    string start_date;
    string end_date;

    Car *car;
    Customer *customer;
    Invoice *invoice;
    RentalAgreement *rentAgree;

public:
    // Constructor
    Reservation();
    // Getters
    string getStartDate() const;
    string getEndDate() const;
    Car* getCar() const;
    Customer* getCustomer() const;
    RentalAgreement* getRentAgree() const;
    Invoice* getInvoice() const;
    // Setters
    void setStartDate(string start);
    void setEndDate(string end);
    void setCar(Car* c);
    void setCustomer(Customer* cs);
    void setRentAgree(RentalAgreement* ra);
    void setInvoice(Invoice* in);
    //other
    void inputStart();
    void inputEnd();

    int toDays(string date);
    bool operator==(const Reservation& other) const;

    friend ostream& operator<<( ostream& os, const Reservation& reservation);
};



#endif // RESERVATION_H
