#pragma once
#include<allegro5\allegro.h>
class Block
{
private:
	ALLEGRO_BITMAP* image;
	int position_X;
	int position_Y;
	int height = 56;
	int width = 56;
	int collision_N = position_Y;
	int collision_E = position_X + width;
	int collision_S = position_Y + height;
	int collision_W = position_X;
	int bound;

public:
	Block();
	Block(int);
	~Block();
	ALLEGRO_BITMAP* getImage();
	void setImage(ALLEGRO_BITMAP*);

	void setBound(int);
	void setY(int);
	void setX(int);
		int getY();
		int getX();
		int getHeight();
		int getWidth();
		int getBound();
		void setCollision_S(int);
		void setCollision_W(int);
		void setCollision_N(int);
		void setCollision_E(int);
		int getCollision_E()

		{
			return collision_E;
		}

		int getCollision_S()
		{
			return collision_S;
		}
		int getCollision_W()

		{
			return collision_W;
		}

		int getCollision_N()
		{
			return collision_N;
		}
};

