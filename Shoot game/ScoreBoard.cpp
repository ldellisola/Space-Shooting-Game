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
	this->score = 0;
	this->text = to_string(this->score);
}
