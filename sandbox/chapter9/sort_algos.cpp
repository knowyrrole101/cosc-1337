#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cstdio>

using namespace std;

void bubbleSort(int numbers[], int SIZE);
void selectionSort(int numbers[], int SIZE);
void swap(int &num1, int &num2);

int main()
{      
    int size = 10;
    int numbers[] = {1,7,5,6,9,10,2,3,8,4};

    bubbleSort(numbers, size);
    selectionSort(numbers, size);
    
    for(int k = 0; k < size; k++)
    {
        cout << numbers[k] << endl;
    }
    return 0;
}

void bubbleSort(int numbers[], int SIZE)
{      
    int count;
    int maxElement;
    // Reverse array
    bool swapMade = true;
    // This top level loop keeps the swaps continuously going
    for(maxElement=SIZE-1; maxElement>0 && swapMade; count--)
    {   
        swapMade = false;
        for(count=0; count<SIZE-1; count++)
        {   
            if(numbers[count]>numbers[count+1])
            {   
                swap(numbers[count], numbers[count+1]);
                swapMade = true;
            }    
        }
    }
}

void selectionSort(int numbers[], int SIZE)
{
    int minIndex, minValue;
    
    // Loop to second from last
    for(int start=0; start<(SIZE-1); start++)
    {
        minIndex=start;
        minValue=numbers[start];
        
        // // For loop +1 Index Position
        for(int index=start+1; index < SIZE; index++)
        {
            if(numbers[index] < minValue)
            {   
                minIndex=index;
                minValue=numbers[index];
            }
        }
        // Swap the smallest value with the first index value
        swap(numbers[minIndex], numbers[start]);
    }
}

void swap(int &num1, int &num2)
{   
    int temp;
    temp = num2;
    num2 = num1;
    num1 = temp;
}
