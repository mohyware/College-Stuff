#include <iostream>
#include "CarRentalSystem.h" // Assuming CarRentalSystem is the name of your class

using namespace std;

int main()
{
    CarRentalSystem CRT(10,10,10);

    int choice;
    do
    {
        cout << "========= Car Rental System =========" << endl;
        cout << "1.  Add a Car" << endl;
        cout << "2.  Edit a Car" << endl;
        cout << "3.  Delete a Car (Make it Not Available For Reservation)" << endl;
        cout << "=====================================" << endl;
        cout << "4.  Add a Customer" << endl;
        cout << "5.  Edit a Customer" << endl;
        cout << "6.  View All Customers" << endl;
        cout << "=====================================" << endl;
        cout << "7.  Rent a Car" << endl;
        cout << "8.  Return a Car" << endl;
        cout << "9.  View Available Cars" << endl;
        cout << "10. View Rental History" << endl;
        cout << "11. Generate Reports" << endl;
        cout << "12. Payment of invoice" << endl;
        cout << "0.  Exit" << endl;
        cout << "=====================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
        {
            CRT.addCar();
            break;
        }
        case 2:
        {
            CRT.editCar();
            break;
        }
        case 3:
        {
            CRT.DetCar();
            break;
        }
        case 4:
        {
            CRT.addcustomer();
            break;
        }
        case 5:
        {
            CRT.editCustomer();
            break;
        }
        case 6:
        {
            CRT.PrintCustomers();
            break;
        }
        case 7:
        {
            CRT.startReservation();

            break;
        }
        case 8:
        {
            CRT.endReservation();
            break;
        }
        case 9:
        {
            CRT.Available_Cars();
            break;
        }
        case 10:
        {
            CRT.RentalHistory();
            break;
        }
        case 11:
        {
            CRT.generateReport();
            break;
        }
        case 12:
        {
            CRT.Payment();
            break;
        }
        case 0:
        {
            // Exit
            cout << "Exiting the Car Rental System..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }
        _getch();
        system("cls");
    }
    while (choice != 0);

    return 0;
}
/*
1
Toyota
Camry
2021
100
10
100


1
Mercedes-Benz
Camry
2023
500
10
500


1
Chevrolet
Camaro
1969
200
100
50


1
Tesla
Model-S
2021
500
1000
2000



4
ahmed
cairo
011


4
mohy
zagazig
022


4
mohmammed
aswan
055



7
1
1
2023/05/10
2023/05/30



8
1
2023/05/31



*/
