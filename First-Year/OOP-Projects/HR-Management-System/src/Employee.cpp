#include "Employee.h"

    // Default constructor
    Employee::Employee()
    {
        name = "";
        phone = "";
        email = "";
        jobTitle = "";
        Benefit_count =0;
        Benefit_size = 10;
        benefitList = new Benefit*[Benefit_size];
        department = NULL;
    }


    // Getters
    string Employee::getName() const
    {
        return name;
    }

    string Employee::getPhone() const
    {
        return phone;
    }

    string Employee::getEmail() const
    {
        return email;
    }

    string Employee::getJobTitle() const
    {
        return jobTitle;
    }

    int Employee::getBenefit_count() const
    {
        return Benefit_count;
    }

    Department* Employee::getDepartment()
    {
        return department;
    }

    // Setters
    void Employee::setDepartment(Department* dept)
    {
        department = dept;
    }
    void Employee::setName(string name)
    {
        this->name = name;
    }

    void Employee::setPhone(string phone)
    {
        this->phone = phone;
    }

    void Employee::setEmail(string email)
    {
        this->email = email;
    }

    void Employee::setJobTitle(string jobTitle)
    {
        this->jobTitle = jobTitle;
    }

    // Other methods

    double Employee::calculatePay()
    {
        return 0;
    }

    string Employee::displayDetails()
    {
        string output = "Name: " + name + "\n";
        output += "Phone: " + phone + "\n";
        output += "Email: " + email + "\n";
        output += "Job Title: " + jobTitle + "\n";
        return output;
    }
    double Employee::getSalary()
    {
        return 0;
    }

    string Employee::getDetails()
    {
        return " ";
    }

    void Employee::inputData()
    {
        cout << "Enter name: ";
        cin >> name;

        cout << "Enter phone: ";
        cin >> phone;

        cout << "Enter email: ";
        cin >> email;

        cout << "Enter job title: ";
        cin >> jobTitle;
    }

    void Employee::editData()
    {
        cout << "Enter new name (or press Enter to keep current value): ";
        string newName;
        getline(cin, newName);
        if(!newName.empty())
        {
            setName(newName);
        }

        cout << "Enter new phone (or press Enter to keep current value): ";
        string newPhone;
        getline(cin, newPhone);
        if(!newPhone.empty())
        {
            setPhone(newPhone);
        }

        cout << "Enter new email (or press Enter to keep current value): ";
        string newEmail;
        getline(cin, newEmail);
        if(!newEmail.empty())
        {
            setEmail(newEmail);
        }

        cout << "Enter new job title (or press Enter to keep current value): ";
        string newJobTitle;
        getline(cin, newJobTitle);
        if(!newJobTitle.empty())
        {
            setJobTitle(newJobTitle);
        }
    }

    double Employee::calcBenefits()
    {
        double totalAmount = 0;
        for (int i = 0; i < Benefit_count; i++)
        {
            totalAmount += benefitList[i]->calculateBenefit();
        }
        return totalAmount;
    }


    void Employee::addBenefits()
    {
        while(Benefit_count<Benefit_size)
        {
            cout<<"Enter benefit type: \n";
            cout<<"1. Health Benefit\n";
            cout<<"2. Dental Benefit\n";
            cout<<"0. Exit Benefit Menu\n";
            int type=-1;
            cin>>type;
            if(type == 1)
            {
                benefitList [Benefit_count] = new HealthBenefit();
                benefitList [Benefit_count]->inputData();
                Benefit_count++;
            }
            else if (type == 2)
            {
                benefitList [Benefit_count] = new DentalBenefit();
                benefitList [Benefit_count]->inputData();
                Benefit_count++;
            }
            else if (type == 0)
            {
                return;
            }
            else
            {
                cout<<"Please enter valid Number!!!"<<endl;
            }
        }
    }

    void Employee::EditBenefit()
    {

        int editIndx=-1;
        while(1)
        {
            cout<<"Enter benefit index u want to edit: \n";
            cin>>editIndx;
            editIndx--;
            if(!(editIndx>Benefit_count && editIndx<0))
            {
                break;
            }
            cout<<"Please Enter Valid Benefit Number!!!\n";
        }
            benefitList [editIndx]->editData();
        }

    void Employee::delBenefit(int delIndx)
    {
        if(!(delIndx>Benefit_count && delIndx<0))
        {
            delete benefitList[delIndx];
            // Shift all elements after the deleted element back by one index
            for (int j = delIndx; j < Benefit_count - 1; j++)
            {
                benefitList[j] = benefitList[j+1];
            }
            // Set the last element to null
            benefitList[Benefit_count - 1] = nullptr;
            Benefit_count--;
            cout << "benefit with Index " << delIndx+1 << " has been deleted." << endl;
            return;
        }
        cout << "benefit : " << delIndx << " not found." << endl;
    }

    void Employee::printAllBenefits()
    {
        for(int i = 0; i < Benefit_count; i++)
        {
            cout << "benefit ( "<<i+1<<" ) **********" << endl;
            cout<<benefitList[i]->displayBenefit();
            cout << "-----------" << endl;
            cout<<benefitList[i]->getDetails();
            cout << "*************************" << endl;

        }
    }
