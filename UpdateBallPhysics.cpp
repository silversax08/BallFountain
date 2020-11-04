#include "UpdateBallPhysics.hpp"
#include "BallPhysicsEquations.h"
#include <iostream>

UpdateBallPhysics::UpdateBallPhysics()
{
}

UpdateBallPhysics::UpdateBallPhysics(int inputVelocity, int inputAngle)
{  
    set_inital_velocity(inputVelocity,inputAngle);
}

std::array<double,3> UpdateBallPhysics::get_position()
{
    update_physics();
    check_for_floor_bouncing();
    return position;
}

void UpdateBallPhysics::update_physics()
{
    acceleration = calculate_new_acceleration(acceleration,dragForce);
    velocity = calculate_new_velocity(velocity,acceleration,deltat);
    position = calculate_new_position(position,velocity,deltat);
}

void UpdateBallPhysics::check_for_floor_bouncing()
{
    double xPosition{position[0]};
    double yPosition{position[1]};
    double zPosition{position[2]};

    if (xPosition <= 10.0 && xPosition >= -10.0 && yPosition <= 10.0 && yPosition >= -10.0 && zPosition <= .75)
    {
        check_for_low_z_velocity();
        position[2] = .75;
        update_physics();
    }
    else
        return;
}

void UpdateBallPhysics::check_for_low_z_velocity()
{
    if (velocity[2] <= -.1)
        velocity[2] = -velocity[2]*coefficientOfRestitution;
    else
        velocity[2] = 0;
}

std::array<double,3>  UpdateBallPhysics::set_inital_velocity(int sliderVelocity, int sliderAngle)
//Copied directly from BallPhysicsEquations::set_initial_velocity. Acted weird when called the function in this function though.
{
    if (sliderAngle >= 0)
    {
        double angle{(90-sliderAngle)*3.14/180};
        velocity[0] = sliderVelocity*cos(angle);
        velocity[2] = sliderVelocity*sin(angle);
    }
    else
    {
        double angle{(90+sliderAngle)*3.14/180};
        velocity[0] = -sliderVelocity*cos(-angle);
        velocity[2] = -sliderVelocity*sin(-angle);
    }

    return velocity;
}

std::array<double,3> UpdateBallPhysics::calculate_new_acceleration(std::array<double,3> oldAcceleration,std::array<double,3> newDragForce)
{
    return ballPhysicsEquations::calculate_new_acceleration(oldAcceleration,newDragForce,mass);
}

std::array<double,3> UpdateBallPhysics::calculate_new_velocity(std::array<double,3> oldVelocity, std::array<double,3> newAcceleration, double deltaT)
{
    return ballPhysicsEquations::calculate_new_velocity(oldVelocity,newAcceleration,deltaT);
}

std::array<double,3> UpdateBallPhysics::calculate_new_position(std::array<double,3> oldPosition, std::array<double,3> newVelocity, double deltaT)
{
    return ballPhysicsEquations::calculate_new_position(oldPosition,newVelocity,deltaT);
}
