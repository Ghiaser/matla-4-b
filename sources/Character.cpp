#include "Character.hpp"
#include <iostream>

namespace ariel
{
    Character::Character(string name,Point location,int hitpoints):name(name),location(location),hitpoints(hitpoints){}

    bool Character::isAlive(){ return (hitpoints > 0);}
    double Character::distance(Character *other){ return location.distance(other->getLocation());}
    void Character::hit(int damage){
        if( !this->isAlive()){
            throw runtime_error("Character : this Character is already Dead!");
        }
        if( damage < 1){
            throw invalid_argument("Damage cannot be negative!");
        }
        hitpoints-=damage;
    }
    string Character::getName() const{return this->name;}
    Point Character::getLocation() const{return this->location;}
    void Character::setLocation(Point p){ this->location = p;}
    string Character::print(){
        if(isAlive()){
            return this->getName()+", Hp: "+std::to_string(this->getHitPoints())+", Location: "+this->getLocation().print();
        }else{
            return this->getName()+"]"+", Location: "+this->getLocation().print();
        }
    }

    void Character::setleaderOn(){
        this->isleader = true;
    }
    bool Character::isleaderOn(){
        return this->isleader;
    }

    void Character::setinTeam(){
        this->inteam = true;
    }
    bool Character::isInTeam(){
        return this->inteam;
    }

    /* methods to help with test */
    int Character::getHitPoints(){return this->hitpoints;}


}