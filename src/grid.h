#include "gridelement.cpp"
#include <vector>
#include <cstdint>

using namespace std;

class Grid {

    public:
        vector<grid_element_t> values;
        
        typedef int8_t grid_size_t;
        Grid(const grid_size_t);
        ~Grid();

        void DisplayGrid();
};