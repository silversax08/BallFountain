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

class SphereUpdateCallback: public osg::NodeCallback
{
public:
    SphereUpdateCallback(int count)
    {
        mCount = count;
    }

    virtual void operator()(osg::Node* node, osg::NodeVisitor* nv)
    {
        mCount--;


        osg::Vec3d scaleFactor(1.0, 1.0, mScaleStep*mCount- 10.0);
        osg::PositionAttitudeTransform *pat = dynamic_cast<osg::PositionAttitudeTransform *> (node);
        pat->setPosition(scaleFactor);

        traverse(node, nv);

        if(mCount==0)
            return;
    }
protected:
    bool mUp{true};
    unsigned int mCount{100};
    double mScaleStep{6.0/30.0};
};

#endif // SPHEREUPDATECALLBACK_H