#ifndef HOURSWORKED_H
#define HOURSWORKED_H

#include <iostream>
#include <string>

using namespace std;

class Salary {
private:
    double hoursWorked;
    double rate;

public:
    // Constructor
    Salary(double hoursWorked, double rate) {
        this->hoursWorked = hoursWorked;
        this->rate = rate;
    }

    // Getters
    double getHoursWorked() const {
        return hoursWorked;
    }

    double getRate() const {
        return rate;
    }

    // Setters
    void setHoursWorked(double hoursWorked) {
        this->hoursWorked = hoursWorked;
    }

    void setRate(double rate) {
        this->rate = rate;
    }

    // Other methods
    void addHours(int moreHours) {
        hoursWorked += moreHours;
    }

    double getSalary() {
        // Calculate the salary based on hours worked and hourly rate
        return hoursWorked * rate;
    }

    string getDetails() {
        string result = "Hours Worked: " + to_string(hoursWorked) + "\n";
        result += "Hourly Rate: $" + to_string(rate) + "\n";
        result += "Total Salary: $" + to_string(getSalary()) + "\n";
        return result;
    }
};

#endif // HOURSWORKED_H
