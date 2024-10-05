#include "Reservation.h"

    // Constructor
    Reservation::Reservation()
    {
        start_date="";
        end_date ="";
        car = nullptr;
        customer = nullptr;
        invoice = nullptr;
        rentAgree = nullptr;
    }

    // Getters
    string Reservation::getStartDate() const
    {
        return start_date;
    }
    string Reservation::getEndDate() const
    {
        return end_date;
    }
    Car* Reservation::getCar() const
    {
        return car;
    }
    Customer* Reservation::getCustomer() const
    {
        return customer;
    }
    RentalAgreement* Reservation::getRentAgree() const
    {
        return rentAgree;
    }
    Invoice* Reservation::getInvoice() const
    {
        return invoice;
    }
    // Setters
    void Reservation::setStartDate(string start)
    {
        start_date = start;
    }
    void Reservation::setEndDate(string end)
    {
        end_date = end;
    }
    void Reservation::setCar(Car* c)
    {
        car = c;
    }
    void Reservation::setCustomer(Customer* cs)
    {
        customer = cs;
    }
    void Reservation::setRentAgree(RentalAgreement* ra)
    {
        rentAgree = ra;
    }
    void Reservation::setInvoice(Invoice* in)
    {
        invoice = in;
    }
    //other
    void Reservation::inputStart()
    {
        cout << "Enter Start date in  (yyyy/mm/dd) format: ";
        cin >> start_date;
    }
    void Reservation::inputEnd()
    {
        cout << "Enter End date in  (yyyy/mm/dd) format: ";
        cin >> end_date;
    }

    int Reservation::toDays(string date)
    {
        int year, month, day;

        year = stoi(date.substr(0, 4));
        month = stoi(date.substr(5, 2));
        day = stoi(date.substr(8, 2));

        int days = year * 365 + month * 30 + day;
        return days;
    }
    bool Reservation::operator==(const Reservation& other) const
    {
        return start_date == other.start_date &&
               end_date == other.end_date &&
               *car == *(other.car) &&
               *customer == *(other.customer) &&
               *invoice == *(other.invoice) &&
               *rentAgree == *(other.rentAgree);
    }

    ostream& operator<<( ostream& os, const Reservation& reservation)
    {
        os << "Start Date: " << reservation.start_date <<  endl;
        os << "End Date: " << reservation.end_date <<  endl;
        os << "Car Details: " <<  endl << *(reservation.car) <<  endl;
        os << "Customer Details: " <<  endl << *(reservation.customer) <<  endl;
        os << "Invoice Details: " <<  endl << *(reservation.invoice) <<  endl;
        os << "Rental Agreement Details: " <<  endl << *(reservation.rentAgree) <<  endl;
        return os;
    }

