#include "PLayer.h"
Player::Player(){
    m_Texture.loadFromFile("graphics/player.png");
    m_Sprite.setTexture(m_Texture);
    m_Health = START_HEALTH;
    m_MaxHealth =   START_HEALTH;
    m_Speed = START_SPEED;
    m_Sprite.setOrigin(25,25);
}
void Player::moveLeft(){
    m_MovingLeft = true;
}
void Player::moveRight(){
    m_MovingRight = true;
}
void Player::moveUp(){
    m_MovingUp = true;
}
void Player::moveDown(){
    m_MovingDown = true;
}
void Player::stopLeft(){
    m_MovingLeft = false;
}
void Player::stopRight(){
    m_MovingRight = false;
}
void Player::stopUp(){
    m_MovingUp = false;
}
void Player::stopDown(){ 
    m_MovingDown = false;
}
void Player::spwan(int startX , int startY , IntRect arena){
    m_Arena.left = arena.left;
    m_Arena.top = arena.top;
    m_Arena.width = arena.width;
    m_Arena.height = arena.height;
    m_Position.x = startX;
    m_Position.y = startY;
    m_Sprite.setPosition(m_Position); 
}
