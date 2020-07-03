#include"Game.h"
//inicialitza el joc amb els parametres inicials i els sprites-------------------------------------------------------------
Game::Game()
{
	char fons[] = { "./data/GUI/background_main.png" };
	char fonsInici[] = { "./data/GUI/MainMenu_BG.png" };
	char fonsJoc[] = { "./data/GUI/background_play.png" };
	char fonsFinal[] = { "./data/GUI/GameOver.png" };
	char crono[] = { "./data/GUI/Time_Bar.png" };

	char quadrat0[] = { "./data/GUI/Button_Normal.png" };
	char quadrat1[] = { "./data/GUI/Button_Pressed.png" };
	char radioBoto1[] = { "./data/GUI/Checkbox_Enabled.png" };
	char radioBoto0[] = { "./data/GUI/Checkbox_Disabled.png" };

	char pause[] = { "./data/GUI/Btn_Circle_Pause_1_Normal.png" };
	char play[] = { "./data/GUI/Btn_Circle_Play_1_Normal.png" };
	char surt1[] = { "./data/GUI/Btn_Circle_Close_3_Pressed.png" };
	char surt0[] = { "./data/GUI/Btn_Circle_Close_1_Normal.png" };

	char scores[] = { "./data/GUI/Btn_Circle_Ranking1_1_Normal.png" };

	m_menu = 1;
	m_menuAnt = 1;
	m_punts = 0;
	m_nParaules = 0;
	m_crono = (0.0f);
	m_pausat = 0;
	m_dt = 0;

	m_fons.create(fons);
	m_fonsInici.create(fonsInici);

	m_rBoto[0].setSprites(radioBoto0, radioBoto1);
	m_rBoto[1].setSprites(radioBoto0, radioBoto1);
	m_rBoto[2].setSprites(radioBoto0, radioBoto1);
	m_qBoto[0].setSprites(quadrat0, quadrat1);

	m_fonsJoc.create(fonsJoc);
	m_temps.create(crono);

	m_surt.setSprites(surt0, surt1);
	m_qBoto[1].setSprites(quadrat0, quadrat1);
	m_pause.setSprites(pause, play);

	m_fonsFinal.create(fonsFinal);
	m_qBoto[2].setSprites(quadrat0, quadrat1);

	m_scores.setSprites(scores, scores);
}

//mostren les diferents pantalles del joc----------------------------------------------------------------------------------
void Game::Inici(const int& mousePosX, const int& mousePosY)
{
	NFont b("data/Fonts/FreeSans.ttf", 44, NFont::Color(255, 255, 255, 255));
	//mostra els elments de la pantalla
	m_fons.draw(0, 0);
	m_fonsInici.draw(0, 0);

	m_rBoto[0].mostra(posBotCat_X, posBotCat_Y);
	m_rBoto[1].mostra(posBotEng_X, posBotEng_Y);
	m_rBoto[2].mostra(posBotEsp_X, posBotEsp_Y);
	m_qBoto[0].mostra(posBotoPlay_X, posBotoPlay_Y);
	m_scores.mostra(posBotoScores_X, posBotoScores_Y);
	//detecta pulasacions per canviar de llengua--------------------------------------------
	if (m_rBoto[0].Selecciona(mousePosX, mousePosY))
	{
		m_rBoto[1].setEstat(0);
		m_rBoto[2].setEstat(0);
	}

	if (m_rBoto[1].Selecciona(mousePosX, mousePosY))
	{
		m_rBoto[0].setEstat(0);
		m_rBoto[2].setEstat(0);
	}

	if (m_rBoto[2].Selecciona(mousePosX, mousePosY))
	{
		m_rBoto[0].setEstat(0);
		m_rBoto[1].setEstat(0);
	}

	if (m_scores.Pressiona(mousePosX, mousePosY)) {
		m_menuAnt=m_menu;
		m_menu = 4;
	}
	//detecta pulsacions del boto start--------------------------------------------
	if ((m_qBoto[0].Pressiona(mousePosX, mousePosY)))
	{
		if (m_rBoto[0].getEstat() || m_rBoto[1].getEstat() || m_rBoto[2].getEstat())
		{
			m_menu = 2;
			m_dic.llegeixDiccionari(m_rBoto[0].getEstat(),m_rBoto[1].getEstat(),m_rBoto[2].getEstat());
			m_rBoto[0].setEstat(0);
			m_rBoto[1].setEstat(0);
			m_rBoto[2].setEstat(0);
		}
	}
	//printa les lletres-------------------------------------------------------------------
	b.draw(170, 250, NFont::Scale(1.0f), "START");
	b.draw(70, 85, NFont::Scale(0.6f), "CATALA");
	b.draw(70, 145, NFont::Scale(0.6f), "ENGLISH");
	b.draw(70, 205, NFont::Scale(0.6f), "ESPANOL");
}

void Game::Juga(const int& mousePosX, const int& mousePosY)
{
	//declara les fonts--------------------------------------------------------------------------------------------------
	NFont b("data/Fonts/FreeSans.ttf", 44, NFont::Color(255, 255, 255, 255));
	NFont n("data/Fonts/FreeSans.ttf", 22, NFont::Color(0, 0, 0, 255));
	//mostra elements de la pantalla-------------------------------------------------------------------------------------
	
	m_fons.draw(0, 0);
	m_fonsJoc.draw(0, 0);

	m_surt.mostra(posBotoSurt_X, posBotoSurt_Y);
	m_temps.draw(posCrono_X, posCrono_Y);
	m_qBoto[1].mostra(posBotoCheck_X, posBotoCheck_Y);
	m_pause.mostra(posBotoPause_X, posBotoPause_Y);

	if (!m_pausat) {
		//calcula velocitat, escull unal lletra , comprova els clicks al tauler i mostra la paraula candidata------------
		m_t.velocitat(m_crono);
		m_t.treuLletra(m_dt);
		m_t.comprovaTauler(mousePosX, mousePosY);
		m_t.mostraParaula();
		//esborra la paraula candidata si es vol-------------------------------------------------------------------------
		if (m_surt.Pressiona(mousePosX, mousePosY))
		{
			m_t.esborraParaula();
		}
		//comprova la paraula candidata si es vol------------------------------------------------------------------------
		if (m_qBoto[1].Pressiona(mousePosX, mousePosY))
		{
			string paraula_correcta;
			bool res = m_t.comprovaParaula(m_dic, paraula_correcta);
			
			//sistema de puntuacio per partida;--------------------------------------------------------------------------
			if (res)
			{
				calculaPuntuacio(paraula_correcta);
				m_nParaules++;
			}
		}
	}
	//pausa el joc si s'ha seleccionat-----------------------------------------------------------------------------------
	if (m_pause.Selecciona(mousePosX, mousePosY))
	{
		m_pausat = m_pause.getEstat();
	}

	//printa paraules-----------------------------------------------------------------------------------------------------
	n.draw(250, 40, NFont::Scale(1.0f), "%d", (int)m_crono);
	b.draw(155, 760, NFont::Scale(1.0f), "CHECK");
	//canvia i reestableix la pantalla del joc----------------------------------------------------------------------------
	
	if (m_t.getNCasLliures() == 0) {
		
		m_t.esborraTauler();
		m_t.esborraParaula();
		m_menu = 3;
		m_pausat = 0;
		m_crono = (0.0f);
		m_dic.esborraDiccionari();
	}
}

void Game::Final(const int& mousePosX, const int& mousePosY)
{
	//declara les fonts---------------------------------------------------------------------------------------------
	NFont b("data/Fonts/FreeSans.ttf", 44, NFont::Color(255, 255, 255, 255));
	NFont n("data/Fonts/FreeSans.ttf", 30, NFont::Color(0, 0, 0, 255));
	//pinta els elments de la pantalla------------------------------------------------------------------------------
	m_fons.draw(0, 0);
	m_fonsFinal.draw(0, 0);

	m_qBoto[2].mostra(posBotoReplay_X, posBotoReplay_Y);
	m_scores.mostra(posBotoScores_X, posBotoScores_Y);

	int p1, p2, p3, np1, np2, np3;
	bool H_Score;
	llegeixPuntuacio(p1, p2, p3, np1, np2, np3);
	H_Score = desaPuntuacio(p1, p2, p3, np1, np2, np3);

	//canvia la pantalla si es vol tornar a jugar-------------------------------------------------------------------
	if (m_qBoto[2].Pressiona(mousePosX, mousePosY)){
		m_menu = 1;
		m_punts = 0;
		m_nParaules = 0;
	}

	if (m_scores.Pressiona(mousePosX, mousePosY)) {
		m_menuAnt=m_menu;
		m_menu = 4;
	}
	//mostra les fonts----------------------------------------------------------------------------------------------
	b.draw(145, 760, NFont::Scale(1.00f), "REPLAY");
	n.draw(180, 500, NFont::Scale(1.00f), "Total: %d", (int)m_punts);
	
	if (H_Score) {
		n.draw(120, 650, NFont::Scale(1.00f), "NEW HIGH SCORE!!!");
	}
}

void Game::Scores(const int& mousePosX, const int& mousePosY) {
	NFont n("data/Fonts/FreeSans.ttf", 22, NFont::Color(0, 0, 0, 255));

	m_fons.draw(0, 0);
	
	m_surt.mostra(posBotoSurt2_X, posBotoSurt2_Y);

	if (m_surt.Selecciona(mousePosX, mousePosY)) {
		
		m_menu = m_menuAnt;
	}
	int p1, p2, p3, np1, np2, np3;

	llegeixPuntuacio(p1, p2, p3, np1, np2, np3);
	//mostra el ranking de puntuació---------------------------------------------------------------------------------------
	n.draw(130, 100, NFont::Scale(1.45f), "Punts");
	n.draw(250, 100, NFont::Scale(1.45f), "N. Paraules");
	n.draw(50, 100, NFont::Scale(1.45f), "Pos.");
	n.draw(65, 200, NFont::Scale(1.45f), "1-");
	n.draw(65, 400, NFont::Scale(1.45f), "2-");
	n.draw(65, 600, NFont::Scale(1.45f), "3-");
	n.draw(140, 200, NFont::Scale(1.45f), "%d",(int)p1);
	n.draw(140, 400, NFont::Scale(1.45f), "%d", (int)p2);
	n.draw(140, 600, NFont::Scale(1.45f), "%d", (int)p3);
	n.draw(325, 200, NFont::Scale(1.45f), "%d", (int)np1);
	n.draw(325, 400, NFont::Scale(1.45f), "%d", (int)np2);
	n.draw(325, 600, NFont::Scale(1.45f), "%d", (int)np3);
}
//canvia la pantalla que s'ha de mostrar-----------------------------------------------------------------------------------
void Game::actualitza(const int& mousePosX, const int& mousePosY)
{
	switch (m_menu)
	{
	case 1:
	{
		Inici(mousePosX, mousePosY);
	}
	break;
	case 2:
	{
		Juga(mousePosX, mousePosY);
	}
	break;
	case 3:
	{
		Final(mousePosX, mousePosY);
	}
	break;
	case 4:
	{
		Scores(mousePosX, mousePosY);
	}
	}
}
//compta el temps----------------------------------------------------------------------------------------------------------
void Game::timer(Uint64& NOW, Uint64& LAST)
{
	LAST = NOW;
	NOW = SDL_GetPerformanceCounter();
	m_dt = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
	//suma temps si no esta pausat-----------------------------------------------------------------------------------------
	if (m_menu == 2&&!m_pausat)
	{
		m_crono += m_dt;
	}
}
//funcions que tracten la puntuació----------------------------------------------------------------------------------------
bool Game::desaPuntuacio(int& p1, int& p2, int& p3, int& np1, int& np2, int& np3) {
	//ordena les puntuacions per ordre-------------------------------------------------------------------------------------
	bool hScore = false;
	if (m_punts > p1) {
		
		p3 = p2;
		np3 = np2;
		p2 = p1;
		np2 = np1;
		p1 = m_punts;
		np1 = m_nParaules;
		hScore = true;
	}
	else
	{
		if (m_punts > p2) {
			p3 = p2;
			np3 = np2;
			p2 = m_punts;
			np2 = m_nParaules;
			
		}
		else
		{
			if (m_punts>p3)
			{
				p3 = m_punts;
				np3 = m_nParaules;
				
			}
		}
	}
	
	
	ofstream fitxer;
	string puntuacions = "Scores.txt";
	fitxer.open(puntuacions);

	if (fitxer.is_open()) {
		
		fitxer << p1 << endl;
		fitxer << np1 << endl;
		fitxer << p2 << endl;
		fitxer << np2 << endl;
		fitxer << p3 << endl;
		fitxer << np3 << endl;

		fitxer.close();
	}
	return hScore;
}

void Game::llegeixPuntuacio(int& p1, int& p2, int& p3, int& np1, int& np2, int& np3) {
	//llegeix la puntuació de l'arxiu Score.txt----------------------------------------------------------------------------
	ifstream fitxer;
	string f = "Scores.txt";
	fitxer.open(f);
	if (fitxer.is_open()) {
		fitxer >> p1;	
		fitxer >> np1;
		fitxer >> p2;
		fitxer >> np2;
		fitxer >> p3;
		fitxer >> np3;
	}
}

void Game::calculaPuntuacio(const string& paraula_correcta) {
	//calcula la puntuació segons les dimensions de la paraula-------------------------------------------------------------
	m_punts += paraula_correcta.size() * 10;
	if (paraula_correcta.size() == MAX_PARAULA) {
		m_punts += 20;
	}
	else {
		if (paraula_correcta.size() >= MAX_PARAULA / 4 && paraula_correcta.size() < MAX_PARAULA / 2) {
			m_punts += 3;
		}
		else {
			if (paraula_correcta.size() >= MAX_PARAULA / 2 && paraula_correcta.size() < 3 * MAX_PARAULA / 4) {
				m_punts += 5;
			}
			else
			{
				if (paraula_correcta.size() >= 3 * MAX_PARAULA / 4 && paraula_correcta.size() < MAX_PARAULA) {
					m_punts += 8;
				}
			}
		}
	}
}
