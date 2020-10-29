#include "gtest/gtest.h"
#include "BallMotion.hpp"
#include <osg/StateSet>

TEST(updateBallPosition,whenNewVelocityIsOneAndPreviousPositionIsZero_ExpectCorrectValue)
{
    osg::Vec3d initalPosition(0.0,0.0,0.0);
    osg::Vec3d updatedVelocity(0.0,0.0,1);
    double deltaT{1};

    osg::Vec3d compare(0.0,0.0,1);

    UpdateBallPhysics newInstance;

    EXPECT_EQ(compare, newInstance.calculate_new_velocity(initalPosition, updatedVelocity,deltaT));
}
