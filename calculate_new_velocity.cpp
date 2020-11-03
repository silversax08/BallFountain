#include "gtest/gtest.h"
#include "BallPhysicsEquations.h"

TEST(updateBallVelocity,whenNewAccelerationIsGravityAndPreviousVelocityIsZero_ExpectCorrectValue)
{
    std::array<double,3> initalVelocity{0.0,0.0,0.0};
    std::array<double,3> updatedAcceleration{0.0,0.0,-9.8};
    double deltaT{1};

    std::array<double,3> compare{0.0,0.0,-9.8};

    EXPECT_EQ(compare, ballPhysicsEquations::calculate_new_velocity(initalVelocity, updatedAcceleration,deltaT));
}

TEST(updateBallVelocity,whenNewAccelerationIsGravityAndPreviousVelocityIsZeroAndTwoIterationsAreRun_ExpectCorrectValue)
{
    std::array<double,3> initalVelocity{0.0,0.0,0.0};
    std::array<double,3> updatedAcceleration{0.0,0.0,-9.8};
    double deltaT{1};

    std::array<double,3> compare{0.0,0.0,-19.6};

    std::array<double,3> newVelocity{ballPhysicsEquations::calculate_new_velocity(initalVelocity,updatedAcceleration,deltaT)};

    EXPECT_EQ(compare, ballPhysicsEquations::calculate_new_velocity(newVelocity, updatedAcceleration,deltaT));
}
