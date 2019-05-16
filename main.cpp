#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <windows.h>
#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <spaceship.h>
#include <entity.h>
#include <projectile.h>
#include <enemy.h>
#include <random.h>
#include <textDisplay.h>
#include <border.h>
#include <renderInfo.h>
#include <spaceShipHealth.h>
#include <coin.h>
#include <medkit.h>
#include <doubleProjectile.h>
#include <speedUp.h>
#include <renderBlackHole.h>
#include <blackhole.h>
#include <map.h>

int main()
{
    // set Variation
    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;
    sf::Clock clock4;
    sf::Clock clock5;
    sf::Clock clock6;
    sf::Clock clock7;
    sf::Clock clock8;

    int counter = 0;
    int counter2 = 0;

    // set window
    sf::RenderWindow window(sf::VideoMode(640, 640), "Space Frontier", sf::Style::Default);
    window.setFramerateLimit(60);

    // set font
    sf::Font font;
    if (!font.loadFromFile("pixel.ttf"))
    {
        return EXIT_FAILURE;
    }

    // load a SpaceSprite to display
    sf::Texture textureSpace;
    if (!textureSpace.loadFromFile("space.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteSpace(textureSpace);

    // load a SpaceShipSprite to display
    sf::Texture textureSpaceShip;
    if (!textureSpaceShip.loadFromFile("spaceship.png"))
    {
        return EXIT_FAILURE;
    }

    // load a EnemySprite to display
    sf::Texture textureEnemy;
    if (!textureEnemy.loadFromFile("meteor2.png"))
    {
        return EXIT_FAILURE;
    }

    // load a SpaceShip_Health_Sprite to display
    sf::Texture textureSpaceShipHealth;
    if (!textureSpaceShipHealth.loadFromFile("spaceship_hp_bar2.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteSpaceShipHealth(textureSpaceShipHealth);

    // load a Coin Sprite to display
    sf::Texture textureCoin;
    if (!textureCoin.loadFromFile("coin.png"))
    {
        return EXIT_FAILURE;
    }

    // load a Med kit Sprite to display
    sf::Texture textureMedkit;
    if (!textureMedkit.loadFromFile("medkit.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteMedkit(textureMedkit);

    // load a Double Projectile Sprite to display
    sf::Texture textureDoubleFire;
    if (!textureDoubleFire.loadFromFile("double_projectile.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteDoubleFire(textureDoubleFire);

    // load a Speed Up Sprite to display
    sf::Texture textureSpeedUp;
    if (!textureSpeedUp.loadFromFile("flash2.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteSpeedUp(textureSpeedUp);

    // load a Render Black hole Sprite to display
    sf::Texture textureRenderBlackhole;
    if (!textureRenderBlackhole.loadFromFile("blackhole2.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteRenderBlackhole(textureRenderBlackhole);

    // load a Black hole Sprite to display
    sf::Texture textureBlackhole;
    if (!textureBlackhole.loadFromFile("blackhole.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite spriteBlackhole(textureBlackhole);

    // set Coin Text
    sf::Text textCoin("$", font, 50);
    textCoin.setColor(sf::Color::Yellow);
    textCoin.setCharacterSize(42);
    textCoin.setPosition(0,-12);

    // set Score Text
    sf::Text textScore("Score:", font, 25);
    textScore.setColor(sf::Color::White);
    textScore.setCharacterSize(38);
    textScore.setPosition(510,-12);

    // class spaceship
    class spaceship Spaceship1;
    Spaceship1.sprite.setTexture(textureSpaceShip);

    // class spaceshipHealth
    class spaceShipHealth SpaceshipHealth1;
    SpaceshipHealth1.sprite.setTexture(textureSpaceShipHealth);

    // class Med kit
    class medkit Medkit1;
    Medkit1.sprite.setTexture(textureMedkit);

    // class Double Projectile
    class doubleProjectile DoubleProjectile1;
    DoubleProjectile1.sprite.setTexture(textureDoubleFire);

    // class Speed Up
    class speedUp speedUp1;
    speedUp1.sprite.setTexture(textureSpeedUp);

    // class Render Black Hole
    class renderBlackHole renderBlackHole1;
    renderBlackHole1.sprite.setTexture(textureRenderBlackhole);

    // Map vector Array
    class background Map1;
    vector<background>::const_iterator it7;
    vector<background> mapArray;
    Map1.sprite.setTexture(textureSpace);
    mapArray.push_back(Map1);

    // Black Hole Vector Array
    class blackhole blackHole1;
    vector<blackhole>::const_iterator it6;
    vector<blackhole> blackHoleArray;
    blackHole1.sprite.setTexture(textureBlackhole);

    // Projectile vector Array
    class projectile Projectile1;
    vector<projectile>::const_iterator it;
    vector<projectile> projectileArray;
    Projectile1.sprite.setTexture(textureSpaceShip);

    // Enemy vector Array
    class enemy Enemy1;
    vector<enemy>::const_iterator it2;
    vector<enemy> enemyArray;
    Enemy1.sprite.setTexture(textureEnemy);
    enemyArray.push_back(Enemy1);

    // Text vector array
    class textDisplay textDisplay1;
    vector<textDisplay>::const_iterator it3;
    vector<textDisplay> textDisplayArray;
    textDisplay1.text.setFont(font);

    // Border vector Array
    class border border1;
    vector<border>::const_iterator it4;
    vector<border> borderArray;

    // Coin vector Array
    class coin coin1;
    vector<coin>::const_iterator it5;
    vector<coin> coinArray;
    coin1.sprite.setTexture(textureCoin);
    coin1.rect.setSize(sf::Vector2f(23, 23));
    coin1.rect.setPosition(500, 400);
    coin1.sprite.setPosition(500, 400);
    coinArray.push_back(coin1);

    // setup Border
    border1.rect.setSize(sf::Vector2f(1, 700));
    border1.rect.setPosition(-10,0);
    borderArray.push_back(border1);

    border1.rect.setPosition(650,0);
    borderArray.push_back(border1);

    border1.rect.setSize(sf::Vector2f(700, 1));
    border1.rect.setPosition(0,650);
    borderArray.push_back(border1);

    // Load sound effects
    sf::SoundBuffer bufferShot;
    if (!bufferShot.loadFromFile("shot.ogg"))
        return -1;
    sf::Sound soundShot;
    soundShot.setBuffer(bufferShot);

    sf::SoundBuffer bufferCollision;
    if (!bufferCollision.loadFromFile("collision.ogg"))
        return -1;
    sf::Sound soundCollision;
    soundCollision.setBuffer(bufferCollision);

    sf::SoundBuffer bufferPowerUp;
    if (!bufferPowerUp.loadFromFile("Powerup.ogg"))
        return -1;
    sf::Sound soundPowerUp;
    soundPowerUp.setBuffer(bufferPowerUp);

    sf::SoundBuffer bufferImpact;
    if (!bufferImpact.loadFromFile("spaceshipImpact.ogg"))
        return -1;
    sf::Sound soundImpact;
    soundImpact.setBuffer(bufferImpact);

    sf::SoundBuffer bufferCoin;
    if (!bufferCoin.loadFromFile("coin2.ogg"))
        return -1;
    sf::Sound soundCoin;
    soundCoin.setBuffer(bufferCoin);

    sf::SoundBuffer bufferExplosion;
    if (!bufferExplosion.loadFromFile("explosion.ogg"))
        return -1;
    sf::Sound soundExplosion;
    soundExplosion.setBuffer(bufferExplosion);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("HansZimmer.ogg"))
    {
        return EXIT_FAILURE;
    }

    // PLay music
    music.play();
    music.setLoop(true);

    // Start the game loop;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Clock screen
        sf::Time elapsed1 = clock.getElapsedTime();
        sf::Time elapsed2 = clock2.getElapsedTime();
        sf::Time elapsed3 = clock3.getElapsedTime();
        sf::Time elapsed4 = clock4.getElapsedTime();
        sf::Time elapsed5 = clock5.getElapsedTime();
        sf::Time elapsed6 = clock6.getElapsedTime();
        sf::Time elapsed7 = clock7.getElapsedTime();
        sf::Time elapsed8 = clock8.getElapsedTime();

        window.clear();

        // Spaceship collides border
        counter = 0;
        for (it4 = borderArray.begin(); it4 < borderArray.end(); it4++)
        {
            if (Spaceship1.rect.getGlobalBounds().intersects(borderArray[counter].rect.getGlobalBounds()))
            {
                // Hit border
                if (Spaceship1.direction == 1) // Left
                {
                    Spaceship1.canMoveLeft = false;
                    Spaceship1.rect.move(1,0);
                }
                else if (Spaceship1.direction == 2) // Right
                {
                    Spaceship1.canMoveRight = false;
                    Spaceship1.rect.move(-1,0);
                }
                else if (Spaceship1.direction == 4) // Down
                {
                    Spaceship1.canMoveDown = false;
                    Spaceship1.rect.move(0,-1);
                }
            }
            counter++;
        }

        if (elapsed3.asSeconds() >= 0.5)
        {
            clock3.restart();

            // Enemy collides with Spaceship (Spaceship takes damage)
            counter2 = 0;
            for (it2 = enemyArray.begin(); it2 != enemyArray.end(); it2++)
            {
                if (Spaceship1.rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
                {
                    // Play sound
                    if (Spaceship1.hp >= 2)
                    {
                        soundImpact.play();
                    }
                    // Text display
                    textDisplay1.text.setString(to_string(enemyArray[counter2].attackDamage));
                    textDisplay1.text.setPosition(Spaceship1.rect.getPosition().x+60, Spaceship1.rect.getPosition().y+60);
                    textDisplayArray.push_back(textDisplay1);
                    Spaceship1.hp -= enemyArray[counter2].attackDamage;
                    SpaceshipHealth1.update();
                    enemyArray[counter2].alive = false;
                }
                counter2++;
            }
        }

        // $
        textCoin.setString("$" + to_string(Spaceship1.$));

        //Spaceship collides with coin
        counter = 0;
        for (it5 = coinArray.begin(); it5 != coinArray.end(); it5++)
        {
            if (coinArray[counter].rect.getGlobalBounds().intersects(Spaceship1.rect.getGlobalBounds()))
            {
                // Play Sound
                soundCoin.play();

                Spaceship1.$ += 1;
                coinArray[counter].isCoin = false;
            }
            counter++;
        }

        // Score
        int static score = 0;
        textScore.setString("Score: " + to_string(score));

        //Projectile collides with enemy
        counter = 0;
        for (it = projectileArray.begin(); it != projectileArray.end(); it++)
        {
            counter2 = 0;
            for (it2 = enemyArray.begin(); it2 != enemyArray.end(); it2++)
            {
                if (projectileArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
                {
                    // update Score
                    score++;
                    // Play Sound
                    soundCollision.play();
                    if (Projectile1.attackDamage == 2)
                    {
                        score += 1;
                    }

                    // Destroy Projectile
                    projectileArray[counter].destroy = true;

                    // Text display
                    textDisplay1.text.setString(to_string(projectileArray[counter].attackDamage));
                    textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x+60, enemyArray[counter2].rect.getPosition().y+60);
                    textDisplayArray.push_back(textDisplay1);
                    enemyArray[counter2].hp -= projectileArray[counter].attackDamage;
                    if (enemyArray[counter2].hp <= 0)
                    {
                        coin1.rect.setPosition(enemyArray[counter2].rect.getPosition().x+40, enemyArray[counter2].rect.getPosition().y+50);
                        coin1.sprite.setPosition(enemyArray[counter2].rect.getPosition().x+40, enemyArray[counter2].rect.getPosition().y+50);
                        coinArray.push_back(coin1);
                        enemyArray[counter2].alive = false;
                    }
                }
                counter2++;
            }
            counter++;
        }

        // Black Hole collides with Spaceship
            counter2 = 0;
            for (it6 = blackHoleArray.begin(); it6 != blackHoleArray.end(); it6++)
            {
                if (Spaceship1.rect.getGlobalBounds().intersects(blackHoleArray[counter2].rect.getGlobalBounds()))
                {
                    // Play sound
                    soundPowerUp.play();

                    score *= 2;
                    blackHoleArray[counter2].destroy = true;
                    Spaceship1.hp = 10;
                    // full hp
                    SpaceshipHealth1.powerUp();
                    SpaceshipHealth1.powerUp();
                    SpaceshipHealth1.powerUp();
                    SpaceshipHealth1.powerUp();
                    SpaceshipHealth1.powerUp();
                    // change Spaceship
                    Spaceship1.sprite.setTextureRect(sf::IntRect(15, 125*generateAnotherRandomSpaceship() + 10, 122, 122));
                }
                counter2++;
            }


        // Delete Dead Enemy
        counter2 = 0;
        for (it2 = enemyArray.begin(); it2 != enemyArray.end(); it2++)
        {
            if (enemyArray[counter2].alive == false)
            {
                enemyArray.erase(it2);
                break;
            }
            counter2++;
        }

        // Delete Projectile
        counter = 0;
        for (it = projectileArray.begin(); it != projectileArray.end(); it++)
        {
            if (projectileArray[counter].destroy == true)
            {
                std::cout << "Projectile terminated" << endl;
                projectileArray.erase(it);
                break;
            }
            counter++;
        }

        // Delete Coin
        counter = 0;
        for (it5 = coinArray.begin(); it5 != coinArray.end(); it5++)
        {
            if (coinArray[counter].isCoin == false)
            {
                coinArray.erase(it5);
                break;
            }
            counter++;
        }

        // Delete Text
        counter = 0;
        for (it3 = textDisplayArray.begin(); it3 < textDisplayArray.end(); it3++)
        {
            if (textDisplayArray[counter].destroy == true)
            {
                std::cout << "Text Deleted" << endl;
                textDisplayArray.erase(it3);
                break;
            }
            counter++;
        }

        // Delete BlackHole
        counter = 0;
        for (it6 = blackHoleArray.begin(); it6 < blackHoleArray.end(); it6++)
        {
            if (blackHoleArray[counter].destroy == true)
            {
                std::cout << "Black Hole Deleted" << endl;
                blackHoleArray.erase(it6);
                break;
            }
            counter++;
        }

        // draw Space
        counter2 = 0;
        double SpaceSpeed = 2.5;
        for (it7 = mapArray.begin(); it7 != mapArray.end(); it7++)
        {
            window.draw(mapArray[counter2].sprite);
            mapArray[counter2].updateMovement(SpaceSpeed);
            counter2++;
        }

        // update Space Movement
        double spaceFrequency = 6.0;
        if (elapsed8.asSeconds() >= spaceFrequency)
        {
            clock8.restart();
            Map1.sprite.setPosition(0,-640*3.9);
            mapArray.push_back(Map1);
        }

        // draw border
        counter = 0;
        for (it4 = borderArray.begin(); it4 < borderArray.end(); it4++)
        {
            window.draw(borderArray[counter].rect);
            counter++;
        }

        // update Spaceship
        Spaceship1.update();
        Spaceship1.updateMovement();

        // draw SpaceShip
        window.draw(Spaceship1.sprite);

        // draw SpaceShip_Health
        window.draw(SpaceshipHealth1.sprite);
        SpaceshipHealth1.sprite.setPosition(Spaceship1.rect.getPosition().x+4, Spaceship1.rect.getPosition().y+90);

        // draw BlackHole
        counter = 0;
        for (it6 = blackHoleArray.begin(); it6 < blackHoleArray.end(); it6++)
        {
            blackHoleArray[counter].update();
            //window.draw(blackHoleArray[counter].rect);
            window.draw(blackHoleArray[counter].sprite);
            counter++;
        }

        // draw enemy
        counter2 = 0;
        for (it2 = enemyArray.begin(); it2 != enemyArray.end(); it2++)
        {
            //window.draw(enemyArray[counter2].rect);
            window.draw(enemyArray[counter2].sprite);
            enemyArray[counter2].update();
            enemyArray[counter2].updateMovement();
            counter2++;
        }

        // random Enemy
        double enemyFrequency = 0.22;
        if (elapsed2.asSeconds() >= enemyFrequency)
        {
            clock2.restart();
            Enemy1.rect.setPosition(generateRandomX(),-300);
            enemyArray.push_back(Enemy1);
            std::cout << generateRandomX() << ' ' << endl;
        }

        // fire projectile
        double fireRate = 0.2;
        if (elapsed1.asSeconds() >= fireRate)
        {
            clock.restart();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                soundShot.play();
                Projectile1.rect.setPosition(Spaceship1.rect.getPosition().x+37, Spaceship1.rect.getPosition().y-15);
                projectileArray.push_back(Projectile1);
            }
        }

        // draw coin
        counter = 0;
        for (it5 = coinArray.begin(); it5 < coinArray.end(); it5++)
        {
            //window.draw(coinArray[counter].rect);
            coinArray[counter].updateMovement();
            window.draw(coinArray[counter].sprite);
            counter++;
        }

        // draw projectile
        counter = 0;
        for (it = projectileArray.begin(); it < projectileArray.end(); it++)
        {
            projectileArray[counter].update();
            //window.draw(projectileArray[counter].rect);
            window.draw(projectileArray[counter].sprite);
            counter++;
        }

        // draw text
        counter = 0;
        for (it3 = textDisplayArray.begin(); it3 < textDisplayArray.end(); it3++)
        {
            textDisplayArray[counter].update();
            window.draw(textDisplayArray[counter].text);
            counter++;
        }


        // update HP up
        if (elapsed4.asSeconds() >= 0.1)
        {
            clock4.restart();
            if (Spaceship1.$ >= 10) // Hp up is ready to use
            {
                Medkit1.isReady();
            }
            else Medkit1.isNotReady();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && Spaceship1.$ >= 10) // Press Z if Coin >= 10
            {
                // Play sound
                soundPowerUp.play();
                score *= 1.2;
                Medkit1.update(Spaceship1.$, Spaceship1.hp);
                SpaceshipHealth1.powerUp(); // Update Health Bar
            }
        }

        cout << Spaceship1.hp << endl;

        // update Double Fire
        if (elapsed5.asSeconds() >= 0.1)
        {
            clock5.restart();
            if (Spaceship1.$ >= 15 && Projectile1.attackDamage < 2) // double Fire is ready to use
            {
                DoubleProjectile1.isReady();
            }
            else if (Spaceship1.$ < 15 && Projectile1.attackDamage < 2) // double Fire is ready to use
            {
                DoubleProjectile1.isNotReady();
            }
            if (Projectile1.attackDamage < 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::X)  && Spaceship1.$ >= 15) // Press X if coin >= 15
            {
                score *= 1.3;
                DoubleProjectile1.update(Spaceship1.$, Projectile1.attackDamage); // Update $ and projectile damage.
                Projectile1.doubleFire(); // update double projectile;
                speedUp1.sprite.setPosition(1, 165); // replace Double Projectile with speed up
            }
        }

        // update Speed
        if (elapsed6.asSeconds() >= 0.1)
        {
            clock6.restart();
            if (Spaceship1.$ >= 15 && Projectile1.attackDamage >= 2 && Projectile1.Lifetime > 7) // Speed Up is Ready to use
            {
                speedUp1.isReady();
            }
            if (Spaceship1.$ >= 15 && Projectile1.attackDamage >= 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::X)) // Distinguish from double projectile - Press X if coin >= 15
            {
                score += 1.4;
                speedUp1.update(Spaceship1.$, Projectile1.projectileSpeed, Projectile1.Lifetime); // Update $ and projectile speed, range
                Projectile1.doubleFire(); // remain double projectile
            }
        }

        // update Black Hole
        if (elapsed7.asSeconds() >= 0.1)
        {
            clock7.restart();
            if (Spaceship1.$ >= 20)
            {
                renderBlackHole1.isReady();
            }
            else renderBlackHole1.isNotReady();
            if (Spaceship1.$ >= 20 && sf::Keyboard::isKeyPressed(sf::Keyboard::C))
            {
                // create Black Hole
                blackHole1.rect.setPosition(generateRandomBlackHoleX(), generateRandomBlackHoleY());
                blackHoleArray.push_back(blackHole1);
                // update coin
                blackHole1.updateCoin(Spaceship1.$);
            }
        }

        // update Difficulty
            if (score >= 40 && score < 80)
            {
                Enemy1.enemySpeed = 3.5;
                SpaceSpeed = 3.5;
                spaceFrequency = 5.0*2.5/3.5;
                Spaceship1.shipSpeed = 8;
                fireRate = 0.1;
            }
            // depend on the power up
            if (Projectile1.attackDamage >= 2) // double fire
            {
                Enemy1.enemySpeed = 4.5;
                SpaceSpeed = 4.5;
                Enemy1.hp = 6;
                Spaceship1.shipSpeed = 9;
                enemyFrequency = 0.16;
            }

            if (Projectile1.projectileSpeed == 45) // speed up projectile
            {
                Enemy1.enemySpeed = 6;
                Spaceship1.shipSpeed = 10;
                SpaceSpeed = 6;
                fireRate = 0.02;
                enemyFrequency = 0.11;
            }

        window.draw(textCoin);
        window.draw(textScore);
        window.draw(Medkit1.sprite);
        window.draw(DoubleProjectile1.sprite);
        window.draw(speedUp1.sprite);
        window.draw(renderBlackHole1.sprite);
        window.display();

        // Endgame
        if (Spaceship1.hp <= 0)
        {
            soundExplosion.play();
            std::string Endgame = "    ENDGAME!!! \n    SCORE: " + to_string(score);
            if(MessageBox(NULL, Endgame.c_str(), "GAME OVER ", MB_OK)== IDOK) window.close();
        }
    }

    return 0;
}
