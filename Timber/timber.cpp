#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    VideoMode vm(resolution.x, resolution.y);
    RenderWindow window(vm, "Timber Game!!");

    // SET BACKGROUND
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("./Sprites/graphics/background.png");
    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    // SET TREE
    Texture treeTexture;
    treeTexture.loadFromFile("./Sprites/graphics/tree.png");
    Sprite treeSprite;
    treeSprite.setTexture(treeTexture);
    treeSprite.setPosition(((resolution.x / 2) - (300 / 2)), 0);

    // SET BRANCH
    Texture branchTexture;
    branchTexture.loadFromFile("./Sprites/graphics/branch.png");
    Sprite branchSprite;
    branchSprite.setTexture(branchTexture);
    branchSprite.setPosition((resolution.x / 2) + 150, ((resolution.y / 2) - 50));

    // SET BEE
    Texture beeTexture;
    beeTexture.loadFromFile("./Sprites/graphics/bee.png");
    Sprite beeSprite1;
    beeSprite1.setTexture(beeTexture);
    // beeSprite1.setPosition((resolution.x / 2) + 300, (resolution.y / 2) - 40);
    Sprite beeSprite2;
    beeSprite2.setTexture(beeTexture);
    // beeSprite2.setPosition((resolution.x / 2) - 500, (resolution.y / 2) - 40);

    // SET CLOUD
    Texture cloudTexture;
    cloudTexture.loadFromFile("Sprites/graphics/cloud.png");
    Sprite cloudSprite1;
    cloudSprite1.setTexture(cloudTexture);
    //cloudSprite1.setPosition((resolution.x / 2) - 600, (resolution.y / 2) - 450);
    Sprite cloudSprite2;
    cloudSprite2.setTexture(cloudTexture);
    //cloudSprite2.setPosition((resolution.x / 2) + 425, (resolution.y / 2) - 450);
    Sprite cloudSprite3;
    cloudSprite3.setTexture(cloudTexture);
    //cloudSprite3.setPosition((resolution.x / 2) - 200, (resolution.y / 2) - 450);

    // BEE1
    float bee1Speed = 0.0f;
    float bee1Height = 0.0f;
    bool beeActive1 = false;
    // BEE2
    // float bee2Speed = 0.0f;
    // float bee2Height = 0.0f;
    // bool beeActive2 = false;

    // Clock Object
    Clock clock;

    //Cloud1
    float cloudSpeed1 = 0.0f;
    float cloudHeight1 = 0.0f;
    bool cloudActive1 = false;
    //Cloud2
    float cloudSpeed2 = 0.0f;
    float cloudHeight2 = 0.0f;
    bool cloudActive2 = false;
    //Cloud3
    float cloudSpeed3 = 0.0f;
    float cloudHeight3 = 0.0f;
    bool cloudActive3 = false;



    // TIME BAR
    RectangleShape timeBar;
    float timeBarStartWidth = 400.0f;
    float timeBarHeight = 80.0f;
    timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));
    timeBar.setFillColor(Color::Red);
    timeBar.setPosition((resolution.x / 2.0) - (timeBarStartWidth / 2.0), resolution.y - 100);
    float timeRemaining = 6.0f;
    float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;
    bool paused = true; // Checks whether game started or not


    //FONT AND TEXT
    //TEXT FOR STARTING GAME
    Font font1;
    font1.loadFromFile("./Sprites/fonts/KOMIKAP_.ttf");
    Text messageText;
    messageText.setFont(font1);
    messageText.setFillColor(Color::White);
    messageText.setCharacterSize(100);
    messageText.setString("Press Enter To Start");
    FloatRect textRect = messageText.getLocalBounds();
    //messageText.setPosition();



    // GAME LOOP
    while (window.isOpen())
    {

        Event event; //[Discrete Event Handling ....
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        } //......]
        if (Keyboard::isKeyPressed(Keyboard::Escape)) //[Loop Event Handling...
        {
            window.close();
        } //.......]

        if (Keyboard::isKeyPressed(Keyboard::Return))
        { //[Game pause....
            paused = false;
            timeRemaining = 5.0f; // Game Restart from remaining 5 sec
        } //.....]

        if (!paused)
        { //[Pause Handling.......
            // Scene updates if game is on
            Time dt1 = clock.restart();
            timeRemaining -= dt1.asSeconds();
            if(timeRemaining<=0.0){
                paused = true;
            }

            timeBar.setSize(Vector2f(timeBarWidthPerSecond*timeRemaining,timeBarHeight));





            // BEE MOVEMET
            // BEE Movement 1
            if (!beeActive1)
            { // Initially Bee is in static position

                // speed
                srand(time(0) * 10);
                bee1Speed = rand() % 200 + 200;

                // height
                srand(time(0) * 20);
                bee1Height = rand() % 500 + 500;

                beeSprite1.setPosition(2000, bee1Height);
                beeActive1 = true;
            }
            else
            { // Initially bee is in moving state
                float x = beeSprite1.getPosition().x - (bee1Speed * dt1.asSeconds());
                beeSprite1.setPosition(x, beeSprite1.getPosition().y);
                if (beeSprite1.getPosition().x < -100)
                {
                    beeActive1 = false;
                }
            }

            // // BEE MOVEMENT 2
            // if (!beeActive2)
            // {
            //     srand(time(0) * 15);
            //     bee2Speed = rand() % 210 + 210;
            //     srand(time(0) * 25);
            //     bee2Height = rand() % 450 + 450;

            //     beeSprite2.setPosition(2000, bee1Height);
            //     beeActive2 = true;
            // }
            // else
            // { // Initially bee is in moving state
            //     float x = beeSprite2.getPosition().x - (bee2Speed * dt1.asSeconds());
            //     beeSprite2.setPosition(x, beeSprite2.getPosition().y);
            //     if (beeSprite2.getPosition().x < -100)
            //     {
            //         beeActive2 = false;
            //     }
            // }

            //CLOUD MOVEMENT1
            if(!cloudActive1){
                srand((int)time(0)*10);
                cloudSpeed1=rand()%201;
                srand(time(0)*10);
                cloudHeight1 = rand()%150;
                cloudSprite1.setPosition(-200,cloudHeight1);
                cloudActive1 = true;
            }
            else{
                float x = cloudSprite1.getPosition().x + (cloudSpeed1 * dt1.asSeconds());
                cloudSprite1.setPosition(x, cloudSprite1.getPosition().y);
                if (cloudSprite1.getPosition().x > 1920)
                {
                    cloudActive1 = false;
                }
            }
            //CLOUD MOVEMENT2
            if(!cloudActive2){
                srand((int)time(0)*10);
                cloudSpeed2=rand()%202;
                srand(time(0)*10);
                cloudHeight2 = rand()%150+150;
                cloudSprite2.setPosition(-200,cloudHeight2);
                cloudActive2 = true;
            }
            else{
                float x = cloudSprite2.getPosition().x + (cloudSpeed2 * dt1.asSeconds());
                cloudSprite2.setPosition(x, cloudSprite2.getPosition().y);
                if (cloudSprite2.getPosition().x > 1920)
                {
                    cloudActive2 = false;
                }
            }
            //CLOUD MOVEMENT3
            if(!cloudActive3){
                srand((int)time(0)*10);
                cloudSpeed3=rand()%200;
                srand(time(0)*10);
                cloudHeight3 = rand()%300+150;
                cloudSprite3.setPosition(-200,cloudHeight3);
                cloudActive3 = true;
            }
            else{
                float x = cloudSprite3.getPosition().x + (cloudSpeed3 * dt1.asSeconds());
                cloudSprite3.setPosition(x, cloudSprite3.getPosition().y);
                if (cloudSprite3.getPosition().x > 1920)
                {
                    cloudActive3= false;
                }
            }


           
        } //......pauseHandling]
        window.clear();
        window.draw(backgroundSprite);
        // window.draw(branchSprite);
        // window.draw(beeSprite3);
        // window.draw(beeSprite4);
        window.draw(cloudSprite1);
        window.draw(cloudSprite2);
        window.draw(cloudSprite3);
        window.draw(treeSprite);
        window.draw(beeSprite1);
        window.draw(timeBar);

        window.display();
    }
    return 0;
}






 // // MOVING BEE1
            // Vector2f beePosition1 = beeSprite1.getPosition();
            // Vector2f iPosition1 = beeSprite1.getPosition();
            // if (beePosition1.x - 2 < -100)
            // {
            //     beeSprite1.setPosition(1920, iPosition1.y);
            // }
            // else
            // {
            //     beePosition1.x -= 0.12;
            //     beeSprite1.setPosition(beePosition1);
            // }
            // // MOVING BEE2
            // Vector2f beePosition2 = beeSprite2.getPosition();
            // Vector2f iPosition2 = beeSprite2.getPosition();
            // if (beePosition2.x - 2 < -100)
            // {
            //     beeSprite2.setPosition(1920, iPosition2.y);
            // }
            // else
            // {
            //     beePosition2.x -= 0.12;
            //     beeSprite2.setPosition(beePosition2);
            // }

            // // MOVING BEE3
            // Vector2f beePosition3 = beeSprite3.getPosition();
            // Vector2f iPosition3 = beeSprite3.getPosition();

            // if (beePosition3.x - 2 < -100)
            // {
            //     beeSprite3.setPosition(1920, iPosition3.y);
            // }
            // else
            // {
            //     beePosition3.x -= 0.12;
            //     beeSprite3.setPosition(beePosition3);
            // }

            // // MOVING BEE4
            // Vector2f beePosition4 = beeSprite4.getPosition();
            // Vector2f iPosition4 = beeSprite4.getPosition();
            // if (beePosition4.x - 2 < -100)
            // {
            //     beeSprite4.setPosition(1920, iPosition4.y);
            // }
            // else
            // {
            //     beePosition4.x -= 0.12;
            //     beeSprite4.setPosition(beePosition4);
            // }
            // MOVING CLOUD1
            // Vector2f cloudPosition1 = cloudSprite1.getPosition();
            // Vector2f icPosition1 = cloudSprite1.getPosition();
            // if (cloudPosition1.x + 2 > 1600)
            // {
            //     cloudSprite1.setPosition(-50, icPosition1.y);
            // }
            // else
            // {
            //     cloudPosition1.x += 0.10;
            //     cloudSprite1.setPosition(cloudPosition1);
            // }
            // // MOVING CLOUD2
            // Vector2f cloudPosition2 = cloudSprite2.getPosition();
            // Vector2f icPosition2 = cloudSprite2.getPosition();
            // if (cloudPosition2.x + 2 > 1600)
            // {
            //     cloudSprite2.setPosition(-50, icPosition2.y);
            // }
            // else
            // {
            //     cloudPosition2.x += 0.12;
            //     cloudSprite2.setPosition(cloudPosition2);
            // }
            // // MOVING CLOUD3
            // Vector2f cloudPosition3 = cloudSprite3.getPosition();
            // Vector2f icPosition3 = cloudSprite3.getPosition();
            // if (cloudPosition3.x + 2 > 1600)
            // {
            //     cloudSprite3.setPosition(-50, icPosition3.y);
            // }
            // else
            // {
            //     cloudPosition3.x += 0.15;
            //     cloudSprite3.setPosition(cloudPosition3);
            // }