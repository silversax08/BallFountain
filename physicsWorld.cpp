#include "physicsWorld.hpp"
#include "Ball.h"

PhysicsWorld::PhysicsWorld()
{

}

osg::PositionAttitudeTransform* PhysicsWorld::add_ball(int inputVelocity, int inputAngle)
{
    Ball newBall(inputVelocity,inputAngle);
    ballList.push_back(newBall.get_physics());
    return newBall.get_transform();
}

void PhysicsWorld::update_for_timestep()
{

}
