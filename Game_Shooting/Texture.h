#pragma once

#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include "Global.h"
#include "Setting.h"
class Texture
{
public:
	static Texture* textureInstance;
	static Texture* instance();
	SDL_Texture* texture;
	SDL_Surface* surface;
	std::string path;

	SDL_Texture * loadTexture(std::string path);
	std::string getPath(std::string path);
private:
	Texture();
	~Texture();
};

