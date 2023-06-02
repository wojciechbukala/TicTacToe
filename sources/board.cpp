#include "board.hpp"

bool Board::empty_index(unsigned int r, unsigned int c) const
{
    if(board[r][c] == ' ') return true;
    else return false;
}

bool Board::full() const 
{
    for (unsigned int i = 0; i < size; i++) 
    {
        for (unsigned int j = 0; j < size; j++) 
        {
            if (board[i][j] == ' ') 
            {
                return false;
            }
        }
    }
    return true;
}

void Board::insert(char sign, unsigned int row, unsigned int column) 
{
    board[row][column] = sign;
}

void Board::print() const
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
            std::cout << "| " << board[i][j] << ' ';
        }

        std::cout << '|' << std::endl;
    }


    for(unsigned int k=0; k<4*size+1; ++k)
    {
        std::cout << '-';
    }

    std::cout << std::endl;
}


/* char Board::win_condition() const 
{
    // Sprawdzenie wierszy
    for (unsigned int i = 0; i < size; i++) 
    {
        char symbol = board[i][0];
        
        if (symbol != ' ') 
        {
            unsigned int count = 1;

            for (unsigned int j = 1; j < size; j++) 
            {
                if (board[i][j] == symbol) 
                {
                    count++;

                    if (count == to_win)
                        return symbol;
                } 
                else 
                {
                    symbol = board[i][j];
                    count = 1;
                }
            }
        }
    }

    // Sprawdzenie kolumn
    for (unsigned int i = 0; i < size; i++) 
    {
        char symbol = board[0][i];
        
        if (symbol != ' ') 
        {
            unsigned int count = 1;

            for (unsigned int j = 1; j < size; j++) 
            {
                if (board[j][i] == symbol) 
                {
                    count++;

                    if (count == to_win)
                        return symbol;
                } 
                else 
                {
                    symbol = board[j][i];
                    count = 1;
                }
            }
        }
    }

    // Sprawdzenie przekątnej 
    for (unsigned int i = 0; i <= size - to_win; i++) 
    {
        for (unsigned int j = 0; j <= size - to_win; j++) 
        {
            char symbol = board[i][j];
            
            if (symbol != ' ') 
            {
                bool win = true;

                for (unsigned int k = 1; k < to_win; k++) 
                {
                    if (board[i + k][j + k] != symbol) 
                    {
                        win = false;
                        break;
                    }
                }

                if (win)
                    return symbol;
            }
        }
    }

    // Sprawdzenie przekątnej /
    for (unsigned int i = 0; i <= size - to_win; i++) 
    {
        for (unsigned int j = to_win - 1; j < size; j++) 
        {
            char symbol = board[i][j];
            
            if (symbol != ' ') 
            {
                bool win = true;

                for (unsigned int k = 1; k < to_win; k++) 
                {
                    if (board[i + k][j - k] != symbol) 
                    {
                        win = false;
                        break;
                    }
                }

                if (win)
                    return symbol;
            }
        }
    }

    return ' ';
}
 */

char Board::win_condition() const {

    unsigned int x_counter, o_counter;

    // poziomo
    for (unsigned int i = 0; i < size; i++) {
        x_counter = o_counter = 1;
        for (unsigned int y = 0; y < size - 1; y++) {
            if (board[i][y] == board[i][y + 1]) {
                if (board[i][y] == 'x')
                    x_counter++;
                else if (board[i][y] == 'o')
                    o_counter++;
                if (x_counter == to_win)
                    return 'x';
                if (o_counter == to_win)
                    return 'o';
            }
        }
    }

    // pionowo
    for (unsigned int y = 0; y < size; y++) {
        x_counter = o_counter = 1;
        for (unsigned int i = 0; i < size - 1; i++) {
            if (board[i][y] == board[i + 1][y]) {
                if (board[i][y] == 'x')
                    x_counter++;
                else if (board[i][y] == 'o')
                    o_counter++;
                if (x_counter == to_win)
                    return 'x';
                if (o_counter == to_win)
                    return 'o';
            }
        }
    }

    // po przekatnych
    for (unsigned int i = 1; i < size - to_win + 1; i++) {
        x_counter = o_counter = 1;
        for (unsigned int y = 0; y < (size - i - 1); y++) {
            if (board[y][i + y] == board[y + 1][i + y + 1]) {
                if (board[y][i + y] == 'x')
                    x_counter++;
                else if (board[y][i + y] == 'o')
                    o_counter++;
                if (x_counter == to_win)
                    return 'x';
                if (o_counter == to_win)
                    return 'o';
            }
        }
    }
    for (unsigned int i = 0; i < size - to_win + 1; i++) {
        x_counter = o_counter = 1;
        for (unsigned int y = 0; y < (size - i - 1); y++) {
            if (board[i + y][y] == board[i + y + 1][y + 1]) {
                if (board[i + y][y] == 'x')
                    x_counter++;
                else if (board[i + y][y] == 'o')
                    o_counter++;
                if (x_counter == to_win)
                    return 'x';
                if (o_counter == to_win)
                    return 'o';
            }
        }
    }
    for (unsigned int i = 0; i < size - to_win + 1; i++) {
        x_counter = o_counter = 1;
        for (unsigned int y = 0; y < (size - i - 1); y++) {
            if (board[size - 1 - y][i + y] == board[size - 1 - (y + 1)][i + y + 1]) {
                if (board[size - 1 - y][i + y] == 'x')
                    x_counter++;
                else if (board[size - 1 - y][i + y] == 'o')
                    o_counter++;
                if (x_counter == to_win)
                    return 'x';
                if (o_counter == to_win)
                    return 'o';
            }
        }
    }
    for (unsigned int i = 1; i < size - to_win + 1; i++) {
        x_counter = o_counter = 1;
        for (unsigned int y = 0; y < (size - i - 1); y++) {
            if (board[size - 1 - i - y][y] == board[size - i - y - 2][y + 1]) {
                if (board[size - 1 - i - y][y] == 'x')
                    x_counter++;
                else if (board[size - 1 - i - y][y] == 'o')
                    o_counter++;
                if (x_counter == to_win)
                    return 'x';
                if (o_counter == to_win)
                    return 'o';
            }
        }
    }

    return ' ';
}