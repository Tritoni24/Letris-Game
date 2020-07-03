#pragma once
#include "Lletra.h"
#include <vector>
#include<stdlib.h>
#include<time.h>
#include<string>
#include "Diccionari.h"
//maxims i minims dels vectors i coordenades
#define MAX_COLUMNES 8
#define MAX_FILES 10
#define INICI_TAULER_X 37
#define INICI_TAULER_Y 147
#define FINAL_TAULER_X 394
#define FINAL_TAULER_Y 606
#define VELOCITAT_INICIAL 50
#define INICI_PARAULA_X 37
#define INICI_PARAULA_Y 700
#define MAX_TAULER 80

using namespace std;

//original Tauler
class Tauler {
public:
	//constructors/destructors
	Tauler();
	~Tauler();
	//seleccionala columna amb menys elements
	int seleccionaCol() const;
	//treu una lletra aleatoria
	void treuLletra(double& dt);
	//dibuixa el tauler
	void mostraTauler();
	//calcula la velocitat de caiguda de les lletres
	void velocitat(float& time);
	//getter de les caselles restants
	int getNCasLliures() const { return m_casLliuresTauler; }
	//comprova si s'ha escollit alguna lletra del tauler
	void comprovaTauler(const int& xMouse, const int& yMouse);
	//elimina tots els elements del tuler
	void esborraTauler();
	//dibuixa les lletres de la paraula candidata
	void mostraParaula();
	//esborra les lletres de la paraula candidata
	void esborraParaula();
	//comprova si existeix la paraula candidata en el diccionari
	bool comprovaParaula(Diccionari& d, string& paraula_correcta);

private:
	vector<Lletra> m_tauler[MAX_COLUMNES], m_paraula;
	int m_temps, m_velocitat, m_casLliuresTauler, m_lletraCau, m_xCaient, m_yCaient,
		m_colCaient, m_casLliuresParaula;
	bool m_lletraCaient;
	Lletra m_abcdari[26];
	Sprite m_lletresBlanques[26],m_lletresGrogues[26];
	
};