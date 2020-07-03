#include"Lletra.h"

//si es clicka la lletra canvia l'estat
bool Lletra::Selecciona(const int& xMouse, const int& yMouse, 
	const int& xLletra, const int& yLletra)
{
	if (xMouse > xLletra && xMouse < xLletra + m_dim && yMouse>yLletra 
		&& yMouse < yLletra + m_dim && Mouse_getButLeft())
	{
		m_estat = !m_estat;

		return 1;
	}
	else
	{
		return 0;
	}
}