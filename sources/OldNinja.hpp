#pragma once
#include "Character.hpp"


namespace ariel
{

class OldNinja: public Character {
  private:
    int speed;            // speed parameter

  public:

    OldNinja(string name, Point l):Character(name,l,150){
      this->speed = 8;
    }

    void move(Character *c);
    void slash(Character *c);
    string print() override;

 };

}