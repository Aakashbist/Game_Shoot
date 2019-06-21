#include "EndState.h"

EndState::EndState()
{
	backgroundTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(GAME_BACKGROUND));

	score = 0;
	highScore = new HighScore();
}

EndState::EndState(int playerScore)
{	 
	backgroundTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(GAME_BACKGROUND));

	score = playerScore;
	highScore = new HighScore();
}



EndState::~EndState()
{
	delete highScore;
	delete backgroundTexture;
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
	}
	if (SDL_GetTicks() >= NEXT_TIMER_TICK) {

		Global::gameStateMachine.pop(); //which will kill this screen
		Global::gameStateMachine.push(new MenuState());
		return;
	}

	
}

void EndState::render()
{
	SDL_RenderCopy(Global::renderer, backgroundTexture, NULL, NULL);

	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Game Over ", 50, 300, 150, Global::menuSelectedColor);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Your Score is : ", 36, 300, 250, Global::menuSelectedColor);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), std::to_string(score).c_str(), 50, 400, 350, Global::menuSelectedColor);
	SDL_RenderPresent(Global::renderer);
}
bool EndState::onEnter()
{
	SoundManager::soundManager.playSound("end");
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
