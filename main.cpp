#include <iostream>
#include "Point2D.h"
#include "Vector2D.h"
#include "Building.h"
#include "GameCommand.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Trainer.h"
#include "Model.h"
#include "View.h"
#include "WildPokemon.h"
#include "Input_Handling.h"

using namespace std;

int main()
{    
    View view;
    Model model1;
    view.Clear();
    view.Draw();
    model1.Update();
    model1.ShowStatus();
    model1.Display(view);
 
    DoCommands(model1); 


    return 0;
}