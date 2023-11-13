#include "graphics.h"
#include "confi.h"
#include "Battle.h"
using namespace graphics;


void update(float ms)
{
    Battle * mybattle = Battle::getInstance();
    mybattle->update();
}

// The window content drawing function.
void draw()
{
    Battle* mybattle = Battle::getInstance();
    mybattle->draw();
}

int main()
{
    createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "CppErgasia");

    Battle* battle = Battle::getInstance();

    setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
    battle->font();
   
    setUpdateFunction(update);
    setDrawFunction(draw);

    startMessageLoop();

    Battle::releaseInstance();

    return 0;
}
