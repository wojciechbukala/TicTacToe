#ifndef SIM_PLAYER
#define SIM_PLAYER

#include "board.hpp"

class Move
{
    public:
        unsigned int column, row;
        int score;
        Move(int s, unsigned int r = 0, unsigned int c = 0)
        {
            score = s;
            row = r;
            column = c;
        }
        Move()
        {
            score = 0;
            row = 0;
            column = 0;
        }
};

class Simulated_player
{
    public:
        char sign;
        Simulated_player(char s)
        {
            sign = s;
        }
        Simulated_player()
        {
            sign = 'n';
        }
       Move make_move(Board& board, char sign);
        Move best_move;
};




#endif