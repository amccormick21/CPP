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

void Grid::DisplayGrid(score_t score)
{
    int location(0);
    for (int row = 0; row < this->gridSize; row++)
    {
        // Line start
        for (int col = 0; col < this->gridSize; col++)
        {
            std::cout << DisplayElement(this->values[location++]);
            std::cout << "  ";
        }
        // Line end
        std::cout << endl;
    }
    std::cout << endl;
    std::cout << "Score: " << score << endl;
}

bool Grid::CheckValidMove(const Direction direction)
{
    // Check the move in a given direction to see if anything actually happens
    bool canMove{false};
    vector<grid_element_t *> row;
    for (auto i = 0; i < this->gridSize; i++)
    {
        row = this->GetRow(direction, i);
        canMove |= Grid::CanRowMove(row);
    }
    return canMove;

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

score_t Grid::MoveGrid(const Direction direction)
{
    score_t score{0};
    vector<grid_element_t *> row;
    for (auto i = 0; i < this->gridSize; i++)
    {
        row = this->GetRow(direction, i);
        score += this->MoveRow(row);
    }
    return score;

}

vector<grid_element_t *> Grid::GetRow(const Direction direction, grid_size_t nRowID)
{
    vector<grid_element_t *> rowPtrs;

    grid_size_t startIndex{0};
    grid_size_t increment{0};

    switch (direction)
    {
        case Direction::left:
            startIndex = 0 + this->gridSize * nRowID;
            increment = 1;
            break;
        case Direction::up:
            startIndex = 0 + nRowID;
            increment = this->gridSize;
            break;
        case Direction::right:
            startIndex = (this->gridSize-1) + this->gridSize * nRowID;
            increment = -1;
            break;
        case Direction::down:
            startIndex = this->gridSize * (this->gridSize-1) + nRowID;
            increment = -this->gridSize;
            break;
    }

    grid_element_t * elementPtr;
    for (auto i = 0; i < this->gridSize; i++)
    {
        elementPtr = &this->values[0] + startIndex + i * increment;
        rowPtrs.push_back(elementPtr);
    }

    return rowPtrs;
}

score_t Grid::MoveRow(vector<grid_element_t *> row)
{
    grid_size_t lastNonzeroLocation;
    grid_element_t lastNonzeroValue{*row[0]};
    bool lastNonzeroValueHasCombined{false};

    score_t score{0};

    // Check the first element - the first element is a special case as it will never combine
    if (*row[0] != 0)
    {
        lastNonzeroLocation = 0;
    }
    else
    {
        lastNonzeroLocation = -1;
    }    

    // From start to end of array
    for (auto i = 1; i < this->gridSize; i++)
    {
        if ((*row[i] == lastNonzeroValue) && (!lastNonzeroValueHasCombined) && (lastNonzeroValue != 0))
        {
            // Combine
            *row[lastNonzeroLocation] += *row[i];
            lastNonzeroValueHasCombined = true;
            score += *row[lastNonzeroLocation];
            lastNonzeroValue = grid_element_t{0};
            *row[i] = grid_element_t{0};

            // Because we have combined, there is one fewer cell on the board
            this->nValues--;
        }
        else if (*row[i] != 0)
        {
            // Update last nonzero location plus one
            lastNonzeroLocation += 1;
            lastNonzeroValue = *row[i];
            lastNonzeroValueHasCombined = false;
            
            // Reset the source value if the element has moved
            if (lastNonzeroLocation != i)
            {
                *row[lastNonzeroLocation] = *row[i];
                *row[i] = grid_element_t{0};
            }
        }
    }

    return score;
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

bool Grid::CanRowMove(vector<grid_element_t*> row)
{
    bool foundZero{false};
    bool doubledValue{false};
    grid_element_t lastValue{0};

    for (int i = 0; i < row.size(); i++)
    {
        if (*row[i] == 0)
        {
            foundZero = true;
            break;
        }
        else if (*row[i] == lastValue)
        {
            doubledValue = true;
            break;
        }
        else
        {
            lastValue = *row[i];
        }
   }

   return (foundZero || doubledValue);
}