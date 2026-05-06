#include <SFML/Graphics.hpp>
#include "Car.cpp"
using namespace sf;

class PlayerCar : public Car
{
    float leftBoundary;
    float rightBoundary;

public:
    PlayerCar(float left, float right, Vector2f resolution)
    {
        m_Texture.loadFromFile("./Assets/WhiteCar.png");
        m_Sprite.setTexture(m_Texture);
        m_Sprite.setPosition(resolution.x / 2 + 200, resolution.y - 400);
        leftBoundary = left;
        rightBoundary = right;

        FloatRect bounds = m_Sprite.getLocalBounds();
        m_Sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    }

    void update(Time dt)
    {
        static float totalTime = 0;
        totalTime += dt.asSeconds();

        float baseSpeed = 200 + totalTime * 10;
        float randomFactor = (rand() % 20 - 10);

        m_Speed = baseSpeed + randomFactor;

        float dist = m_Speed * dt.asSeconds();

        if (moving_right && m_Position.x + dist <= rightBoundary)
        {
            m_Position.x += dist;
        }

        if (moving_left && m_Position.x - dist >= leftBoundary)
        {
            m_Position.x -= dist;
        }

        m_Sprite.setPosition(m_Position);
    }
    float getSpeed(){
        return m_Speed;
    }
};