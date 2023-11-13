#pragma once

#define CANVAS_WIDTH 28.0f
#define CANVAS_HEIGHT 16.0f

#define ASSET_PATH ".\\assets\\" 

#define CARD_SIZE 5.0f
#define INFO_SIZE 1.0f

#define SETCOLOR(c,r,g,b){c[0] = r; c[1] =g; c[2] = b;}

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

inline float distance(float x1, float y1, float x2, float y2)
{
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx * dx + dy * dy);
}


