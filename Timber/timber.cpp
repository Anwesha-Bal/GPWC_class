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
    beeSprite1.setPosition((resolution.x/2)+300,(resolution.y/2)-40);
    Sprite beeSprite2;
    beeSprite2.setTexture(beeTexture);
    beeSprite2.setPosition((resolution.x/2)-500,(resolution.y/2)-40);
    Sprite beeSprite3;
    beeSprite3.setTexture(beeTexture);
    beeSprite3.setPosition((resolution.x/2)+550,(resolution.y/2)+30);
    Sprite beeSprite4;
    beeSprite4.setTexture(beeTexture);
    beeSprite4.setPosition((resolution.x/2)-300,(resolution.y/2)+20);

    //SET CLOUD
    Texture cloudTexture;
    cloudTexture.loadFromFile("Sprites/graphics/cloud.png");
    Sprite cloudSprite1;
    cloudSprite1.setTexture(cloudTexture);
    cloudSprite1.setPosition((resolution.x/2)-600,(resolution.y/2)-450);
    Sprite cloudSprite2;
    cloudSprite2.setTexture(cloudTexture);
    cloudSprite2.setPosition((resolution.x/2)+425,(resolution.y/2)-450);
    Sprite cloudSprite3;
    cloudSprite3.setTexture(cloudTexture);
    cloudSprite3.setPosition((resolution.x/2)-200,(resolution.y/2)-450);
    // Clock clock;
    // Time time;
    // float bee1 =  0.12;
    // float bee2 =  0.12;
    // float bee3 =  0.12;
    // float bee4 =  0.12;
    int pause = 1;

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
        int flag = 1;
        
        
        if(Keyboard::isKeyPressed(Keyboard::Enter)){
            pause = !pause;

        }
        if(pause){
            //MOVING BEE1
            Vector2f beePosition1 = beeSprite1.getPosition();
            Vector2f iPosition1 = beeSprite1.getPosition();
            Vector2f currentPosition;
            if(beePosition1.x-2<-100){
                beeSprite1.setPosition(1920,iPosition1.y);
            }
            else{
            beePosition1.x-=0.12;
            beeSprite1.setPosition(beePosition1);
            }
            //MOVING BEE2
            Vector2f beePosition2 = beeSprite2.getPosition();
            Vector2f iPosition2 = beeSprite2.getPosition();
            if(beePosition2.x-2<-100){
                beeSprite2.setPosition(1920,iPosition2.y);
                }
            else{
                beePosition2.x-=0.12;
                beeSprite2.setPosition(beePosition2);
                }
            
            //MOVING BEE3
            Vector2f beePosition3 = beeSprite3.getPosition();
            Vector2f iPosition3 = beeSprite3.getPosition();

            if(beePosition3.x-2<-100){
                beeSprite3.setPosition(1920,iPosition3.y);
            }
            else{
                beePosition3.x-=0.12;
                beeSprite3.setPosition(beePosition3);
            }
            
            //MOVING BEE4
            Vector2f beePosition4 = beeSprite4.getPosition();
            Vector2f iPosition4 = beeSprite4.getPosition();
            if(beePosition4.x-2<-100){
                beeSprite4.setPosition(1920,iPosition4.y);
            }
            else{
            beePosition4.x-=0.12;
            beeSprite4.setPosition(beePosition4);
            }
            //MOVING CLOUD1
            Vector2f cloudPosition1 = cloudSprite1.getPosition();
            Vector2f icPosition1 = cloudSprite1.getPosition();
            if(cloudPosition1.x+2>1600){
                cloudSprite1.setPosition(-2,icPosition1.y);
            }
            else{
                cloudPosition1.x+=0.10;
                cloudSprite1.setPosition(cloudPosition1);
            }
            //MOVING CLOUD2
            Vector2f cloudPosition2 = cloudSprite2.getPosition();
            Vector2f icPosition2 = cloudSprite2.getPosition();
            if(cloudPosition2.x+2>1600){
                cloudSprite2.setPosition(-2,icPosition2.y);
            }
            else{
                cloudPosition2.x+=0.12;
                cloudSprite2.setPosition(cloudPosition2);
            }
            //MOVING CLOUD3
            Vector2f cloudPosition3 = cloudSprite3.getPosition();
            Vector2f icPosition3 = cloudSprite3.getPosition();
            if(cloudPosition3.x+2>1600){
                cloudSprite3.setPosition(-2,icPosition3.y);
            }
            else{
                cloudPosition3.x+=0.15;
                cloudSprite3.setPosition(cloudPosition3);
            }
        }
       

        window.clear();
        window.draw(backgroundSprite);
        window.draw(treeSprite);
        window.draw(branchSprite);
        window.draw(beeSprite1);
        window.draw(beeSprite2);
        window.draw(beeSprite3);
        window.draw(beeSprite4);
        window.draw(cloudSprite1);
        window.draw(cloudSprite2);
        window.draw(cloudSprite3);

        window.display();
    }
    return 0;
}