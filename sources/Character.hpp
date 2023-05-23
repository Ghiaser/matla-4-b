#pragma once
#include <string>
#include "Point.hpp"
#include <iostream>

using namespace std;


namespace ariel
{
class Character {                       // The class
private:                                // private Access specifier
    Point location;                     // Character location
    int hitpoints;                      // Hp
    string name;                        // Character name
    bool isleader = false;              // var to tell if character is a leader
    bool inteam = false;                // var to tell if character is in a team

public:                                 // Access specifier

    Character(string name,Point location,int hitpoints);

    virtual bool isAlive();
    virtual double distance(Character *other);
    virtual void hit(int damage);
    virtual string getName() const;
    virtual Point getLocation() const;
    virtual void setLocation(Point p);
    virtual string print();
    virtual void setleaderOn();
    virtual bool isleaderOn();

    virtual void setinTeam();
    virtual bool isInTeam();

    /* methods to help with test */
    virtual int getHitPoints();


};
}