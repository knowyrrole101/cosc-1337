#include <iostream>
#include <string>
#include <cmath>
// For formatting text with width, floating point precision.
#include <iomanip>

using namespace std;

int main() {

    int num1 = 555, num2 = 888, num3 = 999;
    double num4 = 5.5522255, num5 = 6.77722227, num6 = 45.90922269;

    // Width for printing
    cout << setw(5) << num1 << setw(5) << num2 << setw(5) << num3 << endl;

    // Precision for floating points
    cout << setprecision(7) << num4 << endl; 
    cout << setprecision(4) << num4 << endl; 
    cout << setprecision(2) << num4 << endl; 
    cout << setprecision(1) << num4 << endl; 

    

    //  Sets fixed precision afted decimal place
    cout << fixed << setprecision(2);
    double bigNum = 1.4568e+005;
    double bigtimeNum = 1456.0;
    cout << bigNum << endl;
    cout << bigtimeNum << endl;

    string month = "January",
            month2 = "February",
            month3 = "March";

    int days1 = 31,
        days2 = 18,
        days3 = 31;
    
    double high1 = 22.6,
            high2 = 37.4,
            high3 = 53.9;
    
    // Fixed decimals, left right aligning, etc.
    cout << fixed << showpoint << setprecision(1);
    cout << "Month       Days          High\n";
    cout << left << setw(12) << month 
         << right << setw(4) << days1 << setw(14) << high1 << "\n";

    // Grabbing input strings
    string name, 
            city;
    
    name = "Bob"; 
    cout << name << endl; 

    cout << "Please enter your name: ";
    // Grabs entire line including spaces
    getline(cin, name);
    cout << "Please enter city: ";
    getline(cin, city);
    cout << "Your name is " << name << " and you are from " << city << "!" << endl;

    // Character storage
    char ch;
    
    cout << "Program has paused press [Enter] to continue." << endl;
    cin.get(ch);

    cout << "Program has paused for a second time press [Enter] to continue." << endl;
    ch = cin.get();

    // String Functions
    string state = "New Jersey";
    int state_size = state.length();

    // Way to assign fixed number of spaces
    // string fixedsign;
    // fixedsign.assign(22, "b ");
    // cout << fixedsign << endl;

    string firstName = "Moon";
    firstName += " Ahmed";
    cout << firstName << endl;

    string lastName, fullName;
    string stars;
    int numStars;

    cout << "Enter first name: ";
    getline(cin, firstName);

    cout << "Enter last name:";
    getline(cin, lastName);

    fullName += firstName + " " + lastName;

    numStars = fullName.length();
    stars.assign(numStars, '*');

    cout << endl;
    cout << stars << endl;
    cout << fullName << endl;
    cout << stars << endl;


    // C STRINGS!!!!
    /* Size declarator. 10 tells how many cells to 
    hold the chars */
    char word[10] = "hello";
    const int SIZE = 12;
    char gname[SIZE],
            cname2[SIZE];

    // Include the space when using
    strcpy (gname, "Mikey");
    strcpy (cname2, gname);

    cout << gname << endl;
    cout << cname2 << endl;

    // Example of how to copy one c-string to another
    const int BIGSIZE = 81;
    char sentence[BIGSIZE];

    cout << "Enter a sentence: ";
    cin.getline(sentence, BIGSIZE);
    cout << "You entered: " << sentence << endl;



    return 0;
}