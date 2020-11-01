#ifndef UPDATEBALLPHYSICS_HPP
#define UPDATEBALLPHYSICS_HPP

#include <osg/StateSet>
#include <array>

class UpdateBallPhysics
{
public:
    UpdateBallPhysics();
    UpdateBallPhysics(int inputVelocity, int inputAngle);
    ~UpdateBallPhysics();
    std::array<double,3> get_position();
    std::array<double,3>  set_inital_velocity(int sliderVelocity, int sliderAngle);
    std::array<double,3> calculate_new_acceleration(std::array<double,3> oldAcceleration, std::array<double,3> newdragForce);
    std::array<double,3> calculate_new_velocity(std::array<double,3> oldVelocity, std::array<double,3> newAcceleration, double deltaT);
    std::array<double,3> calculate_new_position(std::array<double,3> oldPosition, std::array<double,3> newVelocity, double deltaT);
protected:
    void update_physics();
    void check_for_floor_bouncing();
    void check_for_leaving_world();
    std::array<double,3> calculate_drag_force();
    std::array<double,3> acceleration{0.0,0.0,-9.8};
    std::array<double,3> velocity{0.0,0.0,0.0};
    std::array<double,3> position{0.0,0.0,1.0};
    std::array<double,3> dragForce{0.0,0.0,0.0};
    double deltat{0.1};
    double mass{1.0};
    double coefficientOfRestitution{.75};
};


#endif // UPDATEBALLPHYSICS_HPP
