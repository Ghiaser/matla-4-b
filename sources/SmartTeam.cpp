#include "SmartTeam.hpp"
#include <limits.h>


namespace ariel
{
    SmartTeam::SmartTeam(Character *lead): Team(lead){
    }

    Character* mostDamagedEnemy(Team *enemyTeam){
        Character* mDEnemy = nullptr;
        int minHp = INT_MAX;
        for(unsigned int j = 0; j < enemyTeam->getfighterslist().size(); j++)
        {
            if((enemyTeam->getfighterslist()[j]->isAlive()) && (enemyTeam->getfighterslist()[j]->getHitPoints() < minHp) ){
                mDEnemy = enemyTeam->getfighterslist()[j];
                minHp = enemyTeam->getfighterslist()[j]->getHitPoints();
            }
        }
        return mDEnemy;
    }

    /* fights on two sides :
            ninjas attack the closest alive enemies and cowboys attack the most damaged enemies */

    void SmartTeam::attack(Team *other){
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

        /* third -> shooting time */
        for(unsigned int j = 0; j < this->getfighterslist().size(); j++)
        {
            if((this->getfighterslist()[j]->isAlive()) && dynamic_cast<Cowboy*>(this->getfighterslist()[j])){
                /* search for most damaged enemy so cowboys can hit first */
                Character* enemyTarget = mostDamagedEnemy(other);
                if(enemyTarget == nullptr){ /* if didnt find an alive enemy target to hit */
                    return;
                }
                /* queue shooters by when they joined the group */
                if(dynamic_cast<Cowboy*>(this->getfighterslist()[j])->hasboolets()){
                    static_cast<Cowboy*>(this->getfighterslist()[j])->shoot(enemyTarget);
                }else{
                    static_cast<Cowboy*>(this->getfighterslist()[j])->reload();
                }
                /* search for the closest enemy to each ninja */
                enemyTarget = findNearestCharacter(other,this->getfighterslist()[j]);
                if(enemyTarget == nullptr){ /* if didnt find an alive enemy target to hit */
                    return;
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

    int SmartTeam::stillAlive(){
        int counter=0;
        for(unsigned int j = 0; j < this->getfighterslist().size(); j++)
        {
            if(this->getfighterslist()[j]->isAlive()){
                counter++;
            }
        }
        return counter;
    }
    
    void SmartTeam::print(){
        /* queue print by when they joined the group */
        for(unsigned int j = 0; j < this->getfighterslist().size(); j++)
        {
            cout << this->getfighterslist()[j]->print() << endl;
        }
    }

    SmartTeam::~SmartTeam(){
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