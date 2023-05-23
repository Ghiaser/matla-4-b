#include "Cowboy.hpp"

using namespace std;

namespace ariel
{
    Cowboy::Cowboy(string name, Point l):Character(name,l,110),bullets(6){}
    void Cowboy::shoot(Character *c){
        if(!this->isAlive()){
            throw runtime_error("Cowboy shoot: this Character is already Dead!");
        }
        if(this == c){
            throw runtime_error("Cannot shoot themselve!");
        }
        if(this->hasboolets()){
            c->hit(10);
            this->bullets --;
        }
    }
    bool Cowboy::hasboolets(){ return (this->bullets > 0);}
    void Cowboy::reload(){
        if(!this->isAlive()){
            throw runtime_error("Cowboy reload: this Character is already Dead!");
        }
        this->bullets = 6;
    }
    string Cowboy::print(){
        if(this->isAlive()){
            return "Name: C "+Character::print();
        }else{
            return "Name: C ["+Character::print();
        }
    }

    /* methods to help with test */
    int Cowboy::getBullets(){ return this->bullets;}
}