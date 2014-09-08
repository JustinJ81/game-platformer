#include "Block.h"

Block::Block()
{

}

Block::Block(int sprite)
{
	if (sprite == 1)

	{
		this->image = al_load_bitmap("images/block.jpg");
	}
	else
	{
		this->image = al_load_bitmap("images/block2.jpg");
	}
}


Block::~Block()
{
}

ALLEGRO_BITMAP* Block::getImage()
{
	return image;
}

void Block::setImage(ALLEGRO_BITMAP* nimage)
{
	this->image = nimage;
}

void Block::setX(int x)
{
	this->position_X = x;
}

void Block::setY(int y)
{
	this->position_Y = y;
}

int Block::getX()
{
	return position_X;
}

int Block::getY()
{
	return position_Y;
}

void Block::setCollision_S(int col)
{
	this->collision_S = col;
}

void Block::setCollision_W(int col)
{
	this->collision_W = col;
}
void Block::setCollision_E(int col)
{
	this->collision_E = col;
}
void Block::setCollision_N(int col)
{
	this->collision_N = col;
}

int Block::getHeight()
{
	return height;
}

int Block::getWidth()
{
	return width;
}

int Block::getBound()
{
	return bound;
}

void Block::setBound(int b)
{
	this->bound = b;
}