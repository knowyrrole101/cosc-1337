# Chapter 2 Notes     

1. Preprocessor directive - e.g #include <iostream> - Sets up source code for compiler. (header file)
    * Called a header file because it starts at top of program and includes brackets.
    * Iostream allows input/ouput to screen and read input from keyboard.
2. Namespace - e.g using namespace std; in order to access std to use the entities in iostream it must have access to std namespace.
3. Functions - e.g int main(){} - int represents indicates function sends integer value back to operating system when it is finished executing. 
    * return 0; usually indicates the program completed successfully
4. Print - cout Classified as a stream object. << sends string to cout. Stream insertion operator. 
    * cout << "hello world" << endl; or \n for newlines
    * literals - piece of data written directly into a programs code. (e.g. int apples; apples 20; cout << "There are " << apples << "apples! \n")
5. Reserved Identifiers/Key Words in C++:
    *alignas, alignof, and, and_eq, int, long, mutable, namespace, tempalte, this, or, false, break, bool, bitand, auto, asm, case, catch, char, char16_t, char32_t
6. Integer Data Types:
    * short int - 2 bytes range: -32k to 32k
    * unsigned short int - 2 bytes range: 0 to 65k
    * int - 4 bytes - -2Billion to +2 bilion
    * unsigned int - 4 bytes - 0 to +4billion
    * long int - 4 bytes
    * unsigned long int - 4 bytes
    * long long int - 8 bytes
    * unsigned long long int - 8 bytes
7. Floating Point Data Types - Similar to scientific notation 4.56 x 10^3. Mantissa is teh first part of the number. Mantissa multiplied by power of 10. 
    * Computers typically use e notation to represent floating point values. 4.728197E4 == 4.7228197x10^4 == 47,281.97
    * In c++ three data types can represent floating point numbers
    * float, double, long double - guranteed double at least as big as float, and long double as least as big as double
    * single precision - float - 4 bytes 
    * double precision - double - 8 bytes - +-1.7E+-308. Significant digits = 16
    * long double precision - long double - 8 bytes* 
8. Floating point literals - num = 14.725f; otherwise will throw warning. you can use e notation or decimal notation.
9. Char - Single character 1 byte of memory
    * e.g char bob = 'A';
    * When character stored in memory its stored as number. Represented in ASCII code (a number combo that represents a letter 65 is capital A, 66 capital B....)
10. Strings 
    * Because string literal can be virtually any length. C++ appends extra byte to its end and storing 0 in it. This is called null terminator or null character to mark end of string.
    * \0 not to be confused with ASCII CODE 48 which is '0'
    * each string contains +1 bytes to account for null terminator.
    * 'A' is char and stored as A in memory 1 byte
    * "A" is string and stored as A \0 in memory 2 bytes 
    * Char literals must be in single quotes. String literals in double quotes.
11. String Class - different data type than char. Can use #include <string> but not necessary will still compile technically.
12. sizeof - determine bytes of memory used by data type or variable. 
13. Variables - operand on the left side of equal sign is lvalue. Identifies places in memory. Rvalue on right. 
    * Every variable has scope.