#include "gtest/gtest.h"
#include "BallMotion.hpp"
#include <osg/StateSet>

TEST(updateBallAcceleration,whenInitialAccelerationIsGravityAndThereIsNoDragForce_ExpectCorrectValue)
{
    osg::Vec3d initalDragForce(0.0,0.0,0.0);
    osg::Vec3d initialAcceleration(0.0,0.0,-9.8);

    osg::Vec3d compare(0.0,0.0,-9.8);

    UpdateBallPhysics newInstance;

    EXPECT_EQ(compare, newInstance.calculate_new_acceleration(initialAcceleration));
}
