#include "HallOfFameState.h"



HallOfFameState::HallOfFameState()
{
	backgroundTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(GAME_BACKGROUND));

	highScore = new HighScore();
}


HallOfFameState::~HallOfFameState()
{
	delete highScore;
	delete backgroundTexture;
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
 	
}

void HallOfFameState::render()
{
	SDL_RenderCopy(Global::renderer,backgroundTexture, NULL, NULL);
	int * scores = highScore->getHighScores();
	int yOfText = 150;
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Scores : ", 85, 150, 50, Global::menuSelectedColor);
	for (int i = 0; i <= 10; i++) {
		string score = std::to_string(*(scores + i));
		Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), (score).c_str(), 55, 200, yOfText, Global::menuSelectedColor);
		yOfText += 50;
	}
	SDL_RenderPresent(Global::renderer);
}

bool HallOfFameState::onEnter()
{
	Mix_Music*  music = Mix_LoadMUS(GAME_INTRO_SOUND);
	Mix_PlayMusic(music, -1);
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
