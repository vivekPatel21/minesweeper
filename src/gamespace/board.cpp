#include "board.h"

Board::Board(int size) : size(size) {
    createCoords();
}


//O(n^2) time
void Board::createCoords() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            coordinates.emplace_back(i, j);
        }
    }
}
