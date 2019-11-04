//******************************************************************
// Postal Packages - Assignment 7
// Programmer: Mamun Ahmed
// Completed : 11/3/2019
// Status    : Completed
//
// 
// Program that accepts user input for package weight and dimensions.
// The program successfully validates the dimensions and weight.
// It also uses basic linear search to identify a shipping charge
// regardless of whether it is equal or between two values. The
// packages are only stored in memory for the loop and transaction
// numbers and counts are stored in local variables in that processing
// function. Everything is displayed and a summary is displayed as well
// when the user decides to exit.
//*********************************************************************

#include <iostream> // Handle input/output 
#include <iomanip>  // I/O manupulator declarations
#include <string>   // Strings
#include <typeinfo> // Type Information
#include <sstream>

using namespace std;

// Function Prototypes
void processTransaction(const int weight[], const double shippingCharges[], int COUNT);
bool validatePackage(int weight, int length, int height, int width);
void getShippingCharges(const int weight[], const double shippingCharges[], int COUNT);
void displayPackage(int packageWeight, int transactionNumber, double shippingCost=0, bool validPackage=false);
void displaySummary(int acceptedPackages, int rejectedPackages);

int main()
{   
    // Package Weight and Associated Charges Arrays
    const int COUNT = 15;
    int weight[COUNT] = {1, 2, 3, 5, 7, 10, 13, 16, 20, 25, 30, 35, 40, 45, 50};
    double shippingCharges[COUNT] = { 1.50, 2.10, 4.00, 6.75, 9.90, 14.95, 19.40,
                                    24.20, 27.30, 31.90, 38.50, 43.50, 44.80, 
                                    47.40, 55.20 }; 

    // Primary Processing Logic Function
    processTransaction(weight, shippingCharges, COUNT);
    
    return 0;
}

// Linear Search to Find Shipping Charges based on weight
int getShippingCharges(int packageWeight, const int weight[], const double shippingCharges[], int COUNT)
{
    for(int index=0; index < COUNT; index++)
    {   
        // If weight matches return that index shipping charge
        if(packageWeight == weight[index])
        {
            return shippingCharges[index];
        // If between two weights. Select Charge that is for index value + 1
        } else if (packageWeight > weight[index] && packageWeight < weight[index+1])
        {
            return shippingCharges[index+1];
        }
    }
    return 0;
}

// Validate Package Function
bool validatePackage(int weight, int length, int height, int width)
{   
    // Only validate package if it passes weight validation.
    if(weight <= 50)
    {   
        // Dimension Validation
        if(height > 36 || length > 36 || width > 36)
        {
            return false;
        }
        // Local variables
        int packageGirth;
        int largest;

        // Find maximum value 
        if(length < width && length < height)
        {
            largest = length;
        } else if (width < length && width < height){
            largest = width;
        } else {
            largest = height;
        } 

        // Measure girth and validate if equal/less 5ft.
        packageGirth = 2*(length+height+width-largest);
        if(packageGirth <= 60)
        {
            return true;
        }
    }
    return false;
}

// Package Information Display Function
void displayPackage(int packageWeight, int transactionNumber, double shippingCost, bool validPackage)
{   
    // If Package is valid print out valid display
    if(validPackage){
        cout << fixed << showpoint << setprecision(2); // Set Floating Point Precision
        cout << left << setw(15) << "Transaction :" << right << setw(20) << transactionNumber << endl;
        cout << left << setw(15) << "Status      :" << right << setw(20) << "Accepted" << endl;
        cout << left << setw(15) << "Weight      :" << right << setw(20) << packageWeight << endl;
        cout << left << setw(15) << "Cost        :" << right << setw(15) << "$" << shippingCost << endl; 
    // Reject Package Display
    } else {
        cout << left << setw(15) << "Transaction :" << right << setw(20) << transactionNumber << endl;
        cout << left << setw(15) << "Status      :" << right << setw(20) << "Rejected" << endl; 
        cout << left << setw(15) << "Weight      :" << right << setw(20) << packageWeight << endl;
        cout << left << setw(15) << "Cost        :" << right << setw(20) << "--" << endl; 
    }    
    cout << "\n";
}

// Summary Display Function
void displaySummary(int acceptedPackages, int rejectedPackages)
{   
    cout << "Number of accepted packages: " << acceptedPackages << endl;
    cout << "Number of rejected packages: " << rejectedPackages << endl;
}

// Main Function that processes all inputs, and transactions
void processTransaction(const int weight[], const double shippingCharges[], int COUNT)
{
    // Package Variables
    int transactionNumber;
    int packageWeight;
    int length;
    int height;
    int width;
    int acceptedPackages;
    int rejectedPackages;
    int shippingCost;

    // Explain to user how to enter in input properly, and how to exit
    cout << "For each transaction, enter package weight and 3 dimensions." << endl;
    cout << "Enter -1 to quit \n" << endl;

    // Initial Count Variables
    transactionNumber = 0;
    acceptedPackages = 0;
    rejectedPackages = 0;
    
    while(packageWeight != -1)
    {   
        // Initial Main Loop To Capture User Input
        cout << "Enter package weight and 3 dimensions (seperated by spaces): ";
        cin >> packageWeight;
        // Handle Quit Input
        if(packageWeight == -1)
        {   
            // Summary Display Function on Exit!
            cout << "\n";
            displaySummary(acceptedPackages, rejectedPackages);
            cout << "\n";
            cout << "Exiting Program" << endl;
            cout << "Goodbye!" << endl;
            break;
        }
        // Store Package Dimensions
        cin >> length;
        cin >> height;
        cin >> width;

        // Validate Initial Package Weight and Dimensions
        if (packageWeight <=  0 || length <= 0 || height <= 0 || width <= 0)
        {
            cout << "Error: Please ensure weight/dimensions are greater than 0!" << endl;
            cout << "Please Try Entering Again!" << endl;
            cout << "\n";
        } else {
            bool validPackage = validatePackage(packageWeight, length, height, width);
            // If Package Dimensions & Weight are Valid!
            if(validPackage){
                // Valid Package Cost Calculation
                int shippingCost = getShippingCharges(packageWeight, weight, shippingCharges, COUNT);
                // Valid Package Logic
                transactionNumber++;
                acceptedPackages++;
                displayPackage(packageWeight, transactionNumber, shippingCost, validPackage);
            } else {
                // Rejected Package Logic
                transactionNumber++;
                rejectedPackages++;
                displayPackage(packageWeight, transactionNumber);    
            }
        }
    }
}
