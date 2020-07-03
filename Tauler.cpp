#include "Tauler.h"
using namespace std;

Tauler::Tauler() {

	m_casLliuresTauler = MAX_TAULER;
	m_casLliuresParaula = MAX_PARAULA;
	m_colCaient = 0;
	m_lletraCaient = 0;
	m_xCaient = INICI_TAULER_X;
	m_yCaient = INICI_TAULER_Y;
	m_lletraCau = 0;
	m_temps = 0;
	m_velocitat = 3;

	const char lletresBlanques[26][28] = {
		"./data/Letters/white_0.png",
		"./data/Letters/white_1.png",
		"./data/Letters/white_2.png",
		"./data/Letters/white_3.png",
		"./data/Letters/white_4.png",
		"./data/Letters/white_5.png",
		"./data/Letters/white_6.png",
		"./data/Letters/white_7.png",
		"./data/Letters/white_8.png",
		"./data/Letters/white_9.png",
		"./data/Letters/white_10.png",
		"./data/Letters/white_11.png",
		"./data/Letters/white_12.png",
		"./data/Letters/white_13.png",
		"./data/Letters/white_14.png",
		"./data/Letters/white_15.png",
		"./data/Letters/white_16.png",
		"./data/Letters/white_17.png",
		"./data/Letters/white_18.png",
		"./data/Letters/white_19.png",
		"./data/Letters/white_20.png",
		"./data/Letters/white_21.png",
		"./data/Letters/white_22.png",
		"./data/Letters/white_23.png",
		"./data/Letters/white_24.png",
		"./data/Letters/white_25.png"
	};

	const char lletresGrogues[26][29]{
		"./data/Letters/yellow_0.png",
		"./data/Letters/yellow_1.png",
		"./data/Letters/yellow_2.png",
		"./data/Letters/yellow_3.png",
		"./data/Letters/yellow_4.png",
		"./data/Letters/yellow_5.png",
		"./data/Letters/yellow_6.png",
		"./data/Letters/yellow_7.png",
		"./data/Letters/yellow_8.png",
		"./data/Letters/yellow_9.png",
		"./data/Letters/yellow_10.png",
		"./data/Letters/yellow_11.png",
		"./data/Letters/yellow_12.png",
		"./data/Letters/yellow_13.png",
		"./data/Letters/yellow_14.png",
		"./data/Letters/yellow_15.png",
		"./data/Letters/yellow_16.png",
		"./data/Letters/yellow_17.png",
		"./data/Letters/yellow_18.png",
		"./data/Letters/yellow_19.png",
		"./data/Letters/yellow_20.png",
		"./data/Letters/yellow_21.png",
		"./data/Letters/yellow_22.png",
		"./data/Letters/yellow_23.png",
		"./data/Letters/yellow_24.png",
		"./data/Letters/yellow_25.png"
	};

	for (int i = 0; i < 26; i++) {
		m_lletresBlanques[i].create(lletresBlanques[i]);
		m_lletresGrogues[i].create(lletresGrogues[i]);

		switch (i)
		{
		case 0: {
			m_abcdari[i].setValor(97);
			m_abcdari[i].setNAlfabet(0);
		}break;
		case 1: {
			m_abcdari[i].setValor(101);
			m_abcdari[i].setNAlfabet(4);
		}break;
		case 2: {
			m_abcdari[i].setValor(105);
			m_abcdari[i].setNAlfabet(8);
		}break;
		case 3: {
			m_abcdari[i].setValor(111);
			m_abcdari[i].setNAlfabet(14);
		}break;
		case 4: {
			m_abcdari[i].setValor(117);
			m_abcdari[i].setNAlfabet(20);
		}break;
		case 5: {
			m_abcdari[i].setValor(98);
			m_abcdari[i].setNAlfabet(1);
		}break;
		case 6: {
			m_abcdari[i].setValor(99);
			m_abcdari[i].setNAlfabet(2);
		}break;
		case 7: {
			m_abcdari[i].setValor(100);
			m_abcdari[i].setNAlfabet(3);
		}break;
		case 8: {
			m_abcdari[i].setValor(102);
			m_abcdari[i].setNAlfabet(5);
		}break;
		case 9: {
			m_abcdari[i].setValor(103);
			m_abcdari[i].setNAlfabet(6);
		}break;
		case 10: {
			m_abcdari[i].setValor(104);
			m_abcdari[i].setNAlfabet(7);
		}break;
		case 11: {
			m_abcdari[i].setValor(106);
			m_abcdari[i].setNAlfabet(9);
		}break;
		case 12: {
			m_abcdari[i].setValor(107);
			m_abcdari[i].setNAlfabet(10);
		}break;
		case 13: {
			m_abcdari[i].setValor(108);
			m_abcdari[i].setNAlfabet(11);
		}break;
		case 14: {
			m_abcdari[i].setValor(109);
			m_abcdari[i].setNAlfabet(12);
		}break;
		case15: {
			m_abcdari[i].setValor(110);
			m_abcdari[i].setNAlfabet(13);
		}break;
		case 16: {
			m_abcdari[i].setValor(112);
			m_abcdari[i].setNAlfabet(15);
		}break;
		case 17: {
			m_abcdari[i].setValor(113);
			m_abcdari[i].setNAlfabet(16);
		}break;
		case 18: {
			m_abcdari[i].setValor(114);
			m_abcdari[i].setNAlfabet(17);
		}break;
		case 19: {
			m_abcdari[i].setValor(115);
			m_abcdari[i].setNAlfabet(18);
		}break;
		case 20: {
			m_abcdari[i].setValor(116);
			m_abcdari[i].setNAlfabet(19);
		}break;
		case 21: {
			m_abcdari[i].setValor(118);
			m_abcdari[i].setNAlfabet(21);
		}break;
		case 22: {
			m_abcdari[i].setValor(119);
			m_abcdari[i].setNAlfabet(22);
		}break;
		case 23: {
			m_abcdari[i].setValor(120);
			m_abcdari[i].setNAlfabet(23);
		}break;
		case 24: {
			m_abcdari[i].setValor(121);
			m_abcdari[i].setNAlfabet(24);
		}break;
		case 25: {
			m_abcdari[i].setValor(122);
			m_abcdari[i].setNAlfabet(25);
		}break;
		};
	}
}

Tauler::~Tauler() {
	m_temps = m_velocitat = m_casLliuresParaula = m_lletraCau = m_xCaient = m_yCaient = m_colCaient = m_casLliuresTauler = 0;
	for (int i = 0; i < 26; i++)
	{
		m_abcdari[i].~Lletra();
		m_lletresBlanques[i].~Sprite();
		m_lletresGrogues[i].~Sprite();
	}
}

int Tauler::seleccionaCol() const {
	int min = MAX_FILES, next ;
	
	for (int i = 0; i < MAX_COLUMNES; i++)
	{
		//busca la columna amb menys elements----------------------------------------------------------------------
		if (m_tauler[i].size() < min) {
			min = m_tauler[i].size();
			next = i;
		}
	}
	
	return next;
}

void Tauler::mostraTauler() {

	for(int i = 0; i < MAX_COLUMNES; i++)
	{
		int j = 0;
		//dibuixa les lletres segons el seu estat--------------------------------------------------------------------------------
		while (j<m_tauler[i].size()) {
			if (!m_tauler[i][j].getEstat()) {
				m_lletresBlanques[m_tauler[i][j].getNAlfabet()].draw(INICI_TAULER_X + i * 51, FINAL_TAULER_Y - j * 51);
			}
			else
			{
				m_lletresGrogues[m_tauler[i][j].getNAlfabet()].draw(INICI_TAULER_X + i * 51, FINAL_TAULER_Y - j * 51);
			}
			j++;
		}
	}
}

void Tauler::treuLletra(double& dt ) {
	
	if (m_casLliuresTauler > 0) {
		
		if (!m_lletraCaient) {
			//si no cau cap lletra en treu una a l'atzar-----------------------------------------------------------
			m_lletraCaient = !m_lletraCaient;
			m_colCaient = seleccionaCol();
			int n = rand() % 100;
			if (n <= 30) {
				m_lletraCau = rand() % 5;
			}
			else
			{
				m_lletraCau = 5 + rand() % (21);
			}
			m_xCaient = INICI_TAULER_X + 51 * m_colCaient;
			m_yCaient = INICI_TAULER_Y;
			m_lletresBlanques[m_abcdari[m_lletraCau].getNAlfabet()].draw(m_xCaient, m_yCaient);
		}
		else
		{
			if (m_yCaient >= FINAL_TAULER_Y - 51 *( m_tauler[m_colCaient].size()))
			{
				//si la lletra ha arribat a la posicio la guarda al vector----------------------------------------------
				m_lletraCaient=!m_lletraCaient;
				m_tauler[m_colCaient].push_back(m_abcdari[m_lletraCau]);
				m_casLliuresTauler--;
			}
			else
			{
				//actualitza la posicio de la lletra que cau-------------------------------------------------------------
				m_yCaient += dt * m_velocitat;
				m_lletresBlanques[m_abcdari[m_lletraCau].getNAlfabet()].draw(m_xCaient, m_yCaient);

			}
		}
	}
	//mostra el tauler de lletres-----------------------------------------------------------------------------------------
	mostraTauler();

}

void Tauler::velocitat(float& time) {
	//calcula la velocitat segons el temps pasat--------------------------------------------------------------------
	m_velocitat = VELOCITAT_INICIAL + 5 * time / 10;
}

void Tauler::comprovaTauler(const int& xMouse, const int& yMouse) {
	for (int i = 0; i < MAX_COLUMNES; i++)
	{
		int j = 0;
		
		while (j<m_tauler[i].size())
		{
			//mira si algunalletra ha estat presionada-------------------------------------------------------------------
			if (m_casLliuresParaula > 0 && !m_tauler[i][j].getEstat() && m_tauler[i][j].Selecciona(xMouse, yMouse,
				INICI_TAULER_X + i * 51, FINAL_TAULER_Y - j * 51)) {
				//afegeix les lletres presionades a la paraula candidata--------------------------------------------------
				m_paraula.push_back(m_tauler[i][j]);
				m_casLliuresParaula--;
			}
			j++;
		}
	}
}

void Tauler::esborraTauler() {
	
	for (int i = 0; i < MAX_COLUMNES; i++)
	{
		//neteja tot el tauler-------------------------------------------------------------------------------------
		m_tauler[i].clear();
	}
	//torna el nombre de caselles lliures al màxim-------------------------------------------------------------------
	m_casLliuresTauler = MAX_TAULER;
}

void Tauler::mostraParaula() {
	int j = 0;
	
	while (j<m_paraula.size())
	{
		//pinta totes les lletres de les de la paraula candidata-------------------------------------------------------
		m_lletresBlanques[m_paraula[j].getNAlfabet()].draw(INICI_PARAULA_X + j * 51, INICI_PARAULA_Y);
		
		j++;
	}
}

void Tauler::esborraParaula() {
	//neteja la paraula candidata--------------------------------------------------------------------------------------------
	m_paraula.clear();
	m_casLliuresParaula = MAX_PARAULA;
	
	for (int i = 0; i < MAX_COLUMNES; i++) {
		int j = 0;
		
		while (j<m_tauler[i].size()) {
			
			if (m_tauler[i][j].getEstat()) {
				//desselecciona les lletres de tauler---------------------------------------------------------------
				m_tauler[i][j].setEstat(0);
				
			}
			j++;
		}
	}
}

bool Tauler::comprovaParaula(Diccionari& d, string& paraula_correcta) {
	
	if (!m_paraula.empty()) {
		string paraula_formada;
		for (int i = 0; i < m_paraula.size(); i++)
		{
			//converteix les lletres en un string--------------------------------------------------------------------
			paraula_formada.push_back(m_paraula[i].getValor());
		}
		//comprova si la paraula esta al diccionari--------------------------------------------------------------------
		bool correcte=d.cercaParaula(paraula_formada);

		if (correcte) {
			//retorna la paraula correcta per parametre--------------------------------------------------------------------------
			paraula_correcta = paraula_formada;

			//elimina les lletres seleccionades del tauler----------------------------------------------------------------
			for (int i = 0; i < MAX_COLUMNES; i++) {
				
				vector<Lletra>::iterator actual = m_tauler[i].begin();
				vector<Lletra>::iterator final = m_tauler[i].end();
		
				while (actual != final) {
					
					if (actual->getEstat()) {
						m_tauler[i].erase(actual);
						m_casLliuresTauler++;
						actual = m_tauler[i].begin();
						final = m_tauler[i].end();
					}
					else
					{
						actual++;
					}
				}
			}
			//esborra la paraula----------------------------------------------------------------------------------------
			esborraParaula();
		}
		return  correcte;
	}
	else
	{
		//si no hi ha lletres o la paraula no existeix retorna false---------------------------------------------------------
		return false;
	}
}