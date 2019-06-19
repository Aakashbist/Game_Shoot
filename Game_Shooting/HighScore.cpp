#include "HighScore.h"



HighScore::HighScore()
{
}


HighScore::~HighScore()
{
}

void HighScore::setHighScore(int score)
{
	
	fout.open(highScoreFile, std::ofstream::app);
	fout << "\n";
	fout << score;
	fout.close();

}

int * HighScore::getHighScores()
{
	fin.open(highScoreFile);
	if (!fin.eof()) {
		for (int i = 0; i < 10; i++) {
			fin >> score[i];
		}
		fin.close();
	}
	return &score[0];
	
}
