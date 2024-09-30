#include <iostream>
#include "PokemonCenter.h"


using namespace std;

PokemonCenter::PokemonCenter():Building()
{
    display_code = 'C';
    potion_capacity = 100;
    num_potions_remaining = potion_capacity;
    pokedollar_cost_per_potion = 5;
    state = POTIONS_AVAILABLE;
    cout << "PokemonCenter default constructed" << endl;
}

PokemonCenter::PokemonCenter(int in_id, double potion_cost, unsigned int potion_cap, Point2D in_loc):Building()
{
    id_num = in_id;
    location = in_loc;
    pokedollar_cost_per_potion = potion_cost;
    potion_capacity = potion_cap;
    display_code = 'C';
    num_potions_remaining = potion_capacity;

    cout << "PokemonCenter constructed" << endl;
    state = POTIONS_AVAILABLE;
}

PokemonCenter::~PokemonCenter()
{
    cout << "PokemonCenter destructed" << endl;
}

bool PokemonCenter::HasPotions()
{
    if (state == 0)
        return true;
    else
        return false;
}

unsigned int PokemonCenter::GetNumPotionRemaining()
{
    return num_potions_remaining;
}

bool PokemonCenter::CanAffordPotion(unsigned int potion, double budget)
{
    if (budget >= pokedollar_cost_per_potion * potion)
        return true;
    else
        return false;
}

double PokemonCenter::GetPokeDollarCost(unsigned int potion)
{
    return potion * pokedollar_cost_per_potion;
}

unsigned int PokemonCenter::DistributePotion(unsigned int potion_needed)
{
    if (num_potions_remaining >= potion_needed)
    return num_potions_remaining -= potion_needed;

    else
    {
        int temp;
        temp = num_potions_remaining;
        num_potions_remaining = 0;
        return temp;
    }
    
}

bool PokemonCenter::Update()
{
    if (num_potions_remaining == 0 && state != NO_POTIONS_AVAILABLE)
    {
        state = NO_POTIONS_AVAILABLE;
        display_code = 'c';
        cout << "PokemonCenter " << id_num << " has ran out of potions";
        return true;
    }
    else
    {
        return false;
    }
}

void PokemonCenter::ShowStatus()
{
    cout << "PokemonCenter Status: ";
    Building::ShowStatus();
    cout << "PokeDollars per potion: " << pokedollar_cost_per_potion << " has " << num_potions_remaining << " potion(s) remaining" << endl;
}