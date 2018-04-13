#pragma once
#include "WrittenBox.h"
#include <iostream>
#include <fstream>



class ScoreBoard :
	public WrittenBox
{
public:
	ScoreBoard(float x_, float y_, float width_, float height_, int fontSize_, string text_, const char * fontPath, const char * fontColor, const char * filePath)
		:WrittenBox( x_,  y_,  width_,  height_,  fontSize_,  text_,  fontPath, fontColor){
		this->text = to_string(0);
		this->filePath = filePath;
		fstream file(filePath);
		string line;
		if (file.good())
		{
			getline(file, line);
			highscore = atoi(line.c_str());
		}
			
		else
			(file.write("0", 2));
		

		
	}
	~ScoreBoard();
	unsigned int getScore();
	void updateScore();
	void reset();
private:
	const char * filePath;
	unsigned int score = 0;
	unsigned int highscore;

};

