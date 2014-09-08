#include "Map.h"
#include <fstream>
#include <iostream>

Map::Map(int temp[11][14])
{
	//int sprite;
	//std::ifstream file;
	//file.open("map.txt", std::ios::in);
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				//file >> sprite;
				//std::cout << sprite;
				currentMap[i][j].setX(i * 64);
				currentMap[i][j].setY(j * 64);
				currentMap[i][j].setCollision_E(currentMap[i][j].getX() + 56);
				currentMap[i][j].setCollision_S(currentMap[i][j].getY() + 56);
				currentMap[i][j].setCollision_W(currentMap[i][j].getX() );
				currentMap[i][j].setCollision_N(currentMap[i][j].getY() );

				if (temp[i][j] == 1)
				{
					currentMap[i][j].setImage(image1);
					currentMap[i][j].setBound(1);
				}
				else if (temp[i][j] == 2)
				{
					currentMap[i][j].setImage(image2);
					currentMap[i][j].setBound(1);
				}
				else{
					currentMap[i][j].setImage(NULL);
					currentMap[i][j].setBound(0);

				}
			}
	}
}


Map::~Map()
{
}

Block Map::getMap(int i, int j)
{
	return currentMap[i][j];
}
