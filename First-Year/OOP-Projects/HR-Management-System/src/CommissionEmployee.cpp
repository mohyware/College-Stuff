#include "CommissionEmployee.h"
    // constructor
    CommissionEmployee::CommissionEmployee()
    {
        target=0.0;
        rate=0.0;
    }
    // Setters
    void CommissionEmployee::setTarget(double target)
    {
        this->target = target;
    }

    void CommissionEmployee::setRate(double rate)
    {
        this->rate = rate;
    }

    // Getters
    double CommissionEmployee::getTarget() const
    {
        return target;
    }

    double CommissionEmployee::getRate() const
    {
        return rate;
    }

    double CommissionEmployee::getSalary()
    {
        return target * rate;
    }

    // Other method
    string CommissionEmployee::getDetails()
    {
        string result =string("-----> Type: Commission Employee\n" )+ "Target: " + to_string(target) + ", Rate: " + to_string(rate) +"\n";
        result += "Total Salary: $" + to_string(getSalary()) + "\n";
        return result ;
    }

    double CommissionEmployee::calculatePay()
    {
        return getSalary() + calcBenefits();
    }

    void CommissionEmployee::inputData()
    {
        Employee::inputData();
        cout<<"----- > Special info for Commission Employee"<<endl;
        cout << "Enter target: ";
        cin >> target;
        cout << "Enter rate: ";
        cin >> rate;
    }

    void CommissionEmployee::editData()
    {
        Employee::editData();
        string trg,rt;
        cout<<"----- > Special info for Commission Employee"<<endl;
        cout << "Enter new target (or press Enter to keep current value): ";
        getline(cin, trg);
        if(!trg.empty())
            double target = stod(trg);

        cout << "Enter new rate (or press Enter to keep current value): ";
        getline(cin, rt);
        if(!rt.empty())
            double rate = stod(rt);
    }

