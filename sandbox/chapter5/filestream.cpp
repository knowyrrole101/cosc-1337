#include <iostream>
#include <string>
#include <cmath>
// For formatting text with width, floating point precision.
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    // Reading txt data
    ifstream inputFile;

    inputFile.open("sample.txt");
    
    inputFile.close();

    ofstream outputFile;

    // Output the file;
    outputFile.open("myCFile.txt");

    // Write to file
    outputFile << "Big shot bob\n";
    outputFile << "This is line 2\n";
    outputFile << "We are writing files\n";
    outputFile << "in c++\n";

    outputFile.close();

    cout << "Done!!\n";

    inputFile.open("myCFile.txt");
    
    string text;

    // Stream a file to console.
    // for (int line=1; line<=4; line++){
    //     inputFile >> text;
    //     cout << text << endl;
    // };
    
    // File stream word by word
    if (inputFile){
        while(inputFile >> text) {
            cout << "Reading out: " << text << endl;
        };
    };
    // Stream a file line by line.  1`
    // while(getLine(inputFile, text)){
    //   cout << text << endl;
    // };
    return 0;
}