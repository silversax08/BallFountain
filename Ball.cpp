#include "Ball.h"
#include "sphereupdatecallback.h"
#include <osg/Geode>
#include <osg/Material>
#include <osg/ShapeDrawable>

Ball::Ball(int inputVelocity, int inputAngle)
{
    velocity = inputVelocity;
    angle  = inputAngle;
    create_physics_representation();
    create_visual_representation();
}

osg::PositionAttitudeTransform* Ball::get_transform()
{
    return transform;
}

UpdateBallPhysics* Ball::get_physics()
{
    return ballPhysics;
}

void Ball::create_physics_representation()
{
    ballPhysics = new UpdateBallPhysics(velocity,angle);
}

void Ball::create_visual_representation()
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

    transform = new osg::PositionAttitudeTransform;
    transform->setPosition(osg::Vec3( 4.0, 0.0, 2.0 ));
    transform->setUpdateCallback(new SphereUpdateCallback(ballPhysics));
    transform->addChild(geode);
}
