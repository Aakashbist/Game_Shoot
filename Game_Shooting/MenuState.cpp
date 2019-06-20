#include "MenuState.h"
#include "Texture.h"
#include "PlayState.h"


MenuState::MenuState()
{

}


MenuState::~MenuState()
{
	SDL_DestroyTexture(backgroundTexture);

}


void MenuState::update() {

	SDL_Event event;
	//int score = Hero::hero.getScore();
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT) {
			//exit our loop,
			Global::quitGame = true;
			Global::gameStateMachine.pop();
			return;

		}
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				//exit loop
				Global::quitGame = true;
				Global::gameStateMachine.pop();
				return;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
				Mix_FreeMusic(music);
				switch (selectedIndex) {
				case 1:
					Global::gameStateMachine.push(new PlayState());
					break;
				case 2:
					Global::gameStateMachine.push(new HallOfFameState());
					break;
				case 3:
					Global::quitGame = true;
					Global::gameStateMachine.pop();
					return;
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

	
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "SPACE SHOOTER", 75, 100, 50, Global::menuSelectedColor);
	menuOption(selectedIndex);
}
void MenuState::render() {

	SDL_RenderPresent(Global::renderer);

}
bool MenuState::onEnter() {

	music = Mix_LoadMUS(GAME_INTRO_SOUND);
	Mix_PlayMusic(music, -1);
	std::cout << "Entering menu state" << std::endl;
	return true;

}
bool MenuState::onExit() {

	std::cout << "Exiting menu state" << std::endl;
	return true;
}
std::string MenuState::getStateID() {
	return "menuState";
}

void menuOption(int num) {

	
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Play", 55, 350, 170, Global::menuDeselectedColor);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Hall of Fame", 55, 200,270, Global::menuDeselectedColor);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Exit", 55, 350, 370, Global::menuDeselectedColor);
	switch (num) {	
	case 1:
		Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Play", 55, 350, 170, Global::menuSelectedColor);
		break;
	case 2:
		Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Hall of Fame", 55, 200,270, Global::menuSelectedColor);
		break;
	case 3:
		Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Exit", 55, 350, 370, Global::menuSelectedColor);
		break;
	}
}