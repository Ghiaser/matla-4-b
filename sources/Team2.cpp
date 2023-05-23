#include "Team2.hpp"
#include <limits.h>


namespace ariel
{
    Team2::Team2(Character *lead): Team(lead){
    }

    void Team2::attack(Team *other){
        if(other == nullptr){
            throw invalid_argument("Enemy Team is Null!");
        }
        if(this->stillAlive() == 0){
            throw runtime_error("Dead Team!");
        }
        if(other->stillAlive() == 0){
            throw runtime_error("Dead Team!");
        }
        if(this == other){
            throw runtime_error("Cannot attack same Team!");
        }
        /* first check if the leader still alive */
        if(!this->getLeader()->isAlive()){
            Character* newLeader = findNearestCharacter(this,this->getLeader());
            this->setLeader(newLeader);
            if(newLeader == nullptr){
                return;
            }
        }
        /* second search for our enemy target from other team*/
        Character* enemyTarget = findNearestCharacter(other,this->getLeader());
        if(enemyTarget == nullptr){ /* if didnt find an alive enemy target to hit */
            return;
        }

        /* third -> shooting time */
        for(unsigned int j = 0; j < this->getfighterslist().size(); j++)
        {
            if((this->getfighterslist()[j]->isAlive()) && dynamic_cast<Cowboy*>(this->getfighterslist()[j])){
                /* check if the enemy still alive, otherwise search for another enemy */
                if(!enemyTarget->isAlive()){
                    enemyTarget = findNearestCharacter(other,this->getLeader());
                    if(enemyTarget == nullptr){ /* if didnt find an alive enemy target to hit */
                        return;
                    }
                }
                /* queue shooters by when they joined the group */
                if(dynamic_cast<Cowboy*>(this->getfighterslist()[j])->hasboolets()){
                    static_cast<Cowboy*>(this->getfighterslist()[j])->shoot(enemyTarget);
                }else{
                    static_cast<Cowboy*>(this->getfighterslist()[j])->reload();
                }
                if(dynamic_cast<OldNinja*>(this->getfighterslist()[j])){
                    if(this->getfighterslist()[j]->distance(enemyTarget) <= 1 ){
                        static_cast<OldNinja*>(this->getfighterslist()[j])->slash(enemyTarget);
                    }else{
                        static_cast<OldNinja*>(this->getfighterslist()[j])->move(enemyTarget);
                    }
                }
                if(dynamic_cast<YoungNinja*>(this->getfighterslist()[j])){
                    if(this->getfighterslist()[j]->distance(enemyTarget) <= 1 ){
                        static_cast<YoungNinja*>(this->getfighterslist()[j])->slash(enemyTarget);
                    }else{
                        static_cast<YoungNinja*>(this->getfighterslist()[j])->move(enemyTarget);
                    }
                }
                if(dynamic_cast<TrainedNinja*>(this->getfighterslist()[j])){
                    if(this->getfighterslist()[j]->distance(enemyTarget) <= 1 ){
                        static_cast<TrainedNinja*>(this->getfighterslist()[j])->slash(enemyTarget);
                    }else{
                        static_cast<TrainedNinja*>(this->getfighterslist()[j])->move(enemyTarget);
                    }
                }
            }
        }
    }

    int Team2::stillAlive(){
        int counter=0;
        for(unsigned int j = 0; j < this->getfighterslist().size(); j++)
        {
            if(this->getfighterslist()[j]->isAlive()){
                counter++;
            }
        }
        return counter;
    }
    
    void Team2::print(){
        /* queue print by when they joined the group */
        for(unsigned int j = 0; j < this->getfighterslist().size(); j++)
        {
            cout << this->getfighterslist()[j]->print() << endl;
        }
    }

    Team2::~Team2(){
        if(! this->getLeader()){
            delete this->getLeader();
        }
        this->setLeader(nullptr);
        for(unsigned int j = 0; j < this->getfighterslist().size(); j++)
        {
            if(! this->getfighterslist()[j]){
                delete this->getfighterslist()[j];
            }
            this->getfighterslist()[j] = nullptr;
        }
    }
}