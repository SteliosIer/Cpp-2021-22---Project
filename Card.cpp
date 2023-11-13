# include "Card.h"
#include "graphics.h"
#include "confi.h"
using namespace graphics;

Card::Card()
{
}

void Card::draw(std::string(link), float leftright, float updown, float width, float smallbig)
{	
	Brush br;
	br.outline_opacity = 0.0f;
	br.texture = link;
	drawRect(leftright, updown, width, smallbig, br);
}


void Card::update()
{
}


void Card::setPosX(float x)
{
	m_pos[0] = x;
}


void Card::setPosY(float y)
{
	m_pos[1] = y;
}


float Card::getPosX()
{
	return m_pos[0];
}


float Card::getPosY()
{
	return m_pos[1];
}


void Card::setPower(int p)
{
	power = p;
}


int Card::getPower()
{
	return power;
}


bool Card::contains(float x, float y)
{
	return distance(x,y,m_pos[0], m_pos[1]) < CARD_SIZE*0.4f;
}