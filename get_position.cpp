#include "gtest/gtest.h"
#include "BallMotion.hpp"
#include <osg/StateSet>
#include <array>

TEST(getPosition,whenPositionIsZeroVelocityIsZeroAccelerationIsGravity_ExpectCorrectValue)
{
    std::array<double,3> compare{0.0,0.0,9.902};

    UpdateBallPhysics newInstance;
    std::array<double,3> position{newInstance.get_position()};

    EXPECT_NEAR(compare[0], position[0],.001);
    EXPECT_NEAR(compare[1], position[1],.001);
    EXPECT_NEAR(compare[2], position[2],.001);
}

TEST(getPosition,whenPositionIsZeroVelocityIsZeroAccelerationIsGravityAndTwoIterations_ExpectCorrectValue)
{
    std::array<double,3> compare{0.0,0.0,9.706};

    UpdateBallPhysics newInstance;
    std::array<double,3> position{newInstance.get_position()};
    position = newInstance.get_position();

    EXPECT_NEAR(compare[0], position[0],.001);
    EXPECT_NEAR(compare[1], position[1],.001);
    EXPECT_NEAR(compare[2], position[2],.001);
}
