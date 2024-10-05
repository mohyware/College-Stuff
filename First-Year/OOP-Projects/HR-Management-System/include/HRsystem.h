#ifndef HRSYSTEM_H
#define HRSYSTEM_H

#include <conio.h>
#include "Employee.h"
#include "CommissionEmployee.h"
#include "SalariedEmployee.h"
#include "ManagerEmployee.h"
#include "HourlyEmployee.h"

class HRsystem
{
private:
    int employeeCount ;
    int employeeSize ;
    Employee **employeeList;

    int departCount ;
    int departSize ;
    Department **departList;

public:
    //Constructor and Destructor
    HRsystem(int empSize,int departSize);
    ~HRsystem();

    //Menu
    void EmployeeMenu();
    void BenefitMenu ();
    void departMenu();
    //Employee
    void  addEmployee();
    void  editEmployee();
    void  delEmployee();
    void  findEmployee();
    void  printAll() ;
    //Department
    void  addDepart();
    void  editDepart();
    void  delDepart();
    void  printDepart();
    //Employee and Department
    void AddToDepart();
    void RemoveFromDepart();
    void printAllDeparts();
    //get ID
    int  getEmp_Indx();
    int  getDepart_Indx();

    //other
    int  getEmployeeCount() const;
    void  calcTotalPayroll();
    void calcAverage();
};

#endif // HRSYSTEM_H
