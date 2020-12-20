#include "SFML/Graphics.hpp"


int main(int argc, char ** argv){
  sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game");
  sf::Event event;
  sf::Texture texture;
  texture.loadFromFile("img/run_cycle_scaled.png");
  sf::Sprite sprite(texture, sf::IntRect(0,600,200,200));
  renderWindow.setFramerateLimit(20);


  while (renderWindow.isOpen()){
    while (renderWindow.pollEvent(event)){
      if (event.type == sf::Event::EventType::Closed)
        renderWindow.close();
    }
    renderWindow.clear();
    renderWindow.draw(sprite);

    renderWindow.display();
  }
}