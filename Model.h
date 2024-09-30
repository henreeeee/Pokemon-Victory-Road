#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include "GameObject.h"
#include "Trainer.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"
#include "WildPokemon.h"
#include <list>
#include <iterator>


class Model
{
    private:
    int time;
    list<GameObject*> object_ptrs;
    list<GameObject*> active_ptrs;
    list<PokemonCenter*> center_ptrs;
    list<PokemonGym*> gym_ptrs;
    list<Trainer*> trainer_ptrs;
    list<WildPokemon*> wildpokemon_ptrs;


    public:
    Model();
    ~Model();
    Trainer* GetTrainerPtr(int);
    PokemonCenter* GetPokemonCenterPtr(int);
    PokemonGym* GetPokemonGymPtr(int);
    bool Update();
    void Display(View&);
    void ShowStatus();
    void NewCommand(char type, int in_id, double x, double y);

    
};






#endif