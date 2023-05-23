#pragma once
#include "Character.hpp"


namespace ariel
{

class YoungNinja: public Character {
  private:
    int speed;            // speed parameter

  public:

    YoungNinja(string name, Point l):Character(name,l,100){
      this->speed = 14;
    }

    void move(Character *c);
    void slash(Character *c);
    string print() override;

 };

}