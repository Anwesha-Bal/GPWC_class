#pragma once
#include "Car.h"
#include <string>
class PlayerCar : public Car
{
private:
    Vector2f resolution;

    bool moving_left = false;
    bool moving_right = false;

    float m_Acceleration = 15.0f;

public:
    PlayerCar(float startX, float startY);

    void moveLeft();

    void moveRight();

    void stopLeft();

    void stopRight();

    void update(Time dt);
};
