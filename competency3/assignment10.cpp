//******************************************************************
// Payroll 3.0 - Assignment 10
// Programmer: Mamun Ahmed
// Completed : 12/13/2019
// Status    : Completed
//
// Payroll 3.0 stores all initial program file data in Employee class
// Strings are represented using c-strings and updated with pointers.
// Once data is processed and matched against an ID. It is then 
// processed and written to file. One file is records, and one is 
// error record logs.
//*********************************************************************
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

// Employee Class
class Employee
{   
    
    private:
        int id;
        char name[21];
        float hourlyPay;
        int numDeps;
        int type;
    
    public:
        
        Employee(){
          strcpy(this->name, "");
          this->id = 0;
          this->hourlyPay = 0.00;
          this->numDeps = 0.00;
          this->type = 0.00;
        };

        bool set(int newId, char newName[], float newHourlyPay, int newNumDeps, int newType);

        const char *getName();
        int getNumDeps();
        int getId();
        int getType();
        float getPay();

};

bool Employee::set(int newId, char newName[], float newHourlyPay, int newNumDeps, int newType){
    bool passed = false;
    if(newId > 0 && newHourlyPay > 0.00 && newNumDeps >= 0 && newType >= 0 && newType <= 1 && strlen(newName)>0){
        this->id = newId;
        strcpy(this->name, newName);
        this->hourlyPay = newHourlyPay;
        this->numDeps = newNumDeps;
        this->type = newType;
    }
    return passed;
}

int Employee::getNumDeps(){
    return this->numDeps;
}

int Employee::getId(){
    return this->id;
}

int Employee::getType(){
    return this->type;
}
float Employee::getPay(){
    return this->hourlyPay;
}

const char * Employee::getName(){
    return this->name;
}

// Function Prototypes
void readMasterFile(Employee employees[], int MAX_EMPLOYEES, int &EMPLOYEE_COUNT);
void readTransFile(Employee employees[], int MAX_EMPLOYEES,  int EMPLOYEE_COUNT);
void processPayroll(Employee employee, int hours, int &success, float &totalGrossPay, float &totalNetPay);
void writeFileHeaders();

int main(){

    const int MAX_EMPLOYEES = 100;
    int EMPLOYEE_COUNT = 0;

    Employee employees[MAX_EMPLOYEES] = {};

    readMasterFile(employees, MAX_EMPLOYEES, EMPLOYEE_COUNT);
    writeFileHeaders();
    readTransFile(employees, MAX_EMPLOYEES, EMPLOYEE_COUNT);

    return 0;
}

void readMasterFile(Employee employees[], int MAX_EMPLOYEES, int &EMPLOYEE_COUNT){
    ifstream inFile;
    
    inFile.open("master10.txt");
    
    // Temp variables
    int firstId;
    char firstName[21];
    float firstHourlyPay;
    int firstNumDeps;
    int firstType;
    char gender; //ignored temp

    int numEmployees = 0;

    // First Employee Information
    inFile >> firstId;
    inFile.ignore(); 
    inFile.getline(firstName, 21);
    inFile.clear();
    inFile >> firstHourlyPay >> firstNumDeps >> firstType >> gender;
    char *ptr;
    ptr = firstName;
    
    employees[numEmployees].set(firstId, ptr, firstHourlyPay, firstNumDeps, firstType);
    numEmployees++;
    
    //  EOF LOOP BUG!! RESOLVED WITH INFILE GOOD!
    while(!inFile.eof() && numEmployees < MAX_EMPLOYEES)
    {
        inFile >> firstId;
        inFile.ignore(); 
        inFile.getline(firstName, 21);
        ptr = firstName;
        // Clear the stream
        inFile.clear();
        inFile >> firstHourlyPay >> firstNumDeps >> firstType >> gender;
        if (!inFile.good())
        {
            //input failure, leave the loop
            break;
        }
        employees[numEmployees].set(firstId, ptr, firstHourlyPay, firstNumDeps, firstType);
        numEmployees++;
    }
    EMPLOYEE_COUNT = numEmployees;
    // Clear Pointer Memory
    ptr = nullptr;    
    // Close File
    inFile.close();
}

void readTransFile(Employee employees[], int MAX_EMPLOYEES, int EMPLOYEE_COUNT){
    ifstream inFile;
    ofstream payrollFile;
    ofstream logFile;

    inFile.open("trans10.txt");
    payrollFile.open("payroll.txt", std::fstream::in | std::fstream::out | std::fstream::app);

    int ids;
    double hours;
    int numEmployees = 0;
    int successCount = 0;
    float totalNetPay = 0.00;
    float totalGrossPay = 0.00;        

    inFile >> ids >> hours;
    numEmployees++;    
    // Process Logic
    while(!inFile.eof() && numEmployees < MAX_EMPLOYEES){
        int count;
        for(count=0; count < EMPLOYEE_COUNT;count++)
        {   
            // Temp Employee Data Holder to pass to payroll
            Employee tempEmp;
            tempEmp = employees[count];
            
            if(employees[count].getId()==ids){
                processPayroll(tempEmp, hours, successCount, totalNetPay, totalGrossPay);
            } 
        }
        inFile >> ids >> hours;
        if(!inFile.good()){
            break;
        }
        numEmployees++;
    }   
    // Write Weekly Payouts
    inFile.close();
    payrollFile << fixed << showpoint << setprecision(2);
    payrollFile << "Total Weekly Gross Pay: $" << totalGrossPay << endl;
    payrollFile << "Total Weekly Net Pay: $" << totalNetPay << endl;
    payrollFile.close();
    // Total Records processed to log file
    logFile.open("./logfile.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    logFile << "Total records processed (success): " << successCount;
    logFile.close();

    
}

void processPayroll(Employee employee, int hours, int &success, float &totalGrossPay, float &totalNetPay){
    // File io
    ofstream payrollFile;
    ofstream logFile;
    payrollFile.open("./payroll.txt", std::fstream::in | std::fstream::out | std::fstream::app); // To Append to Text File
    logFile.open("./logfile.txt", std::fstream::in | std::fstream::out | std::fstream::app); // To Append to Text File
    
    float regularHours;
    float regularPay;
    float overTimeHours;
    float overTimePay;
    float insurancePaid;
    float grossPay;
    float netPay;
    float taxPaid;
    
    // Transaction Processing
    if(employee.getType() == 0){
        // If Member has worked Overtime
        if(hours>40){
          regularHours = 40; 
          overTimeHours = hours - regularHours; 
          overTimePay = (overTimeHours * employee.getPay()) * 1.5; 
          regularPay = regularHours * employee.getPay(); 
          insurancePaid = employee.getNumDeps() * 20.0; 
          grossPay = regularPay + overTimePay; 
          netPay = (grossPay * .85) - insurancePaid;
          taxPaid = grossPay - (grossPay * .85); 
        // If Worked 40 Hours or Less
        } else if (hours > 0 && hours <= 40) {
          regularHours = hours;
          regularPay = regularHours * employee.getPay();
          insurancePaid = employee.getNumDeps() * 20.0;
          grossPay = regularPay; 
          netPay = (grossPay * .85) - insurancePaid;
          taxPaid = grossPay - (grossPay * .85);
        }
    //   // Management Pay Processing
    } else {
        if(hours > 0) {
          regularHours = hours;
          regularPay = regularHours * employee.getPay();
          insurancePaid = employee.getNumDeps() * 20.0;
          grossPay = regularPay;
          netPay = (grossPay * .85) - insurancePaid;
          taxPaid = grossPay - (grossPay * .85);
        } 
    }

    payrollFile << fixed << showpoint << setprecision(2);
    if(employee.getId() > 0 && hours > 0.0){
        payrollFile << left << setw(15) << employee.getId() 
                          << setw(20) << employee.getName()
                          << setw(20) <<  taxPaid
                          << setw(20) <<  insurancePaid
                          << setw(20) <<  grossPay
                          << setw(20) <<  netPay
                          << endl; 
        success++;
    } 
    else if(hours < 0.0){
        logFile << fixed << showpoint << setprecision(2);
        logFile << left << setw(15) << employee.getId() 
                          << setw(20) << employee.getName()
                          << setw(20) << taxPaid
                          << setw(20) << insurancePaid
                          << setw(20) << grossPay
                          << setw(20) << netPay
                          << setw(20) << hours
                          << setw(20) << "inaccurate hours"
                          << endl;     
    }

    // Add to total net/gross pay summaries    
    totalGrossPay += grossPay;
    totalNetPay += netPay;
    
    payrollFile.close();
    logFile.close();
}

// File Header Row Function
void writeFileHeaders(){
    ofstream payrollFile;
    ofstream logFile;
    payrollFile.open("./payroll.txt");

    payrollFile << left << setw(15) << "ID: " 
                      << setw(20) << "Name:" 
                      << setw(20) << "Tax:" 
                      << setw(20) << "Insurance:"
                      << setw(20) << "Gross Pay:" 
                      << setw(20) << "Net Pay:"
                      << endl;
    

    logFile.open("./logfile.txt");
    logFile << left << setw(15) << "ID: " 
                      << setw(20) << "Name:" 
                      << setw(20) << "Tax:" 
                      << setw(20) << "Insurance:"
                      << setw(20) << "Gross Pay:" 
                      << setw(20) << "Net Pay:"
                      << setw(20) << "Hours:"
                      << setw(20) << "Error Message:"
                      << endl;
}