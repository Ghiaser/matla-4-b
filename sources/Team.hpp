#pragma once
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <vector>

using namespace std;


namespace ariel
{
class Team {                            // The class
private:                                // private Access specifier
    Character* leader;                  // leader
    vector<Character*> fighters;         // team group of Fighters

public:                             // Access specifier
    
    Team(Character *lead);          // Constructor with parameters

    void add(Character *p);         // add a new member to the team

    virtual void attack(Team *other);       // attack another team

    virtual int stillAlive();               // return number of alive members in the team

    virtual void print();

    virtual Character* findNearestCharacter(Team *a,Character *ch);

    vector<Character*> getfighterslist(){
        return this->fighters;
    }

    Character* getLeader(){
        return this->leader;
    }

    void setLeader(Character *newLeader){
        this->leader = newLeader;
    }

    ~Team();                        // distructor



    /* methods to help with test */
    void getLeaderName();
};
}