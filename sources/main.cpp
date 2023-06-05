#include <iostream>
#include <vector>
#include <chrono>
#include "board.hpp"
#include "sim_player.hpp"

using namespace std;


int main() 
{
    unsigned int board_size, Depth, To_win;

    std::cout << "Gra kolko i krzyzyk. Czlowiek vs AI" << std::endl << std::endl;
    std::cout << "Podaj wielkosc planszy: ";
    std::cin >> board_size;
    std::cout << std::endl << "Podaj ilosc punktow do wygranej: ";
    std::cin >> To_win;
    std::cout << std::endl << "Podaj glebokosc rekurencji: ";
    std::cin >> Depth;
    std::cout << std::endl;

    Board board(board_size,To_win);
    Simulated_player pl('o',Depth);

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
        
        auto start = std::chrono::high_resolution_clock::now();
        Move bestMove = pl.findBestMove(board);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end- start).count();
        std::cout << "Czas wykonywania ruchu: "<< duration << " sekund " << std::endl;
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
