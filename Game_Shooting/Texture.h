#pragma once
#include "Graphics.h"
class Texture
{
protected:
	SDL_Texture* texture;
	Graphics* graphics ;
	
	
public:
	Texture();
	Texture(string path);
	Texture(string text,string fontPath, int size);

	~Texture();
	
	
	virtual void render();
};

