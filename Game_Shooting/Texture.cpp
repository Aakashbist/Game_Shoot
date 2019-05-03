#include "Texture.h"


Texture::Texture()
{
}

Texture::Texture(string path)
{
	graphics = Graphics::instance();
	texture = graphics->loadTexture(path);

}

Texture::Texture(string text, string fontPath, int size)
{
	
}

Texture::~Texture()
{
	SDL_DestroyTexture(texture);
	texture = NULL;

	graphics = NULL;
}



void Texture::render()
{

	graphics->drawTexture(texture);
}
