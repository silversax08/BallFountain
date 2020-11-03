#ifndef BALL_H
#define BALL_H

#include "UpdateBallPhysics.hpp"
#include <osg/Geode>
#include <osg/Material>
#include <osg/ShapeDrawable>

class Ball
{
public:
    Ball(int inputVelocity, int inputAngle);
    osg::PositionAttitudeTransform* get_transform();
    UpdateBallPhysics* get_physics();
protected:
    void create_physics_representation();
    void create_visual_representation();
    UpdateBallPhysics* ballPhysicsPointer;
    int velocity{7};
    int angle{0};
    osg::PositionAttitudeTransform* transform;
    UpdateBallPhysics* ballPhysics;
};

#endif // BALL_H
