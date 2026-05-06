#include <SFML/Graphics.hpp>
#include "Car.cpp"
#include <ctime>
using namespace sf;
class EnemyCar : public Car
{
    const float RED_SPEED = 150;
    const float YELLOW_SPEED = 100;

public:
    void spawn(float startX, int type)
    {
        switch (type)
        {
        case 0:
            m_Texture.loadFromFile("./Assets/RedCar1.png");
            m_Sprite.setTexture(m_Texture);
            m_Speed = RED_SPEED;
            break;
        case 1:
            m_Texture.loadFromFile("./Assets/RedCar2.png");
            m_Sprite.setTexture(m_Texture);
            m_Speed = RED_SPEED;
            break;
        case 2:
            m_Texture.loadFromFile("./Assets/YellowCar1.png");
            m_Sprite.setTexture(m_Texture);
            m_Speed = YELLOW_SPEED;
            break;
        case 3:
            m_Texture.loadFromFile("./Assets/YellowCar2.png");
            m_Sprite.setTexture(m_Texture);
            m_Speed = YELLOW_SPEED;
            break;
        case 4:
            m_Texture.loadFromFile("./Assets/YellowCar3.png");
            m_Sprite.setTexture(m_Texture);
            m_Speed = YELLOW_SPEED;
            break;
        default:
            break;
        }
        float modifier = (rand() % 30 + 70) / 100.0f;
        m_Speed *= modifier;

        modifier /= 100;
        m_Position.x = startX;
        m_Position.y = -100;
        FloatRect bounds = m_Sprite.getLocalBounds();
        m_Sprite.setOrigin(bounds.width / 2, bounds.height / 2);
        m_Sprite.setPosition(m_Position);
    }

    void update(Time dt)
    {
        float dist = m_Speed * dt.asSeconds();

        m_Position.y += dist;

        m_Sprite.setPosition(m_Position);
    }
};