#ifndef TRAINER_H
#define TRAINER_H
#include <iostream>
#include <string>
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "GameObject.h"

enum TrainerStates {
STOPPED = 0,
MOVING = 1,
FAINTED = 2,
AT_CENTER = 3,
IN_GYM = 4,
MOVING_TO_CENTER = 5,
MOVING_TO_GYM = 6,
BATTLING_IN_GYM = 7,
RECOVERING_HEALTH = 8
};

class Trainer:public GameObject
{
    public:
    Trainer();
    Trainer(char);
    Trainer(string, int, char, unsigned int, Point2D);
    virtual ~Trainer();
    void StartMoving(Point2D);
    void StartMovingToGym(PokemonGym*);
    void StartMovingToCenter(PokemonCenter*);
    void StartBattling(unsigned int);
    void StartRecoveringHealth(unsigned int);
    void Stop();
    bool HasFainted();
    virtual bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
    string GetName();

    protected:
    bool UpdateLocation();
    void SetupDestination(Point2D);

    private:
    double speed;
    bool is_at_center = false;
    bool is_IN_GYM = false;
    unsigned int health = 20;
    unsigned int experience = 0;
    double PokeDollars = 20;
    unsigned int battles_to_buy = 0;
    unsigned int potions_to_buy = 0;
    string name;
    PokemonCenter* current_center = 0;
    PokemonGym* current_gym = 0;
    Point2D destination;
    Vector2D delta;

    
};

static double GetRandomAmountOfPokeDollars();

#endif