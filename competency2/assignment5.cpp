//******************************************************************
// Payroll Version 1.0 - Assignment 5
// Programmer: Mamun Ahmed
// Completed : 10/13/2019
// Status    : Completed
//
// 
// Program creates 2 structures. One for employee data and one for
// payroll data. Program grabs user input and has basic validation
// for data to be stored in structs. The input is saved to the structs
// and then subsequently payroll struct is calculated and saved for 
// output at a later time.
//******************************************************************

#include <iostream> // Handle input/output 
#include <iomanip>  // I/O manupulator declarations
#include <string>   // Strings
#include <typeinfo> // Type Information

using namespace std;

// Employee Structure
struct Employee
{
    int employeeId;
    char employeeName[20]; 
    double employeePayRate;
    int employeeType;
};

// Payroll Structure
struct EmployeePayroll
{   
    double employeeHours;
    double employeeTaxPaid;
    double employeeGrossPay;
    double employeeNetPay;
};

// Function Prototypes
void grabAllEmployeeInformation(Employee employees[], int size); // Grab Employee Information
void grabEmployeeTimesheetInfo(Employee employees[], EmployeePayroll employeePayrolls[], int count); // Grab Timesheet information
void grabEmployeeMasterInfo(Employee &emp, int); // Grab a Single Employees Data
void calculatePay(Employee employees[], EmployeePayroll employeePayrolls[], int size); // Calculate Pay Function
void runPayrollReport(Employee employees[], EmployeePayroll employeePayrolls[], int size); // Run the Payroll Report 

// Main Function
int main()
{   
    // Employee Array of Structs
    int EMPLOYEE_COUNT = 4; // Employees Array Count
    Employee employees[EMPLOYEE_COUNT]; // Array Employees that Holds Employee Structs
    // Employee Payroll Array of Structs
    EmployeePayroll employeePayrolls[EMPLOYEE_COUNT]; // Array that holds Employee Payroll data 

    // Data Input Functions
    grabAllEmployeeInformation(employees, EMPLOYEE_COUNT); // Grab all Employee Information
    grabEmployeeTimesheetInfo(employees, employeePayrolls, EMPLOYEE_COUNT); // Match Employees with Time Worked (hours)        
    
    // Print Payroll
    runPayrollReport(employees, employeePayrolls, EMPLOYEE_COUNT);
    return 0;
}

// Grab Employee Information
void grabEmployeeMasterInfo(Employee &emp, int count)
{
    cout << "Enter Information for Employee " << count << endl;

    // Employee ID Validation
    do {
        cout << "Employee Id: ";    
        cin >> emp.employeeId;

        // Check Variable and break loop if valid
        if (emp.employeeId > 0)
        {
            break;
        } else {
            cout << "Please Enter Valid ID" << endl;
            
        }
    } while (emp.employeeId <= 0);

    // Clear Buffer Stream as cin.get gets skipped in a loop unless all garbage in stream is cleared
    cin.clear();
    cin.ignore();

    // Grab Employee Name
    cout << "Enter Employee Name: ";
    cin.getline(emp.employeeName, 20);

    // Employee Pay Rate Input Validation
    do {
        cout << "Employee Pay Rate: ";    
        cin >> emp.employeePayRate;

        // Check Variable and break loop if valid
        if (emp.employeePayRate > 0)
        {
            break;
        } else {
            cout << "Please Enter Valid Pay Rate" << endl;
        }
    } while (emp.employeePayRate <= 0);
    
    // Input validation and capture of Employee Type
    do {
        cout << "Employee Type (0 or 1): ";
        cin >> emp.employeeType;

        if (emp.employeeType == 0 || emp.employeeType == 1)
        {
            break;
        } else {
            cout << "Please Enter Valid Response!" << endl;
        }
    } while(emp.employeeType != 0 || emp.employeeType != 1);
    
    cout << endl;
}

// Loop through Employees Array, Grab Employee data, and Push to Array
void grabAllEmployeeInformation(Employee employees[], int size)
{
    Employee emp; // Employee struct to be passed into employees array.
    for(int count=1; count<size+1; count++)
    {
        grabEmployeeMasterInfo(emp, count);
        employees[count-1] = emp; // Pass Employee Struct to array.   
    }

}

// Grab Employee Timesheet Data. Loop through both arrays and enter in Appropriate Payroll Data
void grabEmployeeTimesheetInfo(Employee employees[], EmployeePayroll employeePayrolls[], int size)
{   
    double hoursInput; // Local Function User Input Variable to capture Hours
    
    cout << "Enter Timecard Information for each employee: " << endl;
    /* Loop Through Employee Payroll Array To Grab Employee ID information
       and create new array that stores employee id and data 
    */
    for(int count=0; count < size; count++)
    {   
        // Input for hours worked by employee and validation loop for hours
        do {
            cout << "Enter hours worked for " << employees[count].employeeName << ": ";
            cin >> hoursInput;
            if (hoursInput > 0)
            {   
                // Pass Hours Input to specific employee
                employeePayrolls[count].employeeHours = hoursInput;
            } else {
                cout << "Please Enter Valid Number" << endl;
            }
        } while(hoursInput <= 0);

        calculatePay(employees, employeePayrolls, count);
    }
    cout << endl;
}

void calculatePay(Employee employees[], EmployeePayroll employeePayrolls[], int count)
{   
    // Local Function Variables
    double overTimeHours; // Overtime hours 40 - employeeHours
    double regularHours; // Assigned 40 or employeeHours
    double taxPaid; // Taxes paid by employee
    double regularPay; // (Hours worked * salary rate)
    double overTimePay; // (Hours Worked over 40 * salary rate) * 1.5
    double netPay; // Overtime Pay + Gross Pay
    double grossPay; // Net Play less 15% 

    // Check Employee Type
    if(employees[count].employeeType == 0)
    {
        // Calculate Union Member Pay
        if (employeePayrolls[count].employeeHours>40)
        {
            regularHours = 40;
            overTimeHours = employeePayrolls[count].employeeHours - regularHours;
            overTimePay = (overTimeHours * employees[count].employeePayRate) * 1.5;
            regularPay = 40 * employees[count].employeePayRate;
            grossPay = regularPay + overTimePay; 
            netPay = grossPay * .85; // Net pay minus 15%
            taxPaid = grossPay - netPay;
        } else {
            regularHours = employeePayrolls[count].employeeHours;
            regularPay = regularHours * employees[count].employeePayRate;
            grossPay = regularPay;
            netPay = grossPay * .85;
            taxPaid = grossPay - netPay;
        }
        // Add Calculated Pay to EmployeePayroll Structures Array
        employeePayrolls[count].employeeNetPay = netPay;
        employeePayrolls[count].employeeGrossPay = grossPay;
        employeePayrolls[count].employeeTaxPaid = taxPaid;
    
    // Calculate Management Pay 
    } else {           
        // Hour Pay for Management are the same regardles if > 40
        regularHours = employeePayrolls[count].employeeHours;
        regularPay = regularHours * employees[count].employeePayRate;
        grossPay = regularPay;
        netPay = grossPay * .85;
        taxPaid = grossPay - netPay;

        // Add Management Calculated Pay to EmployeePayroll Structures Array
        employeePayrolls[count].employeeNetPay = netPay;
        employeePayrolls[count].employeeGrossPay = grossPay;
        employeePayrolls[count].employeeTaxPaid = taxPaid;
    }
    
}

// Print out the Payroll Report 
void runPayrollReport(Employee employees[], EmployeePayroll employeePayrolls[], int size)
{   
    double grossPayTotals; // Local sum gross pay total 
    double netPayTotals; // Local sum gross pay total 

    // Header Text
    cout << "Payroll Report\n" << endl;
    cout << fixed << showpoint << setprecision(2);

    cout << left << setw(10) << "ID" << setw(25) << "Name" 
         << right << setw(10) << "Gross Pay" << setw(10) << "Tax" << setw(10) << "Net Pay" << endl;

    // Calculate Gross and Net Pay 
    // Iteratively Print out Payroll Data and align 
    for(int count=0; count<size; count++)
    {   
        // Sum the Gross Pay and Net Pay 
        grossPayTotals += employeePayrolls[count].employeeGrossPay;
        netPayTotals += employeePayrolls[count].employeeNetPay;

        // Text alignment for each Payroll Record and Employee Data
        cout << left << setw(10) << employees[count].employeeId << setw(25) << employees[count].employeeName 
         << right << setw(10) << employeePayrolls[count].employeeGrossPay << setw(10) << employeePayrolls[count].employeeTaxPaid << setw(10) << employeePayrolls[count].employeeNetPay << endl;
        
    }

    // Output Summed Gross and Net Pay
    cout << "\n";
    cout << left << setw(10) << "Total Gross Pay: $ " << grossPayTotals << endl;
    cout << left << setw(10) << "Total Net Pay:   $ " << netPayTotals << endl;
}

