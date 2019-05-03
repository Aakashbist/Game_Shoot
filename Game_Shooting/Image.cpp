#include "Image.h"

Image::Image()
{
	
}


Image::~Image()
{
}

void Image::loadImage()
{
	//load image into ram, as a surface we can access and tweak pixel data if we like
	surface = SDL_LoadBMP(GAME_BACKGROUND);
	//convert surface into texture. Texture will be stored in VRAM for our graphics card to use
	//texture = SDL_CreateTextureFromSurface(renderer, surface);
	//dont need surface anymore, lets free its memory
	SDL_FreeSurface(surface);
}

