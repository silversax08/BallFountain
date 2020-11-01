#include "UpdateBallPhysics.hpp"
#include <iostream>

UpdateBallPhysics::UpdateBallPhysics()
{

}

UpdateBallPhysics::UpdateBallPhysics(int inputVelocity, int inputAngle)
{  
    set_inital_velocity(inputVelocity,inputAngle);
}

UpdateBallPhysics::~UpdateBallPhysics()
{
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

std::array<double,3> calculate_drag_force()
{
    std::array<double,3> dragForce{0,0,0};
    return dragForce;
}

std::array<double,3> UpdateBallPhysics::calculate_new_acceleration(std::array<double,3> oldAcceleration,std::array<double,3> newDragForce)
{
    std::array<double,3> newAcceleration;

    for (size_t i{0}; i < newAcceleration.size(); i++)
    {
        newAcceleration[i] = oldAcceleration[i]+(newDragForce[i]/mass);
    }
    std::cout<<newDragForce[2]<<std::endl;
    std::cout<<mass<<std::endl;

    return newAcceleration;
}

std::array<double,3> UpdateBallPhysics::calculate_new_velocity(std::array<double,3> oldVelocity, std::array<double,3> newAcceleration, double deltaT)
{
    std::array<double,3> newVelocity;

    for (size_t i{0}; i < newVelocity.size(); i++)
    {
        newVelocity[i] = oldVelocity[i]+newAcceleration[i]*deltaT;
    }

    return newVelocity;
}

std::array<double,3> UpdateBallPhysics::calculate_new_position(std::array<double,3> oldPosition, std::array<double,3> newVelocity, double deltaT)
{
    std::array<double,3> newPosition;

    for (size_t i{0}; i < newPosition.size(); i++)
    {
        newPosition[i] = oldPosition[i]+newVelocity[i]*deltaT;
    }

    return newPosition;
}

void UpdateBallPhysics::check_for_floor_bouncing()
{
    if (position[0] < 10.0 && position[0] > -10.0 && position[2] < .75)
    {
        if (position[1] < 10.0 && position[1] >= -10.0)
        {
                velocity[2] = -velocity[2]*coefficientOfRestitution;
        }
        else
            return;
        update_physics();
    }
    else
        return;
}

void UpdateBallPhysics::check_for_leaving_world()
{
    if (position[2] <= -15)
        delete this;
}

void UpdateBallPhysics::set_inital_velocity(int sliderVelocity, int sliderAngle)
{


    if (sliderAngle >= 0)
    {
        int angle{90-sliderAngle};
//        velocity[0] = sliderVelocity*cos(angle);
//        velocity[2] = sliderVelocity*sin(angle);
        velocity[0] = 0;
        velocity[2] = sliderVelocity;
    }
    else
    {
        int angle{90+sliderAngle};
//        velocity[0] = -sliderVelocity*cos(-angle);
//        velocity[2] = sliderVelocity*sin(-angle);
        velocity[0] = 0;
        velocity[2] = sliderVelocity;
    }
}
