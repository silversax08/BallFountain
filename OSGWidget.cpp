#include "OSGWidget.h"
#include <osg/Material>
#include <osgViewer/ViewerEventHandlers>
#include <osgGA/TrackballManipulator>
#include <QPainter>
#include "sphereupdatecallback.h"
#include "Ball.h"
#include <QKeyEvent>



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

//    osg::ref_ptr<osgGA::TrackballManipulator> manipulator = new osgGA::TrackballManipulator;
//    manipulator->setAllowThrow( false );
//    manipulator->setHomePosition(osg::Vec3d(0.0,-25.0,14.0),osg::Vec3d(0,0,2),osg::Vec3d(0,0,1));
//    mView->setCameraManipulator( manipulator );
    manipluator_setup();

    mViewer_setup();

    block_setup();
    muzzle_setup();

    this->setFocusPolicy( Qt::StrongFocus );
    this->setMinimumSize( 100, 100 );
    this->setMouseTracking( true );

    this->update();

    mTimerId=startTimer(timer_and_frames_setup());

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

double OSGWidget::timer_and_frames_setup()
{
    double framesPerSecond{30};
    double timeStep{1.0/framesPerSecond};
    double timerDurationInMilliSeconds{timeStep * 1000};
    return timerDurationInMilliSeconds;
}

void OSGWidget::mViewer_setup()
{
    mView->setSceneData( mRoot.get() );
    mView->addEventHandler( new osgViewer::StatsHandler );

    mViewer->addView( mView );
    mViewer->setThreadingModel( osgViewer::CompositeViewer::SingleThreaded );
    mViewer->realize();
    mView->home();
}

void OSGWidget::manipluator_setup()
{
    osg::ref_ptr<osgGA::TrackballManipulator> manipulator = new osgGA::TrackballManipulator;
    manipulator->setAllowThrow( false );
    manipulator->setHomePosition(osg::Vec3d(0.0,-25.0,14.0),osg::Vec3d(0,0,2),osg::Vec3d(0,0,1));
    mView->setCameraManipulator( manipulator );
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

void OSGWidget::sphere_setup(int velocity, int angle)
{
    Ball newBall(velocity, angle);
    mRoot->addChild(newBall.get_transform());
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
    osg::Cylinder* cylinder    = new osg::Cylinder( osg::Vec3( 0.f, 0.f, 0.f ), 1.5f, 3.5f );
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

void OSGWidget::keyPressEvent( QKeyEvent* event )
{
    QString keyString   = event->text();
    const char* keyData = keyString.toLocal8Bit().data();

    if( event->key() == Qt::Key_H )
    {
        osgViewer::ViewerBase::Views views;
        mViewer->getViews( views );

        for( std::size_t i = 0; i < views.size(); i++ )
        {
            osgViewer::View* view = views.at(i);
            view->home();
        }
        return;
    }

    this->getEventQueue()->keyPress( osgGA::GUIEventAdapter::KeySymbol( *keyData ) );
}

void OSGWidget::keyReleaseEvent( QKeyEvent* event )
{
    QString keyString   = event->text();
    const char* keyData = keyString.toLocal8Bit().data();

    this->getEventQueue()->keyRelease( osgGA::GUIEventAdapter::KeySymbol( *keyData ) );
}

void OSGWidget::mouseMoveEvent( QMouseEvent* event )
{
    auto pixelRatio = this->devicePixelRatio();

    this->getEventQueue()->mouseMotion( static_cast<float>( event->x() * pixelRatio ),
                                        static_cast<float>( event->y() * pixelRatio ) );
}

void OSGWidget::mousePressEvent( QMouseEvent* event )
{
    // 1 = left mouse button
    // 2 = middle mouse button
    // 3 = right mouse button

    unsigned int button = 0;

    switch( event->button() )
    {
    case Qt::LeftButton:
        button = 1;
        break;
    case Qt::MiddleButton:
        button = 2;
        break;
    case Qt::RightButton:
        button = 3;
        break;
    default:
        break;
    }

    auto pixelRatio = this->devicePixelRatio();

    this->getEventQueue()->mouseButtonPress( static_cast<float>( event->x() * pixelRatio ),
                                             static_cast<float>( event->y() * pixelRatio ),
                                             button );
}

void OSGWidget::mouseReleaseEvent(QMouseEvent* event)
{
    // 1 = left mouse button
    // 2 = middle mouse button
    // 3 = right mouse button

    unsigned int button = 0;

    switch( event->button() )
    {
    case Qt::LeftButton:
        button = 1;
        break;
    case Qt::MiddleButton:
        button = 2;
        break;
    case Qt::RightButton:
        button = 3;
        break;
    default:
        break;
    }

    auto pixelRatio = this->devicePixelRatio();
    this->getEventQueue()->mouseButtonRelease( static_cast<float>( pixelRatio * event->x() ),
                                               static_cast<float>( pixelRatio * event->y() ),
                                               button );

}

void OSGWidget::wheelEvent( QWheelEvent* event )
{
    event->accept();
    int delta = event->delta();

    osgGA::GUIEventAdapter::ScrollingMotion motion = delta > 0 ?   osgGA::GUIEventAdapter::SCROLL_UP
                                                                 : osgGA::GUIEventAdapter::SCROLL_DOWN;

    this->getEventQueue()->mouseScroll( motion );
}



