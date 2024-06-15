#ifndef BOARD
#define BOARD_H


#include "coord.h"
#include <Eigen/Dense>


#define EASYBOARDSIZE 9
#define NOMRALBOARDSIZE 11
#define HARDMODESIZE 13
#define BOARDMAX 50

#define CUSTOMMAX .3 //Max Number of bombs that can be on a board.


enum CellState {
    HIDDEN,
    REVEALED,
    FLAGGED
};

struct Cell {
    bool hasMine; 
    int adjMines;
    CellState state;
};

#endif //BOARD_H