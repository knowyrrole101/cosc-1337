#include <iostream>
#include <string>
#include <cmath>

using namespace std;
  
int main() {

    int books,
        months;
    double booksPerMonth;

    cout << "How many books plan to read" << endl;
    cin >> books;
    cout << "How many months will it take to read them all" << endl;
    cin >> months;

    // Type casting . This converts books INT to double for calculation purposes.
    //  It is a copy of books.
    booksPerMonth = static_cast<double>(books)/months;
    cout << "That is " << booksPerMonth << " books per month. \n";

    int number = 65;

    cout << number << endl;

    // This returns the char tied to 65 
    cout << static_cast<char>(number) << endl;
    return 0;
}