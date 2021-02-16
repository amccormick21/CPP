#include "../include/stdafx.h"
#include "gridelement.cpp"
#include "score.cpp"
#include <vector>
#include <cstdint>
#include <random>

using namespace std;

class Grid {

    public:
        typedef int8_t grid_size_t;

        vector<grid_element_t> values;
        grid_size_t gridSize, nMaxValues, nValues;
        
        Grid(const grid_size_t);
        ~Grid();

        score_t MoveGrid(const Direction);
        void AddValue();

        string DisplayElement(grid_element_t);
        void DisplayGrid(score_t);
        void Initialise();

        bool CheckValidMove(const Direction);
        static bool CanRowMove(vector<grid_element_t *>, const Direction);

    private:

        grid_size_t GetRandomLocation();
        grid_element_t GetRandomValue();

        vector<grid_element_t *> GetRow(Direction, grid_size_t);
        static score_t MoveRow(vector<grid_element_t *>);

        default_random_engine generator;
        uniform_real_distribution<float> valueDistribution;
};