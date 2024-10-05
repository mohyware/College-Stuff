#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
using namespace std;
class Customer
{
private:
    string name;
    string address;
    string phone_number;
public:
    Customer();
    //getters
    string getName() const;
    string getAddress() const;
    string getPhoneNumber() const;
    //setters
    void setName(const string& newName);
    void setAddress(const string& newAddress);
    void setPhoneNumber(const string& newPhoneNumber);

    //other methods
    void inputData();
    void editData();
    bool operator==(const Customer& other) const;
    friend ostream& operator<<(ostream& os, const Customer& customer) ;

};



#endif // CUSTOMER_H
