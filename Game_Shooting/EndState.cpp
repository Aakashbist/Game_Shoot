#include "EndState.h"

EndState::EndState()
{
	score = 0;
	highScore = new HighScore();
}

EndState::EndState(int playerScore)
{	 	
	score = playerScore;
	highScore = new HighScore();
}



EndState::~EndState()
{
	delete highScore;
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
	
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Game Over ", 50, 300, 150, Global::menuSelectedColor);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Your Score is : ", 36, 300, 250, Global::menuSelectedColor);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), std::to_string(score).c_str(), 36, 300, 350, Global::menuSelectedColor);
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
