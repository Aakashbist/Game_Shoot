#include "HallOfFameState.h"



HallOfFameState::HallOfFameState()
{
	highScore = new HighScore();
}


HallOfFameState::~HallOfFameState()
{
	delete highScore;
}

void HallOfFameState::update()
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
	int * scores = highScore->getHighScores();
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), std::to_string(*scores), 55, 300, 150, Global::menuDeselectedColor);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), std::to_string(*(scores+1)), 55, 300, 250, Global::menuDeselectedColor);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), std::to_string(*(scores + 2)), 55, 300, 350, Global::menuDeselectedColor);
	
}

void HallOfFameState::render()
{

	SDL_RenderPresent(Global::renderer);
}

bool HallOfFameState::onEnter()
{
	cout << "Entering EndState.h \n";
	return true;
}

bool HallOfFameState::onExit()
{
	return true;
}

std::string HallOfFameState::getStateID()
{
	return "hallOfFameState";
}
