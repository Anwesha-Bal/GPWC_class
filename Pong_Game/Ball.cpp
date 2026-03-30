#include "Ball.h"


//Constuctor
Ball :: Ball(float startX, float startY){
    m_Position.x = startX;
    m_Position.y = startY;

    m_Shape.setRadius(10.0);
    m_Shape.setPosition(m_Position);
}

//getPosition

FloatRect Ball :: getPosition(){
    return m_Shape.getGlobalBounds();
}

//getShape()

CircleShape Ball :: getShape(){
    return m_Shape;
}

//getXVelocity--Returns x direction

float Ball::getXVelocity(){
    return m_DirectionX;
}

//Rebound Sides

void Ball::reboundSides(){
     m_DirectionX = -m_DirectionX;
}

//Rebound Bat or Top

void Ball::reboundBatOrTop(){
    m_DirectionY = -m_DirectionY;
}

//rebound Bottom

void Ball::reboundBottom(){
    //m_DirectionY = -m_DirectionY;
    m_Position.x=500.0;
    m_Position.y=0.0;
    //m_Shape.setPosition(m_Position);
}

//update position

void Ball::update(Time dt){
    m_Position.x += m_DirectionX*m_Speed*dt.asSeconds();
    m_Position.y += m_DirectionY*m_Speed*dt.asSeconds();
    
    m_Shape.setPosition(m_Position);


}


