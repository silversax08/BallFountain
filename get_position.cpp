#include "gtest/gtest.h"
#include "UpdateBallPhysics.hpp"

TEST(getPosition,whenPositionIsTenVelocityIsZeroAccelerationIsGravity_ExpectCorrectValue)
{
    std::array<double,3> compare{0.0,0.0,2.902};

    UpdateBallPhysics newInstance;
    std::array<double,3> position{newInstance.get_position()};

    EXPECT_EQ(compare,position);
}

TEST(getPosition,whenPositionIsTenVelocityIsZeroAccelerationIsGravityAndTwoIterations_ExpectCorrectValue)
{
    std::array<double,3> compare{0.0,0.0,2.706};

    UpdateBallPhysics newInstance;
    std::array<double,3> position{newInstance.get_position()};
    position = newInstance.get_position();

    EXPECT_EQ(compare,position);
}
