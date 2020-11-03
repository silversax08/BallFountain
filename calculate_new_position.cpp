#include "gtest/gtest.h"
#include "UpdateBallPhysics.hpp"
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

TEST(updateBallPosition,whenNewVelocityIsOneAndPreviousPositionIsZero2_ExpectCorrectValue)
{
    std::array<double,3> initalPosition{0.0,0.0,0.0};
    std::array<double,3> updatedVelocity{0.0,0.0,1};
    double deltaT{1};

    std::array<double,3> compare{0.0,0.0,1};

    UpdateBallPhysics newInstance;

    EXPECT_EQ(compare, newInstance.calculate_new_velocity(initalPosition, updatedVelocity,deltaT));
}

TEST(updateBallPosition,whenNewVelocityIsOneAndPreviousPositionIsZeroAndTwoIterationsAreRun2_ExpectCorrectValue)
{
    std::array<double,3> initalPosition{0.0,0.0,0.0};
    std::array<double,3> updatedVelocity{0.0,0.0,1};
    double deltaT{1};

    std::array<double,3> compare{0.0,0.0,2};

    UpdateBallPhysics newInstance;
    std::array<double,3> newPosition{newInstance.calculate_new_position(initalPosition,updatedVelocity,deltaT)};

    EXPECT_EQ(compare, newInstance.calculate_new_velocity(newPosition, updatedVelocity,deltaT));
}
