#include "OldNinja.hpp"

namespace ariel
{
    void OldNinja::move(Character *c){
        if( !this->isAlive()){
            throw runtime_error("this Ninja is already Dead!");
        }
        if( c == NULL){
            throw runtime_error("Other Ninja doesnt exist!");
        }
        this->setLocation( (this->getLocation().moveTowards(this->getLocation(),c->getLocation(),this->speed)) );
    }

    void OldNinja::slash(Character *c){
        if( !this->isAlive()){
            throw runtime_error("this Ninja is already Dead!");
        }
        if( c == NULL){
            throw runtime_error("Other Ninja doesnt exist!");
        }
        if( c == this){
            throw runtime_error("cant slash themselves!");
        }
        if(this->distance(c) <= 1){                 // distance should be less than 1 meter, otherwise nothing happen
            c->hit(40);
        }
    }

    string OldNinja::print(){
        if(this->isAlive()){
            return "Name: N "+Character::print();
        }else{
            return "Name: N ["+Character::print();
        }
    }
}