#include "gtest/gtest.h"
#include "BallMotion.hpp"
#include <osg/StateSet>

//TEST(updateBallVelocity,whenNewAccelerationIsGravityAndPreviousVelocityIsZero_ExpectCorrectValue)
//{
//    osg::Vec3d initalVelocity(0.0,0.0,0.0);
//    osg::Vec3d updatedAcceleration(0.0,0.0,-9.8);
//    double deltaT{1};

//    osg::Vec3d compare(0.0,0.0,-9.8);

//    UpdateBallPhysics newInstance;

//    EXPECT_EQ(compare, newInstance.calculate_new_velocity(initalVelocity, updatedAcceleration,deltaT));
//}
