#include "sim_player.hpp"

#include <algorithm>

int maximum_int = std::numeric_limits<int>::max();

Move Simulated_player::make_move(Board& board, char sign)
{
    char game_state = board.win_condition();
    if(game_state == 'x')
    {
        best_move = Move(1, 0, 0);
        return best_move;
    }
    else if(game_state == 'o')
    {
        best_move = Move(-1, 0, 0);
        return best_move;
    }
    else if(board.full())
    {
        best_move = Move(0, 0, 0);
        return best_move;
    } 


    Move best_move = ((sign == 'o') ? -maximum_int : maximum_int);
    for(unsigned int i = 0; i < board.size; ++i)
    {
        for(unsigned int j = 0; j < board.size; ++j)
        {
            if(board.empty_index(i, j))
            {
                board.insert(sign, i, j);

                Move move = make_move(board, (sign == 'x') ? 'o' : 'x');    

                if ((sign == 'x' && move.score > best_move.score) ||
                        (sign == 'o' && move.score < best_move.score)) {
                        best_move.column = i;
                        best_move.row = j;
                        best_move.score = move.score;
                    }

                board.insert(' ', i, j);
            }
        }
    } 
    return best_move;
} 
/* class Player {
public:
    Player(char sign) : _sign(sign) {}

    void makeMove(Board& board) {
        // Call the Minimax algorithm to determine the best move
        Move bestMove = minimax(board, _sign);

        // Make the best move on the board
        board.insert(_sign, bestMove.column, bestMove.row);
    }

private:
    struct Move {
        unsigned int column;
        unsigned int row;
        int score;
    };

    char _sign;

    Move minimax(Board& board, char player) {
        // Base cases: check for terminal states
        char result = board.win_condition();
        if (result == 'x') {
            return {0, 0, -1}; // x wins, return a negative score
        } else if (result == 'o') {
            return {0, 0, 1}; // o wins, return a positive score
        } else if (board.full()) {
            return {0, 0, 0}; // draw, return score of 0
        }

        // Initialize the best move with a low score for the maximizing player (x)
        Move bestMove = {0, 0, (player == 'x') ? -1000 : 1000};

        // Try all possible moves and recursively evaluate the resulting game states
        for (unsigned int i = 0; i < board.size; ++i) {
            for (unsigned int j = 0; j < board.size; ++j) {
                if (board.empty_index(i, j)) {
                    // Make a move for the current player
                    board.insert(player, i, j);

                    // Recursively call minimax for the opponent
                    Move move = minimax(board, (player == 'x') ? 'o' : 'x');

                    // Update the best move based on the player's turn
                    if ((player == 'x' && move.score > bestMove.score) ||
                        (player == 'o' && move.score < bestMove.score)) {
                        bestMove.column = i;
                        bestMove.row = j;
                        bestMove.score = move.score;
                    }

                    // Undo the move
                    board.insert(' ', i, j);
                }
            }
        }

        return bestMove;
    }
}; 


Move Simulated_player::make_move(Board& board, char sign)
{
    char game_state = board.win_condition();
    if(game_state == 'x')
    {
        best_move = Move(1, 0, 0);
        return best_move;
    }
    else if(game_state == 'o')
    {
        best_move = Move(-1, 0, 0);
        return best_move;
    }
    else if(board.full())
    {
        best_move = Move(0, 0, 0);
        return best_move;
    } 


    Move best_move = ((sign == 'o') ? -maximum_int : maximum_int);
    for(unsigned int i = 0; i < board.size; ++i)
    {
        for(unsigned int j = 0; j < board.size; ++j)
        {
            if(board.empty_index(i, j))
            {
                board.insert(sign, i, j);

                Move move = make_move(board, (sign == 'x') ? 'o' : 'x');    

                if ((sign == 'x' && move.score > best_move.score) ||
                        (sign == 'o' && move.score < best_move.score)) {
                        best_move.column = i;
                        best_move.row = j;
                        best_move.score = move.score;
                    }

                board.insert(' ', i, j);
            }
        }
    } 
    return best_move;
} 

int maximum_int = std::numeric_limits<int>::max();

void Simulated_player::best_move(Board& board, char sign)
{
/*     char game_state = board.win_condition();
    if(game_state == 'x')
    {
        best_move = Move(1, 0, 0);
        return best_move;
    }
    else if(game_state == 'o')
    {
        best_move = Move(-1, 0, 0);
        return best_move;
    }
    else if(board.full())
    {
        best_move = Move(0, 0, 0);
        return best_move;
    }  

    int score;
    int best_score = -maximum_int;
    for(unsigned int i = 0; i < board.size; ++i)
    {
        for(unsigned int j = 0; j < board.size; ++j)
        {
            if(board.empty_index(i, j))
            {
                board.insert(sign, i, j);
                score = minimax(borad);

                if(score > best_score)
                {
                    best_score = score;
                }

                board.insert(' ', i, j);
            }
        }
    } 
    return best_move;
} 

int Simulated_player::minimax(Board &board)
{
    return 1;
}

*/