#include "DentalBenefit.h"

    // Constructor
    DentalBenefit::DentalBenefit()
    {
        info = "";
    }

    // Getter
    string DentalBenefit::getInfo() const
    {
        return info;
    }

    // Setter
    void DentalBenefit::setInfo(string info)
    {
        this->info = info;
    }

    // Other methods
    double DentalBenefit::calculateBenefit()
    {
        return amount*0.10; // calculation
    }

    string DentalBenefit::getDetails()
    {
        string result = "Dental Benefit Information: " + info + "\n";
        result += "Calculated Benefit Amount: $" + to_string(calculateBenefit()) + "\n";
        return result;
    }

    void DentalBenefit::inputData()
    {
        Benefit::inputData();
        cout<<"----- > Special info for Dental Benefit"<<endl;
        cout<<"Enter info:  ";
        cin>>info;
    }

    void DentalBenefit::editData()
    {
        Benefit::editData();
        string in;
        cout<<"----- > Special info for Dental Benefit"<<endl;
        cout << "Enter new info (or press Enter to keep current value): ";
        getline(cin, in);
        if(!in.empty())
            info=in;

    }
