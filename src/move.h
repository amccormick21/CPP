#include "direction.cpp"
#include "score.cpp"

class Move {

    public:
        Direction direction;
        
        Move(const Direction *);
        ~Move();
};