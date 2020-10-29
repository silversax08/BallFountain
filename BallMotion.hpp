#ifndef BALLMOTION_HPP
#define BALLMOTION_HPP

#include <osg/StateSet>

class UpdateBallPhysics
{
public:
    UpdateBallPhysics();
    osg::Vec3d get_position();

protected:
    void update_physics();
    osg::Vec3d calculate_new_acceleration(osg::Vec3d oldAcceleration);
    osg::Vec3d calculate_new_velocity(osg::Vec3d oldVelocity, osg::Vec3d newAcceleration, double deltaT);
    osg::Vec3d calculate_new_position(osg::Vec3d oldPosition, osg::Vec3d newVelocity, double deltaT);
    osg::Vec3d calculate_drag_force();
    osg::Vec3d acceleration{0.0,0.0,-9.8};
    osg::Vec3d velocity{0.0,0.0,0.0};
    osg::Vec3d position{0.0,0.0,10.0};
    osg::Vec3d dragForce{0.0,0.0,0.0};
    double deltat{0.0};
};


#endif // BALLMOTION_HPP
