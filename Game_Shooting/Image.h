#pragma once
#include<SDL_image.h>
#include"Setting.h"
class Image
{
public:
	Image();
	~Image();

private:
	SDL_Texture* texture=nullptr;
	SDL_Surface* surface=nullptr;
	void loadImage();
};

