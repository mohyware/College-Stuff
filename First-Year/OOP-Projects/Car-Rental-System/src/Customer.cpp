#include "Customer.h"


Customer::Customer()
{
    name="";
    address="";
    phone_number="";
}
//getters
string Customer::getName() const
{
    return name;
}
string Customer::getAddress() const
{
    return address;
}
string Customer::getPhoneNumber() const
{
    return phone_number;
}
//setters
void Customer::setName(const string& newName)
{
    name = newName;
}

void Customer::setAddress(const string& newAddress)
{
    address = newAddress;
}

void Customer::setPhoneNumber(const string& newPhoneNumber)
{
    phone_number = newPhoneNumber;
}

//other methods

void Customer::inputData()
{
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter address: ";
    getline(cin, address);

    cout << "Enter phone number: ";
    getline(cin, phone_number);
}

void Customer::editData()
{
    cin.ignore();
    cout << "Enter new name (or press Enter to keep current value): ";
    string newName;
    getline(cin, newName);
    if (!newName.empty())
    {
        name = newName;
    }

    cout << "Enter new address (or press Enter to keep current value): ";
    string newAddress;
    getline(cin, newAddress);
    if (!newAddress.empty())
    {
        address = newAddress;
    }

    cout << "Enter new phone number (or press Enter to keep current value): ";
    string newPhoneNumber;
    getline(cin, newPhoneNumber);
    if (!newPhoneNumber.empty())
    {
        phone_number = newPhoneNumber;
    }
}
bool Customer::operator==(const Customer& other) const
{
    return name == other.name &&
           address == other.address &&
           phone_number == other.phone_number;
}

ostream& operator<<(ostream& os, const Customer& customer)
{
    os << "Name: " << customer.name << endl;
    os << "Address: " << customer.address << endl;
    os << "Phone Number: " << customer.phone_number << endl;
    return os;
}
