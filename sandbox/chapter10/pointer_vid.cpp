#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cstdio>

#define LOG(x) std::cout << x << std::endl

using namespace std;

int main()
{
    // // void* ptr = nullptr;

    // int var1 = 8; 
    // // Cast pointer to double
    // // double* ptr = (double*) &var1;
    // int* ptr = &var1;
    // // Deferencing is accessing the data
    // *ptr = 10.0;
    // // Write from or read the data in a pointer. Dereferencing

    // LOG(var1);
    
    char* buffer = new char[8];
    memset(buffer, 0, 8);

    // Pointer to a pointer Double Pointer!!
    char** ptr = &buffer;

    delete[] buffer;
    return 0;


}