#include <iostream> // Handle input/output 
#include <iomanip>  // I/O manupulator declarations
#include <string>   // string
#include <vector> // Vectors
using namespace std;
int main() 
{
    // Declare a vector
    vector<int> numbers(3);
    // Vector full of strings
    vector<string> moonsNames;
    // Declare vector with size
    vector<int> numbers1(10);
    // Initialize a base value 10 times with second argument in vectors
    vector<int> numbers2(10, 4);
    // Copying a vector
    vector<int> numbers3(numbers2);
    // Defines vector of length 3 with values 12,11,10 
    vector<int> length{12,11,10};
    // Vector of Double Floating Point
    vector<double> employees;

for(int count=0; count < 10; count++)
{
    cout << numbers3[count] << endl;
    // cout << numbers2[count] << endl;

}
cout << "Hello world!";
// Pass array val by reference so elements can be added to vector
for(int &val : numbers)
{
    cout << "Enter an integer value: ";
    cin >> val;
}

for(int &val : numbers)
{
    cout << val << endl;    
}
// When vector size does not exist like vector "numbers"
// use push back member function. This pushes value to back of vector. 

for(int count=0; count<20; count++)
{
    cout << "Enter some words: ";
    string temp;
    cin >> temp;
    moonsNames.push_back(temp);
}
// Cout the sizze of a vector
cout << "Vector size is: " << moonsNames.size();
// Removing elements from a vector 
// Pop last element off the vector
moonsNames.pop_back();
// To clear a vector out.
moonsNames.clear();
// Detecting whether vector is empty. returns boolean
// moonsNames.empty();

// Vector Member Functions
int index_position = 5;
moonsNames.at(index_position);
// Push a new element to last element of vector. Add a new element if full.
moonsNames.push_back("Big shot moon");
int n = 200;
moonsNames.resize(n);
// Return number of elements in vector
moonsNames.size();  
// Swap contents of vector
vector<string> someNewVector;
moonsNames.swap(someNewVector);
}