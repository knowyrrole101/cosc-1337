#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>

using namespace std;

class Employee 
{
  private:
    int id;             // employee ID
    char name[21];      // Char Name Array   
    double hourlyPay;   // pay per hour
    int numDeps;        // number of dependents
    int type;           // employee type

  public:
    // Constructor. Defaults included in initial args.
    Employee(int initId=0.0, double initHourlyPay=0.0, int initNumDeps=0, int initType=0){
        id = initId;
        strcpy(name, " ");
        hourlyPay=initHourlyPay;
        numDeps = initNumDeps;
        type = initType;
    };

    bool set(int newId, char *newName, double newHourlyPay, int newNumDeps, int newType);

    // Member function prototypes
    int getId();
    char *getName();
    float getPay();
    int getNumDeps();
    int getEmpType();
};

bool Employee::set(int newId, char *newName, double newHourlyPay, int newNumDeps, int newType){
    bool status = false;
    if ( newId > 0 && newHourlyPay > 0 && newNumDeps >= 0 && newType >= 0 && newType <= 1 &&strlen(newName)>=2)
    {   
        status=true;
        this->id = newId;
        strcpy(this->name, newName);
        this->hourlyPay = newHourlyPay;
        this->numDeps = newNumDeps;
        this->type = newType;
    }

    return status;
}

char *Employee::getName(){
    return this->name;
}

int Employee::getId(){
    return this->id;
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
  double empHours = 0.00;
  double empInsurancePaid = 0.00;
  double empTaxPaid = 0.00;
  double empGrossPay = 0.00;
  double empNetPay = 0.00;
};

int fileLineCount(string masterFileName);
void readMasterFile(string masterFileName, int EMPLOYEE_SIZE);

int main()
{   
    string masterFileName;
    masterFileName = "./master10.txt";
    string transactionFileName;
    transactionFileName = "./trans10.txt";

    // Count Employee Record Rows (Non-Empty Rows)
    int EMPLOYEE_SIZE = fileLineCount(masterFileName);
    // Initialize Employee Object and Employee Payroll Struct
    Employee employeeArray[EMPLOYEE_SIZE];
    EmployeePayroll employeePayrolls[EMPLOYEE_SIZE];    
    
    readMasterFile(masterFileName, EMPLOYEE_SIZE);

    
    // Employee someEmp;
    char name[21] = "moon ahmed";
    char *ptr;
    ptr = name;
    // cout << ptr << endl;
    Employee moon;
    moon.set(1, ptr, 10.50, 2, 0);
    // cout << moon.getName() << endl;
    ptr=nullptr;
        
    

    return 0;
}
// Reads the file for row count minus empty rows and returns count for employee array
int fileLineCount(string masterFileName)
{   
    ifstream inFile;
    inFile.open(masterFileName);
    string line;
    
    int count=0;
    while(!inFile.eof()){
        getline(inFile,line,'\n');
        if(line.length()>2){
            count ++;
        }
    }
    inFile.close();
    return count;
}

void readMasterFile(string masterFileName, int EMPLOYEE_SIZE){
    ifstream inFile;
    istringstream cstr;

    int empId;
    int numDeps;
    int type;
    double hourlyPay;
    char firstName[21];
    char lastName[21];
    
    Employee tempEmp;

    inFile.open(masterFileName); 
    char line[100];
    if (inFile.good()){
        while(!inFile.eof()){
            cout << "going" << endl;
        }
       
        
    }
    // for(int count=0; count < EMPLOYEE_SIZE; count++){
        
    //     inFile.get(line, 50, '\n');
    //     cstr.str(line);
    //     cstr >> empId >> firstName >> lastName >> hourlyPay >> numDeps >> type;
    //     cout << empId << endl; 
    //     cout << firstName << endl;
    //     cout << lastName << endl;
        
        
    // }
        
   
    

}

