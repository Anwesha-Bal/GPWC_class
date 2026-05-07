#include <SFML/Graphics.hpp>
#include <ctime>
#include <sstream>
#include "Car.h"
#include "PlayerCar.h"
#include "EnemyCar.h"

using namespace sf;

enum class Lane
{
    LEFT,
    RIGHT,
    NONE
};

int main()
{
    srand(static_cast<unsigned>(time(0)));

    enum class State
    {
        PLAYING,
        PAUSED,
        GAMEOVER
    };

    enum class Level
    {
        EASY,
        MEDIUM,
        HARD
    };

    State state = State::PAUSED;
    Level level = Level::EASY;

    Vector2f resolution;

    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    RenderWindow window(
        VideoMode(resolution.x, resolution.y),
        "Car Dodging",
        Style::Fullscreen
    );

    View mainView(
        FloatRect(
            0,
            0,
            resolution.x,
            resolution.y
        )
    );

    Font font;

    font.loadFromFile("./Assets/KOMIKAP_.ttf");

    Text text;

    text.setFont(font);
    text.setCharacterSize(60);
    text.setFillColor(Color::Red);

    FloatRect textRect = text.getLocalBounds();

    text.setOrigin(
        (textRect.left + textRect.width) / 2.0f,
        (textRect.top + textRect.height) / 2.0f
    );

    text.setPosition(
        resolution.x / 2.0f,
        resolution.y / 2.0f
    );

    text.setString("Press ENTER to Start");

    Clock clock;

    bool paused = true;

    const int maxEnemies = 10;

    int carNum = 5;

    Lane lane[maxEnemies];

    EnemyCar* enemies[maxEnemies];

    for (int i = 0; i < maxEnemies; i++)
    {
        enemies[i] = nullptr;
        lane[i] = Lane::NONE;
    }

    int score = 0;

    PlayerCar player(
        resolution.x / 2.0f,
        resolution.y - 200.0f
    );

    if (level == Level::EASY)
    {
        carNum = 5;
        player.setSpeed(100);
    }

    if (level == Level::MEDIUM)
    {
        carNum = 7;
        player.setSpeed(150);
    }

    if (level == Level::HARD)
    {
        carNum = 10;
        player.setSpeed(200);
    }

    float spawnTimer = 0.0f;
    float spawnInterval = 2.0f;

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (
                event.type == Event::KeyPressed &&
                event.key.code == Keyboard::Escape
            )
            {
                window.close();
            }

            if (
                event.type == Event::KeyPressed &&
                event.key.code == Keyboard::Enter
            )
            {
                paused = false;
                state = State::PLAYING;

                score = 0;

                player.setPosition(
                    resolution.x / 2.0f,
                    resolution.y - 200.0f
                );

                for (int i = 0; i < maxEnemies; i++)
                {
                    if (enemies[i] != nullptr)
                    {
                        delete enemies[i];
                        enemies[i] = nullptr;
                    }
                }

                text.setString("");
            }
        }

        Time dt = clock.restart();

        if (!paused)
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

            player.update(dt);

            if (spawnInterval > 0.6f)
            {
                spawnInterval -= 0.05f * dt.asSeconds();
            }

            spawnTimer += dt.asSeconds();

            if (spawnTimer >= spawnInterval)
            {
                for (int i = 0; i < carNum; i++)
                {
                    if (enemies[i] == nullptr)
                    {
                        enemies[i] = new EnemyCar();

                        float randomX =
                            (rand() %
                            (int)(resolution.x - 200))
                            + 100;

                        enemies[i]->spawn(
                            randomX,
                            rand() % 5,
                            score * 10.0f
                        );

                        break;
                    }
                }

                spawnTimer = 0;
            }

            for (int i = 0; i < carNum; i++)
            {
                if (enemies[i] != nullptr)
                {
                    enemies[i]->update(dt);

                    if (
                        player.getBounds().intersects(
                            enemies[i]->getBounds()
                        )
                    )
                    {
                        state = State::GAMEOVER;

                        paused = true;

                        text.setString("GAME OVER");
                    }

                    if (enemies[i]->isOffScreen())
                    {
                        delete enemies[i];

                        enemies[i] = nullptr;

                        score++;
                    }
                }
            }
        }

        mainView.setCenter(
            resolution.x / 2.0f,
            resolution.y / 2.0f
        );

        window.clear();

        window.setView(mainView);

        window.draw(player.getSprite());

        for (int i = 0; i < carNum; i++)
        {
            if (enemies[i] != nullptr)
            {
                window.draw(
                    enemies[i]->getSprite()
                );
            }
        }

        if (paused)
        {
            window.draw(text);
        }

        window.display();
    }

    for (int i = 0; i < maxEnemies; i++)
    {
        if (enemies[i] != nullptr)
        {
            delete enemies[i];
        }
    }

    return 0;
}