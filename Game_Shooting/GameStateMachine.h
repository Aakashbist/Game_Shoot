#pragma once
#include "GameState.h"
#include <vector>

class GameStateMachine
{
public:
	
	std::vector <GameState*>  gameStates;
	GameStateMachine();
	~GameStateMachine();

	//state management
	void push(GameState* state);
	void changeState(GameState* state);
	void pop();
	void clearAll();

	//update and render
	void update();
	void render();

	//global reference we can use


};

