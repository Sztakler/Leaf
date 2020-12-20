#include "animator.hpp"

Animator::Animator() {}

Animator::Animator(sf::Texture* texture, sf::Vector2u image_count, float switch_time)
{
    this->image_count = image_count;
    this->switch_time = switch_time;
    this->total_time = 0.0f;
    this->current_image.x = 0.0f;

    this->uv_rect.width = texture->getSize().x / float(image_count.x);
    this->uv_rect.height = texture->getSize().y / float(image_count.y);
}

Animator::~Animator() {}

void Animator::update(int row, float delta_time)
{
    this->current_image.y = row;
    this->total_time += delta_time;

    if(this->total_time >= this->switch_time)
    {
        this->total_time -= this->switch_time;
        this->current_image.x++;

        if(this->current_image.x >= this->image_count.x)
        {
            this->current_image.x = 0;
        }
    }

    this->uv_rect.left = this->current_image.x * this->uv_rect.width;
    this->uv_rect.top = this->current_image.y * this->uv_rect.height;
}
