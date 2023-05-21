#include "board.hpp"

Board::Board()
{
    size = 3;
    blank_board();
}

Board::~Board()
{
    _board.clear();
}

Board::Board(unsigned int s, unsigned int t_w)
{
    size = s;
    to_win = t_w;
   blank_board();
}

void Board::blank_board()
{
    for(unsigned int i=0; i<size; ++i)
    {
        _board.push_back(std::vector<char>());
        for(unsigned int j=0; j<size; ++j)
        {
            _board[i].push_back(' ');
        }
    }
}

void Board::print()
{
    for(unsigned int i=0; i<size; ++i)
    {
        for(unsigned int k=0; k<4*size+1; ++k)
        {
            std::cout << '-';
        }

        std::cout << std::endl;

        for(unsigned int j=0; j<size; ++j)
        {
            std::cout << "| " << _board[i][j] << ' ';
        }

        std::cout << '|' << std::endl;
    }
    
    for(unsigned int k=0; k<4*size+1; ++k)
    {
        std::cout << '-';
    }

    std::cout << std::endl;
}

bool Board::empty_index(unsigned int r, unsigned int c)
{
    if(_board[r][c] == ' ') return true;
    else return false;
}

bool Board::full()
{
    if(inserted == (size*size))
    {
        return true;
    }
    return false;
}


void Board::insert(char sign, unsigned int column, unsigned int row)
{   
    _board[column-1][row-1] = sign;
    ++inserted;
}

char Board::win_condition()
{
    unsigned int x_counter = 1;
    unsigned int o_counter = 1;
    char winner = 'n';

    //row
    unsigned int k;
    for(unsigned int i=0; i<size; ++i)
    {
        for(unsigned int j=0; j<size; ++j)
        {
            k = j;
            while(k < size && _board[i][k] == _board[i][k+1])
            {
                if(_board[i][k] == 'o' && _board[i][k+1] == 'o')
                {
                    o_counter++;
                }
                if(_board[i][k] == 'x' && _board[i][k+1] == 'x')
                {
                    x_counter++;
                }
                k++;
            }

            if(o_counter == to_win)
            {
                winner = 'o';
            }
            else
            {
                o_counter = 1;
            }

            if(x_counter == to_win)
            {
                winner = 'x';
            }
            else
            {
                x_counter = 1;
            }

        }

        
    }

    //column
    unsigned int m;
    for(unsigned int i=0; i<size; ++i)
    {
        for(unsigned int j=0; j<size; ++j)
        {
            m = j;
            
            while(m < size-1 && _board[m][i] == _board[m+1][i])
            {
                if(_board[m][i] == 'o' && _board[m+1][i] == 'o')
                {
                    o_counter++;
                }
                if(_board[m][i] == 'x' && _board[m+1][i] == 'x')
                {
                    x_counter++;
                }
                m++;
            } 
            if(o_counter == to_win)
            {
                winner = 'o';
            }
            else
            {
                o_counter = 1;
            }

            if(x_counter == to_win)
            {
                winner = 'x';
            }
            else
            {
                x_counter = 1;
            }

        }
    }


    //diagonally
    unsigned int n, l;
    for(unsigned int i=0; i<size; ++i)
    {
        for(unsigned int j=0; j<size; ++j)
        {
            l = j;
            n = i;
            while(n < size-1 && l < size && _board[n][l] == _board[n+1][l+1])
            {
                if(_board[n][l] == 'o' && _board[n+1][l+1] == 'o')
                {
                    o_counter++;
                    //std::cout << "O++" << std::endl;
                }
                if(_board[n][l] == 'x' && _board[n+1][l+1] == 'x')
                {
                    x_counter++;
                }
                ++n;
                ++l;
            } 
            if(o_counter == to_win)
            {
                winner = 'o';
            }
            else
            {
                o_counter = 1;
            }

            if(x_counter == to_win)
            {
                winner = 'x';
            }
            else
            {
                x_counter = 1;
            }

        }
    }



    return winner;
}