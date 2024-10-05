#include "ManagerEmployee.h"

    // constructor
    ManagerEmployee::ManagerEmployee()
    {
        bonus=0.0;
    }
    // Getters
    double ManagerEmployee::getBonus()
    {
        return bonus;
    }
    double ManagerEmployee::getSalary()
    {
        return salary + bonus;
    }
    string ManagerEmployee::getDetails()
    {
        string result=string("-----> Type: Manager Employee\n" )+ "bonus: " + to_string(bonus) + "\n";
        result += "salary: $" + to_string(salary) + "\n";
        result += "Total Salary: $" + to_string(getSalary()) + "\n";
        return result;
    }
    // Setters
    void ManagerEmployee::setBonus(double newBonus)
    {
        bonus = newBonus;
    }
    // Other method
    void ManagerEmployee::addBonus(double moreBonus)
    {
        bonus += moreBonus;
    }

    double ManagerEmployee::calculatePay()
    {
        return getSalary() + calcBenefits();
    }

    void ManagerEmployee::inputData()
    {
        Employee::inputData();
        cout<<"----- > Special info for Manager Employee"<<endl;
        cout << "Enter salary: ";
        cin >> salary;
        cout << "Enter bonus: ";
        cin >> bonus;
    }

    void ManagerEmployee::editData()
    {
        Employee::editData();
        string bon,sal;
        cout<<"----- > Special info for Manager Employee"<<endl;
        cout << "Enter new salary (or press Enter to keep current value): ";
        getline(cin, sal);
        if(!sal.empty())
            double salary = stod(sal);

        cout << "Enter new bonus (or press Enter to keep current value): ";
        getline(cin, bon);
        if(!bon.empty())
            double bonus = stod(bon);
    }
