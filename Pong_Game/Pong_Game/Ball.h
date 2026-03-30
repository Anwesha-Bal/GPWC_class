#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Ball{
    private:
       //Position
       Vector2f m_Position;
       //Shape
       CircleShape m_Shape;
       //Speed
       float m_Speed=1000.0f;
       //X direction
       float m_DirectionX=0.2f;
       //Y direction
       float m_DirectionY=0.2f;
    public:
       //Constructor
       Ball(float startX,float startY);
       //Position
       FloatRect getPosition();
       //Shape
       CircleShape getShape();
       //X velocity
       float getXVelocity();
       //Rebound Sides
       void reboundSides();
       //Rebound bat or top
       void reboundBatOrTop();
       //rebound bottom
       void reboundBottom();
       //Update position
       void update(Time dt);   
};