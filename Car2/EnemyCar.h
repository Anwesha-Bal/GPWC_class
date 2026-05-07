#pragma once

#include "Car.h"


class EnemyCar : public Car
{
private:
    float screenHeight;

public:
    EnemyCar();

    void spawn(float startX, int type, float globalSpeedMultiplier);

    void update(Time dt);

    bool isOffScreen();
};
