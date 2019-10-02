#include <iostream>
#include <string>
#include <cmath>
// For formatting text with width, floating point precision.
#include <iomanip>

using namespace std;

class Circle 
{
    private: // Access Specificiers (Pub and Priv.)
        double radius;
    
    public: // Access Specifiers
        // inline class functions/methods
        void setRadius(double r){
            radius = r;
        };
        double calcArea(){
            return 3.14 * pow(radius, 2 );
        };
        // Put Function prototype in class
        void setMyName(string);
};

// creating class methods outside the class ()
void Circle::setMyName(string myName)
{   
    cout << "Hello from circle your name is: " << myName << endl;
};

class Rectangle
{
    private:
        double length;
        double width;
    public:
        Rectangle() { // constructor function
            width = 1;
            cout << "Initializing the Rectangle Class!" << endl;
        };
        // Overloading Constructors. First One is default constructor
        Rectangle(int bigConstructor){
            width = bigConstructor;
            cout << "Initializing the Rectangle Class with a super big width!!" << endl;
        };

        // Overloading Constructors

        void setLength(double);
        void setWidth(double);
        double getLength();
        double getWidth();
        double calcArea();
};

// Constructor can be put outside class as well

void Rectangle::setLength(double len){
    length = len;
};

void Rectangle::setWidth(double w) {
    width = w;
};

double Rectangle::getWidth() {
    return width;
};

double Rectangle::getLength() {
    return length;
};

double Rectangle::calcArea() {
    return width*length;
};

class Person
{
    private:
        string firstName, lastName;

    public:
        Person(){
            cout << "Creating a person without name" << endl;
        }
        Person(string first, string last){
            firstName = first;
            lastName = last;

        }

        void getName() {
            cout << "Your name is: " << firstName << " " << lastName << endl; 
        }


};

// Person::~Person() //Destruction Function running for Person class.
// {
//     cout << "Destructor now running!" << endl;
// }

// Function Prototype 1; Creates and returns a Person object
Person createPerson();
// Function Prototype 2
void showPerson(const Person &newPerson); // reference to a Person object

Person createPerson(){
    Person tempPerson;
    string firstName, lastName;
    cout << "Enter First Name" << endl;
    cin >> firstName;
    cout << "Enter Last Name" << endl;
    cin >> lastName;
    //  This function returns a Class Object
    // Person class object is returned. So declared at beginning of function
    return tempPerson;

}

void showPerson(const Person &newPerson){
    newPerson.name
}


int main() {
    Circle circle1, circle2;

    circle1.setRadius(1); // Set radius for circle 1
    circle2.setRadius(3);
    circle1.setMyName("Moon Ahmed Bigsly");
    // Call class method
    cout << "The area of circle1 is: " << circle1.calcArea() << endl;
    cout << "The area of circle2 is: " << circle2.calcArea() << endl;

    // Rectangle class
    Rectangle rect1;

    Person moon("Moon", "Ahmed");
    moon.getName();



    rect1.setLength(14);
    rect1.setWidth(14);
    double wid = rect1.getWidth();
    double len = rect1.getLength();
    
    Rectangle rect2(111);
    cout << rect2.getWidth() << endl;

    cout << "The length is: " << len << " and the width is: " << wid << endl;
    cout << "The area is: " << rect1.calcArea() << endl;

    Person newPerson = createPerson();

    return 0;
};

