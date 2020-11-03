#ifndef BALLPHYSICSEQUATIONS_H
#define BALLPHYSICSEQUATIONS_H

#include <array>

namespace ballPhysicsEquations{
std::array<double,3> set_inital_velocity(int sliderVelocity, int sliderAngle);
std::array<double,3> calculate_new_acceleration(std::array<double,3> oldAcceleration, std::array<double,3> newdragForce,double mass);
std::array<double,3> calculate_new_velocity(std::array<double,3> oldVelocity, std::array<double,3> newAcceleration, double deltaT);
std::array<double,3> calculate_new_position(std::array<double,3> oldPosition, std::array<double,3> newVelocity, double deltaT);
}

#endif // BALLPHYSICSEQUATIONS_H

