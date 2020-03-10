#ifndef PLAYER_H
#define PLAYER_H
#include <QString>

class Player
{
protected:
    unsigned int score;
public:
    Player();
    virtual void add_score() = 0;
    virtual unsigned int get_score() = 0;
    virtual QString play_turn() = 0;
};

#endif // PLAYER_H
