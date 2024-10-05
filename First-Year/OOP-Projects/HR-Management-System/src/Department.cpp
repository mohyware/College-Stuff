#include "Department.h"

    Department::Department()
    {
        departiD = 0;
        departName = "";
    }

    //setters

    void Department::setDepartiD(int id)
    {
        departiD = id;
    }

    void Department::setDepartName(const string& name)
    {
        departName = name;
    }
    //getters
    string Department::getDepartName() const
    {
        return departName;
    }

    int Department::getDepartiD() const
    {
        return departiD;
    }
    //other
    void Department::Print() const
    {
        cout << "Department ID: " << departiD << endl;
        cout << "Department Name: " << departName << endl;
    }

    void Department::inputData()
    {
        cout << "Enter Department ID: ";
        cin >> departiD;

        cout << "Enter Department Name: ";
        cin >> departName;
    }

    void Department::editData()
    {
        string id;
        cout << "Enter new Department ID (or press Enter to keep current value): ";
        getline(cin, id);
        if(!id.empty())
        departiD = stoi(id);

        cout << "Enter new Department Name (or press Enter to keep current value): ";
        string departName;
        getline(cin, departName);
        if(!departName.empty())
        {
            setDepartName(departName);
        }

    }
