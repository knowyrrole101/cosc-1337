//******************************************************************
// Monkey Food - Assignment 6
// Programmer: Mamun Ahmed
// Completed : 10/19/2019
// Status    : Completed
//
// Program that accepts user inputs around lbs of food eaten
// by monkeys. The user input accepts floats and validates
// to ensure no negative numbers are passed in. The program
// also calculaties the min, max, and average food for all
// monkeys. Finally a tabular report of all data is printed out 
// at the end. 
//******************************************************************

#include <iostream> // Handle input/output 
#include <iomanip>  // I/O manupulator declarations
#include <string>   // Strings

using namespace std;

// Constants for Monkey Data Multidimensional array.
const int ROWS = 3;
const int COLS = 7;

// Function Prototypes
void getMonkeysData(double [][COLS], int ROWS); // Get User Input Function
double averageFoodPerDay(double monkeyDataStorage[][COLS], int ROWS); // Average Food Per Day Function
double leastFoodEaten(double monkeyDataStorage[][COLS], int ROWS); // Minimum Value in Multidimensional Array Function
double mostFoodEaten(double monkeyDataStorage[][COLS], int ROWS); // Greatest Value in Multidimensional Array Function
void displayData(double monkeyDataStorage[][COLS], int ROWS, double foodAverage, double minFood, double maxFood); // Display Data

int main()
{
    // Variable Declarations
    double foodAverage;
    double minFood;
    double maxFood;

    // Two-dimensional Array to Store Monkey Data
    double monkeyDataStorage[ROWS][COLS];

    // Function Executions
    getMonkeysData(monkeyDataStorage, ROWS); // Grab Monkey Data and Pass to Array 
    foodAverage = averageFoodPerDay(monkeyDataStorage, ROWS); // Grab Average Data
    minFood = leastFoodEaten(monkeyDataStorage, ROWS); // Grab Min Data and store
    maxFood = mostFoodEaten(monkeyDataStorage, ROWS); // Grab Max Data and store
    displayData(monkeyDataStorage, ROWS, foodAverage, minFood, maxFood); // Display the report.
    
}

// Function That Grabs User Input, Validates, and Stores in Existing Monkey Data Multi-Dimensional Array
void getMonkeysData(double monkeyDataStorage[][COLS], int ROWS)
{
    double userInput; // User Input Local Variable
    string daysOfWeek[7] = {"Sun", "Mon", "Tues", "Wed", "Thu", "Fri", "Sat"}; // Days Array

    // Input Loop for Each Monkey and each day.
    for(int row=0; row<ROWS; row++)
    {   
        cout << "Enter Data for Monkey "<< row+1 << endl;
        for(int col=0; col<COLS; col++)
        {   
            // User Input validation to ensure non-negative numbers
            do{
                // Grab User Input for Monkey Food
                cout << "Enter pounds of food eaten by monkey " << row+1 << " on " << daysOfWeek[col] <<": ";
                cin >> userInput; // Store Input in Temp Variable

                if(userInput < 0)
                {
                    cout << "Enter a valid number greater than 0! Please Try Again!" << endl;
                } else {
                    monkeyDataStorage[row][col] = userInput; // Pass Temp Data into Appropriate Index
                }
            } while(userInput<0);
            
        }
    }
}

double averageFoodPerDay(double monkeyDataStorage[][COLS], int ROWS){
    double sum; // Local variable to sum all values in array
    double count = ROWS * COLS; // Total Cell Count;
    double average; // Local variable to store calculated average;

    for(int row=0; row<ROWS; row++)
    {
        for(int col=0; col<COLS; col++)
        {
            sum += monkeyDataStorage[row][col];
        }
    }
    average = sum/count; // Calculate the average
    return average; // Return Double Floating Point Average Calculation
}

// Function to Return Minimum Food Eaten
double leastFoodEaten(double monkeyDataStorage[][COLS], int ROWS){
    double least; // Local variable to sum all values in array
    least = monkeyDataStorage[0][0]; // Assign temp value

    for(int row=0; row<ROWS; row++)
    {   
        for(int col=0; col<COLS; col++)
        {   
            if(least > monkeyDataStorage[row][col])
            {
                least = monkeyDataStorage[row][col];
            }
        }
    }
    return least; // Return Minimum Value
}

// Function to Return Maximum Food Eaten
double mostFoodEaten(double monkeyDataStorage[][COLS], int ROWS){
    double max; // Local variable to sum all values in array
    max = monkeyDataStorage[0][0]; // Assign temp value

    for(int row=0; row<ROWS; row++)
    {
        for(int col=0; col<COLS; col++)
        {   
            if(max < monkeyDataStorage[row][col])
            {
                max = monkeyDataStorage[row][col];
            }
        }
    }
    return max; // Return Maximum Value
}

void displayData(double monkeyDataStorage[][COLS], int ROWS, double foodAverage, double minFood, double maxFood)
{   
    // Header Text
    cout << "Pounds of Food Eaten By Monkey and Day of Week\n" << endl;
    cout << fixed << showpoint << setprecision(1); // Set 2 Point Floating Numbers

    // Data Column Header
    cout << left << setw(10) << "Monkey" << setw(10) << "Sun" << setw(10) << "Mon" << setw(10) << "Tue" << setw(10) << "Wed"
         << setw(10) << "Thu" << setw(10) << "Fri" << setw(10) << "Sat" << endl;
    
    // Iteratively print out all monkey data for each row
    for(int count=0; count<ROWS; count++)
    {
        cout << left << setw(10) << count << setw(10) << monkeyDataStorage[count][0] << setw(10) << monkeyDataStorage[count][1]    
             << setw(10) << monkeyDataStorage[count][2] << setw(10) << monkeyDataStorage[count][3] << setw(10) << monkeyDataStorage[count][4]
             << setw(10) << monkeyDataStorage[count][5] << setw(10) << monkeyDataStorage[count][6] << endl;   
    }
    
    //  Print out aggregation metrics
    cout << "\n";
    cout << left << "The average food eaten per day by all monkeys : " << right << setw(10) << foodAverage << " pounds" << endl;
    cout << left << "The least amount of food eaten by any monkey  : " << right << setw(10) << minFood << " pounds" << endl;
    cout << left << "The largest amount of food eaten by any monkey: " << right << setw(10) << maxFood << " pounds" << endl;
}