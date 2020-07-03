#pragma once
#include "../Graphic Lib/NFont/NFont.h"
#include "../Graphic Lib/libreria.h"

using namespace std;

class Boto
{
public:
	//declara constructors
	Boto() { m_estat = 0, m_amp = 0, m_alt = 0; };
	Boto(char noAct[], char act[])
		{ m_pres.create(act), m_noPres.create(noAct), m_estat = 0, m_amp = m_noPres.getScaleX(), m_alt = m_pres.getScaleY(); }
	//setters
	void setEstat(bool i) { m_estat = i; }
	void setSprites(char s1[], char s2[])
		{ m_pres.create(s2), m_noPres.create(s1), m_estat = 0, m_amp = m_noPres.getScaleX(), m_alt = m_pres.getScaleY(); }
	//getters
	bool getEstat() { return m_estat; }
	//mostra el boto
	void mostra(int x, int y);
	//selecciona o presiona el boto depenent de tipus de boto
	bool Selecciona(int mouseX, int mouse_Y);
	bool Pressiona(int mouseX, int mouseY);

private:
	int m_x = 0, m_y = 0 , m_alt, m_amp;
	bool m_estat;
	Sprite m_pres, m_noPres;
};