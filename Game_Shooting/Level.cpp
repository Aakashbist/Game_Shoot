#include "Level.h"



Level::Level()
{
	backgroundTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(GAME_BACKGROUND));
}


Level::~Level()
{
	delete backgroundTexture;
}



void Level::update()
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
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				//exit loop
				Global::gameStateMachine.push(new MenuState());
				return;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {

				switch (selectedIndex) {
				case 1:
				case 2:
					Global::gameStateMachine.push(new PlayState(selectedIndex));
					break;
				case 3:
					Global::gameStateMachine.push(new MenuState());
					break;
				}
			}

			if (event.key.keysym.scancode == SDL_SCANCODE_UP) {
				selectedIndex--;
				if (selectedIndex <= 0) {
					selectedIndex = 3;
				}
			}

			if (event.key.keysym.scancode == SDL_SCANCODE_DOWN) {
				selectedIndex++;
				if (selectedIndex > 3) {
					selectedIndex = 1;
				}
			}
		}
	}
	
}




void Level::render()
{
	SDL_RenderCopy(Global::renderer, backgroundTexture, NULL, NULL);
	levelOption(selectedIndex);
	SDL_RenderPresent(Global::renderer);
}

bool Level::onEnter()
{
	SoundManager::soundManager.playSound("end");
	cout << "Entering EndState.h \n";
	return true;
}

bool Level::onExit()
{
	return true;
}

std::string Level::getStateID()
{
	return "Level.h";
}
void levelOption(int num) {


	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Level 1", 55, 300, 170, Global::menuDeselectedColor);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Level 2", 55, 300, 270, Global::menuDeselectedColor);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Exit", 55, 300, 370, Global::menuDeselectedColor);
	switch (num) {
	case 1:
		Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Level 1", 55, 300, 170, Global::menuSelectedColor);
		break;
	case 2:
		Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Level 2", 55, 300, 270, Global::menuSelectedColor);
		break;
	case 3:
		Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Exit", 55, 300, 370, Global::menuSelectedColor);
		break;
	}
}