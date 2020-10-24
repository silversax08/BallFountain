#ifndef BALLMOTION_HPP
#define BALLMOTION_HPP

#include <osg/StateSet>

class UpdateBallPhysics
{
public:
    UpdateBallPhysics();
protected:
    osg::Vec3d calculate_new_acceleration();
    osg::Vec3d calculate_new_velocity();
    osg::Vec3d calculate_new_position();
    osg::Vec3d calculate_drag_force();
private:
    osg::Vec3d oldAcceleration{0.0,0.0,-9.8};
    osg::Vec3d oldVelocity{0.0,0.0,0.0};
    osg::Vec3d oldPosition{0.0,0.0,0.0};
    osg::Vec3d oldDragForce{0.0,0.0,0.0};
    double deltat{0.0};
};


#endif // BALLMOTION_HPP
