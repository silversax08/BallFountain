#include "BallPhysicsEquations.h"

std::array<double,3> ballPhysicsEquations::calculate_new_acceleration(std::array<double,3> oldAcceleration,std::array<double,3> newDragForce,double mass)
{
    std::array<double,3> newAcceleration;

    for (size_t i{0}; i < newAcceleration.size(); i++)
    {
        newAcceleration[i] = oldAcceleration[i]+(newDragForce[i]/mass);
    }

    return newAcceleration;
}

std::array<double,3> ballPhysicsEquations::calculate_new_velocity(std::array<double,3> oldVelocity, std::array<double,3> newAcceleration, double deltaT)
{
    std::array<double,3> newVelocity;

    for (size_t i{0}; i < newVelocity.size(); i++)
    {
        newVelocity[i] = oldVelocity[i]+newAcceleration[i]*deltaT;
    }

    return newVelocity;
}

std::array<double,3> ballPhysicsEquations::calculate_new_position(std::array<double,3> oldPosition, std::array<double,3> newVelocity, double deltaT)
{
    std::array<double,3> newPosition;

    for (size_t i{0}; i < newPosition.size(); i++)
    {
        newPosition[i] = oldPosition[i]+newVelocity[i]*deltaT;
    }

    return newPosition;
}

std::array<double,3>  ballPhysicsEquations::set_inital_velocity(int sliderVelocity, int sliderAngle)
{
    std::array<double,3> velocity{0.0,0.0,0.0};

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
