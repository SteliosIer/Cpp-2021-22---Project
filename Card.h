#pragma once
#include "graphics.h"
using namespace graphics;

class Card 
{
	float m_pos[2];
	float m_color[3];

	int power;
	
public:

	Card();

	void draw(std::string(link), float leftright, float updown, float width, float smallbig);
	void update();

	void setPosX(float x);
	void setPosY(float y);
	float getPosX();
	float getPosY();

	void setPower(int p);
	int getPower();


	bool contains(float x, float y);
};