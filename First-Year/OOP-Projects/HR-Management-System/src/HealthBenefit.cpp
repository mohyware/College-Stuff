#include "HealthBenefit.h"

    // Constructor
    HealthBenefit::HealthBenefit()
    {
        info = "";
        coverage = "";
    }

    // Getters
    string HealthBenefit::getInfo() const
    {
        return info;
    }

    string HealthBenefit::getCoverage() const
    {
        return coverage;
    }

    // Setters
    void HealthBenefit::setInfo(string info)
    {
        this->info = info;
    }

    void HealthBenefit::setCoverage(string coverage)
    {
        this->coverage = coverage;
    }

    // Other methods
    double HealthBenefit::calculateBenefit()
    {
        return amount*0.20; // calculation
    }

    string HealthBenefit::getDetails()
    {
        string result = "Health Benefit Information: " + info + "\n";
        result += "Coverage: " + coverage + "\n";
        result += "Calculated Benefit Amount: $" + to_string(calculateBenefit()) + "\n";
        return result;
    }

    void HealthBenefit::inputData()
    {
        Benefit::inputData();
        cout<<"----- > Special info for Health Benefit"<<endl;
        cout<<"Enter info:  ";
        cin>>info;
        cout<<"Enter coverage:  ";
        cin>>coverage;
    }

    void HealthBenefit::editData()
    {
        Benefit::editData();
        string in,cov;
        cout<<"----- > Special info for Health Benefit"<<endl;
        cout << "Enter new info (or press Enter to keep current value): ";
        getline(cin, info);
        if(!in.empty())
            info=in;

        cout << "Enter new coverage (or press Enter to keep current value): ";
        getline(cin, coverage);
        if(!cov.empty())
            coverage=cov;

    }
