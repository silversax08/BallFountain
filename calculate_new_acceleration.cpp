#include "gtest/gtest.h"
#include "BallMotion.hpp"
#include <osg/StateSet>

TEST(updateBallAcceleration,whenInitialAccelerationIsGravity_ExpectCorrectValue)
{
    osg::Vec3d initalDragForce(0.0,0.0,0.0);
    osg::Vec3d initialAcceleration(0.0,0.0,-9.8);
    osg::Vec3d initialVelocity(0.0,0.0,0.0);
    osg::Vec3d initialPosition(0.0,0.0,0.0);

    osg::Vec3d compare(1.0,0.0,0.0);

    UpdateBallPhysics newInstance;
    EXPECT_EQ(compare, newInstance.updatedAcceleration);
}
