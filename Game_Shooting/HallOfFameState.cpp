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
	int yOfText = 150;
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Scores : ", 85, 150, 50, Global::menuSelectedColor);
	for (int i = 0; i <= 10; i++) {
		string score =std::to_string(*(scores + i));
		Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), (score).c_str(), 55, 200, yOfText, Global::menuSelectedColor);
		yOfText += 50;
	}
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
