#ifndef BALLMOTION_HPP
#define BALLMOTION_HPP
#include <array>

class UpdateBallPhysics
{
public:
    UpdateBallPhysics();
protected:
    std::array<double,3> calculate_new_acceleration();
    std::array<double,3> calculate_new_velocity();
    std::array<double,3> calculate_new_position();
private:
    std::array<double,3> oldAcceleration{0.0,0.0,-9.8};
    std::array<double,3> oldVelocity{0.0,0.0,0};
    std::array<double,3> oldPosition{0.0,0.0,0};
    double deltat{0};
    double dragForce{0};
};


#endif // BALLMOTION_HPP
