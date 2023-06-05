#include "sim_player.hpp"

#include <algorithm>
#include <limits>
#include <chrono>

const int max_int = std::numeric_limits<int>::max();

int Simulated_player::evaluate(const Board& board) 
{
    char winner = board.win_condition();

    if (winner == 'x') {
        return LOSS;
    } else if (winner == 'o') {
        return WIN;
    }

    if (board.full()) {
        return DRAW;
    }

    return DRAW;
}


int Simulated_player::minimax(Board& board, int depth, int alpha, int beta, bool isMaximizer) 
{
    int score = evaluate(board);
    if (score == WIN) 
    {
        return score - depth;
    }

    if (score == LOSS) 
    {
        return score + depth;
    }

    if (board.full() || depth == Max_Depth) 
    {
        return DRAW;
    }

    if (isMaximizer) 
    {
        int bestScore = -max_int;

        for (unsigned int i = 0; i < board.size; i++) 
        {
            for (unsigned int j = 0; j < board.size; j++) 
            {
                if (board.empty_index(i, j)) 
                {
                    board.insert('o', i, j);
                    int currentScore = minimax(board, depth + 1, alpha, beta, !isMaximizer);
                    bestScore = std::max(bestScore, currentScore);
                    alpha = std::max(alpha, bestScore);
                    board.insert(' ', i, j);
                    if (beta <= alpha) 
                    {
                        return alpha;  
                    }
                }
            }
        }

        return bestScore;
    } 
    else 
    {
        int bestScore = max_int;

        for (unsigned int i = 0; i < board.size; i++) 
        {
            for (unsigned int j = 0; j < board.size; j++) 
            {
                if (board.empty_index(i, j)) 
                {
                    board.insert('x', i, j);
                    int currentScore = minimax(board, depth + 1, alpha, beta, !isMaximizer);
                    bestScore = std::min(bestScore, currentScore);
                    beta = std::min(beta, bestScore);
                    board.insert(' ', i, j);
                    if (beta <= alpha) 
                    {
                        return beta;  
                    }
                }
            }
        }

        return bestScore;
    }
}

Move Simulated_player::findBestMove(Board& board) 
{
    int bestScore = -1000;
    Move bestMove;

    for (unsigned int i = 0; i < board.size; i++) {
        for (unsigned int j = 0; j < board.size; j++) {
            if (board.empty_index(i, j)) 
            { 
                board.insert('o', i, j);
                int moveScore = minimax(board, 0, -max_int, max_int, false);
                board.insert(' ', i, j);

                if (moveScore > bestScore) {
                    bestScore = moveScore;
                    bestMove.row = i;
                    bestMove.col = j;
                }
            }
        }
    }

    return bestMove;
}