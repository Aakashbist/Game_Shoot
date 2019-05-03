#include "Graphics.h"

Graphics* Graphics::graphicsInstance =NULL;
bool  Graphics::graphicsInitilised = false;

Graphics * Graphics::instance()
{
	if (graphicsInstance == NULL) {
		graphicsInstance = new Graphics();
	}
	return graphicsInstance;
}

bool Graphics::initilised()
{
	return graphicsInitilised;
}

void Graphics::release()
{
	delete graphicsInstance;
	graphicsInstance = NULL;

}

Graphics::Graphics()
{
	surface = NULL;
graphicsInitilised=init();
}


Graphics::~Graphics()
{
	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(window);
	window = NULL;
	
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	
}




bool Graphics::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {

		cout << "SDL failed: " << SDL_GetError() << endl;
		system("pause");
		return false;
	}

	// create window
	window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		cout << "window failed: " << SDL_GetError() << endl;
		system("pause");
		SDL_Quit(); //cleans up SDL for us
		return false;
	}

	surface = SDL_GetWindowSurface(window);


	//create a renderer, which helps draw stuff to the window
 renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL)
	{
		cout << "renderer failed: " << SDL_GetError() << endl;
		system("pause");
		SDL_Quit(); //cleans up SDL for us
		return false;
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
			cout << "sdl image failed: " << IMG_GetError() << endl;
			SDL_Quit();
			system("pause");
			return false;
		}

	//INIT sdl ttf
	if (TTF_Init() != 0) {
		cout << "sdl ttf failed: " << TTF_GetError() << endl;
		system("pause");
		SDL_Quit();
		return false;
	}
	return true;

}



void Graphics::render()
{

	SDL_RenderPresent(renderer);
}

void Graphics::clearSurface()
{
	SDL_RenderClear(renderer);
}

SDL_Texture * Graphics::loadTexture(string path)
{

	SDL_Texture * texture = NULL;
	SDL_Surface* surface = IMG_Load(path.c_str());
	//SDL_Surface* background = SDL_LoadBMP("assets/background1.bmp");
	if (surface == NULL) {
		cout << "Image load failed: " << IMG_GetError() << endl;
		return texture;
	}
	
	
	 texture = SDL_CreateTextureFromSurface(renderer, surface);
	 
	 if (texture == NULL) {
		 cout << "Create texture error: " << SDL_GetError() << endl;
		 return texture;
	 }
	SDL_FreeSurface(surface);
	return texture;
}

SDL_Texture * Graphics::createGameHeadingTexture(TTF_Font * font, string text)
{
	{

		SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), { 255,0,255 });
		if (surface == NULL) {
			cout << "Text render error: " << IMG_GetError() << endl;
			return NULL;
		}
		SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);

		if (texture == NULL) {
			cout << "Create texture error: " << SDL_GetError() << endl;
			return NULL;
		}
		SDL_FreeSurface(surface);
		return texture;

	}
}

void Graphics::drawTexture(SDL_Texture * texture)
{
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}

void Graphics::loadTextOnScreen(SDL_Texture * texture, SDL_Rect * rect)
{
	SDL_RenderCopy(renderer, texture, NULL, rect);
}

