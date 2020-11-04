#include "gtest/gtest.h"
#include "UpdateBallPhysics.hpp"
#include "BallPhysicsEquations.h"

void run_test(int inputAngle, std::array<double,3> compare)
{
    std::array<double,3> velocity{ballPhysicsEquations::set_inital_velocity(3,inputAngle)};

    EXPECT_NEAR(compare[0],velocity[0],.01);
    EXPECT_NEAR(compare[1],velocity[1],.01);
    EXPECT_NEAR(compare[2],velocity[2],.01);
}

TEST(setInitialVelocity,whenInputVelocityIs3AndAngleIs90Degrees_ExpectCorrectValue)
{
    std::array<double,3> compare{3.0,0.0,0.0};
    int inputAngle{90};
    run_test(inputAngle,compare);
}

TEST(setInitialVelocity,whenInputVelocityIs3AndAngleIs45Degrees_ExpectCorrectValue)
{
    std::array<double,3> compare{2.12132,0.0,2.12132};
    int inputAngle{45};
    run_test(inputAngle,compare);
}

TEST(setInitialVelocity,whenInputVelocityIs3AndAngleIsNegative45Degrees_ExpectCorrectValue)
{
    std::array<double,3> compare{-2.12132,0.0,2.12132};
    int inputAngle{-45};
    run_test(inputAngle,compare);
}
