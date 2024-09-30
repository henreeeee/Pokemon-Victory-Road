#include <iostream>
#include "PokemonGym.h"

using namespace std;

PokemonGym::PokemonGym():Building()
{
    this -> display_code = 'G';
    state = NOT_DEFEATED;
    max_number_of_battles = 10;
    num_battle_remaining = max_number_of_battles;
    PokeDollar_cost_per_battle = 1.0;
    experience_per_battle = 2;
    cout << "PokemonGym default constructed";
}

PokemonGym::PokemonGym(unsigned int max_battle, unsigned int health_loss, double PokeDollar_cost, unsigned int exp_per_battle, int in_id, Point2D in_loc)
{
    id_num = in_id;
    max_number_of_battles = max_battle;
    health_cost_per_battle = health_loss;
    experience_per_battle = exp_per_battle;
    PokeDollar_cost_per_battle = PokeDollar_cost;
    location = in_loc;
    display_code = 'G';
    state = 0;
    num_battle_remaining = max_number_of_battles;
    cout << "PokemonGym constructed" << endl;
}

PokemonGym::~PokemonGym()
{
    cout << "PokemonGym destructed" << endl;
}

double PokemonGym::GetPokeDollarCost(unsigned int battle_qty)
{
    return PokeDollar_cost_per_battle* battle_qty;
}

unsigned int PokemonGym::GetHealthCost(unsigned int battle_qty)
{
    return health_cost_per_battle * battle_qty;
}

unsigned int PokemonGym::GetNumBattlesRemaining()
{
    return num_battle_remaining;
}

bool PokemonGym::IsAbleToBattle(unsigned int battle_qty, double budget, unsigned int health)
{
    if (budget >= GetPokeDollarCost(battle_qty) && health >= GetHealthCost(battle_qty))
        return true;

    else
        return false;
}

unsigned int PokemonGym::TrainPokemon(unsigned int battle_units)
{
    if (battle_units > num_battle_remaining)
    {
        int temp;
        temp = num_battle_remaining;
        num_battle_remaining = 0;
        return temp*experience_per_battle;
    }
        

    else
    {
        num_battle_remaining -= battle_units;
        return battle_units*experience_per_battle; 
    }
    
}

unsigned int PokemonGym::GetExperiencePerBattle()
{
    return experience_per_battle;
}

bool PokemonGym::Update()
{
    if (num_battle_remaining == 0 && state != DEFEATED)
    {
        state = DEFEATED;
        display_code = 'g';
        cout << display_code << " " << id_num << " has been beaten";
        return true;
    }

    else
        return false;   
}

bool PokemonGym::passed()
{
    if (num_battle_remaining == 0)
        return true;
    
    else
        return false;
}

void PokemonGym::ShowStatus()
{
    cout << "PokemonGymStatus: ";
    GameObject::ShowStatus();
    cout << "Max number of battles: " << max_number_of_battles << " Health cost per battle: " << health_cost_per_battle << " PokeDollar per battle: " << health_cost_per_battle << " Experience per battle " << experience_per_battle << " " << num_battle_remaining << " battle(s) are remaining for this PokemonGym" << endl;
}
