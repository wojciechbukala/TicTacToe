#ifndef SIM_PLAYER
#define SIM_PLAYER

#include "board.hpp"

struct Move 
{
    int row;
    int col;
};

class Simulated_player : public Move
{
    private:
        int evaluate(const Board& board);
        int minimax(Board& board, int depth, bool isMaximizer);
        char sign;
    public:
        Simulated_player() {};
        Simulated_player(char ai_sign) : sign(ai_sign) {};
        Move findBestMove(Board& board);

};





#endif