#pragma once
#include "../Graphic Lib/NFont/NFont.h"
#include "../Graphic Lib/libreria.h"

class Lletra
{
public:
	//declara constructors
	Lletra() { m_estat = 0, m_dim = 50, m_valor = 0, m_nAlfabet=0; }
	~Lletra(){ m_estat = 0, m_dim = 0, m_valor = 0, m_nAlfabet = 0; }
	//setters
	void setEstat(const bool& i) { m_estat = i; }
	void setValor(const char& a) { m_valor = a; }
	void setNAlfabet(const int& i) { m_nAlfabet = i; }
	//getters
	bool getEstat() const { return m_estat; }
	int getDimensions() const { return m_dim; }
	int getValor()const { return m_valor; }
	int getNAlfabet() const { return m_nAlfabet; }
	//fució selecciona les lletres clicades del tauler
	bool Selecciona(const int& xMouse, const int& yMouse,
		const int& xLletra, const int& yLletra);

private:
	int m_dim, m_nAlfabet;
	bool m_estat;
	char m_valor;
};