#include "sphereupdatecallback.h"

SphereUpdateCallback::SphereUpdateCallback(UpdateBallPhysics* ballPhysics)
{
    newBall = ballPhysics;
}

void SphereUpdateCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
{
    std::array<double,3> position{newBall->get_position()};
    osg::Vec3d scaleFactor(position[0], position[1], position[2]);
    osg::PositionAttitudeTransform *pat = dynamic_cast<osg::PositionAttitudeTransform *> (node);
    pat->setPosition(scaleFactor);

    traverse(node, nv);
}
