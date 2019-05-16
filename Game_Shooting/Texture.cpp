#include "Texture.h"


 Texture* Texture::textureInstance =NULL;


Texture::Texture()
{
}


Texture::~Texture()
{
	SDL_DestroyTexture(texture);
	texture = NULL;


}
Texture * Texture::instance()
{
	if (textureInstance == NULL) {
		textureInstance = new Texture();
	}
	return textureInstance;
}
SDL_Texture * Texture::loadTexture(std::string path)
{

	 texture = NULL;
	 surface = IMG_Load(path.c_str());
	//SDL_Surface* background = SDL_LoadBMP("assets/background1.bmp");
	if (surface == NULL) {
		std::cout << "Image load failed: " << IMG_GetError() << std::endl;
		return texture;
	}


	texture = SDL_CreateTextureFromSurface(Global::renderer, surface);

	if (texture == NULL) {
		std::cout << "Create texture error: " << SDL_GetError() << std::endl;
		return texture;
	}
	SDL_FreeSurface(surface);
	return texture;
}

std::string Texture::getPath(std::string path)
{
	std::string pathUrl = SDL_GetBasePath();
	pathUrl.append(path);
	return pathUrl;
}