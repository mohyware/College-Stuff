#include "Benefit.h"

//using namespace std;
    // Constructor
    Benefit::Benefit()
    {
        planType = "";
        amount = 0.0;
    }

    // Getters
    string Benefit::getPlanType() const
    {
        return planType;
    }

    double Benefit::getAmount() const
    {
        return amount;
    }

    // Setters
    void Benefit::setPlanType(string planType)
    {
        this->planType = planType;
    }

    void Benefit::setAmount(double amount)
    {
        this->amount = amount;
    }

    // Other methods
    double Benefit::calculateBenefit()
    {
        return amount;
    }

    string Benefit::getDetails()
    {
        return " ";
    }

    string Benefit::displayBenefit()
    {
        string result = "Plan Type: " + planType + "\n";
        result += "Amount: $" + to_string(amount) + "\n";
        return result;
    }

    void Benefit::inputData()
    {
        cout<<"Enter plan Type:  ";
        cin>>planType;
        cout<<"Enter amount:  ";
        cin>>amount;
    }

    void Benefit::editData()
    {
        string pt,amnt;

        cout << "Enter new planType (or press Enter to keep current value): ";
        getline(cin, pt);
        if(!pt.empty())
            planType=pt;

        cout << "Enter new amount (or press Enter to keep current value): ";
        getline(cin, amnt);
        if(!amnt.empty())
            double amount = stod(amnt);
    }

