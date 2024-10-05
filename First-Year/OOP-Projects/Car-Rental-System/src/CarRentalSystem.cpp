#include "CarRentalSystem.h"

CarRentalSystem::CarRentalSystem(int crSize,int cusSize,int resSize)
{
    carCount = 0;
    carSize = crSize;
    carList = new Car*[carSize];

    customerCount = 0;
    customerSize = cusSize;
    customerList = new Customer*[customerSize];

    reservCount = 0;
    reservSize = resSize;
    reservList = new Reservation*[reservSize];
};
CarRentalSystem::~CarRentalSystem()
{
    for(int i=0; i<carCount; i++)
    {
        delete carList[i];
    }

    delete [] carList;

    for(int i=0; i<customerCount; i++)
    {
        delete customerList[i];
    }

    delete [] customerList;

    for(int i=0; i<reservCount; i++)
    {
        delete reservList[i];
    }

    delete [] reservList;
}

//car methods
void CarRentalSystem::addCar()
{
    if(carCount == carSize)
    {
        cout<<"the space is full no new Cars can be added to the system !!!!!"<<endl;
        return;
    }
    Car* newCar=new Car();

    newCar->inputData();

    carList[carCount++] = newCar;
}

void CarRentalSystem::editCar()
{
    int carID=0;
    cout<<"Enter Car ID : ";
    cin>>carID;
    carList[carID-1]->editData() ;
}

void CarRentalSystem::DetCar()
{
    int carID=0;
    cout<<"Enter Car ID : ";
    cin>>carID;
    carList[carID-1]->setAvailability(false) ;
}

void CarRentalSystem::Available_Cars()
{
    int found_counter=0;
    for(int i=0 ; i<carCount; i++)
    {
        if(carList[i]->isAvailable()==true)
        {
            cout<<"**********************************"<<endl;
            cout<<"Car ID -----> ("<<i+1<<")"<<endl;
            cout<<*carList[i];
            cout<<"**********************************"<<endl;
            found_counter++;
        }
    }
    if(found_counter==0)
    {
        cout<<"NO Availalbe Cars FOUND!\n";
    }
    else
    {
        cout<<found_counter<<" FOUNDED\n";
    }
}
//customer
void CarRentalSystem::addcustomer()
{
    if(customerCount == customerSize)
    {
        cout<<"the space is full no new Customers can be added to the system !!!!!"<<endl;
        return;
    }
    Customer* newCustomer=new Customer();

    newCustomer->inputData();

    customerList[customerCount++] = newCustomer;
}

void CarRentalSystem::editCustomer()
{
    int customerID=0;
    cout<<"Enter Customer ID : ";
    cin>>customerID;
    customerList[customerID-1]->editData() ;
}
void CarRentalSystem::PrintCustomers()
{
    int found_counter=0;
    for(int i=0 ; i<customerCount; i++)
    {
        cout<<"**********************************"<<endl;
        cout<<"Customer ID -----> ("<<i+1<<")"<<endl;
        cout<<*customerList[i];
        cout<<"**********************************"<<endl;
        found_counter++;
    }
    if(found_counter==0)
    {
        cout<<"NO Customers FOUND!\n";
    }
    else
    {
        cout<<found_counter<<" FOUNDED\n";
    }
}
//other
void CarRentalSystem::startReservation()
{
    Reservation* newreserv=new Reservation();
    Invoice* newInvoice=new Invoice();
    RentalAgreement* newRent=new RentalAgreement();

    int carID=0;
    cout<<"Enter Car ID : ";
    cin>>carID;
    //check car is available
    if(carList[carID-1]->isAvailable()==false)
        return;
    carList[carID-1]->setAvailability(false);

    int customerID=0;
    cout<<"Enter Customer ID : ";
    cin>>customerID;

    //get start and end date then calculate it in days
    int startDate,endDate;
    newreserv->inputStart();
    newreserv->inputEnd();
    startDate= newreserv->toDays(newreserv->getStartDate());
    endDate  = newreserv->toDays(newreserv->getEndDate());
    //set all rental agreement attributes (according to the car he chose)
    double rental=carList[carID-1]->getRentalRate()*(endDate-startDate);
    double total =rental+carList[carID-1]->getInsuranceCharges() + carList[carID-1]->getTaxes();
    newRent->setRentalPeriod(endDate-startDate);
    newRent->setRentalRate(carList[carID-1]->getRentalRate());
    newRent->setInsuranceCharges(carList[carID-1]->getInsuranceCharges());
    newRent->setRentalCharges( rental  );
    //set all invoice attributes (according to the car he chose)
    newInvoice->setTaxes(carList[carID-1]->getTaxes());
    newInvoice->setRentalCharges( rental );
    newInvoice->setTotalAmountDue( total);
    //set rental agreement ,invoice ,customer and car to this reservation
    newreserv->setCar(carList[carID-1]);
    newreserv->setRentAgree(newRent);
    newreserv->setInvoice(newInvoice);
    newreserv->setCustomer(customerList[customerID-1]);

    cout<<"This Reservation ID : "<<reservCount+1<<endl;
    reservList[reservCount++]=newreserv;
    cout<<*reservList[reservCount-1];
    _getch();
}
void CarRentalSystem::endReservation()
{
    int reservationID=0;
    cout<<"Enter Reservation ID : ";
    cin>>reservationID;
    int startDate,actualDate,actualPeriod,reservPeriod;
    //get Period he should return car in
    reservPeriod=reservList[reservationID-1]->getRentAgree()->getRentalPeriod();
    //calculate reservation period then calculate actual Period he returned it in
    reservList[reservationID-1]->inputEnd();
    startDate= reservList[reservationID-1]->toDays(reservList[reservationID-1]->getStartDate());
    actualDate= reservList[reservationID-1]->toDays(reservList[reservationID-1]->getEndDate());
    actualPeriod=actualDate-startDate;

    int totalAmount,rental,additionalCharges=0;
    totalAmount = reservList[reservationID-1]->getInvoice()->getTotalAmountDue();
    rental = reservList[reservationID-1]->getInvoice()->getRentalCharges();
    //a fine for late return
    if(actualPeriod>reservPeriod)
    {
        cout<<"======================================"<<endl;
        cout<<"you are late ("<<actualPeriod-reservPeriod<<") days"<<endl;
        cout<<"You will be charged a fine equal to double the rental rate multiplied by the additional duration"<<endl;
        additionalCharges=  (reservList[reservationID-1]->getRentAgree()->getRentalRate() )*(actualPeriod-reservPeriod)*2;
        cout<<"Old Rental Charges = "<<rental<<endl;
        cout<<"Additional Rental Charges = "<<additionalCharges<<endl;
        cout<<"======================================"<<endl;
    }
    //add additionalCharges if there is
    rental+=additionalCharges;
    totalAmount+=additionalCharges;
    Invoice* newInvoice=new Invoice();
    RentalAgreement* newRent=new RentalAgreement();
    newInvoice =reservList[reservationID-1]->getInvoice();
    newRent = reservList[reservationID-1]->getRentAgree();
    //change rental charges if there is additional charges
    newInvoice->setRentalCharges(rental );
    newInvoice->setTotalAmountDue(totalAmount);
    newRent->setRentalCharges(rental );
    newRent->setRentalPeriod(actualPeriod );
    //change this reservation rental agreement and invoice if there is additional rent
    reservList[reservationID-1]->setRentAgree(newRent);
    reservList[reservationID-1]->setInvoice(newInvoice);
    cout<<*reservList[reservationID-1];

    _getch();
    for(int i=0 ; i<carCount; i++)
    {
        if(reservList[reservationID-1]->getCar()==carList[i])
        {
            carList[i]->setAvailability(true);
        }
    }
}

void CarRentalSystem::RentalHistory()
{
    int choice=-1;
    cout << "1. For a Car" << endl;
    cout << "2. For a Customer" << endl;
    cin>>choice;
    if(choice==1)
    {
        int carID=0;
        cout<<"Enter Car ID : ";
        cin>>carID;

        for(int i=0 ; i<reservCount; i++)
        {
            if(reservList[i]->getCar()==carList[carID-1])
            {
        cout<<"**********************************"<<endl;
        cout<<"reservation ID -----> ("<<i+1<<")"<<endl;
        cout<<*reservList[i];
        cout<<"**********************************"<<endl;
        }
        }

    }
    else if(choice == 2)
    {
        int customerID=0;
        cout<<"Enter Customer ID : ";
        cin>>customerID;

        for(int i=0 ; i<reservCount; i++)
        {
            if(reservList[i]->getCustomer()==customerList[customerID-1])
            {
        cout<<"**********************************"<<endl;
        cout<<"reservation ID -----> ("<<i+1<<")"<<endl;
        cout<<*reservList[i];
        cout<<"**********************************"<<endl;            }
        }
    }
}
void CarRentalSystem::Payment()
{
    int reservationID=0;
    cout<<"Enter Reservation ID : ";
    cin>>reservationID;

    double total =reservList[reservationID-1]->getInvoice()->getTotalAmountDue();
    if(total == 0 )
    {
        cout<<"The invoice already has been paid.";
        return;
    }
    double paid,remain=0;
    cout<<"Total Invoice to Pay : "<<total<<endl;
    cout<<"Pay : ";
    cin>>paid;
    //operator overloading
    remain=total-paid;
    Invoice* newInvoice=new Invoice();
    newInvoice = reservList[reservationID-1]->getInvoice();
    if( remain > 0)
    {
        cout<<"The remaining amount to Pay is "<<remain;
        newInvoice->setTotalAmountDue(remain);
    }
    else if (remain < 0)
    {
        cout<<"The remaining amount for u sir is "<<remain*-1;
        newInvoice->setTotalAmountDue(0);
    }
    else
    {
        cout<<"The invoice has been successfully paid.";
        newInvoice->setTotalAmountDue(0);
    }
    //update invoice
    reservList[reservationID-1]->setInvoice(newInvoice);
}

void CarRentalSystem::generateReport()
{
    // Print the list of cars
    cout << "=== Car Report ===" << endl;
    for (int i = 0; i < carCount; i++)
    {
        cout << "Car ID: " << i + 1 << endl;
        cout << *carList[i] << endl;
        cout<<"================================="<<endl;
    }

    if(carCount == 0 )
    {
        cout<<"No Cars Has been Founded in the system."<<endl;
    }

    // Print the list of customers
    cout << "=== Customer Report ===" << endl;
    for (int i = 0; i < customerCount; i++)
    {
        cout << "Customer ID: " << i + 1 << endl;
        cout << *customerList[i] << endl;
        cout<<"================================="<<endl;
    }

    if(customerCount == 0 )
    {
        cout<<"No Customers Has been Founded in the system."<<endl;
    }

    // Print the list of reservations
    cout << "=== Reservation Report ===" << endl;
    for (int i = 0; i < reservCount; i++)
    {
        cout << "Reservation ID: " << i + 1 << endl;
        cout << *reservList[i] << endl;
        cout<<"================================="<<endl;
    }

    if(reservCount == 0 )
    {
        cout<<"No Reservations Has been Founded in the system."<<endl;
    }

}
