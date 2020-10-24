#ifndef BALLMOTION_HPP
#define BALLMOTION_HPP

#include <osg/StateSet>

class UpdateBallPhysics
{
public:
    UpdateBallPhysics();
    void calculate_new_acceleration(osg::Vec3d OldAcceleration, osg::Vec3d OldDragForce);
    osg::Vec3d calculate_new_velocity();
    osg::Vec3d calculate_new_position();
    osg::Vec3d calculate_drag_force();
    osg::Vec3d updatedAcceleration{0.0,0.0,0.0};
    osg::Vec3d updatedVelocity{0.0,0.0,0.0};
    osg::Vec3d updatedPosition{0.0,0.0,0.0};
    osg::Vec3d updatedDragForce{0.0,0.0,0.0};
protected:

private:
    double deltat{0.0};
};


#endif // BALLMOTION_HPP
