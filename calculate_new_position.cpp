#include "gtest/gtest.h"
#include "BallPhysicsEquations.h"

std::array<double,3> run_position_calculation_function()
{
    std::array<double,3> initalPosition{0.0,0.0,0.0};
    std::array<double,3> updatedVelocity{0.0,0.0,1};
    double deltaT{1};

    return ballPhysicsEquations::calculate_new_velocity(initalPosition, updatedVelocity,deltaT);
}

TEST(updateBallPosition,whenNewVelocityIsOneAndPreviousPositionIsZero_ExpectCorrectValue)
{
    std::array<double,3> compare{0.0,0.0,1};

    EXPECT_EQ(compare, run_position_calculation_function());
}

TEST(updateBallPosition,whenNewVelocityIsOneAndPreviousPositionIsZeroAndTwoIterationsAreRun_ExpectCorrectValue)
{
    std::array<double,3> compare{0.0,0.0,2};

    std::array<double,3> newPosition{run_position_calculation_function()};

    EXPECT_EQ(compare, ballPhysicsEquations::calculate_new_velocity(newPosition,{0.0,0.0,1.0},1));
}
