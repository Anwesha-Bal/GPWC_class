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
    branchSprite.setPosition((resolution.x / 2) + 150, ((resolution.y/2)-50));

    //SET BEE
    Texture beeTexture;
    beeTexture.loadFromFile("./Sprites/graphics/bee.png");
    Sprite beeSprite1;
    beeSprite1.setTexture(beeTexture);
    beeSprite1.setPosition((resolution.x/2)+300,(resolution.y/2)-50);
    Sprite beeSprite2;
    beeSprite2.setTexture(beeTexture);
    beeSprite2.setPosition((resolution.x/2)-500,(resolution.y/2)-70);
    Sprite beeSprite3;
    beeSprite3.setTexture(beeTexture);
    beeSprite3.setPosition((resolution.x/2)+550,(resolution.y/2)+70);
    Sprite beeSprite4;
    beeSprite4.setTexture(beeTexture);
    beeSprite4.setPosition((resolution.x/2)-300,(resolution.y/2)+100);


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
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
        window.clear();
        window.draw(backgroundSprite);
        window.draw(treeSprite);
        //window.draw(branchSprite);
        window.draw(beeSprite1);
        window.draw(beeSprite2);
        window.draw(beeSprite3);
        window.draw(beeSprite4);

        window.display();
    }
    return 0;
}