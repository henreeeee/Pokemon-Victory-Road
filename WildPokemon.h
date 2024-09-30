#ifndef WILDPOKEMON_H
#define WILDPOKEMON_H

#include <iostream>
#include "GameObject.h"
#include "Trainer.h"

using namespace std;

enum WildPokemonStates
{
    IN_ENVIRONMENT = 0,
    IN_TRAINER = 1,
    DEAD = 2
};

class WildPokemon:public GameObject
{
    protected:
    double attack = 5;
    double health = 2;
    bool variant = false;
    bool in_combat;
    string name;
    Trainer* current_trainer;

    public:
    WildPokemon(string, double, double, bool, int, Point2D);
    virtual ~WildPokemon();
    void follow(Trainer*);
    bool get_variant();
    double get_attack();
    double get_health();
    bool get_in_combat();
    bool Update();
    void ShowStatus();
    bool isAlive();
};




#endif