#pragma once
#include "Character.hpp"


namespace ariel
{

class Cowboy: public Character {
  private:
    int bullets;            // Bullets start with 6
    int hitPoints;

  public:

    Cowboy(string name, Point l);

    void shoot(Character *c);
    bool hasboolets();
    void reload();
    string print() override;

    /* methods to help with test */
    int getBullets();

 };

}