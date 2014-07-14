#pragma once
#include<allegro5\allegro.h>
class Block
{
private:
	ALLEGRO_BITMAP* image;
	int position_X;
	int position_Y;
	int height = 32;
	int width = 32;

public:
	Block();
	~Block();
	ALLEGRO_BITMAP* getImage();
	void setImage(ALLEGRO_BITMAP*);
};

