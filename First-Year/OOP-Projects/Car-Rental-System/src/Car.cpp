#include "Car.h"

Car::Car()
{
    name="";
    model="";
    year=0;
    availability=true;

    taxes=0.0;
    rental_rate=0.0;
    insurance_charges=0.0;
}

//getters
string Car::getName() const
{
    return name;
}
string Car::getModel() const
{
    return model;
}
int Car::getYear() const
{
    return year;
}
bool Car::isAvailable() const
{
    return availability;
}
double Car::getTaxes() const
{
    return taxes;
}
double Car::getRentalRate() const
{
    return rental_rate;
}
double Car::getInsuranceCharges() const
{
    return insurance_charges;
}

//setters
void Car::setName(const string& newName)
{
    name = newName;
}

void Car::setModel(const string& newModel)
{
    model = newModel;
}

void Car::setYear(int newYear)
{
    year = newYear;
}

void Car::setAvailability(bool newAvailability)
{
    availability = newAvailability;
}

void Car::setTaxes(double newTaxes)
{
    taxes = newTaxes;
}

void Car::setRentalRate(double newRentalRate)
{
    rental_rate = newRentalRate;
}

void Car::setInsuranceCharges(double newInsuranceCharges)
{
    insurance_charges = newInsuranceCharges;
}

//others
void Car::inputData()
{
    cout << "Enter name: ";
    cin >> name;

    cout << "Enter model: ";
    cin >> model;

    cout << "Enter year: ";
    cin >> year;

    cout << "Enter taxes: ";
    cin >> taxes;

    cout << "Enter rental rate: ";
    cin >> rental_rate;

    cout << "Enter insurance charges: ";
    cin >> insurance_charges;
}

void Car::editData()
{
    cin.ignore();
    cout << "Enter new name (or press Enter to keep current value): ";
    string newName;
    getline(cin, newName);
    if (!newName.empty())
    {
        setName(newName);
    }

    cout << "Enter new model (or press Enter to keep current value): ";
    string newModel;
    getline(cin, newModel);
    if (!newModel.empty())
    {
        setModel(newModel);
    }

    cout << "Enter new year (or press Enter to keep current value): ";
    int newYear;
    cin >> newYear;
    cin.ignore(); // Ignore the newline character in the input buffer
    if (newYear != 0)
    {
        setYear(newYear);
    }

    cout << "Enter new taxes (or press Enter to keep current value): ";
    double newTaxes;
    cin >> newTaxes;
    cin.ignore();
    if (newTaxes != 0)
    {
        setTaxes(newTaxes);
    }

    cout << "Enter new rental rate (or press Enter to keep current value): ";
    double newRentalRate;
    cin >> newRentalRate;
    cin.ignore();
    if (newRentalRate != 0)
    {
        setRentalRate(newRentalRate);
    }

    cout << "Enter new insurance charges (or press Enter to keep current value): ";
    double newInsuranceCharges;
    cin >> newInsuranceCharges;
    cin.ignore();
    if (newInsuranceCharges != 0)
    {
        setInsuranceCharges(newInsuranceCharges);
    }
}

bool Car::operator==(const Car& other) const
{
    return name == other.name &&
           model == other.model &&
           year == other.year &&
           availability == other.availability &&
           taxes == other.taxes &&
           rental_rate == other.rental_rate &&
           insurance_charges == other.insurance_charges;
}

ostream& operator<<(ostream& os, const Car& car)
{
    os << "Name: " << car.name << endl;
    os << "Model: " << car.model << endl;
    os << "Year: " << car.year << endl;
    os << "Availability: " << (car.availability ? "Available" : "Not available") << endl;
    os << "Taxes: " << car.taxes << endl;
    os << "Rental Rate: " << car.rental_rate << endl;
    os << "Insurance Charges: " << car.insurance_charges << endl;
    return os;
}
