#include "gtest/gtest.h"
#include "BallMotion.hpp"
#include <osg/StateSet>

TEST(updateBallAcceleration,whenInitialAccelerationIsGravityAndThereIsNoDragForce_ExpectCorrectValue)
{
    std::array<double,3> initalDragForce{0.0,0.0,0.0};
    std::array<double,3> initialAcceleration{0.0,0.0,-9.8};

    std::array<double,3> compare{0.0,0.0,-9.8};

    UpdateBallPhysics newInstance;

    EXPECT_EQ(compare, newInstance.calculate_new_acceleration(initialAcceleration,initalDragForce));
}

TEST(updateBallAcceleration,whenOneIterationsIsRunAndDragForceIsOne_ExpectCorrectValue)
{
    std::array<double,3> initalDragForce{0.0,0.0,1.0};
    std::array<double,3> initialAcceleration{0.0,0.0,-9.8};

    std::array<double,3> compare{0.0,0.0,-8.8};

    UpdateBallPhysics newInstance;
    std::array<double,3> acceleration{newInstance.calculate_new_acceleration(initialAcceleration,initalDragForce)};
    acceleration = newInstance.calculate_new_acceleration(acceleration,initalDragForce);

    EXPECT_EQ(compare, acceleration);
}
