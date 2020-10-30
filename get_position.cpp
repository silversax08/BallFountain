#include "gtest/gtest.h"
#include "BallMotion.hpp"
#include <osg/StateSet>
#include <array>

TEST(getPosition,whenNewVelocityIsOneAndPreviousPositionIsZero_ExpectCorrectValue)
{
    std::array<double,3> compare{0.0,0.0,9.92};

    UpdateBallPhysics newInstance;

    EXPECT_EQ(compare, newInstance.get_position());
}
