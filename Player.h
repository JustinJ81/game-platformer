#pragma once

#include <allegro5\allegro.h>
#include<vector>
#include<string>

class Player
{
private:
	ALLEGRO_BITMAP* image;
	ALLEGRO_BITMAP* idleImage[7];
	std::pair<float, float> position;
	float moveSpeed;
	float x = 200;
	float y =200;
	int collision_N = y - 1;
	int collision_E = x + 1;
	int collision_S = y + 1;
	int collision_W = x - 1;


public:
	Player();
	~Player();

	void update(ALLEGRO_EVENT ev);
	void draw(ALLEGRO_DISPLAY* display);

	void setImage(ALLEGRO_BITMAP*);
	ALLEGRO_BITMAP* getImage();

	void moveX(float);
	void moveY(float);
	float getX();
	float getY();

	int getCollision_W()
	{
		return collision_W;
	}
	int getCollision_N()
	{
		return collision_N;
	}

	int getCollision_S()
	{
		return collision_S;
	}
	int getCollision_E()
	{
		return collision_E;
	}
//	void setX(float);
//	void setY(float)

};

