#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class Bat{
    //Declare Position
    Vector2f m_Position;
    //Declare Shape
    RectangleShape m_Shape;
    //declare Speed
    float m_Speed = 1000.0f;
    //declare bool var for left and right movement
    bool m_movingRight = false;
    bool m_movingLeft = false;

    public:
        //Declare Constructor
        Bat(float startX , float startY);

        //getPosition
        FloatRect get_Position();

        //get shape
        RectangleShape get_Shape();

        //declare moveRight
        void moveRight();
        //declare moveleft
        void moveLeft();

        //stop right
        void stopRight();
         //stop Left
        void stopLeft();

        //update
        void update(Time dt);

}