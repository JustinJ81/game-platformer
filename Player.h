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
	int x = 200;
	int y =200;


public:
	Player();
	~Player();

	void update(ALLEGRO_EVENT ev);
	void draw(ALLEGRO_DISPLAY* display);

	void setImage(ALLEGRO_BITMAP*);
	ALLEGRO_BITMAP* getImage();

	void moveX(int);
	void moveY(int);
	int getX();
	int getY();

};

