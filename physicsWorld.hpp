#ifndef PHYSICSWORLD_HPP
#define PHYSICSWORLD_HPP

#include "UpdateBallPhysics.hpp"
#include <osg/ShapeDrawable>

class PhysicsWorld
//Did not get the chance to finish working on this class
{
public:
    PhysicsWorld();
    osg::PositionAttitudeTransform* add_ball(int inputVelocity, int inputAngle);
protected:
    std::vector<UpdateBallPhysics*> ballList;
    void update_for_timestep();
};

#endif // PHYSICSWORLD_HPP
