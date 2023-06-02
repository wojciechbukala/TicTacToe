#ifndef BOARD
#define BOARD

#include <iostream>
#include <vector>

const int EMPTY = 0;
const int X = 1;
const int O = 2;
const int DRAW = 0;
const int WIN = 10;
const int LOSS = -10;

class Board {
    public:
        
        unsigned int size;
        unsigned int to_win;

        Board(unsigned int n, unsigned int tw)
        {
            size = n;
            to_win = tw;
            board.resize(size, std::vector<char>(size, ' '));
        }
        bool empty_index(unsigned int r, unsigned int c) const;
        bool full() const;
        void insert(char sign, unsigned int row, unsigned int column);
        void print() const;
        char win_condition() const;
    private:
        std::vector<std::vector<char>> board;
};

#endif