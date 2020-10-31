#include "OSGWidget.h"

#include <osg/Camera>
#include <osg/DisplaySettings>
#include <osg/Geode>
#include <osg/Material>
#include <osg/Shape>
#include <osg/ShapeDrawable>
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

#include "sphereupdatecallback.h"
#include "UpdateBallPhysics.hpp"



OSGWidget::OSGWidget( QWidget* parent, Qt::WindowFlags flags ):
    QOpenGLWidget{ parent,flags },
    mGraphicsWindow{ new osgViewer::GraphicsWindowEmbedded{ this->x(),
                                                            this->y(),
                                                            this->width(),
                                                            this->height() } }
  , mViewer{ new osgViewer::CompositeViewer }
{
    mRoot = new osg::Group;

    mView = new osgViewer::View;

    float aspectRatio = static_cast<float>( this->width() ) / static_cast<float>( this->height() );
    int pixelRatio   = this->devicePixelRatio();

    camera_setup(this->width(), this->height(), pixelRatio, aspectRatio);

    mView->setSceneData( mRoot.get() );
    mView->addEventHandler( new osgViewer::StatsHandler );

    osg::ref_ptr<osgGA::TrackballManipulator> manipulator = new osgGA::TrackballManipulator;
    manipulator->setAllowThrow( false );
    manipulator->setHomePosition(osg::Vec3d(0.0,-25.0,14.0),osg::Vec3d(0,0,2),osg::Vec3d(0,0,1));
    mView->setCameraManipulator( manipulator );


    mViewer->addView( mView );
    mViewer->setThreadingModel( osgViewer::CompositeViewer::SingleThreaded );
    mViewer->realize();
    mView->home();

    sphere_setup();
    block_setup();
    muzzle_setup();
//    world_setup();


    this->setFocusPolicy( Qt::StrongFocus );
    this->setMinimumSize( 100, 100 );
    this->setMouseTracking( true );

    this->update();

    double framesPerSecond{30};
    double timeStep{1.0/framesPerSecond};
    double timerDurationInMilliSeconds{timeStep * 1000};
    mTimerId=startTimer(timerDurationInMilliSeconds);

}

OSGWidget::~OSGWidget()
{
    killTimer(mTimerId);
    delete mViewer;
}

void OSGWidget::timerEvent(QTimerEvent *)
{
    update();
}

void OSGWidget::paintEvent( QPaintEvent* /* paintEvent */ )
{
    this->makeCurrent();

    QPainter painter( this );
    painter.setRenderHint( QPainter::Antialiasing );

    this->paintGL();

    painter.end();

    this->doneCurrent();
}

void OSGWidget::paintGL()
{
    mViewer->frame();
}

void OSGWidget::resizeGL( int width, int height )
{
    this->getEventQueue()->windowResize( this->x(), this->y(), width, height );
    mGraphicsWindow->resized( this->x(), this->y(), width, height );

    this->on_resize( width, height );
}

void OSGWidget::on_resize( int width, int height )
{
    std::vector<osg::Camera*> cameras;
    mViewer->getCameras( cameras );

    auto pixelRatio = this->devicePixelRatio();

    cameras[0]->setViewport( 0, 0, width * pixelRatio, height * pixelRatio );
}

osgGA::EventQueue* OSGWidget::getEventQueue() const
{
    osgGA::EventQueue* eventQueue = mGraphicsWindow->getEventQueue();

    if( eventQueue )
        return eventQueue;
    else
        throw std::runtime_error( "Unable to obtain valid event queue");
}

void OSGWidget::camera_setup(int width, int height, int pixelRatio,float aspectRatio)
{
    osg::Camera* camera = new osg::Camera;
    camera->setViewport( 0, 0, width * pixelRatio, height * pixelRatio);

    camera->setClearColor( osg::Vec4( 0.f, 0.f, .5, 1.f ) );
    camera->setProjectionMatrixAsPerspective( 45.f, aspectRatio, 1.f, 1000.f );
    camera->setGraphicsContext( mGraphicsWindow );
    mView->setCamera( camera );
}

void OSGWidget::sphere_setup()
{
    osg::Sphere* sphere    = new osg::Sphere( osg::Vec3( 0.f, 0.f, 0.f ), 1.0f );
    osg::ShapeDrawable* sd = new osg::ShapeDrawable(sphere);
    sd->setColor( osg::Vec4( 1.f, 0.f, 0.f, 1.f ) );
    sd->setName( "Sphere" );

    osg::Geode* geode = new osg::Geode;
    geode->addDrawable( sd );

    osg::StateSet* stateSet = geode->getOrCreateStateSet();
    osg::Material* material = new osg::Material;

    material->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );

    stateSet->setAttributeAndModes( material, osg::StateAttribute::ON );
    stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );

    osg::PositionAttitudeTransform *transform = new osg::PositionAttitudeTransform;
    transform->setPosition(osg::Vec3( 4.0, 0.0, 2.0 ));
    transform->setUpdateCallback(new SphereUpdateCallback());
    transform->addChild(geode);

    mRoot->addChild(transform);
}

void OSGWidget::block_setup()
{
    osg::Box* box    = new osg::Box( osg::Vec3( 0.f, 0.f, 0.f ), 20.0f );
    osg::ShapeDrawable* sd = new osg::ShapeDrawable( box );
    sd->setColor( osg::Vec4( 1.f, 1.f, 0.f, 1.f ) );
    sd->setName( "Box" );

    osg::Geode* geode = new osg::Geode;
    geode->addDrawable( sd );

    osg::StateSet* stateSet = geode->getOrCreateStateSet();
    osg::Material* material = new osg::Material;

    material->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );

    stateSet->setAttributeAndModes( material, osg::StateAttribute::ON );
    stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );

    osg::PositionAttitudeTransform *transform = new osg::PositionAttitudeTransform;
    transform->setPosition(osg::Vec3( 0.0, 0.0, -11.0 ));
    transform->addChild(geode);

    mRoot->addChild(transform);
}

void OSGWidget::muzzle_setup()
{
    osg::Cylinder* cylinder    = new osg::Cylinder( osg::Vec3( 0.f, 0.f, 0.f ), 1.0f, 2.0f );
    osg::ShapeDrawable* sd = new osg::ShapeDrawable( cylinder );
    sd->setColor( osg::Vec4( 0.f, 0.f, 0.f, 0.f ) );
    sd->setName( "Cylinder" );

    osg::Geode* geode = new osg::Geode;
    geode->addDrawable( sd );

    osg::StateSet* stateSet = geode->getOrCreateStateSet();
    osg::Material* material = new osg::Material;

    material->setColorMode( osg::Material::AMBIENT_AND_DIFFUSE );

    stateSet->setAttributeAndModes( material, osg::StateAttribute::ON );
    stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::ON );

    osg::PositionAttitudeTransform *transform = new osg::PositionAttitudeTransform;
    transform->addChild(geode);

    mRoot->addChild(transform);
}

