#ifndef PLAYER_X_H
#define PLAYER_X_H
#include "Player.h"

class Player_X : public Player
{
public:
    Player_X();
    virtual void add_score();
    virtual unsigned int get_score();
    virtual QString play_turn();
};

#endif // PLAYER_X_H
