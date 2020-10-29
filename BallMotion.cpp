#include "BallMotion.hpp"
//#include <osg/StateSet>

UpdateBallPhysics::UpdateBallPhysics()
{  
}

osg::Vec3d UpdateBallPhysics::get_position()
{
    update_physics();
    return position;
}

void UpdateBallPhysics::update_physics()
{
    acceleration = calculate_new_acceleration(acceleration);
    velocity = calculate_new_velocity(velocity,acceleration,deltat);
    position = calculate_new_position(position,velocity,deltat);
}

osg::Vec3d calculate_drag_force()
{
    osg::Vec3d dragForce(0,0,0);
    return dragForce;
}

osg::Vec3d UpdateBallPhysics::calculate_new_acceleration(osg::Vec3d oldAcceleration)
{
    return oldAcceleration;
}

osg::Vec3d UpdateBallPhysics::calculate_new_velocity(osg::Vec3d oldVelocity, osg::Vec3d newAcceleration, double deltaT)
{
    osg::Vec3d newVelocity{oldVelocity+newAcceleration*deltaT};
    return newVelocity;
}

osg::Vec3d UpdateBallPhysics::calculate_new_position(osg::Vec3d oldPosition, osg::Vec3d newVelocity, double deltaT)
{
    osg::Vec3d newPosition{oldPosition+newVelocity*deltaT};
    return newPosition;
}
