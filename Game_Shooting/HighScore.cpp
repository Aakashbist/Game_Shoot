#include "HighScore.h"



HighScore::HighScore()
{
}


HighScore::~HighScore()
{
}

void HighScore::setHighScore(int score)
{
	
	fout.open(highScoreFile);
	fout << score;
	fout.close();

}

int * HighScore::getHighScores()
{
	fin.open(highScoreFile);
	if (!fin.eof()) {
		fin >> score[0];
		fin >> score[1];
		fin >> score[2];
		fin.close();
	}
	return &score[0];
	
}
