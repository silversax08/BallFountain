#include "gtest/gtest.h"
#include "BallMotion.hpp"
#include <osg/StateSet>
#include <array>

//TEST(updateBallPosition,whenNewVelocityIsOneAndPreviousPositionIsZero_ExpectCorrectValue)
//{
//    std::array<double,3> initalPosition{0.0,0.0,0.0};
//    std::array<double,3> updatedVelocity{0.0,0.0,1};
//    double deltaT{1};

//    std::array<double,3> compare{0.0,0.0,1};

//    UpdateBallPhysics newInstance;

//    EXPECT_EQ(compare, newInstance.calculate_new_velocity(initalPosition, updatedVelocity,deltaT));
//}
