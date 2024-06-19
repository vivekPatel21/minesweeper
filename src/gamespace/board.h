#ifndef BOARD_H
#define BOARD_H

#include <Eigen/Dense>
#include "coord.h"
#include <random>
#include <iostream>
#include <queue>

class Board {
public:
    Eigen::Matrix<coord, Eigen::Dynamic, Eigen::Dynamic> matrix;
    Board(int size);

    void createCoords();
    void printBoard() const;
    int bombsToPlace(float chosenDifficulty) const;
    void populateBoard(coord ignore, int numberToPlace);
    void setValues();
    int BFS(coord start);

private:
    int size;
    

    // Random number generation members
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> dis;
};

#endif // BOARD_H
