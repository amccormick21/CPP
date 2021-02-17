#include <vector>

enum class Direction {
    left,
    up,
    right,
    down
};

namespace Directions {
    static std::vector<Direction> Directions {Direction::left, Direction::up, Direction::right, Direction::down};
}