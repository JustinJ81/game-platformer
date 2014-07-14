#include "Block.h"


Block::Block()
{
	this->image = al_load_bitmap("images/block.jpg");
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