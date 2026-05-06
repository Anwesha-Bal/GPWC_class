#include "EnemyCar.cpp"

EnemyCar* createCar(int numCars, float leftBoundary, float rightBoundary)
{
    EnemyCar* cars = new EnemyCar[numCars];

    int numLanes = 5;
    float laneWidth = (rightBoundary - leftBoundary) / numLanes;

    for (int i = 0; i < numCars; i++)
    {
        int type = rand() % 5;

        int laneIndex = rand() % numLanes;
        float x = leftBoundary + laneWidth/2 + laneIndex * laneWidth;

        cars[i].spawn(x, type);
    }

    return cars;
}