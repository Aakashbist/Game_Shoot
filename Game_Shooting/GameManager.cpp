#include "GameManager.h"
GameManager* GameManager::gameManagerInstance = NULL;

GameManager* GameManager::instance() {
	if (gameManagerInstance == NULL)
		gameManagerInstance = new GameManager();
	return gameManagerInstance;
}

void GameManager::release()
{
	delete gameManagerInstance;
	gameManagerInstance = NULL;
}


GameManager::GameManager()
{
	quit = false;
	graphics = Graphics::instance();

	if (!Graphics::initilised)
		quit = true;
	
string path = SDL_GetBasePath();
	path.append(GAME_BACKGROUND);
	texture = new Texture(path);
	
}


GameManager::~GameManager()
{

	Graphics::release();
	graphics = NULL;

	delete texture;
	texture=NULL;
	
}


void GameManager::run()
{
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			//check if window closed
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			//check if they pressed the ESC key
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
					quit = true;
				}
			}
			graphics->clearSurface();
		
			texture->render();
			RenderText* text = new RenderText("SPACE SHOOTER", TTF_FONT, 75,150,50);
			RenderText* text1 = new RenderText("Menu", TTF_FONT, 55, 300, 150); 
			RenderText* text2 = new RenderText("Play", TTF_FONT, 55, 300, 250);
			RenderText* text3 = new RenderText("Instruction", TTF_FONT, 55, 300, 350);
			RenderText* text4 = new RenderText("Exit", TTF_FONT, 55, 300, 450);
			graphics->render();


		}
		
	}
	
}
