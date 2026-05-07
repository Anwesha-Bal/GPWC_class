#include "EnemyCar.h"
#include <string>

    EnemyCar::EnemyCar() {
        screenHeight = (float)VideoMode::getDesktopMode().height;
    }
    void EnemyCar::spawn(float startX, int type, float globalSpeedMultiplier) {
        std::string path;
        float baseSpeed = 0;

        switch (type) {
            case 0: path = "./Assets/RedCar1.png"; baseSpeed = 150.0f; break;
            case 1: path = "./Assets/RedCar2.png"; baseSpeed = 200.0f; break;
            case 2: path = "./Assets/YellowCar1.png"; baseSpeed = 100.0f; break;
            case 3: path = "./Assets/YellowCar2.png"; baseSpeed = 100.0f; break;
            case 4: path = "./Assets/YellowCar3.png"; baseSpeed = 100.0f; break;
        }

        if (m_Texture.loadFromFile(path)) {
            m_Sprite.setTexture(m_Texture);
        }

        m_Speed = baseSpeed + globalSpeedMultiplier;
        
        setPosition(startX, -200.0f); 
    }

    void EnemyCar::update(Time dt) {
        m_Position.y += m_Speed * dt.asSeconds();
        m_Sprite.setPosition(m_Position);
    }

    bool EnemyCar::isOffScreen() {
        return m_Position.y > screenHeight + 100;
    }
