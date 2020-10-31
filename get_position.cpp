#include "gtest/gtest.h"
#include "UpdateBallPhysics.hpp"

TEST(getPosition,whenPositionIsZeroVelocityIsZeroAccelerationIsGravity_ExpectCorrectValue)
{
    std::array<double,3> compare{0.0,0.0,9.902};

    UpdateBallPhysics newInstance;
    std::array<double,3> position{newInstance.get_position()};

    EXPECT_EQ(compare,position);
}

TEST(getPosition,whenPositionIsZeroVelocityIsZeroAccelerationIsGravityAndTwoIterations_ExpectCorrectValue)
{
    std::array<double,3> compare{0.0,0.0,9.706};

    UpdateBallPhysics newInstance;
    std::array<double,3> position{newInstance.get_position()};
    position = newInstance.get_position();

    EXPECT_EQ(compare,position);
}
