# pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Car
{
protected:
    Vector2f m_Position;
    Texture m_Texture;
    Sprite m_Sprite;
    float m_Speed = 0;

public:
    virtual ~Car();

    FloatRect getBounds();

    void setPosition(float x, float y);

    Sprite& getSprite();

    float getSpeed();

    void setSpeed(float s);
};
