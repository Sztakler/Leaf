#pragma once

#include <SFML/Graphics.hpp>

class Animator
{
    private:
        sf::Vector2u image_count;
        sf::Vector2u current_image;

        float total_time;
        float switch_time;

    public:
        sf::IntRect uv_rect;

    public:
        Animator();
        Animator(sf::Texture* texture, sf::Vector2u image_count, float switch_time);
        ~Animator();

    public:
        void update(int row, float delta_time);
};