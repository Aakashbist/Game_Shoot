#pragma once

#include<SDL.h>
#include<iostream>
#include<string>
#include <SDL_image.h>
#include<SDL_ttf.h>
#include "Setting.h"

	using namespace std;
	class Graphics
	{
	public:		
		
		static Graphics* instance();
		static bool initilised();
		static void release();
		void render();
		void clearSurface();
		SDL_Texture* loadTexture(string path);
		SDL_Texture* createGameHeadingTexture(TTF_Font* font, string text);
		
		void drawTexture(SDL_Texture* texture);
		void loadTextOnScreen(SDL_Texture* texture,SDL_Rect* rect);

	private:

		string title;
		int width, height;
		
		static Graphics* graphicsInstance;
		static bool graphicsInitilised;

		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Surface* surface;

		Graphics();
		~Graphics();		

		bool init();





};

