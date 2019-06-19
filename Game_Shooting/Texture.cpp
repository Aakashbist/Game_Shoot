#include "Texture.h"


Texture* Texture::textureInstance = NULL;


Texture::Texture()
{
}


Texture::~Texture()
{
	SDL_DestroyTexture(texture);
	texture = NULL;


}
std::string Texture::getScore(int score)
{
	return("Score : " + score);
}
std::string Texture::getStateID()
{
	return std::string();
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
void Texture::createGameHeadingTexture(std::string path, std::string text, int size, int x, int y,SDL_Color color)
{
	//RenderText(string text, string fontPath, int size, int x, int y)
	TTF_Font* font = TTF_OpenFont(path.c_str(), size);
	
																	//color
	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(),color);
	if (surface == NULL) {
		std::cout << "Text render error: " << IMG_GetError() << std::endl;
	}
	 texture = SDL_CreateTextureFromSurface(Global::renderer, surface);
	if (texture == NULL) {
		std::cout << "Create texture error: " << SDL_GetError() << std::endl;
	}
	SDL_FreeSurface(surface);
	
	//text destination
	SDL_Rect textDestination;
	textDestination.x = x;
	textDestination.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &textDestination.w, &textDestination.h);
	SDL_RenderCopy(Global::renderer, texture, NULL, &textDestination);

}

std::string Texture::getPath(std::string path)
{
	std::string pathUrl = SDL_GetBasePath();
	pathUrl.append(path);
	return pathUrl;
}