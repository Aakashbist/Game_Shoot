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
			if (event.key.keysym.scancode == SDL_SCANCODE_A) {
				//exit loop
				Global::quitGame = true;
				Global::gameStateMachine.pop();
				return;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_RETURN) {
				Mix_FreeMusic(music);
				Global::gameStateMachine.push(new PlayState());
				//Global::currentGameState = Game_State::PLAY;
			}
		}
	}
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Score : ", 36, 550, 30);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), std::to_string(Hero::hero.getScore()).c_str(), 36, 680, 30);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "SPACE SHOOTER", 75, 150, 50);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Menu", 55, 300, 150);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Play",  55, 300, 250);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Hall of Fame", 55, 300, 350);
	Texture::instance()->createGameHeadingTexture(Texture::instance()->getPath(TTF_FONT), "Exit", 55, 300, 450);
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