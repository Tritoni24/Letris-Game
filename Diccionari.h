#include<vector>
#include<string>
#include <fstream>;

using namespace std;

#define MAX_PARAULA 8

class Diccionari {
public:
	Diccionari() {};
	~Diccionari() {};
	//carrega el diccionari a la memoria
	void llegeixDiccionari(const bool& c, const bool& e, const bool& s);
	//cerca una paraula en le diccionari carregat
	bool cercaParaula(const string& p);
	//esborra el diccionari de la memoria
	void esborraDiccionari();
private:
	vector<string> m_d;
};
