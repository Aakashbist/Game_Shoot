

#include <SDL_ttf.h>//text to font
#include <SDL_mixer.h>//sound n music

#include"Setting.h"
#include"Animation.h"
#include"Hero.h"
#include"KeyboardHandler.h"
#include"Texture.h"
using namespace std;


int main(int argc, char** argv) {


	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		cout << "SDL failed: " << SDL_GetError() << endl;
		system("pause");
		return -1;
	}


	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		cout << "sdl image failed: " << IMG_GetError() << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}


	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		cout << "Mixer error: " << Mix_GetError() << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}

	// create window
	Global::window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	if (Global::window == NULL)
	{
		cout << "window failed: " << SDL_GetError() << endl;
		system("pause");
		SDL_Quit();
		return -1;
	}

	Global::renderer = SDL_CreateRenderer(Global::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);



	SDL_Texture* backgroundTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(GAME_BACKGROUND));

	SDL_Texture* playerTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(PLAYER_SPRITE));


	Animation anim1(playerTexture, Global::renderer, 1, 99, 75, 0.1);

	list<Entity*> entities;

	Entity::entities = &entities;

	//build a hero
	Hero* hero = new Hero();
	hero->setAnimation(&anim1);
	hero->setRenderer(Global::renderer);
	hero->setXY(WINDOW_WIDTH/2,WINDOW_HEIGHT/2);
	
	//entities.push_back(hero);

	//KeyboardHandler keyboardHandler;
	//keyboardHandler.hero = hero;

	////LOAD UP SOME MUSIC
	//Mix_Music* music = Mix_LoadMUS(GAME_SOUND);
	//if (music == NULL) {
	//	cout << "Music failed! : " << Mix_GetError() << endl;
	//	SDL_Quit();
	//	system("pause");
	//	return -1;
	//}

	//Play the music!
	//params: music to play
	//		how many times to loop the music (-1 play infinitely)
	//Mix_PlayMusic(music, -1);

	Uint32 lastUpdate = SDL_GetTicks();

	bool loop = true;
	while (loop) {
		Uint32 timeDiff = SDL_GetTicks() - lastUpdate;

		float DT = timeDiff / 1000.0;
		lastUpdate = SDL_GetTicks();

		//Poll inputs
		SDL_Event event;

		while (SDL_PollEvent(&event)) 
		{
			hero->consumeKeyboardEvent(&event,DT);
			if (event.type == SDL_QUIT) {
				loop = false;
			}	
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
					loop = false;
				}
			}
			//keyboardHandler.update(&event);
		}
		SDL_RenderCopy(Global::renderer, backgroundTexture, NULL, NULL);
		//keyboardHandler.updateHeldKeys();
		//entity management stuff
		//for each (Entity* entity in entities)
		//{
		/*	entity->update(DT);
			entity->draw();
		}*/
		hero->update(DT);
		hero->draw();
		SDL_RenderPresent(Global::renderer);
	}

	////stop playing music BEFORE you release its memory
	//Mix_PausedMusic();
	////delete song from memory
	//Mix_FreeMusic(music);


	SDL_DestroyTexture(backgroundTexture);
	SDL_DestroyTexture(playerTexture);
	SDL_DestroyRenderer(Global::renderer);
	SDL_DestroyWindow(Global::window);

	SDL_Quit();

	return 0;
}