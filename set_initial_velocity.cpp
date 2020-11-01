#include "gtest/gtest.h"
#include "UpdateBallPhysics.hpp"

TEST(setInitialVelocity,whenInputVelocityIs3AndAngleIs90Degrees_ExpectCorrectValue)
{
    std::array<double,3> compare{3.0,0.0,0.0};

    UpdateBallPhysics newInstance;
    int inputVelocity{3};
    int inputAngle{90};
    std::array<double,3> velocity{newInstance.set_inital_velocity(inputVelocity, inputAngle)};

    EXPECT_EQ(compare,velocity);
}

TEST(setInitialVelocity,whenInputVelocityIs3AndAngleIs45Degrees_ExpectCorrectValue)
{
    std::array<double,3> compare{1.5,0.0,1.5};

    UpdateBallPhysics newInstance;
    int inputVelocity{3};
    int inputAngle{45};
    std::array<double,3> velocity{newInstance.set_inital_velocity(inputVelocity, inputAngle)};

    EXPECT_EQ(compare,velocity);
}

TEST(setInitialVelocity,whenInputVelocityIs3AndAngleIsNegative45Degrees_ExpectCorrectValue)
{
    std::array<double,3> compare{1.5,0.0,1.5};

    UpdateBallPhysics newInstance;
    int inputVelocity{3};
    int inputAngle{-45};
    std::array<double,3> velocity{newInstance.set_inital_velocity(inputVelocity, inputAngle)};

    EXPECT_EQ(compare,velocity);
}
