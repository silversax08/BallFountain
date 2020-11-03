#include "gtest/gtest.h"
#include "UpdateBallPhysics.hpp"
#include "BallPhysicsEquations.h"

TEST(updateBallAcceleration,whenInitialAccelerationIsGravityAndThereIsNoDragForce_ExpectCorrectValue)
{
    std::array<double,3> initalDragForce{0.0,0.0,0.0};
    std::array<double,3> initialAcceleration{0.0,0.0,-9.8};

    std::array<double,3> compare{0.0,0.0,-9.8};

    EXPECT_EQ(compare, ballPhysicsEquations::calculate_new_acceleration(initialAcceleration,initalDragForce,1));
}

TEST(updateBallAcceleration,whenInitialAccelerationIsGravityAndThereIsNoDragForce2_ExpectCorrectValue)
{
    std::array<double,3> initalDragForce{0.0,0.0,0.0};
    std::array<double,3> initialAcceleration{0.0,0.0,-9.8};

    std::array<double,3> compare{0.0,0.0,-9.8};

    UpdateBallPhysics newInstance;

    EXPECT_EQ(compare, newInstance.calculate_new_acceleration(initialAcceleration,initalDragForce));
}
