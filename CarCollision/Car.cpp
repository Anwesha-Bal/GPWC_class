#include <SFML/Graphics.hpp>
using namespace sf;


class Car{
    const float START_SPEED = 200;

    Vector2f m_Position;
    Texture m_Texture;
    Sprite m_Sprite;
    bool moving_right=false;
    bool moving_left=false;
    float m_Speed;

    public:
        Car(float startX , float startY){
            m_Position.x = startX;
            m_Position.y = startY;
            m_Speed = START_SPEED;
            m_Sprite.setPosition(m_Position);
        }
        Sprite getSprite(){
            return m_Sprite;
        }
        FloatRect getPosition(){
            return m_Sprite.getGlobalBounds();
        }
        void moveRight(){
            moving_right = true;
        }
        void moveLeft(){
            moving_left = true;
        }
        void stopRight(){
            moving_right=false;
        }
        void stopLeft(){
            moving_left = false;
        }
        void update(Time dt){
            float dist = m_Speed*dt.asSeconds();
            if(moving_right){
                 m_Position.x += dist;
            }
            if(moving_left){
                 m_Position.x -= dist;
            }
            m_Sprite.setPosition(m_Position);
        }
};