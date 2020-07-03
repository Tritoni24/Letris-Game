#include "Boto.h"

/*ens mostra el boto*/
void Boto::mostra(int x, int y)
{
	m_x = x;
	m_y = y;

	if (m_estat == 1)
	{
		m_pres.draw(x, y);
	}
	else
	{
		m_noPres.draw(x, y);
	}
}
/*permeten interactuar amb el boto depenent de si es un boto amb animació de canvi d'estat*/
bool Boto::Selecciona(int x, int y)
{
	if (x > m_x && x<m_x + m_amp && y>m_y && y < m_y + m_alt && Mouse_getButLeft())
	{
		m_estat = !m_estat;

		return 1;
	}
	else
	{
		return 0;
	}
}

bool Boto::Pressiona(int x, int y)
{
	if (x > m_x && x<m_x + m_amp && y>m_y && y < m_y + m_alt && Mouse_getBtnLeft())
	{
		m_estat = 1;
		mostra(m_x, m_y);
	}
	else
	{
		m_estat = 0;
		mostra(m_x, m_y);
	}

	return m_estat;
}

