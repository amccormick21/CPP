#define BOOST_TEST_MODULE GridTest
#include <grid.h>
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE ( grid_init_cells_test )
{    
    Grid * grid = new Grid(4);
    grid->Initialise();

    BOOST_TEST(grid->nValues == 2);
}

BOOST_AUTO_TEST_CASE ( grid_init_value_test )
{    
    Grid * grid = new Grid(4);
    grid->Initialise();

    grid_element_t sum(0);
    for (int i = 0; i < grid->nMaxValues; i++)
    {
        sum += grid->values[i];
    }
    BOOST_CHECK((sum == 4) || (sum == 6) || (sum == 8) );
}