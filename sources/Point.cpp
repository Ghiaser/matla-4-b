#include "Point.hpp"
#include <cmath>
#include <iostream>


namespace ariel
{

    Point::Point(double x,double y):_x(x),_y(y){}

    double Point::distance(Point p){return sqrt( ( (pow((this->_x  - p._x),2)) + (pow((this->_y  - p._y),2)) ) );}

    string Point::print(){return "("+ std::to_string(this->_x) + ","+std::to_string(this->_y)+")";}

    Point Point::moveTowards(Point src , Point dest , double distance){
        if(distance < 0){throw invalid_argument("Distance should be Positive!");}
        double dist = src.distance(dest);
        if(distance < dist){
            return (Point( (src._x + ((dest._x - src._x)*(distance/dist)) ) , (src._y + ((dest._y - src._y)*(distance/dist)) ) ));
        }else{
            return dest;
        }
    }

    /* == */
    bool operator ==(const Point& a, const Point& b){
        return( ((a._x == b._x) && (a._y == b._y)) );
    }

}