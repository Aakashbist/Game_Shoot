#pragma once

#include<fstream>
#include"Setting.h"
class HighScore
{
public:
	HighScore();
	~HighScore();

	int score[3];
	std::ofstream fout;
	std::ifstream fin;


	void setHighScore(int score);
	int * getHighScores();


};

