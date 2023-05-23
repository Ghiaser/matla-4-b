#pragma once
#include "Team.hpp"

using namespace std;


namespace ariel
{
class SmartTeam : public Team{              // The class
public:                             // Access specifier
    
    SmartTeam(Character *lead);          // Constructor with parameters

    void attack(Team *other) override;       // attack another team

    int stillAlive() override;               // return number of alive members in the team

    void print() override;

    ~SmartTeam();                        // distructor
};
}