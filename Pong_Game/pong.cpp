#include "Ball.h"
#include "Bat.h"
#include <sstream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main(){
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    VideoMode vm(resolution.x, resolution.y);
    RenderWindow window(vm, "Pong!!",Style::Fullscreen);
    
    int score=0;
    int lives=3;

    //Create Bat
    Bat bat(resolution.x/2,resolution.y-50);

    //Create Ball
    Ball ball(resolution.x/2,0);

    //CREATE A TEXT OBJCT CALLED HUD(HEAD UP DISPLAY)
    Font font;
    font.loadFromFile("./fonts/KOMIKAP_.ttf");
    Text hud;
    hud.setFont(font);

    //SET FONT SIZE
    hud.setCharacterSize(75);
    hud.setFillColor(Color::Red); //Red is a static initial constant and color is a class not a enum value
    hud.setPosition(20.0,20.0);

    Clock clock;
    while(window.isOpen()){
        //Handle player input
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed){
                window.close();
            }
        }
        //Quit
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            window.close();
        }
        //HANDLE PLAYER MOVEMENT
        //LEFT CURSOR MOVEMENT
        if(Keyboard::isKeyPressed(Keyboard::Left)){
            if(bat.get_Position().left<=0){
                bat.stopLeft();
            }
            else{
                bat.moveLeft();
            }
        }
        else{
            bat.stopLeft();//every time it is false
        }
        //RIGHT CURSOR MOVEMENT
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            if(((bat.get_Position().left)+(bat.get_Position().width))>=resolution.x){
                bat.stopRight();
            }
            else{
                bat.moveRight();
            }
        }
        else{
            bat.stopRight();//every time it is false
        }

        //Update delta time
        Time dt = clock.restart();
        
        //Update bat
        bat.update(dt);
        //Update ball
        ball.update(dt);

        //Udate the hud text
        std::stringstream ss;
        ss<<"Score: "<<score<<"  Lives: "<<lives;
        hud.setString(ss.str());

        //Handle ball hiting the bottom
        if(ball.getPosition().top>=resolution.y){
            lives--;

            if(lives<=0){
                lives = 3;
                score = 0;
            }
            ball.reboundBottom();
            //ball.update(dt);
        }
        //Handle ball hitting the top
        if(ball.getPosition().top<=0){
            score++;
            ball.reboundBatOrTop();
        }
        //Handle ball hitting sides
        if(ball.getPosition().left<=0 || ((ball.getPosition().left)+(ball.getPosition().width))>window.getSize().x){
            ball.reboundSides();
        }

        //Collision between bat and ball
        if(ball.getPosition().intersects(bat.get_Position())){
            score++;
            ball.reboundBatOrTop();
            ball.update(dt);//After collision position of ball
            bat.update(dt);//After collision position of bat (According to Newton's 3rd law)

        }

        window.clear();
        window.draw(ball.getShape());
        window.draw(bat.get_Shape());
        window.draw(hud);
        window.display();
    }
    return 0;

}