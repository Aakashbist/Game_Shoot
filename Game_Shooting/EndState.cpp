#include "EndState.h"



EndState::EndState()
{
	 gameOverTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(GAME_OVER));
	 
	//gameOverAnimation = new Animation(gameOverTexture, Global::renderer, 1, 225, 225, 0.1);
	/* destination.x = WINDOW_WIDTH / 2 - 50;
	 destination.y = WINDOW_HEIGHT / 2 + 300;
	 destination.w = 225;
	 destination.w = 225;*/
	
	 TTF_Font* font = TTF_OpenFont("assets/vermin_vibes_1989.ttf", 16);
	 SDL_Color textColor = { 123, 0, 34, 0 };

	 SDL_Surface* textSurface = TTF_RenderText_Blended(font, "Text on the screen!", textColor);

	 //convert surface to texteure
	 textTexture = SDL_CreateTextureFromSurface(Global::renderer, textSurface);
	 SDL_FreeSurface(textSurface);

	
	 textDestination.x = 50;
	 textDestination.y = 50;
	 //query to get with and height
	 SDL_QueryTexture(textTexture, NULL, NULL, &textDestination.w, &textDestination.h);

}


EndState::~EndState()
{
}

void EndState::update()
{

	SDL_RenderCopy(Global::renderer, gameOverTexture, NULL, NULL);

	//gameOverAnimation->draw(WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT / 2 + 300);
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		
		if (event.type == SDL_QUIT) {
			Global::quitGame = true;
			Global::gameStateMachine.pop();
			return;
		}

		if (event.type == SDL_KEYDOWN) {
			//see if ESC key was pressed
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {

				Global::gameStateMachine.pop(); //which will kill this screen
				Global::gameStateMachine.push(new MenuState());
				return;
			}
		}


	}
	SDL_RenderCopy(Global::renderer, textTexture, NULL, &textDestination);
}

void EndState::render()
{
	
	SDL_RenderPresent(Global::renderer);
}

bool EndState::onEnter()
{
	cout<< "Entering EndState.h \n";
	return true;
}

bool EndState::onExit()
{
	return true;
}

std::string EndState::getStateID()
{
	return "EndState.h";
}
