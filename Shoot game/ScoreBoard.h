#pragma once
#include "WrittenBox.h"
class ScoreBoard :
	public WrittenBox
{
public:
	ScoreBoard(float x_, float y_, float width_, float height_, int fontSize_, string text_, const char * fontPath, const char * fontColor)
		:WrittenBox( x_,  y_,  width_,  height_,  fontSize_,  text_,  fontPath, fontColor){
		this->text = to_string(0);
	}
	~ScoreBoard();
	unsigned int getScore();
	void updateScore();
	void reset();
private:
	unsigned int score = 0;

};

