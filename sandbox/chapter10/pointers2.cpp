#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <memory> // Smart Pointers 

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
    public:
        int height;
        int width;
    Rectangle()
    {
        cout << "Creating rectangle" << endl;
   
    }
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

//     // Assign pointer to class
//     //*** Local object accessed through a pointer
    Rectangle *rectPtr = nullptr;
    Rectangle myRect;
//     // Assign 
    rectPtr = &myRect;
//     // To access attributes inside myRect through rectPtr
    (*rectPtr).width = 5;
    (*rectPtr).height = 10; 
//     // Or through the structure pointer operator
    rectPtr->width = 10;
    rectPtr->height = 20;

    // *** Dynamically allocated object through pointer
    // If Class object takes two params in constructor
    // rectPtr = new Rectangle(10,20);

    // // Main dellocates the Squares Object
    // delete sqPtr;
    // delete rectPtr;
    /* SMART POINTERS!!!!*/
    // Unique Pointer 
    // unique_ptr class

    unique_ptr<int> uniqueInt(new int); // unique pointer class
    unique_ptr<int> uniqueInt2;
    uniqueInt2 = unique_ptr<int>(new int);

    *uniqueInt = *uniqueInt + 3;
    *uniqueInt2 = 12; 
    // Cant assign existing unique ptr to another one you have to use move function
    unique_ptr<int> bigNum(new int);
    unique_ptr<int> bigNum2(new int);
    bigNum2 = move(bigNum);

    cout << bigNum2 << endl; //Memory address
    cout << *bigNum2 << endl;; //Value
    
    bigNum2.reset(); //Reset unique pointer to null pointer 
    // bugNum2 = nullptr; //Reset unique pointer to null pointer 
    // Pass by reference unique pointer
    // void somefunction(unique_ptr<int>& someUniquePtr){}
    
    // UNique pointer call delete if pointing to an array of objects
    unique_ptr<int[]> someUniquePtrArray(new int[5]); // Unique Pointer array

    // Shared ptr class
    // Shared pointer to manage dynamically allocate object that can have more than one owner
    shared_ptr<int>
    
    
    
    
    
    
    return 0;
}