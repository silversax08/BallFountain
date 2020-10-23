#include "OSGWidget.h"

#include <QOpenGLWidget>

#include <osg/ref_ptr>
#include <osgViewer/GraphicsWindow>
#include <osgViewer/CompositeViewer>
#include <osgGA/TrackballManipulator>
#include <osgText/Text>

//osg::ref_ptr<osgViewer::View> camera_setup(int width, int height, int pixelRatio,float aspectRatio)
//{
//    osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> mGraphicsWindow;
//    osg::ref_ptr<osgViewer::View> mView;

//    osg::Camera* camera = new osg::Camera;
//    camera->setViewport( 0, 0, width * pixelRatio, height * pixelRatio);

//    camera->setClearColor( osg::Vec4( 0.f, 0.f, .5, 1.f ) );
//    camera->setProjectionMatrixAsPerspective( 45.f, aspectRatio, 1.f, 1000.f );
//    camera->setGraphicsContext( mGraphicsWindow );
//    mView->setCamera( camera );

//    return mView;
//}

osg::Camera* camera_setup(int width, int height, int pixelRatio,float aspectRatio)
{
    osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> mGraphicsWindow;
    osg::ref_ptr<osgViewer::View> mView;

    osg::Camera* camera = new osg::Camera;
    camera->setViewport( 0, 0, width * pixelRatio, height * pixelRatio);

    camera->setClearColor( osg::Vec4( 0.f, 0.f, .5, 1.f ) );
    camera->setProjectionMatrixAsPerspective( 45.f, aspectRatio, 1.f, 1000.f );
    camera->setGraphicsContext( mGraphicsWindow );
//    mView->setCamera( camera );

    return camera;
}
