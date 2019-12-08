//******************************************************************
// Payroll 2.0 - Assignment 9
// Programmer: Mamun Ahmed
// Completed : 
// Status    : Completed
//
// 
// 
// 
// 
// 
// 
// 
// 
//*********************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Employee Class
class Employee 
{
  private:
    int id;             // employee ID
    string name;        // employee name
    double hourlyPay;   // pay per hour
    int numDeps;        // number of dependents
    int type;           // employee type
    
  public:
    Employee( int initId=0, string initName="", 
              double initHourlyPay=0.0, 
              int initNumDeps=0, int initType=0 );  // Constructor

    bool set(int newId, string newName, double newHourlyPay,
             int newNumDeps, int newType);

    // Member function protos
    int getId();
    string getName();
    float getPay();
    int getNumDeps();
    int getEmpType();
};

Employee::Employee(int initId, string initName, double initHourlyPay, int initNumDeps, int initType)
{
  bool status = set(initId, initName, initHourlyPay, initNumDeps, initType);

  if ( !status )
  {
    id = 0;
    name = "";
    hourlyPay = 0.0;
    numDeps = 0;
    type = 0;    
  }
}

bool Employee::set(int newId, string newName, double newHourlyPay, int newNumDeps, int newType)
{
  bool status = false;
  if ( newId > 0 && newHourlyPay > 0 && newNumDeps >= 0 && newType >= 0 && newType <= 1 )
  {
    status = true;
    id = newId;
    name = newName;
    hourlyPay = newHourlyPay;
    numDeps = newNumDeps;
    type = newType;
  }
  return status;
}

int Employee::getId(){
    return this->id;
}

string Employee::getName(){
    return this->name;
}

float Employee::getPay(){
    return this->hourlyPay;
}

int Employee::getNumDeps(){
    return this->numDeps;
}

int Employee::getEmpType(){
    return this->type;
}

struct EmployeePayroll {
  int empId = 0;
  // Defaults
  double empHours = 0.00;
  double empInsurancePaid = 0.00;
  double empTaxPaid = 0.00;
  double empGrossPay = 0.00;
  double empNetPay = 0.00;
};

// Function Prototypes
void readMasterFile(string masterFileName, Employee employees[], int EMPLOYEE_SIZE);
void readTransactionFile(string transactionFileName, EmployeePayroll employeePayrolls[], int EMPLOYEE_SIZE);
void processPayroll(Employee employees[], EmployeePayroll employeePayrolls[], int EMPLOYEE_SIZE);
void writePayroll(string payrollFileName, Employee employees[], EmployeePayroll employeePayrolls[], int EMPLOYEE_SIZE);

int main()
{   
    // Files to be read
    string masterFileName; 
    masterFileName = "master9.txt";
    string transactionFileName;
    transactionFileName = "trans9.txt";
    // File to be written
    string payrollFileName;
    payrollFileName = "payroll.txt";

    // Employee Information Objects Array
    const int EMPLOYEE_SIZE = 6;
    Employee employees[EMPLOYEE_SIZE] = {};
    readMasterFile(masterFileName, employees, EMPLOYEE_SIZE);
    
    // Employee Payroll Data Structs Array
    EmployeePayroll employeePayrolls[EMPLOYEE_SIZE] = {};
    readTransactionFile(transactionFileName, employeePayrolls, EMPLOYEE_SIZE); 
    
    // Process Data and Calculate Payroll
    processPayroll(employees, employeePayrolls, EMPLOYEE_SIZE);
    
    for(int count=0; count < 6;count++)
    { 
      cout << fixed << showpoint << setprecision(2);
      cout << "******Employee " << count+1 << "******" << endl; 
      cout << "Employee Id: " << employees[count].getId() <<endl;
      cout << "Employee Name: " << employees[count].getName() <<endl;
      cout << "Employee Pay Rate: $" << employees[count].getPay() <<endl;
      cout << "Employee Dependents: " << employees[count].getNumDeps() <<endl;
      cout << "Employee Type: " << employees[count].getEmpType() <<endl;
      cout << "******PAYROLL DATA******" << endl;
      cout << "Employee Id: " << employeePayrolls[count].empId << endl;
      cout << fixed << showpoint << setprecision(1);
      cout << "Employee Hours: " << employeePayrolls[count].empHours << endl;
      cout << fixed << showpoint << setprecision(2);
      cout << "Employee Insurance Paid: $" << employeePayrolls[count].empInsurancePaid << endl;
      cout << "Employee Tax Paid: $" << employeePayrolls[count].empTaxPaid << endl;
      cout << "Employee Gross Pay: $" << employeePayrolls[count].empGrossPay << endl;
      cout << "Employee Net Pay: $" << employeePayrolls[count].empNetPay << endl;
      cout << "******END******" << endl;
    }

    writePayroll(payrollFileName, employees, employeePayrolls, EMPLOYEE_SIZE);

    return 0;
}

void readMasterFile(string masterFileName, Employee employees[], int EMPLOYEE_SIZE)
{   
    string line1, line2; // String Lines to Parse
    string empName; 
    int empId, numDeps, empType;
    double hourlyRate;
    
    // File stream and and data retrieval
    ifstream masterFile;
    masterFile.open(masterFileName);
    
    // Loop Through File by Delimiter Specified.
    int count;
    for(count=0; count < EMPLOYEE_SIZE; count++)
    {
      getline(masterFile, line1, '#');
      getline(masterFile, line2, '\n');
      
      // Store Temp Chars
      string temp;
      string temp2;
      temp = line2[7]; //numDeps Char
      temp2 = line2[9]; //employeeType Char

      if(line1.length()>=23){
        empId = stoi(line1);
        // Where Employee Number starts to 20 Characters per line
        empName = line1.substr(3,20);
        hourlyRate = stod(line2);
        numDeps = stoi(temp);
        empType = stoi(temp2);
      }
      // Create Temp Employee and pass to employees Array.
      Employee empTemp(empId, empName, hourlyRate, numDeps, empType);
      employees[count] = empTemp;
    }
    // Close File
    masterFile.close();
}

void readTransactionFile(string transactionFileName, EmployeePayroll employeePayrolls[], int EMPLOYEE_SIZE)
{   
    string line1; // String Line to Parse
    ifstream transactionFile;
    
    transactionFile.open(transactionFileName);
    int count;
    for(count=0; count<EMPLOYEE_SIZE; count++)
    {
      EmployeePayroll temp;
      getline(transactionFile, line1);

      istringstream str1(line1);
      str1 >> temp.empId >> temp.empHours; 
      
      employeePayrolls[count] = temp;
    }
  
    transactionFile.close();
}

void processPayroll(Employee employees[], EmployeePayroll employeePayrolls[], int EMPLOYEE_SIZE)
{   
    // Local Function Variables
    double overTimeHours; // Overtime hours 40 - employeeHours
    double regularHours; // Assigned 40 or employeeHours
    double taxPaid; // Taxes paid by employee
    double regularPay; // (Hours worked * salary rate)
    double overTimePay; // (Hours Worked over 40 * salary rate) * 1.5
    double insurancePaid; // Insurance Paid
    double netPay; // Overtime Pay + Gross Pay
    double grossPay; // Net Play less 15% 

    
    int count;
    for(count=0; count < EMPLOYEE_SIZE; count++){
      // Union Member
      if(employees[count].getEmpType() == 0){

        if(employeePayrolls[count].empHours>40){
          regularHours = 40; // 40 Hour Work week
          overTimeHours = employeePayrolls[count].empHours - regularHours; // Hours over 40
          overTimePay = (overTimeHours * employees[count].getPay()) * 1.5; // Overtime Pay Rate
          regularPay = regularHours * employees[count].getPay(); // Pay * Hours
          insurancePaid = employees[count].getNumDeps() * 20.0; // Insurance Premiums
          grossPay = (regularPay + overTimePay) - insurancePaid; // Gross pay - minus insurance
          netPay = grossPay * .85; // Net pay minus 15%
          taxPaid = grossPay - netPay; // Net taxes paid

        } else if (employeePayrolls[count].empHours > 0 || employeePayrolls[count].empHours <= 40) {
          regularHours = employeePayrolls[count].empHours;
          regularPay = regularHours * employees[count].getPay();
          insurancePaid = employees[count].getNumDeps() * 20.0;
          grossPay = regularPay - insurancePaid; 
          netPay = grossPay * .85;
          taxPaid = grossPay - netPay;
        }

        employeePayrolls[count].empNetPay = netPay;
        employeePayrolls[count].empGrossPay = grossPay;
        employeePayrolls[count].empInsurancePaid = insurancePaid;
        employeePayrolls[count].empTaxPaid = taxPaid;
        
      // Management Pay Processing
      } else {
        
        if(employeePayrolls[count].empHours > 0) {
          
          regularHours = employeePayrolls[count].empHours;
          regularPay = regularHours * employees[count].getPay();
          insurancePaid = employees[count].getNumDeps() * 20.0;
          grossPay = regularPay;
          netPay = grossPay * .85;
          taxPaid = grossPay - netPay;

          // Add Management Calculated Pay to EmployeePayroll Structures Array
          employeePayrolls[count].empNetPay = netPay;
          employeePayrolls[count].empGrossPay = grossPay;
          employeePayrolls[count].empInsurancePaid = insurancePaid;
          employeePayrolls[count].empTaxPaid = taxPaid;
        }
      }
    }  
}

void writePayroll(){

}