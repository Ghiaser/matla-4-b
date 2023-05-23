#pragma once
#include "Character.hpp"


namespace ariel
{

class TrainedNinja: public Character {
  private:
    int speed;            // speed parameter

  public:

    TrainedNinja(string name, Point l):Character(name,l,120){
      this->speed = 12;
    }

    void move(Character *c);
    void slash(Character *c);
    string print() override;

 };

}