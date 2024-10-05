#include "HourlyEmployee.h"

    // constructor
    HourlyEmployee::HourlyEmployee()
    {
        hoursWorked = 0.0;
        rate = 0.0;
    }
    // Getters
    double HourlyEmployee::getHoursWorked() const
    {
        return hoursWorked;
    }

    double HourlyEmployee::getRate() const
    {
        return rate;
    }

    // Setters
    void HourlyEmployee::setHoursWorked(double hoursWorked)
    {
        this->hoursWorked = hoursWorked;
    }

    void HourlyEmployee::setRate(double rate)
    {
        this->rate = rate;
    }

    // Other methods
    void HourlyEmployee::addHours(int moreHours)
    {
        hoursWorked += moreHours;
    }

    double HourlyEmployee::getSalary()
    {
        // Calculate the salary based on hours worked and hourly rate
        return hoursWorked * rate;
    }


    string HourlyEmployee::getDetails()
    {
        string result = string("-----> Type: Hourly Employee\n" )+ "Hours Worked: " + to_string(hoursWorked) + "\n";
        result += "Hourly Rate: $" + to_string(rate) + "\n";
        result += "Total Salary: $" + to_string(getSalary()) + "\n";
        return result;
    }

    double HourlyEmployee::calculatePay()
    {
        return getSalary() + calcBenefits();
    }

    void HourlyEmployee::inputData()
    {
        Employee::inputData();
        cout<<"----- > Special info for Hourly Employee"<<endl;
        cout << "Enter hours Worked: ";
        cin >> hoursWorked;
        cout << "Enter rate: ";
        cin >> rate;
    }

    void HourlyEmployee::editData()
    {
        Employee::editData();
        string hd,rt;
        cout<<"----- > Special info for Hourly Employee"<<endl;
        cout << "Enter new hours Worked (or press Enter to keep current value): ";
        getline(cin, hd);
        if(!hd.empty())
            double hoursWorked = stod(hd);

        cout << "Enter new rate (or press Enter to keep current value): ";
        getline(cin, rt);
        if(!rt.empty())
            double rate = stod(rt);
    }
