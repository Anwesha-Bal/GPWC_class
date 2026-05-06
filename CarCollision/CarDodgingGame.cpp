#include <SFML/Graphics.hpp>
#include "Car.cpp"
#include "PlayerCar.cpp"
#include "EnemyCar.cpp"
#include "Create_EnemyCar.cpp"
#include <SFML/Audio.hpp>
#include <sstream>
using namespace sf;

int main()
{
    enum class State
    {
        PAUSED,
        GAME_OVER,
        PLAYING
    };
    State state = State::PAUSED;
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    RenderWindow window(VideoMode(resolution.x, resolution.y), "Car Dodging", Style::Fullscreen);

    View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

    Clock clock;

    RectangleShape dash(Vector2f(10, 40));
    dash.setFillColor(Color::White);

    Vector2f center = window.getView().getCenter();
    Vector2f size = window.getView().getSize();
    Font font;
    font.loadFromFile("./Assets/KOMIKAP_.ttf");
    Text text;
    text.setFont(font);
    text.setCharacterSize(75);
    text.setFillColor(Color::Red);
    text.setPosition(20.0, 20.0);
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin((textRect.left + textRect.width) / 2, (textRect.top + textRect.height) / 2);
    text.setPosition(resolution.x / 2, resolution.y / 2);



    int numCar = 0;
    EnemyCar *enemies = NULL;
    PlayerCar player(0,resolution.x,resolution);
    EnemyCar enemy;
    int score = 0;
    int speed = 0;

    bool paused = true;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Return &&
                    state == State::PLAYING)
                {
                    state = State::PAUSED;
                }

                else if (event.key.code == Keyboard::Return &&
                         state == State::PAUSED)
                {   

                    state = State::PLAYING;
                    clock.restart();
                }
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        if(paused){
            player.getSprite().setPosition(resolution.x/2+200,resolution.y-200);
            text.setString("Press Enter to start");
        }

        if (state == State::PLAYING)
        {
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                player.moveLeft();
            }
            else
            {
                player.stopLeft();
            }

            if (Keyboard::isKeyPressed(Keyboard::D))
            {
                player.moveRight();
            }
            else
            {
                player.stopRight();
            }
        }
        if (state == State::PLAYING)
        {
            float top = center.y - size.y / 2;
            float bottom = center.y + size.y / 2;

            float spacing = 80;
            float roadCenterX = (leftBoundary + rightBoundary) / 2;

            numCar = 5;
            delete[] enemies;
            enemies = createCar(numCar);
            for(int i = 0; i<numCar ;i++){
                if(enemies[i].getSprite().getPosition().y>resolution.y){
                 delete[] enemies[i];
               
                }
            }
            std::stringstream ss;
            ss<<"Score: "<<score<<"  Speed: "<<speed;
            text.setString(ss.str());
            
            clock.restart();

        }
        if(state==State::PLAYING){
            Time dt = clock.restart();
            player.update(dt);
            if(player.getSprite().getPosition().y<enemy.getSprite().getPosition().y){
                score++;
            }
            mainView.setCenter(player.getCenter());
            speed = player.getSpeed();
            for (int i = 0; i < numCar i++)
			{
				enemies[i].update(dt.asSeconds());
			}
        }
        if(state==State::PLAYING){
            for(int i = 0 ; i<numCar ; i++){
                if(player.getPosition().intersects(enemies[i].getPosition())){
                    state = State::GAME_OVER;
                    text.setString("Game Over");
                }
            }
        }
        if (state == State::PLAYING)
		{
			window.clear();
			window.setView(mainView);
			 for (int i = (int)(top / spacing) - 1; i <= (int)(bottom / spacing) + 1; i++)
            {
                 dash.setPosition(roadCenterX, i * spacing);
                window.draw(dash);
         }

			
			for (int i = 0; i < numCar; i++)
			{
				window.draw(enemies[i].getSprite());
			}
			window.draw(player.getSprite());
		}


        

    }
}
