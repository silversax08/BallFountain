#ifndef MEEN_570_OSGWIDGET
#define MEEN_570_OSGWIDGET

#include <QOpenGLWidget>
#include <osgViewer/CompositeViewer>
#include "physicsWorld.hpp"

class OSGWidget : public QOpenGLWidget
{
  Q_OBJECT
public:
  OSGWidget( QWidget* parent = 0,
             Qt::WindowFlags f = 0 );
  virtual ~OSGWidget();
  void sphere_setup(int velocity, int angle);
protected:
  PhysicsWorld world;
  void world_setup();
  void muzzle_setup();
  void block_setup();
  void camera_setup( int width, int height, int pixelRatio, float aspectRatio );
  void mViewer_setup();
  void timerEvent(QTimerEvent *);
  void manipluator_setup();
  double timer_and_frames_setup();
  virtual void paintEvent( QPaintEvent* paintEvent );
  virtual void paintGL();
  virtual void resizeGL( int width, int height );
  virtual void keyPressEvent( QKeyEvent* event );
  virtual void keyReleaseEvent( QKeyEvent* event );
  virtual void mouseMoveEvent( QMouseEvent* event );
  virtual void mousePressEvent( QMouseEvent* event );
  virtual void mouseReleaseEvent( QMouseEvent* event );
  virtual void wheelEvent( QWheelEvent* event );
private:
  virtual void on_resize( int width, int height );
  osgGA::EventQueue* getEventQueue() const;
  osg::ref_ptr<osgViewer::GraphicsWindowEmbedded> mGraphicsWindow;
  osg::ref_ptr<osgViewer::CompositeViewer> mViewer;
  osg::ref_ptr<osgViewer::View> mView;
  osg::ref_ptr<osg::Group> mRoot;
  int mTimerId{0};
};

#endif
