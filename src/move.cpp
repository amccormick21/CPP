#include "move.h"

Move::Move(const Direction * direction)
{
    this->direction = *direction;
}

Move::~Move()
{

}