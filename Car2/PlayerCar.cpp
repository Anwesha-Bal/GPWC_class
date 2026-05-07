#include "PlayerCar.h"

PlayerCar::PlayerCar(float startX, float startY)
{
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    m_Texture.loadFromFile("./Assets/WhiteCar.png");
    m_Sprite.setTexture(m_Texture);

    FloatRect bounds = m_Sprite.getLocalBounds();

    m_Sprite.setOrigin(
        bounds.width / 2.0f,
        bounds.height / 2.0f
    );

    setPosition(startX, startY);

    m_Speed = 400.0f;
}

void PlayerCar::moveLeft()
{
    moving_left = true;
}

void PlayerCar::moveRight()
{
    moving_right = true;
}

void PlayerCar::stopLeft()
{
    moving_left = false;
}

void PlayerCar::stopRight()
{
    moving_right = false;
}

void PlayerCar::update(Time dt)
{
    float distance = m_Speed * dt.asSeconds();

    if (moving_left &&
        m_Position.x - distance > 0)
    {
        m_Position.x -= distance;
    }

    if (moving_right &&
        m_Position.x + distance < resolution.x)
    {
        m_Position.x += distance;
    }

    m_Sprite.setPosition(m_Position);
}