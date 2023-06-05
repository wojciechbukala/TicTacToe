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
        int minimax(Board& board, int depth, int alpha, int beta, bool isMaximizer); 
    public:
        Simulated_player() {};
        Simulated_player(char ai_sign, int m_depth)
        {
            sign = ai_sign;
            Max_Depth = m_depth-1;
        }
        Move findBestMove(Board& board);
        char sign;
        int Max_Depth;

};





#endif