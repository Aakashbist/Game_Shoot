
#include "SoundManager.h"
#include "GameManager.h"

using namespace std;


int main(int argc, char** argv) {
	
	GameManager* gameManager = GameManager::instance();
	gameManager->run();

	
	
	GameManager::release();
	gameManager = NULL;

	//
	////initialise SDL with all its sub systems e.g video, input, sound etc
	//if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
	//	cout << "SDL failed: " << SDL_GetError() << endl;
	//	system("pause");
	//	return -1;
	//}

	////Need to initialise other sub libraries
	//if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
	//	cout << "sdl image failed: " << IMG_GetError() << endl;
	//	SDL_Quit();
	//	system("pause");
	//	return -1;
	//}

	////init sdl mixer
	//if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
	//	cout << "Mixer error: " << Mix_GetError() << endl;
	//	SDL_Quit();
	//	system("pause");
	//	return -1;
	//}

	//// create window
	//SDL_Window* window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	//	WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	//if (window == NULL)
	//{
	//	cout << "window failed: " << SDL_GetError() << endl;
	//	system("pause");
	//	SDL_Quit(); //cleans up SDL for us
	//	return -1;
	//}

	////create a renderer, which helps draw stuff to the window
	//SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);


	////load image into ram, as a surface we can access and tweak pixel data if we like
	//SDL_Surface* background = SDL_LoadBMP( "assets/background1.bmp");
	////convert surface into texture. Texture will be stored in VRAM for our graphics card to use
	//SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, background);
	////dont need surface anymore, lets free its memory
	//SDL_FreeSurface(background);

	//
	////LOAD UP SOME MUSIC
	//Mix_Music* music = Mix_LoadMUS(GAME_SOUND);
	//if (music == NULL) {
	//	cout << "Music failed! : " << Mix_GetError() << endl;
	//	SDL_Quit();
	//	system("pause");
	//	return -1;
	//}

	////Play the music!
	////params: music to play
	////		how many times to loop the music (-1 play infinitely)
	//Mix_PlayMusic(music, -1);


	//bool loop = true;
	//while (loop) {
	//	//Poll inputs
	//	SDL_Event event;
	//	//loop through all generated inputs
	//	while (SDL_PollEvent(&event)) {
	//		//check if window closed
	//		if (event.type == SDL_QUIT) {
	//			loop = false;
	//		}
	//		//check if they pressed the ESC key
	//		if (event.type == SDL_KEYDOWN) {
	//			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
	//				loop = false;
	//			}
	//		}
	//	}
	//	SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
	//	SDL_RenderPresent(renderer);
	//}

	////stop playing music BEFORE you release its memory
	//Mix_PausedMusic();
	////delete song from memory
	//Mix_FreeMusic(music);

	//
	//SDL_DestroyTexture(backgroundTexture);
	//SDL_DestroyRenderer(renderer);
	//SDL_DestroyWindow(window);

	//SDL_Quit();
	
	return 0;
}