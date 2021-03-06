#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype> // character testing
#include <cstdio>
#include <memory> // Smart Pointers 
#include <sstream> 
#include <string>

using namespace std;

int main()
{
    char input;
    cout << "Enter a char:" << endl;
    cin.get(input);
    if (isalpha(input))
        cout << "Thats an alphanumeric" << endl;
    if (isdigit(input))
        cout << "Thats a digit" << endl;
    if (islower(input))
        cout << "Thats a lower" << endl;
    if (isupper(input))
        cout << "Thats a upper" << endl;
    if (isspace(input))
        cout << "Thats a space" << endl;

    input = toupper(input);
    cout << input << " this is upper!" << endl;
    input = tolower(input);
    cout << input << " this is lower!" << endl;

    // pointers and chars
    const char *p = nullptr, *q = nullptr;

    p = "Hello ";
    q = "Bailey ";

    cout << p << q << endl;

    // size_t matches pointer memory size
    cout << p << " is stored at " << (int)(size_t)p << endl;
    cout << q << " is stored at " << (int)(size_t)q << endl;

    cout << "String literal stored at " << (int)(size_t)"Literal" << endl;

    // String Literal as array
    const int SIZE = 20;
    char company[SIZE] = "Robotic Systems,inc";
    int count;
    for(count = 0; count<SIZE; count++)
    {
        cout << company[count];
        cout << endl;
    }

    // Pointers to char
    char name[] = "John Marks";
    char *na;
    na = name;
    cout << na << endl;

    // STRING/CHAR FUNCTIONS!!!!!!!!!!!!
    // STRLEN FUNCTIONS
    char str[] = "hello";
    int length = strlen(str);

    // strcat function - concatenate
    const int SIZE2 = 13; 
    char string1[SIZE2] = "Hello ";
    char string2[] = "World!";
    strcat(string1, string2);
    cout << string1 << endl;

    // strcopy function - string copy
    const int SIZE3 = 20;
    char name2[SIZE3];
    strcpy(name2, "Albert Einstein");

    cout << name2 << endl;

    // "somestring" == "somestring" will always equal false due to memory locations
    // Must use string comparison
    cout << strcmp("Mark", "Mark") << endl; // should return 0 if true
    if(strcmp("John", "John") == 0)
    {
        cout << true << endl;
    } else {
        cout << false << endl;
    }
    // USING FALSEY or NOT OPERATOR
    if((!strcmp("John", "John")) == 0)
    {
        cout << true << endl;
    } else {
        cout << false << endl;
    }

    // Sorting Strings Alphaetically
    // const int NAME_LENGTH_MOON = 9;
    // char name10[NAME_LENGTH_MOON], name12[NAME_LENGTH_MOON];
    // name10 = "MOON AHME";
    // name12 = "MOON BHME";

    // if(strcmp(name10, name12) < 0)
    // {
    //     cout << name10 << " then " << name12 << endl;
    // } else {
    //     cout << name12 << " then " << name10 << endl;
    // }

    string namesnstuff = "John 20 50";
    const char *cstr = "Amy 30 42";
    istringstream istr1(namesnstuff);
    istringstream istr2;
    ostringstream ostr;

    string name3;
    int score1, score2, average_score;

    // istring stream use.
    istr1 >> name3 >> score1 >> score2;
    average_score = (score1 + score2)/2;
    ostr << name << " has average score of " << average_score << endl; 
    cout << ostr.str();

    // Convert to hexadecimal
    ostr << hex;
    ostr << name << " has average score of " << average_score << endl; 
    cout << ostr.str();

    // convert string to double
    string string2convert;
    size_t pos;

    string2convert = "342.57isthenumber";
    // Parse double
    double decimal = stod(string2convert, &pos);
    cout << "The converted double is " << decimal << endl;
     
    //stoi(string, &pos) string to integer
    //string copy 
    string thisString = "Moon Ahmed";
    int k = 0;
    while(thisString[k] != ' ' && thisString[k] != '\0')
    {           
        cout << thisString[k] << endl;
        k++;
    }
   
    string someString;

    //string methods
    

    return 0;
}