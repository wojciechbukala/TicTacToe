#include "board.hpp"
#include "sim_player.hpp"

int main()
{   
    /**
     * @brief game settings
     * 
     */
/*     unsigned int dimentions, win_condition;
    std::cout << "         TICTACTOE        " << std::endl << std::endl;
    std::cout << "     WYMIARY PLANSZY?:    " ;
    std::cin  >> dimentions;
    std::cout << "      WIN CONDITION?:     " ;
    std::cin  >> win_condition; */

    /**
     * @brief player settings
     * 
     */
/*     char player_sign = 'n', trigger = 'n';
    std::cout << "KOLKO CZY KRZYZYK?: (o/x) " ;
    do
    {
        std::cin >> player_sign;
    } while(player_sign != 'o' && player_sign != 'x');
    std::cout << "WYSTARTOWAC GRE?: (t/n)   " ;
    std::cin >> trigger;

    char com_sign; 
    
    if(player_sign == 'x')
    {
        com_sign = 'o';
    }
    else
    {
        com_sign = 'x';
    }  */

/*     if(trigger == 't')
    {
        Board b(dimentions, win_condition);
        b.print();
        std::cout << "Winner: " << b.win_condition() << std::endl;
    } */

    Board b(3, 3);
    Simulated_player k('x');
    b.insert('o', 1, 1);
    Move best_move = k.make_move(b, 'x');
    b.insert('x',k.best_move.column, k.best_move.row);
    
/*     b.insert('x',1,1);
    b.insert('o',1,2);
    b.insert('x',1,3);
    b.insert('o',2,1);
    b.insert('o',2,2);
    b.insert('o',2,3);
    b.insert('x',3,1);
    b.insert('o',3,2);
    b.insert('x',3,3); */
    b.print();
    std::cout << "Winner: " << b.win_condition() << std::endl;
    std::cout << "Full: " << b.full() << std::endl;
    return 0;
}
