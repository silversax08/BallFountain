#ifndef PHYSICSWORLD_HPP
#define PHYSICSWORLD_HPP

#include "OSGWidget.h"
#include "sphereupdatecallback.h"
#include <vector>

class PhysicsWorld
{
public:
    PhysicsWorld(OSGWidget* pointer);
    ~PhysicsWorld();
    void add_ball_to_world(int inputVelocity, int inputAngle);
protected:
    OSGWidget* OSGWidgetPointer;
    std::vector<SphereUpdateCallback*> ballList;
    int velocity;
    int angle;
};

#endif // PHYSICSWORLD_HPP
