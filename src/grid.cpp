#include "grid.h"
#include <math.h>

Grid::Grid(Grid::grid_size_t gridSize)
{
    this->values = vector<grid_element_t>(pow(gridSize, 2), grid_element_t(0));
}

Grid::~Grid()
{

}

void Grid::DisplayGrid()
{

}