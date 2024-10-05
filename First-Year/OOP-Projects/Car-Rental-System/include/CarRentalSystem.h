#ifndef CARRENTALSYSTEM_H
#define CARRENTALSYSTEM_H

#include "Car.h"
#include "Customer.h"
#include "Reservation.h"
#include "RentalAgreement.h"
#include "Invoice.h"
#include <conio.h>

class CarRentalSystem
{
private:
    int carCount ;
    int carSize ;
    Car **carList;

    int customerCount ;
    int customerSize ;
    Customer **customerList;

    int reservCount ;
    int reservSize ;
    Reservation **reservList;
public:
    CarRentalSystem(int crSize,int cusSize,int resSize);
    ~CarRentalSystem();
//car
    void addCar();
    void editCar();
    void DetCar();
    void Available_Cars();
//customer
    void addcustomer();
    void editCustomer();
    void PrintCustomers();
//other
    void startReservation();
    void endReservation();
    void RentalHistory();
    void Payment();
    void generateReport();
};

#endif // CARRENTALSYSTEM_H
