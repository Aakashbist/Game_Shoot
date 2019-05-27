

#include <SDL_ttf.h>//text to font
#include <SDL_mixer.h>//sound n music
#include<iostream>
#include<SDL_image.h>
#include"Global.h"
#include"MenuState.h"
#include"Setting.h"
#include<stdlib.h>
#include<time.h>
using namespace std;


int main(int argc, char** argv) {
	srand(time(NULL));

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


	Global::window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN /*| SDL_WINDOW_FULLSCREEN*/);

	if (Global::window != NULL) {
		cout << "Window created!" << endl;
	}
	else
	{
		cout << "Failed to create window!" << endl;
		return -1;
	}

	//create renderer to help draw stuff to the screen
	Global::renderer = SDL_CreateRenderer(Global::window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Global::renderer != NULL)
	{
		cout << "Renderer created!" << endl;
	}
	else
	{
		cout << "Renderer FAILED!" << endl;
		return -1;
	}
	//get global game state to reference this renderer for global access
	


	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		cout << "Mixer error: " << Mix_GetError() << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}
	SDL_Texture* backgroundTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(GAME_BACKGROUND));



Global::gameStateMachine.push(new MenuState());
	
	bool loop = true;
	while (loop) {
			
		Global::gameStateMachine.update();
		Global::gameStateMachine.render();

		if (Global::quitGame || Global::gameStateMachine.gameStates.empty())
			loop = false;

		SDL_RenderCopy(Global::renderer, backgroundTexture, NULL, NULL);
		
	}
	//clean up any extra screen game states
	Global::gameStateMachine.clearAll();

	SDL_DestroyRenderer(Global::renderer);
	SDL_DestroyWindow(Global::window);

	SDL_Quit();

	return 0;
}