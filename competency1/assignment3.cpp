//******************************************************************
// Checkbook Balancing Program Revisited - Assignment 3
// Programmer: Mamun Ahmed
// Completed : 09/21/2019
// Status    : Completed
//
// Fully functioning bank account program that has a number of pieces
// from module 2 abstracted into functions.
// The program allows users to enter in any starting balance, has 
// input validation for 1st and 2nd character inputs
// and it allows users to cash checks, deposit money, and charges
// the appropriate service charges based on transactions and balances.
//******************************************************************

#include <iostream> // Handle input/output 
#include <iomanip>  // I/O manupulator declarations
#include <string>   // string
#include <stdlib.h>

using namespace std; // Standard I/O namespace

void processCheck(double &userBalance, double &transactionAmount, double &userServiceCharges); // Function Prototype Process Check
void processDeposit(double &userBalance, double &transactionAmount, double &userServiceCharges); // Function Prototype Process Deposit
void processEndOfMonth(double &userBalance, double &userServiceCharges); // Process the end of the month transactions and close program.
void checkBalanceFee(double &userBalance, double &userServiceCharges, bool &userBalanceFee); // Function prototype for Checking Account Balance for $10.00 Fee
void validTransactionAmount(double &transactionAmount); // Validate a transaction to ensure its an integer or double.

int main() {

    // Set Fixed 2 decimal places
    cout << fixed << showpoint << setprecision(2); 
    
    double userBalance; // Store the users balance
    bool userBalanceFee = false;
    double userServiceCharges; // Store user total service charges
    char userChoice; // Character store for menu choice
    
    // Intro to Checkbook Program output
    cout << "Welcome to Checkbook Balancing Program!!\n" << endl;
    cout << "Enter the beginning Balance: ";
    cin >> userBalance;

    // Assign service fee of $10.00 if userBalance is under $1000.00 initially
    if (userBalance<1000 && userBalanceFee==false){
        userServiceCharges += 10.00;
        userBalanceFee = true;
        cout << "An initial $10.00 fee was charged upfront for depositing less than $1000 initially." << endl;
        cout << "This fee will not be assessed till the end of the month." << endl;
    };

    // Display User inputted balance to user
    cout << "The current balance is $" << userBalance << endl;
    cout << endl;

    // Main execution loop for bank account program
    do {    
        
        string char2; // Place holder for string transaction amount
        double transactionAmount; // Convert input to double

        // Print the programs user commands
        cout << "C - Process a check" << endl;
        cout << "D - Process a deposit" << endl;
        cout << "E - End the program\n" << endl;
        
        // User I/O to store User Choice and Transaction Amount
        cout << "Enter transaction type and amount (Enter letter, space, and then the transaction amount): ";        
        cin >> userChoice;
        cin >> char2;

        // Converted Input to Double Floating Point
        transactionAmount = atof(char2.c_str());
    

        // Uppercase choice for case insensitivity
        userChoice = toupper(userChoice); 
        
        // Ensure transaction amount is valid and then process business logic.
        if (transactionAmount>0){
            // Core Business Logic to handle transactions
            switch (userChoice)
            {
                // Handle Check Process User Input
                case 'C': cout << "Transaction Type Process Check!\n";
                    processCheck(transactionAmount, userBalance, userServiceCharges);
                    checkBalanceFee(userBalance, userServiceCharges, userBalanceFee);
                    break;
                // Handle Deposit User Input
                case 'D': cout << "Transaction Type Deposit!\n";
                    processDeposit(transactionAmount, userBalance, userServiceCharges);
                    break;
                // Handle E User Input
                case 'E': cout << "Processing End of Month!\n";
                    processEndOfMonth(userBalance, userServiceCharges);
                    break;
                // Default input if 'C D or E' are not selected as first argument from menu.
                default: cout << "Error: You entered an incorrect choice. Please try again!\n";
                    break;
            };
        } else {
            cout << "Error: You entered an incorrect number! Please try again!" << endl;
            continue;
        };
    } while (userChoice != 'E');

    return 0;
};

void validTransactionAmount(double &transactionAmount) {
    if(transactionAmount<0){
        cout << "Error: You entered an incorrect number! Please enter a number or a number greater than 0.00" << endl;
    }
}

// Function that handles Processing Check 
void processCheck(double &transactionAmount, double &userBalance, double &userServiceCharges) {
    bool isOverdraft = false;
    // Deteermine if this transaction will overdraft the account 
    if (transactionAmount > userBalance) {
        userServiceCharges += 35.00;
        isOverdraft = true;
        cout << "You have been charged an overdraft fee" << endl;
    };

    // Handle basic Check Processing and Trsnsaction Charge
    userServiceCharges += 0.35;
    userBalance = userBalance - transactionAmount;

    // Print Transaction, Charges and Balance to User
    cout << "Processing check for $" << transactionAmount << endl;
    cout << "Balance: $" << userBalance << endl;
    cout << "Service Charge: $0.35 for a check" << endl;
    if (isOverdraft){
        cout << "Service Charge: $35.00 for overdrafting account!" << endl;
    };
    cout << "Total service charges: $" << userServiceCharges << endl;
    cout << endl; 
};

// Function to handle deposits to bank account
void processDeposit(double &transactionAmount, double &userBalance, double &userServiceCharges) {
    // Handle the Basic Deposit Transaction
    userBalance = userBalance + transactionAmount;
    
    // Print Transaction, Charges, and Balance to User
    cout << "Processing deposit for $" << transactionAmount << endl;
    cout << "Balance: $" << userBalance << endl;
    cout << "Total service charges: $" << userServiceCharges << endl;
    cout << endl; 
};

void processEndOfMonth(double &userBalance, double &userServiceCharges) {
    // Process Service Charges and display userBalance to user.
    userBalance = userBalance - userServiceCharges;
    
    // Final output for user. Print Final Balance to screen
    cout << "Thanks for using the Checkbook Balancing Program" << endl;
    cout << "Processing End of Month Service Charges" << endl;
    cout << "Month Service Charges: $" << userServiceCharges << endl;
    cout << "Final Balance (after Service Charges): $" << userBalance << endl;
};

// Function that checks after each transaction whether
void checkBalanceFee(double &userBalance, double &userServiceCharges, bool &userBalanceFee) {
    cout << "Checking to see if balance is under $1000.00" << endl;
    // Check balance to see if under 1000 and see if the account fee has been charged
    if(userBalance<1000 && userBalanceFee == false){
        userServiceCharges += 10.00;
        cout << "Your balance is currently $" << userBalance << endl;
        cout << "$10.00 balance service charged to account this month!" << endl;
        cout << endl;
        userBalanceFee = true;
    } else {
        cout << "Your balance is currently $" << userBalance << endl;
        cout << "$10.00 charge not applied for this transaction!" << endl; 
        cout << endl; 
    }
};
