//******************************************************************
// Checkbook Balancing Program - Assignment 2
// Programmer: Mamun Ahmed
// Completed : 09/14/2019
// Status    : Completed
//
// This program reads and accepts user input for an account balance
// It allows you to deposit and withdraw (via checks) from this
// account. Finally it allows you to print out the months end balance
// after fees have been accounted.
//******************************************************************

#include <iostream> // Handle input/output 
#include <iomanip>  // I/O manupulator declarations
#include <string>   // string

using namespace std; // Standard I/O namespace

int main() {

    // Set Fixed 2 decimal places
    cout << fixed << showpoint << setprecision(2); 
    
    double userBalance; // Store the users balance
    double userServiceCharges; // Store user total service charges
    char userChoice; // Character store for menu choice

    // Intro to Checkbook Program output
    cout << "Welcome to Checkbook Balancing Program!!\n" << endl;
    cout << "Enter the beginning Balance: ";

    // Get Beginning User Balance input.
    cin >> userBalance;

    // User Account Initialization Validation
    while (userBalance <= 0) {
        cout << "Error: Enter a balance greater than $0.00" << endl;
        cout << "Enter the beginning Balance: ";
        cin >> userBalance;
    }

    // Display User inputted balance to user
    cout << "The current balance is $" << userBalance << endl;
    cout << endl;

    // Print the programs user commands
    cout << "C - Process a check" << endl;
    cout << "D - Process a deposit" << endl;
    cout << "E - End the program\n" << endl;

    // Main execution loop for bank account program
    do {    
        double transactionAmount; // Transaction amount float

        // User input for User Menu Choice
        cout << "Enter transaction type: ";
        cin >> userChoice;
        
        // Uppercase choice for case insensitivity
        userChoice = toupper(userChoice); 
        
        // Store User transaction Amount 
        if (userChoice != 'E'){
            
            // User input for transaction amount
            cout << "Enter transaction amount: ";   
            cin >> transactionAmount;

            // Transacation validation for deposit
            if (userChoice == 'D') {
                while(transactionAmount<=0) {
                   if(transactionAmount<=0){
                        cout << "Error: Please enter an amount greater than $0.00" << endl;
                   };
                   cout << "Enter transaction amount: ";
                   cin >> transactionAmount;
                };
                cout << endl;
            } else {
                // Transaction Amount Validation for Withdrawal
                while (transactionAmount<=0 || transactionAmount>userBalance){ 
                    if(transactionAmount<=0){
                        cout << "Error: Please enter an amount greater than $0.00" << endl;
                    } else if(transactionAmount>userBalance) {
                        cout << "Error: Please enter an amount less than your account balance!" << endl;
                        cout << "Your current balance is: $" << userBalance << endl;
                    };
                    cout << "Enter transaction amount: ";
                    cin >> transactionAmount;
                };
                cout << endl;
            };
        };
        
        // Core Business Logic to handle transactions
        switch (userChoice)
        {
            // Handle Check Process User Input
            case 'C': cout << "Transaction Type Process Check!\n";
                userBalance = userBalance - transactionAmount;
                userServiceCharges += 0.35;
                cout << "Processing check for $" << transactionAmount << endl;
                cout << "Balance: $" << userBalance << endl;
                cout << "Service Charge: $0.35 for a check" << endl;
                cout << "Total service charges: $" << userServiceCharges << endl;
                cout << endl; 
                break;
            // Handle Deposit User Input
            case 'D': cout << "Transaction Type Deposit!\n";
                userBalance = userBalance + transactionAmount;
                cout << "Processing deposit for $" << transactionAmount << endl;
                cout << "Balance: $" << userBalance << endl;
                cout << "Total service charges: $" << userServiceCharges << endl;
                cout << endl; 
                break;
            // Handle E User Input
            case 'E': cout << "Processing End of Month!\n";
                break;
            default: cout << "Error: You entered an incorrect choice. Please try again!\n";
        };
    } while (userChoice != 'E');

    // Process Service Charges and display userBalance to user.
    userBalance = userBalance - userServiceCharges;
    
    // Final output for user. Print Final Balance to screen
    cout << "Thanks for using the Checkbook Balancing Program" << endl;
    cout << "Month Service Charges: $" << userServiceCharges << endl;
    cout << "Final Balance (after Service Charges): $" << userBalance << endl;
    
    return 0;
};