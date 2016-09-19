#include "General.h"

void General::fizyka()
{
	//fizyka postaci
	if (skok <= 0) { if (kolizje(1)) spritepostac.move(0, masapostaci); else endskok = false;
	}
	else skok--;

}


/*
	Funkcja fizyki ma polegaæ na zebraniu danych masy przedmiotu (np. postac
	ma mase 8 i spada z taka sama prendkosc) i 
	przyciagnac grawitacyjnie do punktu kolizyjnego
*/