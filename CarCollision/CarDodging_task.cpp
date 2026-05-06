#include <SFML/Graphics.hpp>
#include "Car.cpp"
#include "PlayerCar.cpp"
#include "EnemyCar.cpp"
#include "Create_EnemyCar.cpp"
#include <sstream>

using namespace sf;

int main()
{
    enum class State { PAUSED, GAME_OVER, PLAYING };
    State state = State::PAUSED;

    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    RenderWindow window(VideoMode(resolution.x, resolution.y), "Car Dodging", Style::Fullscreen);
    View mainView(FloatRect(0, 0, resolution.x, resolution.y));

    Clock clock;

    RectangleShape dash(Vector2f(10, 40));
    dash.setFillColor(Color::White);

    float leftBoundary = 200;
    float rightBoundary = resolution.x - 200;

    Font font;
    font.loadFromFile("./Assets/KOMIKAP_.ttf");

    Text text;
    text.setFont(font);
    text.setCharacterSize(60);
    text.setFillColor(Color::Red);
    text.setPosition(20, 20);

    PlayerCar player(leftBoundary, rightBoundary, resolution);

    int numCar = 5;
    EnemyCar* enemies = nullptr;

    int score = 0;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Return && state == State::PAUSED)
                {
                    state = State::PLAYING;

                    delete[] enemies;
                    enemies = createCar(numCar);

                    score = 0;
                    clock.restart();
                }

                else if (event.key.code == Keyboard::Return && state == State::GAME_OVER)
                {
                    state = State::PAUSED;
                }
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
            window.close();

        if (state == State::PLAYING)
        {
            if (Keyboard::isKeyPressed(Keyboard::A)) player.moveLeft();
            else player.stopLeft();

            if (Keyboard::isKeyPressed(Keyboard::D)) player.moveRight();
            else player.stopRight();
        }

        if (state == State::PLAYING)
        {
            Time dt = clock.restart();

            player.update(dt);

            for (int i = 0; i < numCar; i++)
            {
                enemies[i].update(dt.asSeconds());

                if (enemies[i].getSprite().getPosition().y > resolution.y)
                {
                    enemies[i].spawn(rand() % (int)(rightBoundary - leftBoundary) + leftBoundary,rand() % 5);
                }
            }

            for (int i = 0; i < numCar; i++)
            {
                if (player.getPosition().intersects(enemies[i].getPosition()))
                {
                    state = State::GAME_OVER;
                    text.setString("GAME OVER\nPress Enter");
                }
            }

            score++;
        }

        window.clear();
        window.setView(mainView);

        Vector2f center = window.getView().getCenter();
        Vector2f size = window.getView().getSize();

        float top = center.y - size.y / 2;
        float bottom = center.y + size.y / 2;

        float spacing = 80;
        float roadCenterX = (leftBoundary + rightBoundary) / 2;

        for (int i = (int)(top / spacing) - 1; i <= (int)(bottom / spacing) + 1; i++)
        {
            dash.setPosition(roadCenterX, i * spacing);
            window.draw(dash);
        }

        if (enemies != nullptr)
        {
            for (int i = 0; i < numCar; i++)
                window.draw(enemies[i].getSprite());
        }

        window.draw(player.getSprite());

        if (state == State::PLAYING)
        {
            std::stringstream ss;
            ss << "Score: " << score;
            text.setString(ss.str());
        }

        window.draw(text);

        window.display();
    }

    delete[] enemies;
    return 0;
}