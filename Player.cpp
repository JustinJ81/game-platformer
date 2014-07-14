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

void Player::moveX(int x)
{
	this->x += x;
}

void Player::moveY(int y)
{
	this->y += y;
}

int Player::getX()
{
	return x;
}

int Player::getY()
{
	return y;
}