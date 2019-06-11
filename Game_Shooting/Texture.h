#pragma once

#include<iostream>
#include<SDL.h>
#include<SDL_ttf.h>
#include<SDL_image.h>
#include "Global.h"
#include "Setting.h"
#include "Hero.h"
class Texture: public Entity
{
public:
	
	static Texture* textureInstance;
	static Texture* instance();
	SDL_Texture* texture;
	
	SDL_Surface* surface;
	std::string path;

	SDL_Texture * loadTexture(std::string path);
	void createGameHeadingTexture(std::string path, std::string text, int size, int x, int y);

	std::string getPath(std::string path);
	std::string getScore(int Score);

	virtual std::string getStateID();

private:
	Texture();
	~Texture();
	
};

