#include "SalariedEmployee.h"


    // constructor
    SalariedEmployee::SalariedEmployee()
    {
        salary = 0.0;
    }

    // Getter
    double SalariedEmployee::getSalary()
    {
        return salary;
    }

    // Setter
    void SalariedEmployee::setSalary(double salary)
    {
        this->salary = salary;
    }

    // Other method
    string SalariedEmployee::getDetails()
    {
        string result = string("-----> Type: Salaried Employee\n" )+ "Salary: $" + to_string(salary) + "\n";
        return result;
    }

    double SalariedEmployee::calculatePay()
    {
        return getSalary() + calcBenefits();
    }

    void SalariedEmployee::inputData()
    {
        Employee::inputData();
        cout<<"----- > Special info for Salaried Employee"<<endl;
        cout << "Enter salary: ";
        cin >> salary;
    }


    void SalariedEmployee::editData()
    {
        Employee::editData();
        string sal;
        cout<<"----- > Special info for Salaried Employee"<<endl;
        cout << "Enter new salary (or press Enter to keep current value): ";
        getline(cin, sal);
        if(!sal.empty())
            double salary = stod(sal);
    }
