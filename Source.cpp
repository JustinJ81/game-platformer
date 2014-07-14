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

void drawMap(int mapX[5],ALLEGRO_BITMAP* bImage, ALLEGRO_BITMAP* bImage2)
{

	//std::ifstream file;
	//file.open("map.txt");
	//nt b;

	//while (file)
	//{
		
	//	std::cout << b;
		//Block block;
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				//file >> b;
				//std::cout << b;
				if (mapX[j] == 1)
				{
					al_draw_scaled_bitmap(bImage2, 0, 0, 100, 100, i * 56, j * 56, 64, 64, 0);
				}
				else
				{
					al_draw_scaled_bitmap(bImage, 0, 0, 100, 100, i * 56, j * 56, 64, 64, 0);
					//	al_draw_bitmap(bImage, i * 100, j * 100, 0);
				}
			}
		}
//	}
	//file.close();
}


int main(void){
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *enemy = NULL;
	ALLEGRO_BITMAP *block = NULL;
	//ALLEGRO_BITMAP *map = NULL;
	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	int player_oriantation;


	//float bouncerT_x = SCREEN_W / 4.0 - BOUNCER_SIZE / 4.0;
	// float bouncerT_y = SCREEN_H / 4.0 - BOUNCER_SIZE / 4.0;

	float bouncer_dx = -4.0, bouncer_dy = 4.0;
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

	Block bloc;
	ALLEGRO_BITMAP* bImage = bloc.getImage();
	ALLEGRO_BITMAP* bmage;
	bmage = al_load_bitmap("images/block2.jpg");
	ALLEGRO_BITMAP* bImage2 = bmage;
 	al_set_target_bitmap(bImage);

	int map[5] = { 1, 2, 2, 1, 1 };

	// /al_set_target_bitmap(map);

	// al_clear_to_color(al_map_rgb(0, 255, 0));

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
	//makeMap();


	al_register_event_source(queue, al_get_display_event_source(display));

	al_register_event_source(queue, al_get_timer_event_source(timer));


	al_register_event_source(queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {



			if (key[KEY_UP] && player.getY() >= 4.0) {

				player.moveY(-10.0);
			}

			/*if(key[KEY_DOWN] && bouncer_y <= SCREEN_H - 64 ) {
			bouncer_y += 4.0;
			}*/

			if (key[KEY_LEFT] && player.getX() >= 4.0) {
				player.moveX(-4.0);
				player_oriantation = 0;
			}

			if (key[KEY_RIGHT] && player.getX() <= SCREEN_W - 64) {
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

				/*   case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;*/

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
			std::cout << "TESTETSTSTETST";
			al_draw_bitmap(pImage, player.getX(), player.getY(), player_oriantation);


			//al_draw_bitmap(enemy, 100, 100, 0);

			drawMap(map, bImage, bImage2);
			                                                                                                                             
	/*		for (int x = 0; x < SCREEN_H + 200; x += 80)
			{
				al_draw_bitmap(block, x, SCREEN_H - 45, 0);
				//        al_draw_bitmap(block, 80 , SCREEN_H - 45, 0);
			} */
			al_flip_display();

		}
	}

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(queue);

	return 0;
}
