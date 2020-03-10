#ifndef PLAYER_O_H
#define PLAYER_O_H
#include "Player.h"

class Player_O : public Player
{
public:
    Player_O();
    virtual void add_score();
    virtual unsigned int get_score();
    virtual QString play_turn();
};

#endif // PLAYER_O_H
