#ifndef SPHEREUPDATECALLBACK_H
#define SPHEREUPDATECALLBACK_H

#include <osg/PositionAttitudeTransform>
#include "UpdateBallPhysics.hpp"

class SphereUpdateCallback: public osg::NodeCallback
{
public:
    SphereUpdateCallback(UpdateBallPhysics* ballPhysics);
protected:
    virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
    int velocity{3};
    int angle{0};
    UpdateBallPhysics* newBall;
};

#endif // SPHEREUPDATECALLBACK_H
