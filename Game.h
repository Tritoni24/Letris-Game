#pragma once
#include "Tauler.h"
#include "Boto.h"

using namespace std;

//posicions del botons 
#define posBotCat_X 35
#define posBotCat_Y 90
#define posBotEng_X 35
#define posBotEng_Y 150
#define posBotEsp_X 35
#define posBotEsp_Y 210
#define posBotoPlay_X 150
#define posBotoPlay_Y 250
#define posBotoPause_X 380
#define posBotoPause_Y 10
#define posBotoCheck_X 140
#define posBotoCheck_Y 760
#define posCrono_X 120
#define posCrono_Y 20
#define posBotoSurt_X 380
#define posBotoSurt_Y 760
#define posBotoReplay_X 140
#define posBotoReplay_Y 760
#define posBotoScores_X 380
#define posBotoScores_Y 10
#define posBotoSurt2_X 190
#define posBotoSurt2_Y 730

class Game
{
public:
	//declaració de contructors
	Game();
	~Game() {};
	//setters/getters
	void setMenu(const int& n) { m_menu = n; }
	int getMenu() { return m_menu; }
	float getCrono() { return m_crono; }
	//mostra i controla la pantalla d'inici
	void Inici(const int& mousePosX, const int& mousePosY);
	//mostra i controla la pantalla per jugar
	void Juga(const int& mousePosX, const int& mousePosY);
	//mostra i controla la pantalla final
	void Final(const int& mousePosX, const int& mousePosY);
	//mostra i controla la pantalla de records
	void Scores(const int& mousePosX, const int& mousePosY);
	//canvia entre les diferents panralles
	void actualitza(const int& mousePosX, const int& mousePosY);
	//controla el temps
	void timer( Uint64& NOW, Uint64& LAST);
	//calcula la puntuació de la partida
	void calculaPuntuacio(const string& paraula_correcta);
	//desa la puntuació a un .txt
	bool desaPuntuacio(int& p1, int& p2, int& p3, int& np1, int& np2, int& np3);
	//llegeix la puntuació
	void llegeixPuntuacio(int& p1, int& p2, int& p3, int& np1, int& np2, int& np3);

	
private:
	int m_menu, m_menuAnt, m_punts, m_nParaules;
	float m_crono;
	bool m_pausat;
	double m_dt;
	Tauler m_t;
	Sprite m_fonsJoc, m_temps, m_fonsInici, m_fons, m_fonsFinal;
	Boto  m_rBoto[3], m_qBoto[3], m_surt, m_pause, m_scores;
	Diccionari m_dic;
};

