#include "PlayState.h"


PlayState::PlayState() {
	
	Entity::entities = &entities;

	heroTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(PLAYER_SPRITE));
	heroAnimation = new Animation(heroTexture, Global::renderer, 1, 98, 75, 0.1);

	astroidTexture = Texture::instance()->loadTexture(Texture::instance()->getPath(ASTROID_SPRITE));
	astroidAnimation = new Animation(astroidTexture, Global::renderer, 1, 99, 96, 0.1);

	astroidtexture2 = Texture::instance()->loadTexture(Texture::instance()->getPath(ENEMY_SPRITE));
	astroidAnimation2 = new Animation(astroidtexture2, Global::renderer, 1, 104, 84, 0.1);

	hero = new Hero();
	hero->setAnimation(heroAnimation);
	hero->setRenderer(Global::renderer);
	hero->setXY(WINDOW_WIDTH / 2 - 50, WINDOW_HEIGHT - 100);

	entities.push_back(hero);

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

	//time management
	Uint32 timeDiff = SDL_GetTicks() - lastUpdate;
	dt = timeDiff / 1000.0;
	lastUpdate = SDL_GetTicks();


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
				//exit loop
				//loop = false;
				Global::gameStateMachine.pop(); //which will kill this screen
				return;
			}

		}

		keyboardHandler.update(&event);
	}

	keyboardHandler.updateHeldKeys();

	//managing astroid and enemy rendering depending on time 

	if (SDL_GetTicks() >= NEXT_TIMER_TICK) {
		printf("no of  sdl %d \n", SDL_GetTicks());
		// Gap from left and right 80 px
		int x = (rand() % (WINDOW_WIDTH - 160)) + 200;
		// astroid start above screen
		int y = -100;
		int animationSelector = rand() % 10;
		Astroid *astroid = new Astroid();
		if (animationSelector < 5) {

			astroid->setAnimation(astroidAnimation);
		}
		else {
			astroid->setAnimation(astroidAnimation2);
		}
		astroid->setRenderer(Global::renderer);
		astroid->setXY(x, y);
		entities.push_back(astroid);
		//Astroid::astroid.push(astroid);

		NEXT_TIMER_TICK = SDL_GetTicks() + TIMER_IN_MILLIS;
	}
	//delete entities if they are inactive
	for (auto entity = entities.begin(); entity != entities.end();)
	{
		if ((*entity)->active)
			entity++;
		else
		{
			//not active
			delete *entity;
			entity = entities.erase(entity);
		}
	}

	// removing bullets form list of bullets
	for (auto bullet = hero->bullets.begin(); bullet != hero->bullets.end();)
	{	
		if ((*bullet)->active) {
			bullet++;
		}
		else
		{			
			//not active
			delete *bullet;
			bullet = hero->bullets.erase(bullet);			
		}
	}

	//updating entities
	for (auto entity : entities) {
		if (entity->active)
			entity->update(dt);
	}

	//checking collission and removing entities if they collied
	for (auto entity : entities) {
		if (entity->getStateID() == "astroid") {
			Astroid*  astroid = (Astroid*)entity;
			for (auto bullet = hero->bullets.begin(); bullet != hero->bullets.end();)
			{
				if ((*bullet)->active && astroid->active &&
					(*bullet)->position.x <astroid->width + astroid->position.x &&
					(*bullet)->position.x + (*bullet)->width>astroid->position.x &&
					(*bullet)->position.y <astroid->position.y + astroid->height &&
					(*bullet)->position.y + (*bullet)->height >astroid->position.y)

				{
					(*bullet)->active = false;
					astroid->active = false;
				}
				bullet++;
			}
		}
	}
}


void PlayState::render() {
	for (auto entity : entities) {
		entity->draw();
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
