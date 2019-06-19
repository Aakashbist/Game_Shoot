#include "EndState.h"



EndState::EndState()
{	 	
}


EndState::~EndState()
{
}

void EndState::update()
{

	

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
	
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Score : ", 36, 550, 30, Global::menuSelectedColor);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), std::to_string(Hero::hero.getScore()).c_str(), 36, 680, 30, Global::menuSelectedColor);
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
