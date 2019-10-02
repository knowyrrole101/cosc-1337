// Preprocessor directive - Include guard
// Prevents header file from being included more than once.
//  Means if not defined 
#ifndef RECTANGLE_H
#define RECTANGLE_H

// Rectangle Class Declaration
class Rectangle
{
    private:
        double length;
        double width;
    public:
        bool setLength(double);
        bool setWidth(double);
        double getLength();
        double getWidth();
        double calcArea();

};
#endif