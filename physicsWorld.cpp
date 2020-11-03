#include "physicsWorld.hpp"
#include "sphereupdatecallback.h"

PhysicsWorld::PhysicsWorld(OSGWidget* pointer)
{
    OSGWidgetPointer = pointer;
}

PhysicsWorld::~PhysicsWorld()
{

}

void PhysicsWorld::add_ball_to_world(int inputVelocity, int inputAngle)
{
    OSGWidgetPointer->sphere_setup(inputVelocity, inputAngle);
//    ballList.push_back(OSGWidgetPointer->sphere_setup(inputVelocity, inputAngle)->SphereUpdateCallback)
}
