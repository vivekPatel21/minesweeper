#include <iostream>
#include <Eigen/Dense>


namespace GameSpace {
    class Coord{
        public:
            int x;
            int y;
            int value; //this is not something that is managed by this class, but by the board class.
            Coord(int x = 0, int y = 0) : x(x), y(y) {}

            
        public:
            bool adjacentCheck(Coord other){
                return(this->x+1 == other.x && this->y == other.y) ||
                (this->x-1 == other.x && this->y == other.y) ||
                (this->x == other.x && this->y-1 == other.y) ||
                (this->x == other.x && this->y+1 == other.y);
            }
        public:
            bool checkDiag(Coord other){
                return(this->x+1 == other.x && this->y+1 == other.y) ||
                (this->x+1 == other.x && this->y-1 == other.y) ||
                (this->x-1 == other.x && this->y-1 == other.y) ||
                (this->x-1 == other.x && this->y+1 == other.y);
            }
        public:
            bool isEqual(Coord other){
                return(this->x == other.x && this->y == other.y);
            }
    };
}