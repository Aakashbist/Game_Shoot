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