#pragma once

#include <string>

using namespace std;

namespace ariel
{
class Point {                       // The class
private:                            // private Access specifier
    double _x;                      // X coordinate
    double _y;                      // Y coordinate

public:                             // Access specifier
    
    Point(double x=0,double y=0);   // Constructor with parameters

    double distance(Point p);       // return distance between the two points

    string print();          // Prints the two coordinates

    static Point moveTowards(Point src , Point dest , double distance);

    /* operator == to compare two points and check if equals*/
    friend bool operator ==(const Point& a, const Point& b);


};
}