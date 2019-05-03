#include "RenderText.h"


RenderText::RenderText()
{
}

RenderText::RenderText(string text, string fontPath, int size)
{
	graphics = Graphics::instance();
	string path = SDL_GetBasePath();
	path.append(TTF_FONT);
	TTF_Font* font = TTF_OpenFont(path.c_str(), size);
	texture = graphics->createGameHeadingTexture(font, text);

	//text destination
	SDL_Rect textDestination;
	textDestination.x = 150;
	textDestination.y = 50;

	SDL_QueryTexture(texture, NULL, NULL, &textDestination.w, &textDestination.h);
	graphics->loadTextOnScreen(texture, &textDestination);
}


RenderText::~RenderText()
{
}

void RenderText::render()
{
}

