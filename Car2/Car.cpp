#include "Car.h"

Car::~Car() {}

FloatRect Car::getBounds()
{
    return m_Sprite.getGlobalBounds();
}

void Car::setPosition(float x, float y)
{
    m_Position.x = x;
    m_Position.y = y;
    m_Sprite.setPosition(m_Position);
}

Sprite& Car::getSprite()
{
    return m_Sprite;
}

float Car::getSpeed()
{
    return m_Speed;
}

void Car::setSpeed(float s)
{
    m_Speed = s;
}