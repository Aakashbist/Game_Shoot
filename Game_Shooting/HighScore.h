#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include"Setting.h"
class HighScore
{
public:
	HighScore();
	~HighScore();

	int score[10];
	std::ofstream fout;
	std::ifstream fin;
	
	void setHighScore(int score);
	int * getHighScores();
	

};

