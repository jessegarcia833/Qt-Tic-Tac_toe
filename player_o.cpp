#include "player_o.h"

Player_O::Player_O()
{
    score = 0;
}

void Player_O::add_score()
{
    score = score + 1;
}

unsigned int Player_O::get_score()
{
    return score;
}

QString Player_O::play_turn()
{
    return "O";
}
