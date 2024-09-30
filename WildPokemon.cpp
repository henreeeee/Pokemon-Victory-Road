#include <iostream>
#include "WildPokemon.h"
using namespace std;

WildPokemon::WildPokemon(string name, double attack, double health, bool variant, int id, Point2D in_loc)
:GameObject(in_loc,id,'W')
{
    id_num = id;
    location = in_loc;
    cout << "WildPokemon Constructed" << endl;
    state = IN_ENVIRONMENT;
}

WildPokemon::~WildPokemon()
{
    cout << "WildPokemon Destructed" << endl;
}

bool WildPokemon::isAlive()
{
    if (health != 0)
        return true;

    else
        return false;
}

void WildPokemon::follow(Trainer* t)
{
    current_trainer = t;
    state = IN_TRAINER;
    cout << "WildPokemon now following trainer" << endl;
}

bool WildPokemon::get_variant()
{
    return variant;
}

double WildPokemon::get_attack()
{
    return attack;
}

double WildPokemon::get_health()
{
    return health;
}

bool WildPokemon::get_in_combat()
{
    return in_combat;
}

bool WildPokemon::Update()
{
    if (this->isAlive() == 1)
    {
        state = DEAD;
    }

    else if (state = IN_TRAINER)
    {
        location = current_trainer->GetLocation();
    }
    
}

void WildPokemon::ShowStatus()
{
    cout << name << " Status: ";
    GameObject::ShowStatus();

    switch(state)
    {
        case DEAD:
        cout << "This WildPokemon is dead" << endl;
        break;

        case IN_ENVIRONMENT:
        cout << "Attack: " << attack << endl;
        cout << "Health: " << health << endl;
        cout << "Status: Alive" << endl;
        break;

        case IN_TRAINER:
        cout << "Attack: " << attack << endl;
        cout << "Health: " << health << endl;
        cout << "Status: Alive" << endl;        
        cout << "Status: Following Trainer" << endl;
    }
}