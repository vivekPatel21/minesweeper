#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

#include <iostream>
#include <Eigen/Dense>

#define BOMBPERCENT .3
#define BombTile

namespace GameSpace {
    class Board {
        int rows; 
        int cols;

        /*
        The variable below let's there be 2 different types of boards, we will use polymorphism
        to pretty much do the same things.
        */
        int inputedBombPercent;


        public: Board(int rows, int cols);

        private: 
            void constructBoard();
            int numberOfBombs();
            int placeBombs();
            int assignValues(); //this is to give the value of the coordinates
    };
}


#endif // MINESWEEPER_BOARD_H