#ifndef BOARD
#define BOARD

#include <iostream>
#include <vector>

class Board
{
    public:

        Board();
        ~Board();
        Board(unsigned int s, unsigned int t_w);
        void print();
        void insert(char sign, unsigned int column, unsigned int row);
        char win_condition();
        unsigned int size;
        unsigned int to_win;
        bool empty_index(unsigned int r, unsigned int c);
        bool full();
/*         inline std::vector<char>& operator[](unsigned int index) 
        {
            return _board[index];
        } */
    private:
        std::vector<std::vector<char>> _board;
        void blank_board();
        unsigned int inserted = 0;
};

#endif