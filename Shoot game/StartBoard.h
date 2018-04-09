#pragma once
#include "WrittenBox.h"




class StartBoard :
	public WrittenBox
{
public:
	StartBoard(float x_, float y_, float width_, float height_, int fontSize_, string text_, const char * fontPath, const char * fontColor)
		:WrittenBox(x_, y_, width_, height_, fontSize_, text_, fontPath, fontColor) {}
	~StartBoard();
};

