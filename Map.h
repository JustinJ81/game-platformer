#pragma once
#include <vector>
#include "Block.h"
#include <fstream>
class Map
{
private:
	
public:
	Block currentMap[11][14];
	int posX = 0;
	int posY = 0;
	ALLEGRO_BITMAP* image1 = al_load_bitmap("images/block.jpg");
	ALLEGRO_BITMAP* image2 = al_load_bitmap("images/block2.jpg");
	////
	Map();
	Map(int[11][14]);
	~Map();

	void setX(int);
		void setY(int);
		int getX();
		int getY();
		Block getMap(int,int);
};

