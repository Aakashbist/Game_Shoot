#include "EndState.h"



EndState::EndState()
{
	 gameOverTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(GAME_OVER));
	 	
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
	
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Text on the screen using new class!", 36,100, 100);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Texguygjugwkjhlihlhlohloihoihiuguyfug new class!", 36, 200, 200);
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
