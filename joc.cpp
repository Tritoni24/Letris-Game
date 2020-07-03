#include "joc.h"
//-----------------------------------------
// joc: porta el control de tot el joc
//-----------------------------------------
void joc()
{
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	srand((int)(time(NULL)));
	
    //Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica-----------
    Screen pantalla(MIDA_X, MIDA_Y);
    //Mostrem la finestra grafica---------------------------------------------------------------------------
    pantalla.show();
	Game Joc;
	
    // Sortim del bucle si pressionem ESC-------------------------------------------------------------------
	do
	{
		// Captura tots els events de ratolí i teclat de l'ultim cicle--------------------------------------
		pantalla.processEvents();

		bool mouseStatus = Mouse_getBtnLeft();
		bool mousePressed = Mouse_getButLeft();

		int mousePosX = Mouse_getX();
		int mousePosY = Mouse_getY();

		Joc.timer(NOW, LAST);

		Joc.actualitza(mousePosX, mousePosY);

		// Actualitza la pantalla---------------------------------------------------------------------------
		pantalla.update();
	} while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));
}
