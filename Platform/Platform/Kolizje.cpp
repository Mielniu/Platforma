#include "General.h"

bool General::kolizje(int jaka)
{
	positionpostac = spritepostac.getPosition();
	switch (jaka)
	{
	case 1:
		if ((positionpostac.y + wysokoscpostaci) < kolizja) return true; else return false; break;
	case 2: if (positionpostac.x > 0) return true; else return false; break;
	case 3: if ((positionpostac.x + szerokoscpostaci) < windowsWidth) return true; else return false; break;
	
	default:
		return false;
			break;
	}


}

/*
	Funkcja kolizji ma na cemu stworzenie lub pobrania z pliku �cie�ki na
	kt�rej ma si� pojawi� kolizja (np. posta� + ziemia lub + �ciana)
*/