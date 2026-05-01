#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Player{
    const int START_HEALTH = 100;
    const int START_SPEED = 200;

    Vector2f m_Position;
    Texture m_Texture;
    Sprite m_Sprite;

    bool m_MovingLeft = false;
    bool m_MovingRight = false;
    bool m_MovingUp = false;
    bool m_MovingDown = false;
    
    int m_Health;
    float m_Speed;
    Time m_LastHit;
    int m_MaxHealth;


    IntRect m_Arena;

    public:
        Player();
        void spwan(int startX , int startY , IntRect arena);
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
        void stopLeft();
        void stopRight();
        void stopUp();
        void stopDown();


};