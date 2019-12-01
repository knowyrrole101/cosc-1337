#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cstdio>

using namespace std;

// using pointers in classes
class Squares
{
    private:
        int length;
        int *sq; // Dynamically allocated array
    public:
        //constructor allocates storage for sequence of squares and creates the sequence
        Squares(int len)
        {
            length = len;
            sq = new int[length];
            for(int k=0;k<length;k++)
            {
                sq[k] = (k+1)*(k+1);
            }
            //Trace
            cout << "Construct an object of size: " << length << endl;
        }

        void print()
        {
            for(int k=0;k<length;k++)
            {
                cout << sq[k] << " ";
                cout << endl;

            }
        }
        // Deconstructor deallocates storage
        ~Squares()
        {   
            // Delete pointer array
            delete []sq;
            //Trace
            cout << "Destroy object of size " << length << endl;
        }
};

class Rectangle
{
    int height, width;
};

// Function accepts Class pointer 
void outputSquares(Squares *sqPtr)
{
    cout << "The list of squares is: ";
    //print pointer
    sqPtr->print();
}

int main()
{
    Squares *sqPtr = new Squares(3);
    outputSquares(sqPtr);

    // Assign pointer to class
    Rectangle *rectPtr = nullptr;
    Rectangle myRect;
    // Assign 
    rectPtr = &myRect;
    // To access attributes inside myRect through rectPtr
    (*rectPtr).width = 5;
    (*rectPtr).length = 10; 
    // Or through the structure pointer operator
    rectPtr->width = 10;
    rectPtr->length = 20;

    // If Class object takes two params in constructor
    rectPtr = new Rectangle(10,20);

    // Main dellocates the Squares Object
    delete sqPtr;
    delete rectPtr;

    return 0;
}