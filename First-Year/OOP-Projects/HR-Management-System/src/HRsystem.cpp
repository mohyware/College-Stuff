#include "HRsystem.h"

using namespace std;

// Default constructor
HRsystem::HRsystem(int empSize,int departSize)
{
    employeeCount = 0;
    employeeSize = empSize;
    employeeList = new Employee*[employeeSize];

    departCount =0 ;
    departSize =departSize;
    departList =new Department*[departSize];
}

// Destructor
HRsystem::~HRsystem()
{
    for(int i=0; i<employeeCount; i++)
    {
        delete employeeList[i];
    }

    delete [] employeeList;

    for(int i=0; i<departCount; i++)
    {
        delete departList[i];
    }

    delete [] departList;
}

// Getters
int HRsystem::getEmployeeCount() const
{
    return employeeCount;
}

// Other methods

void HRsystem::calcTotalPayroll()
{
    bool exitMenu = false;
    double totalPayroll = 0;

    int choice;

    do
    {
        cout << "(1) -Calculate Payroll Menu :" << endl;
        cout << "-------------------------" << endl;
        cout << "1. For Department" << endl;
        cout << "2. All Employees" << endl;
        cout << "0. Exit Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice==1)
        {
            int depart_Indx=-1;
            depart_Indx=getDepart_Indx();
            if(depart_Indx == -1)
            {
                cout << "Exiting the Calculate Payroll Menu " << endl;
                _getch();
                return;
            }
            system("cls");
            for(int i=0; i<employeeCount; i++)
            {
                if(employeeList[i]->getDepartment()!=nullptr)
                    if(employeeList[i]->getDepartment()->getDepartiD()==departList[depart_Indx]->getDepartiD())
                    {
                        totalPayroll += employeeList[i]->calculatePay();
                    }
            }
            break;
        }
        else if(choice==2)
        {
            for(int i=0; i<employeeCount; i++)
            {
                totalPayroll += employeeList[i]->calculatePay();
            }
            break;
        }
        else if(choice==0)
            exitMenu = true;
        else
            cout << "Invalid choice! Please try again." << endl;
        _getch();
        system("cls");
    }
    while(!exitMenu);

    cout << "Total payroll: $" << totalPayroll << endl;
        _getch();
}

void HRsystem::calcAverage()
{
    bool exitMenu = false;
    double totalPayroll = 0,empNUM=0;
    int choice;
    do
    {
        cout << "(1) -Calculate Average Salaries Menu :" << endl;
        cout << "-------------------------" << endl;
        cout << "1. For Department" << endl;
        cout << "2. All Employees" << endl;
        cout << "0. Exit Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice==1)
        {
            int depart_Indx=-1;
            depart_Indx=getDepart_Indx();
            if(depart_Indx == -1)
            {
                cout << "Exiting the Calculate Average Salaries Menu " << endl;
                _getch();
                return;
            }
            system("cls");
            for(int i=0; i<employeeCount; i++)
            {
                if(employeeList[i]->getDepartment()!=nullptr)
                    if(employeeList[i]->getDepartment()->getDepartiD()==departList[depart_Indx]->getDepartiD())
                    {
                        totalPayroll += employeeList[i]->getSalary();
                        empNUM++;
                    }
            }
        break;
        }
        else if(choice==2)
        {
            for(int i=0; i<employeeCount; i++)
            {
                totalPayroll += employeeList[i]->getSalary();
                empNUM++;
            }
        break;
        }
        else if(choice==0)
            exitMenu = true;
        else
            cout << "Invalid choice! Please try again." << endl;
        _getch();
        system("cls");
    }
    while(!exitMenu);
    cout << "Average Salaries: $" << (double)totalPayroll/empNUM << endl;
        _getch();
}
void HRsystem::addEmployee()
{
    Employee* newEmployee = nullptr;
    int employeeType=-1;

    cout << "Enter employee type:\n"
         <<"1.Commission"<<endl
         <<"2.Salaried"<<endl
         <<"3.Manager"<<endl
         <<"4.Hourly"<<endl
         <<"0.Exit this menu"<<endl;
    do
    {
        cin >> employeeType;
        if (employeeType == 1)
        {
            newEmployee = new CommissionEmployee();
            newEmployee->inputData();
        }
        else if (employeeType == 2)
        {
            newEmployee = new SalariedEmployee();
            newEmployee->inputData();
        }
        else if (employeeType == 3)
        {
            newEmployee = new ManagerEmployee();
            newEmployee->inputData();
        }
        else if (employeeType == 4)
        {
            newEmployee = new HourlyEmployee();
            newEmployee->inputData();
        }
        else if (employeeType == 0)
        {
            return;
        }
        else
        {
            cout<<"Enter valid Number Please!!!"<<endl;
        }
    }
    while( !(employeeType > 0 && employeeType < 5 ) );

    employeeList[employeeCount] = newEmployee;
    employeeCount++;

    cout << "Employee added successfully!" << endl;
}

void HRsystem::editEmployee()
{
    if(employeeCount == 0)
    {
        cout << "No employees found!" << endl;
        return;
    }

    string name;
    cout << "Enter employee name to edit: ";
    cin >> name;

    cin.ignore();
    for(int i=0; i<employeeCount; i++)
    {
        if(employeeList[i]->getName() == name)
        {
            employeeList[i]->editData();
            cout << "Employee updated successfully!" << endl;
            return;
        }
    }
    cout << "Employee not found!" << endl;
}


void HRsystem::delEmployee()
{
    string name;
    cout << "Enter employee name to delete: ";
    cin >> name;

    for (int i = 0; i < employeeCount; i++)
    {
        if (employeeList[i]->getName() == name)
        {
            delete employeeList[i];
            // Shift all elements after the deleted element back by one index
            for (int j = i; j < employeeCount - 1; j++)
            {
                employeeList[j] = employeeList[j+1];
            }
            // Set the last element to null
            employeeList[employeeCount - 1] = nullptr;
            employeeCount--;
            cout << "Employee with Name " << name << " has been deleted." << endl;
            return;
        }
    }
    cout << "Employee : " << name << " not found." << endl;
}



void HRsystem::addDepart()
{
    Department* newDepart = nullptr;
    newDepart = new Department();
    int id=-1;
    bool replication=true;
    while(replication)
    {
        replication=false;
        newDepart->inputData();
        id=newDepart->getDepartiD();
        for (int i = 0; i < departCount; i++)
        {
            if(departList[i]->getDepartiD()==id)
                replication = true;
        }
        if(replication)
            cout<<"there is already a department with this id Enter New one:"<<endl;
    }

    departList[departCount] = newDepart;
    departCount++;
    cout << "Department added successfully!" << endl;
}

void HRsystem::editDepart()
{
    if(departCount == 0)
    {
        cout << "No Department found!" << endl;
        return;
    }

    int id;
    cout << "Enter Department id to edit: ";
    cin >> id;

    Department* NewDepart = NULL;
    cin.ignore();
    for(int i=0; i<departCount; i++)
    {
        if(departList[i]->getDepartiD() == id)
        {
            departList[i]->editData();
            NewDepart = departList[i];
            cout << "Department updated successfully!" << endl;
            return;
        }
    }

    //set all emps in this depart with New data
    for (int i = 0; i < employeeCount; i++)
    {
        if(employeeList[i]->getDepartment()!=nullptr)
        {
            if (employeeList[i]->getDepartment()->getDepartiD() == id)
            {
                employeeList[i]->setDepartment(NewDepart);
            }
        }
    }
    cout << "Department not found!" << endl;
}


void HRsystem::delDepart()
{
    int id;
    cout << "Enter Department id to edit: ";
    cin >> id;
    //set all emps in this depart with null
    for (int i = 0; i < employeeCount; i++)
    {
        if(employeeList[i]->getDepartment()!=nullptr)
        {

            if (employeeList[i]->getDepartment()->getDepartiD() == id)
            {
                Department* NullDepart = NULL;
                employeeList[i]->setDepartment(NullDepart);
            }
        }
    }
    cout<<"error"<<endl;

    for (int i = 0; i < departCount; i++)
    {
        if (departList[i]->getDepartiD() == id)
        {
            delete departList[i];
            // Shift all elements after the deleted element back by one index
            for (int j = i; j < departCount - 1; j++)
            {
                departList[j] = departList[j+1];
            }
            // Set the last element to null
            departList[departCount - 1] = NULL;
            departCount--;
            cout << "Department with id " << id << " has been deleted." << endl;
            return;
        }
    }
    cout << "Department : " << id << " not found." << endl;
}


int HRsystem::getEmp_Indx()
{

    while(true)
    {

        int index=-1;
        int findCount=0;
        bool found = false;
        string searchStr;
        cout << "Enter 0 to exit : "<<endl;
        cout << "Enter a field to search by (name, phone, email, jobTitle): ";
        cin >> searchStr;

        for (int i = 0; i < employeeCount; i++)
        {
            Employee* emp = employeeList[i];
            if (emp->getName() == searchStr ||
                    emp->getPhone() == searchStr ||
                    emp->getEmail() == searchStr ||
                    emp->getJobTitle() == searchStr)
            {
                cout << "Emp ( "<<findCount+1<<" ) ***************" << endl;
                cout << "Emp Index is ( "<<i+1<<" )" << endl;
                if(emp->getDepartment()!=NULL)
                    emp->getDepartment()->Print();
                cout<<emp->displayDetails();
                cout << "-----------" << endl;
                cout<<emp->getDetails();
                cout << "*************************" << endl;
                findCount++;
                found = true;
            }
        }
        if(searchStr == "0")
            return -1;

        while(findCount)
        {
            cout<<"Enter employee Index :";
            cin>>index;
            for (int i = 0; i < employeeCount; i++)
            {
                Employee* emp = employeeList[i];
                if (emp->getName() == searchStr ||
                        emp->getPhone() == searchStr ||
                        emp->getEmail() == searchStr ||
                        emp->getJobTitle() == searchStr)
                {
                    if(index-1==i)
                        return index-1;
                }
            }
            cout << "No matching index found! " << endl;
        }

        if (!found)
        {
            cout << "No matching employees found." << endl;
        }

    }
    return -1;
}

int HRsystem::getDepart_Indx()
{

    while(true)
    {

        int index=-1;
        int findCount=0;
        bool found = false;
        int id;
        cout << "Enter 0 to exit : "<<endl;
        cout << "Enter department ID: ";
        cin >> id;
        if(id == 0)
            return -1;

        for (int i = 0; i < departCount; i++)
        {
            Department* depart = departList[i];
            if (depart->getDepartiD() == id)
            {
                cout << "depart ( "<<findCount+1<<" ) ***************" << endl;
                cout << "depart Index is ( "<<i+1<<" )" << endl;
                depart->Print();
                cout << "*************************" << endl;
                findCount++;
                found = true;
            }
        }

        while(findCount)
        {
            cout<<"Enter depart Index :";
            cin>>index;
            for (int i = 0; i < departCount; i++)
            {
                Department* depart = departList[i];
                if (depart->getDepartiD() == id)
                {
                    if(index-1==i)
                        return index-1;
                }
            }
            cout << "No matching index found! " << endl;
        }

        if (!found)
        {
            cout << "No matching departs found." << endl;
        }

    }
    return -1;
}


void HRsystem::findEmployee()
{

    int findCount=0;
    bool found = false;

    string searchStr;
    cout << "Enter a field to search by (name, phone, email, jobTitle): ";
    cin >> searchStr;

    for (int i = 0; i < employeeCount; i++)
    {
        Employee* emp = employeeList[i];
        if (emp->getName() == searchStr ||
                emp->getPhone() == searchStr ||
                emp->getEmail() == searchStr ||
                emp->getJobTitle() == searchStr)
        {
            cout << "Emp ( "<<findCount+1<<" ) ***************" << endl;
            if(emp->getDepartment()!=NULL)
                emp->getDepartment()->Print();
            cout<<emp->displayDetails();
            cout << "-----------" << endl;
            cout<<emp->getDetails();
            cout << "*************************" << endl;
            findCount++;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No matching employees found." << endl;
        return;
    }
    cout<<"found ("<<findCount<<") employees."<<endl;
}

void HRsystem::printDepart()
{

    int findCount=0;
    bool found = false;

    int id;
    cout << "Enter Department ID: ";
    cin >> id;

    for (int i = 0; i < employeeCount; i++)
    {
        Employee* emp = employeeList[i];
        if(emp->getDepartment()!=NULL)
        {

            if (emp->getDepartment()->getDepartiD() == id )
            {
                cout << "Emp ( "<<findCount+1<<" ) ***************" << endl;
                cout<<emp->displayDetails();
                cout << "-----------" << endl;
                cout<<emp->getDetails();
                cout << "*************************" << endl;
                findCount++;
                found = true;
            }
        }
    }

    if (!found)
    {
        cout << "No matching employees found." << endl;
        return;
    }
    cout<<"found ("<<findCount<<") employees."<<endl;
}

void HRsystem::printAllDeparts()
{

    int findCount=0;
    bool found = false;

    for (int i = 0; i < departCount; i++)
    {
        cout << "Department ( "<<findCount+1<<" ) ***************" << endl;
        departList[i]->Print();
        cout << "*************************" << endl;
        findCount++;
        found = true;
    }

    if (!found)
    {
        cout << "No matching departs found." << endl;
        return;
    }
    cout<<"found ("<<findCount<<") departs."<<endl;
}

void HRsystem::printAll()
{
    int findCount=0;

    for (int i = 0; i < employeeCount; i++)
    {
        Employee* emp = employeeList[i];
        cout << "Emp ( "<<findCount+1<<" ) ***************" << endl;
        if(emp->getDepartment()!=NULL)
            emp->getDepartment()->Print();
        cout<<emp->displayDetails();
        cout << "-----------" << endl;
        cout << "have ( "<<emp->getBenefit_count()<<" )Benefits " << endl;
        cout << "-----------" << endl;
        cout<<emp->getDetails();
        cout << "*************************" << endl;
        findCount++;
    }

    cout<<"There are ("<<findCount<<") employees in System."<<endl;
}

void HRsystem::EmployeeMenu()
{
    bool exitMenu = false;
    int choice;

    do
    {
        cout << "(1) -Employee Menu :" << endl;
        cout << "-------------------------" << endl;
        cout << "1. Add employee" << endl;
        cout << "2. Edit employee" << endl;
        cout << "3. Delete employee" << endl;
        cout << "4. Find employee" << endl;
        cout << "0. Exit Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(employeeCount == 0 && !(choice== 1 || choice==0) )
        {
            cout << "No employees in system!" << endl;
            _getch();
            system("cls");
            continue;
        }

        switch(choice)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            editEmployee();
            break;
        case 3:
            delEmployee();
            break;
        case 4:
            findEmployee();
            break;
        case 0:
            exitMenu = true;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
        _getch();
        system("cls");
    }
    while(!exitMenu);
}


void HRsystem::BenefitMenu()
{
    int index=-1;
    index=getEmp_Indx();
    if(index == -1)
    {
        cout << "Exiting the Benefit Menu " << endl;
        return;
    }
    system("cls");
    bool exitMenu = false;
    int choice;

    do
    {
        cout << "(1) -Benefit Menu :" << endl;
        cout << "-------------------------" << endl;
        cout << "1. Add Benefit" << endl;
        cout << "2. Edit Benefit" << endl;
        cout << "3. Delete Benefit" << endl;
        cout << "4. print All Benefit for this employee" << endl;
        cout << "0. Exit Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            employeeList[index]->addBenefits();
            break;
        case 2:
            employeeList[index]->EditBenefit();
            break;
        case 3:
        {
            int delIndx=-1;
            cout<<"enter Benefit index to delete: ";
            cin>>delIndx;
            employeeList[index]->delBenefit(delIndx-1);
        }
        break;
        case 4:
            employeeList[index]->printAllBenefits();
            break;
        case 0:
            exitMenu = true;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
        _getch();
        system("cls");
    }
    while(!exitMenu);
}



void HRsystem::AddToDepart()
{
    int emp_Indx=-1;
    emp_Indx=getEmp_Indx();
    if(emp_Indx == -1)
    {
        cout << "Exiting the AddToDepart Menu " << endl;
        _getch();
        return;
    }
    system("cls");

    int depart_Indx=-1;
    depart_Indx=getDepart_Indx();
    if(depart_Indx == -1)
    {
        cout << "Exiting the AddToDepart Menu " << endl;
        _getch();
        return;
    }
    system("cls");

    employeeList[emp_Indx]->setDepartment(departList[depart_Indx]);

    cout << "Employee Added successfully." ;
}
void HRsystem::RemoveFromDepart()
{
    int emp_Indx=-1;
    emp_Indx=getEmp_Indx();
    if(emp_Indx == -1)
    {
        cout << "Exiting the RemoveFromDepart Menu " << endl;
        return;
    }
    system("cls");

    employeeList[emp_Indx]->setDepartment(NULL);

    cout << "Employee Removed successfully." ;

}

void HRsystem::departMenu()
{
    bool exitMenu = false;
    int choice;

    do
    {
        cout << "(1) -Department Menu :" << endl;
        cout << "-------------------------" << endl;
        cout << "1. Add Department" << endl;
        cout << "2. Edit Department" << endl;
        cout << "3. Delete Department" << endl;
        cout << "-------------------------" << endl;
        cout << "4. Print Department Employees" << endl;
        cout << "5. Print All Departments" << endl;
        cout << "-------------------------" << endl;
        cout << "6. Add Employee to Department" << endl;
        cout << "7. Remove Employee from Department" << endl;
        cout << "0. Exit Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
            addDepart();
            break;
        case 2:
            editDepart();
            break;
        case 3:
            delDepart();
            break;
        case 4:
            printDepart();
            break;
        case 5:
            printAllDeparts();
            break;
        case 6:
            AddToDepart();
            break;
        case 7:
            RemoveFromDepart();
            break;
        case 0:
            exitMenu = true;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
        _getch();
        system("cls");
    }
    while(!exitMenu);
}
