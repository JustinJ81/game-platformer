#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include "Player.h"
#include "Block.h"
#include "Map.h"

ALLEGRO_DISPLAY *display;
ALLEGRO_BITMAP *tiles;
int scroll_x, scroll_y;
float rotate;
float zoom = 1.0;

struct mapTemp
{
	//int map[10][5];
};
const float FPS = 60;
const int SCREEN_W = 800;
const int SCREEN_H = 600;
const int BOUNCER_SIZE = 32;
enum MYKEYS {
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_SPACE
};

void  makeMap()
{
	//return map;
}

void drawMap(Map map)
{
	int test;
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				if (map.getMap(i, j).getImage() != NULL)
				{
					al_draw_scaled_bitmap(map.getMap(i, j).getImage(), 0, 0, 100, 100, j * 56, i * 56, 64, 64, 0);
					//map.getMap(i, j).setX(i * map.getMap(i, j).getWidth());
					//map.getMap(i, j).setCollision_W(i * map.getMap(i, j).getWidth());
					//std::cout << map.getMap(i, j).getX();
					
					//map.getMap(i, j).setY(i * map.getMap(i, j).getHeight());
					//std::cout << map.getMap(i, j).getX();
					//std::cin >> test;
				}
				else
				{
					//al_draw_bitmap(al_map_rgb(200, 200, 200) , 0, 0, 100, 100, j * 56, i * 56, 64, 64, 0);
				}
				
			}
		}
}

bool checkCollision(Map map, Player player)
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (map.getMap(i, j).getBound() == 1)
			{//std::cout << map.getMap(i, j).getCollision_N();
				if (player.getX() > map.getMap(i, j).getCollision_E() &&
					player.getX() < map.getMap(i, j).getCollision_W() )
				//	player.getY() > map.getMap(i, j).getCollision_N() ||
				//	player.getY() < map.getMap(i, j).getCollision_S())
				{
					return false;
				}
				else
				{
					return true;
				}
			}
			else if (map.getMap(i, j).getBound() == 0)
			{
				return false;
			}
		}
	}
}


int main(void){
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *enemy = NULL;
	ALLEGRO_BITMAP *block = NULL;

	int player_oriantation;

	int temp[11][14] = { 
	{ 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 2, 1 },
	{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 2, 2, 1 } };

	bool key[5] = { false, false, false, false, false };
	bool redraw = true;
	bool doexit = false;
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	timer = al_create_timer(1 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	srand(time(NULL));

	al_init_image_addon();
	al_init_primitives_addon();

	Player player;
	ALLEGRO_BITMAP* pImage = player.getImage();
	al_set_target_bitmap(pImage);

	Map map(temp);
	
	al_set_target_bitmap(al_get_backbuffer(display));


	// /al_set_target_bitmap(map);

	al_clear_to_color(al_map_rgb(5, 100, 255));
	al_set_target_bitmap(al_get_backbuffer(display));

	queue = al_create_event_queue();
	if (!queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(pImage);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_start_timer(timer);

	while (1) //game loop
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {

			if (key[KEY_UP] && player.getY() >= 4.0)
			{
					player.moveY(-10.0);
			}

			if (key[KEY_LEFT] && player.getX() >= 4.0 ) 
			{
					player.moveX(-4.0);
					player_oriantation = 0;
			}

			if (key[KEY_RIGHT] && player.getX() <= SCREEN_W - 64) 
			{
					player.moveX(4.0);
					player_oriantation = 1;	
			}


			if (key[KEY_SPACE] && player.getX() <= SCREEN_W && player.getY() <= SCREEN_H && player.getY() != SCREEN_H + 1){


			}

			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;

			case ALLEGRO_KEY_SPACE:
				key[KEY_SPACE] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;

			case ALLEGRO_KEY_SPACE:
				key[KEY_SPACE] = false;
				break;
			}
		}
	if (player.getY() < 500)    //gravity
	{	
			player.moveY(2.0);
	}
	else{}

		if (redraw && al_is_event_queue_empty(queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));
		//	std::cout << "TESTETSTSTETST";
			al_draw_bitmap(pImage, player.getX(), player.getY(), player_oriantation);


			//al_draw_bitmap(enemy, 100, 100, 0);

			drawMap(map);
			                                                                                                                             
	/*		for (int x = 0; x < SCREEN_H + 200; x += 80)
			{
				al_draw_bitmap(block, x, SCREEN_H - 45, 0);
				//        al_draw_bitmap(block, 80 , SCREEN_H - 45, 0);
			} */
			al_flip_display();

		}
	}

	//al_destroy_bitmap(bouncer);
	al_destroy_bitmap(enemy);
	al_destroy_bitmap(block);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(queue);

	return 0;
}
