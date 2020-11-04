#ifndef PHYSICSWORLD_HPP
#define PHYSICSWORLD_HPP

//#include "OSGWidget.h"
#include "sphereupdatecallback.h"
#include <vector>
#include "UpdateBallPhysics.hpp"

#include <osg/Geode>
#include <osg/Material>
#include <osg/ShapeDrawable>

class PhysicsWorld
{
public:
    PhysicsWorld();
    osg::PositionAttitudeTransform* add_ball(int inputVelocity, int inputAngle);
protected:
    std::vector<UpdateBallPhysics*> ballList;
    void update_for_timestep();
};

#endif // PHYSICSWORLD_HPP
