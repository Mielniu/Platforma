#include "General.h"

void General::draw()
{
	windows.clear();
	windows.draw(map);
	windows.draw(spritepostac);
	windows.display();
}