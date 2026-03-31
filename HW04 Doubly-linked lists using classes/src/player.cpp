// include the header file here
#include "../include/player.h"

// add all your player functions in here.
Player *newPlayer(std::string name, int num_goals){
    Player *player = new Player();
    player->name = name;
    player->num_goals = num_goals;

    return player;
}

// Allocate a copy of the player record
Player *copyPlayer(const Player *p){
    if(!p){
        return nullptr;
    }
    Player *player = new Player();
    player->name = p->name;
    player->num_goals = p->num_goals;
    return player;
}

// Deallocate a player record
void deletePlayer(Player *p){
    delete p;
}

// Print player record
void printPlayer(const Player *p){
    if(!p){
         std::cout << "No player found!\n";
    }
       
    else{
        std::cout << "Player name: " << p->name << "\n";
        std::cout << "Total goals: " << p->num_goals << "\n";
    }
}