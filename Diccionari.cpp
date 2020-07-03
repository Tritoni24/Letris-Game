#include "Diccionari.h"

void Diccionari::llegeixDiccionari(const bool& c, const bool& e, const bool& s) {

	ifstream fitxer;
	//selecciona el diccionari escollit-------------------------------------------------------------------------------------------------------------------------------
	string nFitxer;
	if (c) {
		nFitxer = "data/Dictionaries/Catalan.dic";
	}
	else
	{
		if (e)
		{
			nFitxer = "data/Dictionaries/English.dic";
		}
		else
		{
			if (s) {
				nFitxer = "data/Dictionaries/Spanish.dic";
			}
		}
	}

	fitxer.open(nFitxer);

	if (fitxer.is_open()) {
		string paraula;
		bool noFicar = false;
		while (!fitxer.eof())
		{
			//carrega el diccionari en memoria excepte els elements dels que no tenim un sprite-----------------------------------------------------------------
			fitxer >> paraula;
			if (paraula.size() <= MAX_PARAULA) {
				for (int i = 0; (paraula[i] != '\0' && !noFicar); i++) {
					if (paraula[i] ==-73/*·*/ || paraula[i] == -15/*ñ*/ || paraula[i] == -25/*ç*/ || paraula[i] == 46/*.*/ || paraula[i] == 45/*-*/ || paraula[i] == 39/*'*/) {
						noFicar = true;
					}
				}
				
				if (!noFicar) {
					m_d.push_back(paraula);
				}
				else {
					noFicar = false;
				}

			}
		}

		fitxer.close();
	}
}

bool Diccionari::cercaParaula(const string& p) {
	
	bool trobat = false;

	vector<string>::iterator actual = m_d.begin();
	vector<string>::iterator final = m_d.end();
	//cerca la paraula passada per paràmetre en el diccionari-----------------------------------------------------------------------------------------------------
	while (actual != final && !trobat) {

		if (*actual== p) {
			
			trobat = true;
			m_d.erase(actual);
		}
		else
		{
			actual++;
		}
	}

	return trobat;
}

void Diccionari::esborraDiccionari() {
	//esborra tot el vector del diccionari--------------------------------------------------------------------------------------------------------------------------
	m_d.clear();
}
