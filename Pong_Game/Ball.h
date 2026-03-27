#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class Ball{
    private:
        //Position
        Vector2f m_Position;
        //Shape
        CircleShape m_Shape;
        //Speed
        float m_Speed =1000.0f;
        //Direction
        float m_DirectionX = 0.2f;
        float m_DirectionY = 0.2f;
    public:
        //COnstructor
        Ball(float startX , float startY);

        //getPosition
        FloatRect getPosition();

        //getShape
        CircleShape getShape();

        //getXvelocity
        float getXVelocity();

        //Rebound Sides
        void reboundSides();

        //Rebound bat or top
        void reboundBatOrTop();

        //rebound bottom
        void reboundBottom();

        //Update Position
        void updatePosition(Time dt);
}