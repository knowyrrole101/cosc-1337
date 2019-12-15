#include <iostream>

using namespace std;
int main()
{
    std::string greeting = "hello";
    std::cout << greeting[0] << std::endl;
    std::cout << greeting.length() << std::endl;
    // c string is an array of characters 
    // Not reassignable
    char calebname[] = "Caleb"; //\0

    std::string someName;
    std::cout << "GWhat up!!" << std::endl;

    getline(std::cin, someName); 
    // cin.getline() // For numbers, doubles
    std::cout << someName << std::endl;

    char nullChar = '\0'; // null character
    char name1[10];
    // Last character in c string is always '\0'
    char name4[10] = {'J','o','h','n','\0'};
    // Equivalent to abov 
    char name2[16] = "Joseph"; // 16 size
    char name3[] = "Joseph"; // 7 size 
    // ADd string to cSTRING array
    char someRandomName[24];
    strcpy(someRandomName, "Moon Ahmed");
    
    char moonsCopy[30];

    strcpy(someRandomName, moonsCopy);
    // Returns len minus \0
    cout << strlen(someRandomName) << endl;
    
    //String COMPARISON
    if (strcmp(someRandomName, moonsCopy)){
        cout << someRandomName << " is less than " << moonsCopy << endl;
    } else {
        cout << " Long name!!!" << endl;
    }
    

    // // Illegal OPERATION
    // char sName[26];
    // sName = "Billy Bob";


    return 0;
}