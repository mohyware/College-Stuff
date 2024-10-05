#include <iostream>
#include <conio.h>

#include <HRsystem.h>

using namespace std;
HRsystem hrSystem(100,50);

int main()
{
    bool exitProgram = false;
    int choice;

    do
    {
        cout << "HR Management System" << endl;
        cout << "-------------------------" << endl;
        cout << "(1) -Employee Menu" << endl;
        cout << "(2) -Benefit Menu" << endl;
        cout << "(3) -Department Menu" << endl;
        cout << "-------------------------" << endl;
        cout << " 4. Print All" << endl;
        cout << " 5. Calculate payroll" << endl;
        cout << " 6. Calculate Average Salaries" << endl;
        cout << " 0. Exit program" << endl;
        cout << "-------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        system("cls");
        switch(choice)
        {
        case 1:
            hrSystem.EmployeeMenu();
            break;
        case 2:
            hrSystem.BenefitMenu();
            break;
        case 3:
            hrSystem.departMenu();
            break;
        case 4:
        {
            hrSystem.printAll();
            _getch();
        }
        break;
        case 5:
            hrSystem.calcTotalPayroll();
            break;
        case 6:
            hrSystem.calcAverage();
            break;
        case 0:
            exitProgram = true;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
        system("cls");
    }
    while(!exitProgram);

    return 0;

}

/*
1
1
1
ahmed
011
ahmed@gmail.com
programmer
40
40


1
2
mohy
012
mohy@yahoo.com
programmer
2000


1
3
abdo
015
abdo@hotmail.com
doctor
1500
400


1
4
mona
010
mona@gmail.com
engineer
60
10




*/
