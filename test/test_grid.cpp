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

BOOST_AUTO_TEST_CASE ( grid_move_default_test )
{    
    Grid * grid = new Grid(4);

    grid->values[0] = 2;
    auto score = grid->MoveGrid(Direction::down);

    BOOST_CHECK(grid->values[0] == 0);
    BOOST_CHECK(grid->values[12] == 2);
    BOOST_CHECK(score == 0);
}

BOOST_AUTO_TEST_CASE ( grid_move_nomove_test )
{    
    Grid * grid = new Grid(4);

    grid->values[0] = 2;
    
    auto score = grid->MoveGrid(Direction::left);

    BOOST_CHECK(grid->values[0] == 2);
    BOOST_CHECK(score == 0);
}

BOOST_AUTO_TEST_CASE ( grid_move_combine_test )
{    
    Grid * grid = new Grid(4);

    grid->values[0] = 2;
    grid->values[1] = 2;
    grid->values[2] = 0;
    grid->values[3] = 0;
    
    auto score = grid->MoveGrid(Direction::left);

    BOOST_CHECK(grid->values[0] == 4);
    BOOST_CHECK(grid->values[1] == 0);
    BOOST_CHECK(grid->values[2] == 0);
    BOOST_CHECK(grid->values[3] == 0);
    BOOST_CHECK(score == 4);
}

BOOST_AUTO_TEST_CASE ( grid_move_combineandmove1_test )
{    
    Grid * grid = new Grid(4);

    grid->values[0] = 2;
    grid->values[1] = 2;
    grid->values[2] = 4;
    grid->values[3] = 4;
    
    auto score = grid->MoveGrid(Direction::left);

    BOOST_CHECK(grid->values[0] == 4);
    BOOST_CHECK(grid->values[1] == 8);
    BOOST_CHECK(grid->values[2] == 0);
    BOOST_CHECK(grid->values[3] == 0);
    BOOST_CHECK(score == 12);
}

BOOST_AUTO_TEST_CASE ( grid_move_combineandmove2_test )
{    
    Grid * grid = new Grid(4);

    grid->values[0] = 0;
    grid->values[1] = 2;
    grid->values[2] = 2;
    grid->values[3] = 4;
    
    auto score = grid->MoveGrid(Direction::left);

    BOOST_CHECK(grid->values[0] == 4);
    BOOST_CHECK(grid->values[1] == 4);
    BOOST_CHECK(grid->values[2] == 0);
    BOOST_CHECK(grid->values[3] == 0);
    BOOST_CHECK(score == 4);
}

BOOST_AUTO_TEST_CASE ( grid_move_doublemove_test )
{    
    Grid * grid = new Grid(4);

    grid->values[0] = 0;
    grid->values[1] = 2;
    grid->values[2] = 2;
    grid->values[3] = 4;
    
    auto score = grid->MoveGrid(Direction::left);
    score += grid->MoveGrid(Direction::left);

    BOOST_CHECK(grid->values[0] == 8);
    BOOST_CHECK(grid->values[1] == 0);
    BOOST_CHECK(grid->values[2] == 0);
    BOOST_CHECK(grid->values[3] == 0);

    BOOST_CHECK(score == 12);
}

BOOST_AUTO_TEST_CASE ( grid_move_left_test )
{    
    Grid * grid = new Grid(4);

    grid->values[3] = 2;
    grid->values[7] = 4;
    grid->values[11] = 8;
    grid->values[15] = 16;
    
    auto score = grid->MoveGrid(Direction::left);

    BOOST_CHECK(grid->values[0] == 2);
    BOOST_CHECK(grid->values[1] == 0);
    BOOST_CHECK(grid->values[2] == 0);
    BOOST_CHECK(grid->values[3] == 0);
    BOOST_CHECK(grid->values[4] == 4);
    BOOST_CHECK(grid->values[5] == 0);
    BOOST_CHECK(grid->values[6] == 0);
    BOOST_CHECK(grid->values[7] == 0);
    BOOST_CHECK(grid->values[8] == 8);
    BOOST_CHECK(grid->values[9] == 0);
    BOOST_CHECK(grid->values[10] == 0);
    BOOST_CHECK(grid->values[11] == 0);
    BOOST_CHECK(grid->values[12] == 16);
    BOOST_CHECK(grid->values[13] == 0);
    BOOST_CHECK(grid->values[14] == 0);
    BOOST_CHECK(grid->values[15] == 0);

    BOOST_CHECK(score == 0);
}

BOOST_AUTO_TEST_CASE ( grid_move_right_test )
{    
    Grid * grid = new Grid(4);

    grid->values[0] = 2;
    grid->values[4] = 4;
    grid->values[8] = 8;
    grid->values[12] = 16;
    
    auto score = grid->MoveGrid(Direction::right);

    BOOST_CHECK(grid->values[0] == 0);
    BOOST_CHECK(grid->values[1] == 0);
    BOOST_CHECK(grid->values[2] == 0);
    BOOST_CHECK(grid->values[3] == 2);
    BOOST_CHECK(grid->values[4] == 0);
    BOOST_CHECK(grid->values[5] == 0);
    BOOST_CHECK(grid->values[6] == 0);
    BOOST_CHECK(grid->values[7] == 4);
    BOOST_CHECK(grid->values[8] == 0);
    BOOST_CHECK(grid->values[9] == 0);
    BOOST_CHECK(grid->values[10] == 0);
    BOOST_CHECK(grid->values[11] == 8);
    BOOST_CHECK(grid->values[12] == 0);
    BOOST_CHECK(grid->values[13] == 0);
    BOOST_CHECK(grid->values[14] == 0);
    BOOST_CHECK(grid->values[15] == 16);

    BOOST_CHECK(score == 0);
}

BOOST_AUTO_TEST_CASE ( grid_move_down_test )
{    
    Grid * grid = new Grid(4);

    grid->values[0] = 2;
    grid->values[1] = 4;
    grid->values[2] = 8;
    grid->values[3] = 16;
    
    auto score = grid->MoveGrid(Direction::down);

    BOOST_CHECK(grid->values[0] == 0);
    BOOST_CHECK(grid->values[1] == 0);
    BOOST_CHECK(grid->values[2] == 0);
    BOOST_CHECK(grid->values[3] == 0);
    BOOST_CHECK(grid->values[4] == 0);
    BOOST_CHECK(grid->values[5] == 0);
    BOOST_CHECK(grid->values[6] == 0);
    BOOST_CHECK(grid->values[7] == 0);
    BOOST_CHECK(grid->values[8] == 0);
    BOOST_CHECK(grid->values[9] == 0);
    BOOST_CHECK(grid->values[10] == 0);
    BOOST_CHECK(grid->values[11] == 0);
    BOOST_CHECK(grid->values[12] == 2);
    BOOST_CHECK(grid->values[13] == 4);
    BOOST_CHECK(grid->values[14] == 8);
    BOOST_CHECK(grid->values[15] == 16);

    BOOST_CHECK(score == 0);
}

BOOST_AUTO_TEST_CASE ( grid_move_up_test )
{    
    Grid * grid = new Grid(4);

    grid->values[12] = 2;
    grid->values[13] = 4;
    grid->values[14] = 8;
    grid->values[15] = 16;
    
    auto score = grid->MoveGrid(Direction::up);

    BOOST_CHECK(grid->values[0] == 2);
    BOOST_CHECK(grid->values[1] == 4);
    BOOST_CHECK(grid->values[2] == 8);
    BOOST_CHECK(grid->values[3] == 16);
    BOOST_CHECK(grid->values[4] == 0);
    BOOST_CHECK(grid->values[5] == 0);
    BOOST_CHECK(grid->values[6] == 0);
    BOOST_CHECK(grid->values[7] == 0);
    BOOST_CHECK(grid->values[8] == 0);
    BOOST_CHECK(grid->values[9] == 0);
    BOOST_CHECK(grid->values[10] == 0);
    BOOST_CHECK(grid->values[11] == 0);
    BOOST_CHECK(grid->values[12] == 0);
    BOOST_CHECK(grid->values[13] == 0);
    BOOST_CHECK(grid->values[14] == 0);
    BOOST_CHECK(grid->values[15] == 0);

    BOOST_CHECK(score == 0);
}