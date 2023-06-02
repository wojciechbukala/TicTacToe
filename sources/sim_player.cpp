#include "sim_player.hpp"

#include <algorithm>
#include <limits>

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


int Simulated_player::minimax(Board& board, int depth, bool isMaximizer) {
    int score = evaluate(board);

    if (score == WIN) 
    {
        //std::cout << "DUPA 1" << std::endl;
        return score - depth;
    }

    if (score == LOSS) 
    {
        //std::cout << "DUPA 2" << std::endl;
        return score + depth;
    }

    if (board.full()) 
    {
        //std::cout << "DUPA 3" << std::endl;
        return DRAW;
    }

    if (isMaximizer) {
        int bestScore = -max_int;

        for (unsigned int i = 0; i < board.size; i++) {
            for (unsigned int j = 0; j < board.size; j++) {
                if (board.empty_index(i, j)) {
                    board.insert('o', i, j);
                    bestScore = std::max(bestScore, minimax(board, depth + 1, !isMaximizer));
                    board.insert(' ', i, j);
                }
            }
        }

        return bestScore;
    } else {
        int bestScore = max_int;
        //std::cout << "DUPA" << std::endl;
        for (unsigned int i = 0; i < board.size; i++) {
            for (unsigned int j = 0; j < board.size; j++) {
                if (board.empty_index(i, j)) {
                    board.insert('x', i, j);
                    bestScore = std::min(bestScore, minimax(board, depth + 1, !isMaximizer));
                    board.insert(' ', i, j);
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
                //std::cout << "Dupa" << std::endl; 
                board.insert('o', i, j);
                int moveScore = minimax(board, 0, false);
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