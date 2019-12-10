//******************************************************************
// Payroll 2.0 - Assignment 9
// Programmer: Mamun Ahmed
// Completed : 12/8/2019
// Status    : Completed
//
// Payroll 2.0 stores employee data calculates data from two
// input files and writes to a new payroll.txt file.
// Payroll 2.0 relies on Employee class and EmployeePayroll Struct
// objects. They store data in memory before processing and then
// eventually written/formatted in tabular format to a txt file.
//*********************************************************************

#include <iostream>
#include <cctype>
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
    payrollFileName = "./payroll.txt";

    // Employee Information Objects Array
    const int EMPLOYEE_SIZE = 6;
    Employee employees[EMPLOYEE_SIZE] = {};
    readMasterFile(masterFileName, employees, EMPLOYEE_SIZE);
    
    // Employee Payroll Data Structs Array
    EmployeePayroll employeePayrolls[EMPLOYEE_SIZE] = {};
    readTransactionFile(transactionFileName, employeePayrolls, EMPLOYEE_SIZE); 
    
    // Process Data and Calculate Payroll
    processPayroll(employees, employeePayrolls, EMPLOYEE_SIZE);

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
// Pass in File Name, Arrays of Class Employee and Structure EmployeePayroll
void readTransactionFile(string transactionFileName, EmployeePayroll employeePayrolls[], int EMPLOYEE_SIZE)
{   
    string line1; 
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
// Process the payrolls for all employees and run all calculations
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
        // If Member has worked Overtime
        if(employeePayrolls[count].empHours>40){
          regularHours = 40; 
          overTimeHours = employeePayrolls[count].empHours - regularHours; 
          overTimePay = (overTimeHours * employees[count].getPay()) * 1.5; 
          regularPay = regularHours * employees[count].getPay(); 
          insurancePaid = employees[count].getNumDeps() * 20.0; 
          grossPay = regularPay + overTimePay; 
          netPay = (grossPay * .85) - insurancePaid;
          taxPaid = grossPay - (grossPay * .85); 
        // If Worked 40 Hours or Less
        } else if (employeePayrolls[count].empHours > 0 && employeePayrolls[count].empHours <= 40) {
          regularHours = employeePayrolls[count].empHours;
          regularPay = regularHours * employees[count].getPay();
          insurancePaid = employees[count].getNumDeps() * 20.0;
          grossPay = regularPay; 
          netPay = (grossPay * .85) - insurancePaid;
          taxPaid = grossPay - (grossPay * .85);
        }
        // Pass in relevant data to EmployeePayrolls Struct 
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
          netPay = (grossPay * .85) - insurancePaid;
          taxPaid = grossPay - (grossPay * .85);

          // Add Management Calculated Pay to EmployeePayroll Structures Array
          employeePayrolls[count].empNetPay = netPay;
          employeePayrolls[count].empGrossPay = grossPay;
          employeePayrolls[count].empInsurancePaid = insurancePaid;
          employeePayrolls[count].empTaxPaid = taxPaid;
        }
      }
    }  
}

// Write Payroll Data to TXT File
void writePayroll(string payrollFileName, Employee employees[], EmployeePayroll employeePayrolls[], int EMPLOYEE_SIZE)
{ 
  int success;
  ofstream payrollFile;
  payrollFile.open(payrollFileName);
 
  payrollFile << fixed << showpoint << setprecision(2); // Set Floating Point Precision
  payrollFile << left << setw(15) << "ID: " 
                      << setw(20) << "Name:" 
                      << setw(20) << "Gross Pay:"
                      << setw(20) << "Tax:" 
                      << setw(20) << "Insurance:" 
                      << setw(20) << "Net Pay:"
                      << endl;
  
  int count;
  success = 0; // Successful Payrolls Completed
  for(count=0; count < EMPLOYEE_SIZE; count++)
  {
    if(employees[count].getId() > 0 && employeePayrolls[count].empHours > 0.0){
      payrollFile << left << setw(15) << employees[count].getId() 
                          << setw(20) << employees[count].getName()
                          << setw(20) << employeePayrolls[count].empGrossPay
                          << setw(20) << employeePayrolls[count].empTaxPaid
                          << setw(20) << employeePayrolls[count].empInsurancePaid
                          << setw(20) << employeePayrolls[count].empNetPay
                          << endl; 
      success++;
    } else {
      // Error Messaging 
      if(employees[count].getId() <= 0){
        cout << "Invalid Employee ID! Unable to Add to Payroll Processing Report.\n" << endl;
      } else {
        cout << "Invalid Employee Hours! Unable to Add Employee #" << employees[count].getId() << " to Payroll Processing Report.\n" << endl;
      }
    }
  }
  cout << "Payroll Processing complete!\nTotal number of transactions completed successfully: " << success << " out of " << count << endl;
}