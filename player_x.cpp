#include "player_x.h"

Player_X::Player_X()
{
    score = 0;
}

void Player_X::add_score()
{
    score = score + 1;
}

unsigned int Player_X::get_score()
{
    return score;
}

QString Player_X::play_turn()
{
    return "X";
}
