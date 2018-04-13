#include "ScoreBoard.h"





ScoreBoard::~ScoreBoard()
{
}

unsigned int ScoreBoard::getScore()
{
	return this->score;
}

void ScoreBoard::updateScore()
{
	this->score++;

	this->text = to_string(this->score);
}

void ScoreBoard::reset()
{
	fstream file(filePath);
	string line;

	if (file.good())
	{
		getline(file, line);
		highscore = atoi(line.c_str());
		if (score > highscore)
			file.write(to_string(score).c_str(), 3);
	}

	else
		file.write(to_string(score).c_str(), 3);

	this->score = 0;
	this->text = to_string(this->score);
}
