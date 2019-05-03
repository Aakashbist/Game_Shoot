#pragma once
#include "Texture.h"
#include "RenderText.h"
class GameManager
{

private:
	static GameManager* gameManagerInstance;
	bool quit;	
	Graphics* graphics;

	SDL_Event event;
    Texture* texture;
    
	TTF_Font* font;

	GameManager();
	~GameManager();

	

public:
	static GameManager* instance();
	static void release();

	void run();
};

