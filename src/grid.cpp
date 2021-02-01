#include "grid.h"
#include <math.h>
#include <functional>
#include <string>
#include <iostream>

Grid::Grid(Grid::grid_size_t gridSize)
{
    this->gridSize = gridSize;
    this->nValues = 0;
    this->nMaxValues = pow(gridSize, 2);
    this->values = vector<grid_element_t>(this->nMaxValues, grid_element_t(0));
    this->generator = default_random_engine(0);
    this->valueDistribution = uniform_real_distribution<float>(0.0f, 1.0f);
}

Grid::~Grid()
{
}

void Grid::Initialise()
{
    for (int i = 0; i < 2; i++)
    {
        AddValue();
    }
}

std::string Grid::DisplayElement(grid_element_t element)
{
    if (element == 0)
    {
        // Write spaces
        return "     ";       
    }
    else
    {
        // Write the number
        auto numberString = std::to_string(element);

        // Pad with spaces
        return std::string( 5 - numberString.length(), ' ' ).append(numberString);
    }
    
}

void Grid::DisplayGrid()
{
    int location(0);
    for (int row = 0; row < this->gridSize; row++)
    {
        // Line start:
        std::cout << "    ";
        for (int col = 0; col < this->gridSize; col++)
        {
            std::cout << DisplayElement(this->values[location++]);
            std::cout << "  ";
        }
        // Line end
        std::cout << endl;
    }
}

void Grid::AddValue()
{
    auto value = GetRandomValue();
    auto location = GetRandomLocation();

    // i is the location on the overall grid
    auto nEmptyValuesFound = 0;
    for (int i = 0; i < this->nMaxValues; i++)
    {
        // If we encounter a nonzero value, increment the count
        if (this->values[i] == 0)
        {
            if (nEmptyValuesFound++ == location)
            {
                // We have found the intended location
                this->values[i] = value;
                break;
            }
        }
    }

    this->nValues++;
}

Grid::grid_size_t Grid::GetRandomLocation()
{
    int nFree = this->nMaxValues - this->nValues;
    uniform_int_distribution<int> locationDistribution(0, nFree-1);
    return locationDistribution(generator);
}

grid_element_t Grid::GetRandomValue()
{
    if (this->valueDistribution(this->generator) >= 0.9)
        return 4;
    else
        return 2;
}