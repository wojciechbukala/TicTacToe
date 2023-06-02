#include <iostream>
#include <vector>
#include "board.hpp"
#include "sim_player.hpp"

using namespace std;



int main() 
{
    Board board(3,3);
    Simulated_player pl('o');

    while (true) {
        int x, y;
        cout << "Podaj współrzędne X i Y (oddzielone spacją): ";
        cin >> x >> y;

        if (!board.empty_index(x, y)) {
            cout << "To pole jest już zajęte. Podaj inne współrzędne.\n";
            continue;
        }

        board.insert('x', x, y);

        if (board.win_condition() == 'x') {
            cout << "Wygrałeś!\n";
            break;
        }

        if (board.full()) {
            cout << "Remis!\n";
            break;
        }
        

        Move bestMove = pl.findBestMove(board);
        board.insert('o', bestMove.row, bestMove.col);
        board.print();

        if (board.win_condition() == 'o') {
            cout << "Komputer wygrał!\n";
            break;
        }

        if (board.full()) {
            cout << "Remis!\n";
            break;
        }
    }

    return 0;
} 