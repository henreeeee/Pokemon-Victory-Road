#include <iostream>
#include "GameCommand.h"
#include "Input_Handling.h"


void DoMoveCommand(Model& model, int trainer_id, Point2D p1)
{
    Trainer* T1 = model.GetTrainerPtr(trainer_id);

    if (model.GetTrainerPtr(trainer_id) != 0)
    {
        T1->StartMoving(p1);
        cout << "Moving " << model.GetTrainerPtr(trainer_id)->GetName() << " to " << p1 << endl;
    }
    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoMoveToCenterCommand(Model& model, int trainer_id, int center_id)
{
    Trainer* T1 = model.GetTrainerPtr(trainer_id);
    PokemonCenter* G1 = model.GetPokemonCenterPtr(center_id);

    if (T1 != 0 && G1 != 0)
    {
        T1 -> StartMovingToCenter(G1);
        cout << "Moving " << T1->GetName() << " to " << G1->GetId() << endl; 
    }

    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoMoveToGymCommand(Model& model, int trainer_id, int gym_id)
{
    Trainer* T1 = model.GetTrainerPtr(trainer_id);
    PokemonGym* G1 = model.GetPokemonGymPtr(gym_id);

    if (T1 != 0 && G1 != 0)
    {
        T1->StartMovingToGym(G1);
        cout << "Moving " << T1->GetName() << " " << G1->GetId() << endl;
    }

    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoStopCommand(Model & model, int trainer_id) 
{
    if (model.GetTrainerPtr(trainer_id) != 0)
    {
        cout << "Stopping " << model.GetTrainerPtr(trainer_id)->GetName() << endl;
    }

    else
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoBattleCommand(Model& model, int trainer_id, unsigned int battles)
{
    if (model.GetTrainerPtr(trainer_id) != 0)
    {
        model.GetTrainerPtr(trainer_id)->StartBattling(battles);
        cout << model.GetTrainerPtr(trainer_id)->GetName() << " is battling" << endl;
    }

    else 
    cout << "Error: Please enter a valid command!" << endl;
}

void DoRecoverInCenterCommand(Model& model, int trainer_id, unsigned int potions_needed)
{
    if (model.GetTrainerPtr(trainer_id) != 0)
    {
        model.GetTrainerPtr(trainer_id)->StartRecoveringHealth(potions_needed);
        cout << "Recovering " << model.GetTrainerPtr(trainer_id)->GetName() << "'s Pokemon's health" << endl;
    }

    else 
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
}


void DoCommands(Model& model)
{
    char input;
    cout << "Please enter command (m, c, g, s, p, b, a, r, q, n):";
    cin >> input;
    if(!cin)
        throw Invalid_Input("Invalid");
    int id1,id2;
    double x,y;
    unsigned int amount;
    Point2D point;
    View view;
    
    while (input != 'q')
    try{
    switch (input)
    {
    case 'm':
       
        cout << "Enter ID and location:";
        cin >> id1 >> x >> y;
        if(!cin)
            throw Invalid_Input("Invalid");
        point.x = x;
        point.y =y;
        DoMoveCommand(model, id1, point);
        model.Update();
        model.ShowStatus();
        model.Display(view);
        cout << "Please enter command (m, c, g, s, p, b, a, r, q, n):";
        cin >> input;
        break;

    case 'c':
        cout << "Enter Trainer ID and Center ID:";
        cin >> id1 >> id2;
        if(!cin)
            throw Invalid_Input("Invalid");
        DoMoveToCenterCommand(model, id1, id2);
        model.Update();
        model.ShowStatus();
        model.Display(view);
        cout << "Please enter command (m, c, g, s, p, b, a, r, q, n):";
        cin >> input;
        break;

    case 'g':
        cout << "Enter Trainer ID and Gym ID:";
        cin >> id1 >> id2;
        if(!cin)
            throw Invalid_Input("Invalid");        
        DoMoveToGymCommand(model, id1, id2);
        model.Update();
        model.ShowStatus();
        model.Display(view);
        cout << "Please enter command (m, c, g, s, p, b, a, r, q, n):";
        cin >> input;
        break;

    case 's':
        cout << "Enter Trainer ID";
        cin >> id1;
        if(!cin)
            throw Invalid_Input("Invalid");
        DoStopCommand(model, id1);
        model.Update();
        model.ShowStatus();
        model.Display(view);
        cout << "Please enter command (m, c, g, s, p, b, a, r, q, n):";
        cin >> input;
        break;
    
    case 'p':
        cout << "Enter Trainer ID and potion amount:";
        cin >> id1 >> amount;
        if(!cin)
            throw Invalid_Input("Invalid");
        DoRecoverInCenterCommand(model, id1, amount);
        model.Update();
        model.ShowStatus();
        model.Display(view);
        cout << "Please enter command (m, c, g, s, p, b, a, r, q, n):";
        cin >> input;
        break;

    case 'b':
        cout << "Enter Trainer ID and battle amount:";
        cin >> id1 >> amount;
        if(!cin)
            throw Invalid_Input("Invalid");
        DoBattleCommand(model, id1, amount);
        model.Update();
        model.ShowStatus();
        model.Display(view);        
        cout << "Please enter command (m, c, g, s, p, b, a, r, q, n):";
        cin >> input;
        break;
    
    case 'a':
        
        DoAdvancedCommand(model,view);
        model.Update();
        model.ShowStatus();
        model.Display(view);        
        cout << "Please enter command (m, c, g, s, p, b, a, r, q, n):";
        cin >> input;
        break;

    case 'r':
        
        DoRunCommand(model,view);
        model.Update();
        model.ShowStatus();
        model.Display(view);
        cout << "Please enter command (m, c, g, s, p, b, a, r, q, n):";
        cin >> input;
        break;

    case 'n':
        char type;
        int in_id;

        cout << "Enter Parameters for new object (type,id,x,y): " << endl;
        cin >> type >> in_id >> x >> y;
        if(!cin)
            throw Invalid_Input("Invalid");
        model.NewCommand(type,in_id,x,y);
        model.Update();
        model.ShowStatus();
        model.Display(view);
        cout << "Please enter command (m, c, g, s, p, b, a, r, q, n):";
        cin >> input;
        break;

    default:
        exit(1);
        break;
    }
    }
    catch (Invalid_Input& except)
    {
        cout << "Invalid input - " << except.msg_ptr << endl;
        //https://cplusplus.com/forum/beginner/274981/
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}


void DoAdvancedCommand(Model& model, View& view)
{
    model.Update();
    model.Display(view);
    model.ShowStatus();
    cout << "Advancing one tick" << endl;
}

void DoRunCommand(Model& model, View& view)
{
    int count = 0;
    while (model.Update() == 0 && count != 5)
    {
        model.Update();
        count++;
    }

    cout << "Advancing to next event" << endl;
}
