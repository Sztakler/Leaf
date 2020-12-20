#include "player.hpp"

Player::Player() 
{
    this->direction = RIGHT;
    this->texture = new sf::Texture();
    this->texture->loadFromFile("img/leaf_small.png");
    this->sprite = sf::Sprite(*this->texture);
    this->animator = Animator(this->texture, sf::Vector2u(18, 1), 0.111);

    for(int i = 0; i < 5; i++)
    {
        this->animationTextures[i] = new sf::Texture();
    }

    this->animationTextures[0]->loadFromFile("img/leaf_small.png");
    this->animationTextures[1]->loadFromFile("img/leafRunCycleLeft_200px.png");
    this->animationTextures[2]->loadFromFile("img/leafRunCycleRight_200px.png");
    this->animationTextures[3]->loadFromFile("img/leaf_small.png");
    this->animationTextures[4]->loadFromFile("img/leaf_small.png");
}

Player::Player(std::string texture_path)
{
    this->direction = RIGHT;
    this->texture = this->animationTextures[this->direction];
    this->texture->loadFromFile(texture_path);
    this->sprite = sf::Sprite(*this->texture);

    this->animator = Animator(this->texture, sf::Vector2u(18, 1), 0.06f);

    for(int i = 0; i < 5; i++)
    {
        this->animationTextures[i] = new sf::Texture();
    }

    this->animationTextures[0]->loadFromFile("img/leaf_small.png");
    this->animationTextures[1]->loadFromFile("img/leafRunCycleLeft_200px.png");
    this->animationTextures[2]->loadFromFile("img/leafRunCycleRight_200px.png");
    this->animationTextures[3]->loadFromFile("img/leaf_small.png");
    this->animationTextures[4]->loadFromFile("img/leaf_small.png");
}

Player::~Player() {}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(this->sprite, states);
    }

void Player::move(float offsetX, float offsetY)
{
    this->sprite.move(offsetX, offsetY);
}

void Player::move_right(float offset)
{
    this->move(offset, 0);
}

void Player::move_left(float offset)
{
    this->move(-offset, 0);
}

void Player::move(sf::Keyboard::Key keycode, float offset)
{
    switch(keycode)
    {
        case sf::Keyboard::Key::A:
            this->direction = Direction::LEFT;
            this->horizontalSpeed = -offset;
            break;
        case sf::Keyboard::Key::D:
            this->direction = Direction::RIGHT;
            this->horizontalSpeed = offset;
            break;
        default:
            break;
    }
}

void Player::stop(sf::Keyboard::Key keycode)
{
    switch(keycode)
    {
        case sf::Keyboard::Key::A:
            this->direction = Direction::IDLE_RIGHT;
            this->horizontalSpeed = 0;
            break;
        case sf::Keyboard::Key::D:
            this->direction = Direction::IDLE_RIGHT;
            this->horizontalSpeed = 0;
            break;
        default:
            break;
    }
}

void Player::update(int row, float delta_time)
{
    this->updateTexture();
    this->animator.update(row, delta_time);
    this->sprite.setTextureRect(this->animator.uv_rect);
    this->move(this->horizontalSpeed, this->verticalSpeed);
}

void Player::updateTexture()
{
    this->texture = this->animationTextures[this->direction];
}