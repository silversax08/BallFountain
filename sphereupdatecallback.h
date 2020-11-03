#ifndef SPHEREUPDATECALLBACK_H
#define SPHEREUPDATECALLBACK_H

#include <osg/StateSet>
#include <osgDB/WriteFile>
#include <osgGA/EventQueue>
#include <osgViewer/View>
#include <osgViewer/ViewerEventHandlers>
#include <osg/MatrixTransform>
#include <osg/NodeVisitor>
#include <osg/LineWidth>
#include <osgUtil/SmoothingVisitor>
#include <osg/PositionAttitudeTransform>

#include <cassert>
#include <vector>

#include <QKeyEvent>
#include <QPainter>
#include <QWheelEvent>

#include "OSGWidget.h"
#include "UpdateBallPhysics.hpp"

class SphereUpdateCallback: public osg::NodeCallback
{
public:
    SphereUpdateCallback(UpdateBallPhysics* ballPhysics)
    {
        newBall = ballPhysics;
//        velocity = inputVelocity;
//        angle = inputAngle;
    }

    virtual void operator()(osg::Node* node, osg::NodeVisitor* nv)
    {
        std::array<double,3> position{newBall->get_position()};
        osg::Vec3d scaleFactor(position[0], position[1], position[2]);
        osg::PositionAttitudeTransform *pat = dynamic_cast<osg::PositionAttitudeTransform *> (node);
        pat->setPosition(scaleFactor);

        traverse(node, nv);
    }
protected:
    int velocity{3};
    int angle{0};
    UpdateBallPhysics* newBall;
    bool mUp{true};
    unsigned int mCount{100};
    double mScaleStep{6.0/30.0};
};

#endif // SPHEREUPDATECALLBACK_H
