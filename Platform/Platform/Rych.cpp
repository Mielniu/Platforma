#include "General.h"

void General::ruch(int kierunek)
{
	positionpostac = spritepostac.getPosition();
	switch (kierunek)
	{
	case 1: 
			if (positionpostac.y >= (kolizja - 180))
			{
				if (endskok == false)
				{
					if (skok > 0) spritepostac.move(0, -8);
					skok = 10;
				}
			}
			else endskok = true;
			break;
	case 2: spritepostac.move(0, 0); break;
	case 3: if (kolizje(2)) spritepostac.move(-4, 0); break;
	case 4: if (kolizje(3)) spritepostac.move(4, 0); break;

	default:
		break;
	}

}

/*
	1 = skok;
	2 = kucniecie;
	3 = lewo;
	4 = prawo;
*/