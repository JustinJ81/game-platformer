#include "Player.h"


Player::Player()
{
	image = al_load_bitmap("images/player.png");
}


Player::~Player()
{
}

void Player::setImage(ALLEGRO_BITMAP* newImage)
{
	this->image = newImage;
}

ALLEGRO_BITMAP* Player::getImage()
{
	return image;
}

void Player::moveX(float x)
{
	this->x += x;
	this->collision_W = this->x - 1;
}

void Player::moveY(float y)
{
	this->y += y;
	this->collision_N = this->y - 1;
}

float Player::getX()
{
	return x;
}

float Player::getY()
{
	return y;
}