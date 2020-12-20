#pragma once

#include <SFML/Graphics.hpp>
#include "animator.hpp"
#include <iostream>

enum Direction {IDLE_RIGHT, LEFT, RIGHT, UP, DOWN};

class Player : public sf::Sprite
{
    private:
        sf::Texture* texture;
        sf::Sprite sprite;
        Animator animator;
        Direction direction;
        float horizontalSpeed = 0;
        float verticalSpeed = 0;

        sf::Texture* animationTextures[5];

    public:
        Player();
        Player(std::string texture_path);
        ~Player();

    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        
    public:
        void move(float offsetX, float offsetY);
        void move_right(float offset);
        void move_left(float offset);
        void move(sf::Keyboard::Key keycode, float offset);
        void stop(sf::Keyboard::Key keycode);
        void update(int row, float delta_time);
        void updateTexture();

};