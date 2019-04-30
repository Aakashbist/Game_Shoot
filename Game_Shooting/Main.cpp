#include<SDL.h>
#include<iostream>
using namespace std;


int main(int argc, char** argv) {
	//initialise SDL with all its sub systems e.g video, input, sound etc
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		cout << "SDL failed: " << SDL_GetError() << endl;
		system("pause");
		return -1;
	}


	SDL_Window* window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600, SDL_WINDOW_SHOWN);



	bool loop = true;
	while (loop) {

		//Poll inputs
		SDL_Event event;
		//loop through all generated inputs
		while (SDL_PollEvent(&event)) {
			//check if window closed
			if (event.type == SDL_QUIT) {
				loop = false;
			}
			//check if they pressed the ESC key
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
					loop = false;
				}
			}
		}

	}
	return 0;
}