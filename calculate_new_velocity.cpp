#include "gtest/gtest.h"
#include "BallMotion.hpp"
#include <osg/StateSet>
#include <array>

//TEST(updateBallVelocity,whenNewAccelerationIsGravityAndPreviousVelocityIsZero_ExpectCorrectValue)
//{
//    std::array<double,3> initalVelocity{0.0,0.0,0.0};
//    std::array<double,3> updatedAcceleration{0.0,0.0,-9.8};
//    double deltaT{1};

//    std::array<double,3> compare{0.0,0.0,-9.8};

//    UpdateBallPhysics newInstance;

//    EXPECT_EQ(compare, newInstance.calculate_new_velocity(initalVelocity, updatedAcceleration,deltaT));
//}
