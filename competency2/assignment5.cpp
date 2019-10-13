//******************************************************************
//  - Structures - Assignment 5
// Programmer: Mamun Ahmed
// Completed : 10/12/2019
// Status    : Completed
//
// 
// 
// 
// 
// 
//******************************************************************

#include <iostream> // Handle input/output 
#include <iomanip>  // I/O manupulator declarations
#include <string>   // string

using namespace std;

// Employee Structure
struct Employee
{
    int employeeId;
    string employeeName; 
    double employeePayRate;
    int employeeType;
};

// Function Prototypes
void grabEmployeeMasterInfo(Employee &emp, int); // Grab a Single Employees Data
void grabEmployeeTimesheetInfo(); // Grab Timesheet information
void grabAllEmployeeInformation(Employee employees[], int size); // Grab Employee and Timesheet Information
void runPayrollReport(); // Run the Payroll Report 

// Main Function
int main()
{   
    int EMPLOYEE_COUNT = 4; // Employees Array Count
    Employee employees[EMPLOYEE_COUNT]; // Array Employees that Holds Employee Structs
    
    // Grab all Employee Information
    grabAllEmployeeInformation(employees, EMPLOYEE_COUNT);

    // Print Payroll
    runPayrollReport();
    return 0;
}

void grabEmployeeMasterInfo(Employee &emp, int count)
{
    cout << "Enter Information for Employee " << count << endl;
    cout << "Employee Id: ";    
    cin >> emp.employeeId;

    // Use Get Entire Line Here
    cout << "Employee Name: ";    
    cin >> emp.employeeName;
    cout << "Employee Pay Rate: ";
    cin >> emp.employeePayRate;

    while(emp.employeeType != 0 || emp.employeeType != 1){
        cout << "Employee Type (0 or 1): ";
        cin >> emp.employeeType;
        
        cout << emp.employeeType;

        if(emp.employeeType != 0 || emp.employeeType != 1)
        {
            cout << "Please Enter Valid Response!" << endl;
        }
    }
    
    cout << endl;
}

void grabAllEmployeeInformation(Employee employees[], int size)
{
    for(int count=1; count<size+1; count++)
    {
        Employee emp;
        grabEmployeeMasterInfo(emp, count);
        employees[count-1] = emp;
        cout << "\n"; 
    }

}

void grabEmployeeTimesheetInfo()
{

}

void runPayrollReport()
{
    cout << "Running Payroll Report..." << endl;
}

