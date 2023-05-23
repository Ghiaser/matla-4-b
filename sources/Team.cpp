#include "Team.hpp"
#include <limits.h>


namespace ariel
{

    Character* Team::findNearestCharacter(Team *a,Character *ch){
        Character* nearestCharacter = nullptr;
        int minDistance = INT_MAX;
        for(unsigned int j = 0; j < a->getfighterslist().size(); j++)
        {
            if((a->getfighterslist()[j]->isAlive()) && (a->getfighterslist()[j]->distance(ch) < minDistance) ){
                nearestCharacter = a->getfighterslist()[j];
                minDistance = a->getfighterslist()[j]->distance(ch);
            }
        }
        return nearestCharacter;
    }

    Team::Team(Character *lead):leader(lead){
        if(lead->isleaderOn() == true){
            throw runtime_error("This Fighter is already a leader in other team!");
        }
        if( lead->isInTeam() == true){
            throw runtime_error(" This Fighter is already in another team!");
        }
        lead->setleaderOn();
        this->fighters.push_back(leader);
        lead->setinTeam();
    }

    void Team::add(Character *p){
        if( this->fighters.size() >= 10){
            throw runtime_error(" The Team is Full");
        }
        if( p->isInTeam() == true){
            throw runtime_error(" This Fighter is already in another team!");
        }
        p->setinTeam();
        this->fighters.push_back(p);
    }

    void Team::attack(Team *other){
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
        if(!this->leader->isAlive()){
            Character* newLeader = findNearestCharacter(this,this->leader);
            this->leader = newLeader;
            if(newLeader == nullptr){
                return;
            }
        }
        /* second search for our enemy target from other team*/
        Character* enemyTarget = findNearestCharacter(other,this->leader);
        if(enemyTarget == nullptr){ /* if didnt find an alive enemy target to hit */
            return;
        }

        /* third -> shooting time */
        for(unsigned int j = 0; j < this->fighters.size(); j++)
        {
            if((this->fighters[j]->isAlive()) && dynamic_cast<Cowboy*>(this->fighters[j])){
                /* check if the enemy still alive, otherwise search for another enemy */
                if(!enemyTarget->isAlive()){
                    enemyTarget = findNearestCharacter(other,this->leader);
                    if(enemyTarget == nullptr){ /* if didnt find an alive enemy target to hit */
                        return;
                    }
                }
                if(dynamic_cast<Cowboy*>(this->fighters[j])->hasboolets()){
                    static_cast<Cowboy*>(this->fighters[j])->shoot(enemyTarget);
                }else{
                    static_cast<Cowboy*>(this->fighters[j])->reload();
                }
            }
        }
        for(unsigned int j = 0; j < this->fighters.size(); j++)
        {
            if((this->fighters[j]->isAlive())){
                if(!enemyTarget->isAlive()){ /* check if the enemy still alive, otherwise search for another enemy */
                    enemyTarget = findNearestCharacter(other,this->leader);
                    if(enemyTarget == nullptr){ /* if didnt find an alive enemy target to hit */
                        return;
                    }
                }
                if(dynamic_cast<OldNinja*>(this->fighters[j])){
                    if(this->fighters[j]->distance(enemyTarget) <= 1 ){
                        static_cast<OldNinja*>(this->fighters[j])->slash(enemyTarget);
                    }else{
                        static_cast<OldNinja*>(this->fighters[j])->move(enemyTarget);
                    }
                }
                if(dynamic_cast<YoungNinja*>(this->fighters[j])){
                    if(this->fighters[j]->distance(enemyTarget) <= 1 ){
                        static_cast<YoungNinja*>(this->fighters[j])->slash(enemyTarget);
                    }else{
                        static_cast<YoungNinja*>(this->fighters[j])->move(enemyTarget);
                    }
                }
                if(dynamic_cast<TrainedNinja*>(this->fighters[j])){
                    if(this->fighters[j]->distance(enemyTarget) <= 1 ){
                        static_cast<TrainedNinja*>(this->fighters[j])->slash(enemyTarget);
                    }else{
                        static_cast<TrainedNinja*>(this->fighters[j])->move(enemyTarget);
                    }
                }
            }
        }
        
    }

    int Team::stillAlive(){
        int counter=0;
        for(unsigned int j = 0; j < this->fighters.size(); j++)
        {
            if(this->fighters[j]->isAlive()){
                counter++;
            }
        }
        return counter;
    }
    
    void Team::print(){
        /* prints cowboys first then Ninjas after */
        for(unsigned int j = 0; j < this->fighters.size(); j++)
        {
            if(dynamic_cast<Cowboy*>(this->fighters[j]))
            cout << this->fighters[j]->print() << endl;
        }
        for(unsigned int j = 0; j < this->fighters.size(); j++)
        {
            if(! (dynamic_cast<Cowboy*>(this->fighters[j])))
            cout << this->fighters[j]->print() << endl;
        }
    }

    Team::~Team(){
        if(! this->leader){
            delete this->leader;
        }
        this->leader = nullptr;
        for(unsigned int j = 0; j < this->fighters.size(); j++)
        {
            if(! this->fighters[j]){
                delete this->fighters[j];
            }
            this->fighters[j] = nullptr;
        }
    }

    void Team::getLeaderName(){
        cout << this->leader->getName() << endl;
    }
}