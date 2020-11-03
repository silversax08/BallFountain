#include "physicsWorld.hpp"
#include "sphereupdatecallback.h"
#include "Ball.h"

#include <osg/Geode>
#include <osg/Material>
#include <osg/ShapeDrawable>

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
