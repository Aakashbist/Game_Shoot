#include "PlayState.h"



PlayState::PlayState()
{
	

	Entity::entities = &entities;
	heroTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(PLAYER_SPRITE));
	astroidTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(ASTROID_SPRITE));


	heroAnimation=new Animation(heroTexture, Global::renderer, 1, 99, 75, 0.1);
	astroidAnimation = new Animation(astroidTexture, Global::renderer, 1, 99, 75, 0.8);

	Hero* hero = new Hero();
	hero->setAnimation(heroAnimation);
	hero->setRenderer(Global::renderer);
	hero->setXY(WINDOW_WIDTH/2-50,WINDOW_HEIGHT-100);
	
 	entities.push_back(hero);

	Astroid *astroid = new Astroid();
	astroid->setAnimation(astroidAnimation);
	astroid->setRenderer(Global::renderer);
	astroid->setXY(200, 0);
	astroid->velocity.x = 2;
	entities.push_back(astroid);


	keyboardHandler.hero = hero;
	lastUpdate = SDL_GetTicks();

}

PlayState::~PlayState()
{
	//delete everything we need to
	delete hero;
	
	delete heroAnimation;
	SDL_DestroyTexture(heroTexture);
}

void PlayState::update() {
	
	Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
	dt = timeDiff / 1000.0;
	lastUpdate = SDL_GetTicks();

	
	SDL_Event event;
	
	while (SDL_PollEvent(&event))
	{
		//hero->consumeKeyboardEvent(&event, dt);
		//check if user has clicked on the close window button
		if (event.type == SDL_QUIT) {
			//exit our loop,
			//loop = false;
			Global::quitGame = true;
			Global::gameStateMachine.pop(); //which will kill this screen
			return;
		}
		//check if user has 'pressed' a button(not held)
		if (event.type == SDL_KEYDOWN) {
			//see if ESC key was pressed
			if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				//exit loop
				//loop = false;
				Global::gameStateMachine.pop(); //which will kill this screen
				return;
			}

		}
		
			keyboardHandler.update(&event);
			
	}
	
	keyboardHandler.updateHeldKeys();


	for (auto e : entities) {
		e->update(dt);
		//if this entity isd an asteroid
		//loop through all bullets
		//if collision, deal damage to asteroid, kill bullet
		if (e->getStateID() == "astroid")
		{
			
		}
	}

	/*Remove all game entities that are not active
	for (auto en = entities.begin(); en != entities.end();)
	{
		if ((*en)->active)
			en++;
		else
		{
			not active
			delete *en;
			en = entities.erase(en);
		}
	}*/
	//for (auto b : bullets) {

	//	for (auto e : enemies) {
	//		b == e

	//	}

	//}
	
	
}
void PlayState::render() {
		for (auto e : entities) {

		e->draw();
	}
		
	SDL_RenderPresent(Global::renderer);

}
bool PlayState::onEnter() {
	cout << "Enter Gameplay state" << endl;
	return true;
}
bool PlayState::onExit() {
	cout << "Exit Gameplay state" << endl;
	return true;
}
std::string PlayState::getStateID() {
	return "playState";
}