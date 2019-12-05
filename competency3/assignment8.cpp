//******************************************************************
// Test Scores - Assignment 8
// Programmer: Mamun Ahmed
// Completed : 11/30/2019
// Status    : Completed
//
// Program receives input from user to get student class size.
// From there it creates dynamic array tied to a pointer named students
// User input is then required (and validated) to grab test scores from
// all students. Once completed (and validated) an table is output.
// Table contains all data that is sorted (using selection sort algorithm)
// to display in ascending order all student test scores. Average is 
// computed as well using a function that returns the floating point and
// displays in the table at the bottom.
//*********************************************************************

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cstdio>

using namespace std;

// Function Prototypes 
void getStudentGrades(int *students, int size);
void sortStudentGrades(int *students, int size);
float classAverage(int *students, int size);
void displayTable(int *students, int size);

// Utility Function for swapping in selection sort algorithm
void swap(int &a, int &b);

int main()
{   int size; // Student Size
    int *students = nullptr; // Students pointer array
    
    // Grab User Input for Total number of students
    cout << "How many students are in the class: ";
    cin >> size;
    cout << endl;
    
    students = new int[size]; // Allocate an array of size N
    getStudentGrades(students, size);
    sortStudentGrades(students, size);
    displayTable(students, size);

    delete students; // Delete pointer to avoid memory leaks
    return 0;
}

// Function to Grab Student Grades and Store in Students Array
void getStudentGrades(int *students, int size)
{   
    int grade; // Temp variable to store grade
    for(int count=0; count < size; count++)
    {   
        bool inserted = false;
        /** Validate Grade to be input and pass to appropriate
            *students array index **/
        while(inserted==false)
        {
            cout << "Enter Student " << count+1 << "'s Grade: ";
            cin >> grade;
            if(grade >= 0 && grade <= 105)
            {   
                students[count] = grade;
                inserted = true;
            } else {
                cout << "Enter a valid grade between 0 and 105!!" << endl;    
            }

        }
    }
}

// Selection Sort Algorithm to Sort Grades
void sortStudentGrades(int *students, int size)
{
    int minIndex, minValue;
    int start;
    // Main Execution Loop
    for(start=0; start < (size-1); start++)
    {
        minIndex = start;
        minValue = students[minIndex];
        for(int index=start+1; index < size; index++)
        {
            if(students[index] < minValue)
            {   
                minIndex = index;
                minValue = students[index];
            }
        }
        // Swap 
        swap(students[minIndex], students[start]);
    }
}

// Calculate and return a floating point class test average
float classAverage(int *students, int size)
{   
    
    float sumTestScores; // Temp variable to store test scores
    sumTestScores = 0.0;
    
    int count;
    // Sum all test scores 
    for(count=0; count < size; count++)
    {
        sumTestScores += students[count];
    }
    return (sumTestScores/size);
}

// Display Table of Student Test Data
void displayTable(int *students, int size)
{       
    cout << fixed << showpoint << setprecision(2); // Set Floating Point Precision
    cout << endl;
    cout << right << setw(20) << "Grade" << endl;
    cout << right << setw(20) << "-----" << endl;
    int count;
    for(count=0; count < size; count++)
    {   
        cout << right << setw(20) << students[count] << endl;
    }
    cout << right << setw(20) << "-----" << endl;
    cout << left << setw(10) << "Average: " << right << setw(10) << classAverage(students, size) << endl;
}

// Utility Function to help index values
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}