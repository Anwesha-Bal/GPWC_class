#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <sstream>

#include "Car.h"
#include "PlayerCar.h"
#include "EnemyCar.h"

using namespace sf;

int main()
{
    srand(static_cast<unsigned>(time(0)));

    enum class State
    {
        PAUSED,
        PLAYING,
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
        "Car Dodging Game",
        Style::Fullscreen
    );

    window.setFramerateLimit(60);

    Font font;
    font.loadFromFile("./Assets/KOMIKAP_.ttf");

    Text messageText;

    messageText.setFont(font);
    messageText.setCharacterSize(70);
    messageText.setFillColor(Color::White);

    messageText.setPosition(
        resolution.x / 2 - 450,
        resolution.y / 2 - 150
    );

    Text hud;

    hud.setFont(font);
    hud.setCharacterSize(45);

    hud.setFillColor(Color::Yellow);

    hud.setOutlineColor(Color::Black);

    hud.setOutlineThickness(3);

    hud.setPosition(40, 30);



    SoundBuffer engineBuffer;
    engineBuffer.loadFromFile("./Assets/car.mp3");

    Sound engineSound;
    engineSound.setBuffer(engineBuffer);
    engineSound.setLoop(true);



    SoundBuffer crashBuffer;
    crashBuffer.loadFromFile("./Assets/crash.mp3");

    Sound crashSound;
    crashSound.setBuffer(crashBuffer);



    RectangleShape road;

    road.setSize(
        Vector2f(
            resolution.x,
            resolution.y
        )
    );

    road.setFillColor(
        Color(45, 45, 45)
    );

    road.setPosition(0, 0);

    const int numRoadLines = 20;

    RectangleShape roadLines[numRoadLines];

    float lineWidth = 15.0f;
    float lineHeight = 120.0f;
    float gap = 60.0f;

    float centerX = resolution.x / 2.0f;

    for (int i = 0; i < numRoadLines; i++)
    {
        roadLines[i].setSize(
            Vector2f(
                lineWidth,
                lineHeight
            )
        );

        roadLines[i].setFillColor(
            Color::White
        );

        roadLines[i].setPosition(
            centerX - lineWidth / 2.0f,
            i * (lineHeight + gap)
        );
    }

    float lanes[5];

    lanes[0] = resolution.x * 0.15f;
    lanes[1] = resolution.x * 0.32f;
    lanes[2] = resolution.x * 0.50f;
    lanes[3] = resolution.x * 0.68f;
    lanes[4] = resolution.x * 0.85f;

    PlayerCar player(
        resolution.x / 2,
        resolution.y - 220
    );

    const int maxEnemies = 20;

    EnemyCar* enemies[maxEnemies];

    for (int i = 0; i < maxEnemies; i++)
    {
        enemies[i] = nullptr;
    }

    int enemyLimit = 5;

    float enemySpeedMultiplier = 0;

    float spawnInterval = 1.5f;

    int score = 0;

    float gameSpeed = 200;

    Clock clock;

    float spawnTimer = 0;

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
                event.key.code == Keyboard::Num1
            )
            {
                level = Level::EASY;

                enemyLimit = 5;

                spawnInterval = 1.5f;
            }

            if (
                event.type == Event::KeyPressed &&
                event.key.code == Keyboard::Num2
            )
            {
                level = Level::MEDIUM;

                enemyLimit = 8;

                spawnInterval = 1.0f;
            }

            if (
                event.type == Event::KeyPressed &&
                event.key.code == Keyboard::Num3
            )
            {
                level = Level::HARD;

                enemyLimit = 12;

                spawnInterval = 0.7f;
            }

            if (
                event.type == Event::KeyPressed &&
                event.key.code == Keyboard::Enter
            )
            {
                state = State::PLAYING;

                score = 0;

                gameSpeed = 200;

                enemySpeedMultiplier = 0;

                spawnTimer = 0;

                engineSound.stop();
                engineSound.play();

                player.setPosition(
                    resolution.x / 2,
                    resolution.y - 220
                );

                for (int i = 0; i < maxEnemies; i++)
                {
                    if (enemies[i] != nullptr)
                    {
                        delete enemies[i];

                        enemies[i] = nullptr;
                    }
                }
            }

            if (
                event.type == Event::KeyPressed &&
                event.key.code == Keyboard::P
            )
            {
                if (state == State::PLAYING)
                {
                    state = State::PAUSED;

                    engineSound.pause();
                }
                else if (state == State::PAUSED)
                {
                    state = State::PLAYING;

                    engineSound.play();
                }
            }
        }

        Time dt = clock.restart();

        if (state == State::PLAYING)
        {
            gameSpeed += 5 * dt.asSeconds();

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

            for (int i = 0; i < numRoadLines; i++)
            {
                roadLines[i].move(
                    0,
                    gameSpeed * dt.asSeconds()
                );

                if (
                    roadLines[i].getPosition().y >
                    resolution.y
                )
                {
                    roadLines[i].setPosition(
                        centerX - lineWidth / 2.0f,
                        -lineHeight
                    );
                }
            }

            spawnTimer += dt.asSeconds();

            if (spawnTimer >= spawnInterval)
            {
                for (int i = 0; i < enemyLimit; i++)
                {
                    if (enemies[i] == nullptr)
                    {
                        enemies[i] = new EnemyCar();

                        int randomLane = rand() % 5;

                        enemies[i]->spawn(
                            lanes[randomLane],
                            rand() % 5,
                            enemySpeedMultiplier
                        );

                        break;
                    }
                }

                spawnTimer = 0;
            }

            for (int i = 0; i < enemyLimit; i++)
            {
                if (enemies[i] != nullptr)
                {
                    enemies[i]->setSpeed(
                        enemies[i]->getSpeed() +
                        gameSpeed * 0.01f
                    );

                    enemies[i]->update(dt);

                    if (
                        player.getBounds().intersects(
                            enemies[i]->getBounds()
                        )
                    )
                    {
                        crashSound.play();

                        engineSound.stop();

                        state = State::GAMEOVER;
                    }

                    if (enemies[i]->isOffScreen())
                    {
                        delete enemies[i];

                        enemies[i] = nullptr;

                        score++;

                        enemySpeedMultiplier += 1.5f;
                    }
                }
            }
        }

        std::stringstream ss;

        ss << "SCORE : "
           << score

           << "      SPEED : "
           << static_cast<int>(gameSpeed);

        hud.setString(ss.str());

        if (state == State::PAUSED)
        {
            messageText.setString(
                "PRESS ENTER TO START\n\n"
                "1 : EASY\n"
                "2 : MEDIUM\n"
                "3 : HARD"
            );
        }

        if (state == State::GAMEOVER)
        {
            messageText.setString(
                "GAME OVER\n\n"
                "PRESS ENTER TO RESTART"
            );
        }

        window.clear(Color::Black);

        window.draw(road);

        for (int i = 0; i < numRoadLines; i++)
        {
            window.draw(
                roadLines[i]
            );
        }

        window.draw(
            player.getSprite()
        );

        for (int i = 0; i < enemyLimit; i++)
        {
            if (enemies[i] != nullptr)
            {
                window.draw(
                    enemies[i]->getSprite()
                );
            }
        }

        window.draw(hud);

        if (
            state == State::PAUSED ||
            state == State::GAMEOVER
        )
        {
            window.draw(messageText);
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
