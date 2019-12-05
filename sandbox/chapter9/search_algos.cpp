#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cstdio>

using namespace std;

int linearSearch(int array[], int size, int value);
int binarySearch(const int array[], int size, int value);


int main()
{   
    int SIZE = 9;
    int myNumbers[] = {1,2,5,6,7,8,15,3,4};
    
    int found = linearSearch(myNumbers, SIZE, 6);
    cout << "The index position for item is: " << found << endl;

    int SIZE2 = 8;
    int myNumbers2[] = {1,12,123,4543,0,123,567,19};
    

    return 0;
}
int linearSearch(int array[], int size, int value)
{
    int index = 0;
    int position = -1;
    bool found = false;

    while(index < size && !found)
    {
        if(array[index] == value)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position; // Return Index Position
}

int binarySearch(const int array[], int size, int value)
{
    int first = 0,
        last = size - 1,
        middle;

    int position = -1; // Random Value doesn't need to be -1 per se
    bool found = false;

    while(!found && first <= last)
    {   
        // Start parsing logic here
        middle = (first+last)/2;
        if(array[middle] == value)
        {
            found = true;
            position = middle;
        } else if(array[middle]>value) {
            last = middle - 1;
        } else{
            first = middle - 1;
        }
    }
    return position; 
}