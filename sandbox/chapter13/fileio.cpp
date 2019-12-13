#include <iostream> // io stream for printing/input
#include <fstream> // file stream
#include <string>

using namespace std;

int main()
{   

    // class 
    ifstream inFile;
    inFile.open("sometext.txt");
    
    string someText;

    // Error Handling
    if (inFile.fail()){
        cerr << "Error opening file" << endl;
        exit(1);
    }

    int x,y;
    inFile >> x >> y;
    cout << x << y << endl;

    int count = 1;
    string item;
    // Read through file
    while(!inFile.eof()){
        cout << count << endl;
        inFile >> item;
        if(item=="This"){ cout << item << endl;}
        count++;
    }
    cout << count << endl;
    // Close the stream
    inFile.close();

    ofstream outFile;
    // Open a new stream
    outFile.open("what.txt");
    // Add content
    outFile << "Billy Bob Thornton";
    // Outfile stream close
    outFile.close();

    
    return 0;
}