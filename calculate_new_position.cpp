#include "gtest/gtest.h"
#include "BallPhysicsEquations.h"

TEST(updateBallPosition,whenNewVelocityIsOneAndPreviousPositionIsZero_ExpectCorrectValue)
{
    std::array<double,3> initalPosition{0.0,0.0,0.0};
    std::array<double,3> updatedVelocity{0.0,0.0,1};
    double deltaT{1};

    std::array<double,3> compare{0.0,0.0,1};

    EXPECT_EQ(compare, ballPhysicsEquations::calculate_new_velocity(initalPosition, updatedVelocity,deltaT));
}

TEST(updateBallPosition,whenNewVelocityIsOneAndPreviousPositionIsZeroAndTwoIterationsAreRun_ExpectCorrectValue)
{
    std::array<double,3> initalPosition{0.0,0.0,0.0};
    std::array<double,3> updatedVelocity{0.0,0.0,1};
    double deltaT{1};

    std::array<double,3> compare{0.0,0.0,2};

    std::array<double,3> newPosition{ballPhysicsEquations::calculate_new_position(initalPosition,updatedVelocity,deltaT)};

    EXPECT_EQ(compare, ballPhysicsEquations::calculate_new_velocity(newPosition, updatedVelocity,deltaT));
}
