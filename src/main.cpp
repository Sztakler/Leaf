#include <iostream>
#include <SFML/Graphics.hpp>

#include "player.hpp"
#include "animator.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Leaf", sf::Style::Fullscreen);
    window.setFramerateLimit(60); 

    std::string texture_path = "img/leafRunCycleLeft_200px.png";
    Player player(texture_path);

    player.move(500, 500);
    float delta_time = 0.0f;
    sf::Clock clock;

    while(window.isOpen())
    {
        delta_time = clock.restart().asSeconds();

        sf::Event event;

        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                switch(event.key.code)
                {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    default: 
                        player.move(event.key.code, 10);
                        break;
                }
            }
            if (event.type == sf::Event::KeyReleased)
            {
                player.stop(event.key.code);
            }
        }

        window.clear(sf::Color(0, 0, 0));
        player.update(0, delta_time);
        window.draw(player);
        window.display();
    }

    return 0;
}