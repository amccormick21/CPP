#include "gridelement.cpp"
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

        std::string DisplayElement(grid_element_t);
        void DisplayGrid();
        void Initialise();

    private:

        grid_size_t GetRandomLocation();
        grid_element_t GetRandomValue();
        void AddValue();

        default_random_engine generator;
        uniform_real_distribution<float> valueDistribution;
};