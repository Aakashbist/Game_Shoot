

#include <SDL_ttf.h>//text to font
#include <SDL_mixer.h>//sound n music
#include<SDL_image.h>

#include<stdlib.h>
#include<time.h>
#include<iostream>

#include"Global.h"
#include"MenuState.h"
#include"Setting.h"
#include"SoundManager.h"
#include"Hero.h"
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
	
	if (TTF_Init() != 0)
	{
		cout << "Sdl ttf failed: " << TTF_GetError() << endl;
		system("pause");
		SDL_Quit();
		return -1;
	}
	

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		cout << "Mixer error: " << Mix_GetError() << endl;
		SDL_Quit();
		system("pause");
		return -1;
	}

	Hero* hero = new Hero();

	//setup some text
	int score = hero->getScore();
	
	TTF_Font* font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 100);
	SDL_Color textColor = { 123, 0, 34, 0 };

	SDL_Surface* textSurface = TTF_RenderText_Blended(font,std::to_string(score).c_str(), textColor);

	//convert surface to texteure
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(Global::renderer, textSurface);
	SDL_FreeSurface(textSurface);

	SDL_Rect textDestination;
	textDestination.x = 600;
	textDestination.y = 50;
	//query to get with and height
	SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);

	SDL_Texture* backgroundTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(GAME_BACKGROUND));

	// play the music

	//prams: music to play
	//       how may times to loop the music(-1 play infinitly)
	

	//load sound
	SoundManager::soundManager.loadSound("explode",EXPLODE_SOUND);
	SoundManager::soundManager.loadSound("laser", FIRE_SOUND);
	SoundManager::soundManager.loadSound("start",GAME_START_SOUND);

Global::gameStateMachine.push(new MenuState());
	
	bool loop = true;
	while (loop) {
			
		Global::gameStateMachine.update();
		Global::gameStateMachine.render();

		if (Global::quitGame || Global::gameStateMachine.gameStates.empty())
			loop = false;

		SDL_RenderCopy(Global::renderer, backgroundTexture, NULL, NULL);
		//SDL_RenderCopy(Global::renderer, textTexture, NULL, &textDestination);
		
		
	}
		
	//clean up any extra screen game states
	Global::gameStateMachine.clearAll();


	Mix_PausedMusic();
	

	SDL_DestroyRenderer(Global::renderer);
	SDL_DestroyWindow(Global::window);

	SDL_Quit();

	return 0;
}