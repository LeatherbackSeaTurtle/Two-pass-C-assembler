#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <regex>
#include <vector>

#include "relokacije.h"
#include "sekcija.h"

using namespace std;

class Instrukcije {
public:
	static int broj_bajtova(string l);
	static int kod_instrukcije(string l, Sekcija* trenutna_sekcija, vector<Sekcija*>& sekcije, int brojac_lokacija, int sl_adr);

	static int adresiranje_2B_1op(string l, Sekcija* trenutna_sekcija, vector<Sekcija*>& sekcije, int brojac_lokacija, int uslov, int sl_adr);
	static int adresiranje_2B_2op(string l, Sekcija* trenutna_sekcija, vector<Sekcija*>& sekcije, int brojac_lokacija, int uslov, int sl_adr);

	static int adresiranje_1B_1op(string l, Sekcija* trenutna_sekcija, vector<Sekcija*>& sekcije, int brojac_lokacija, int uslov, int sl_adr);
	static int adresiranje_1B_2op(string l, Sekcija* trenutna_sekcija, vector<Sekcija*>& sekcije, int brojac_lokacija, int uslov, int sl_adr);

	static string linija;
	static regex reg;
	static smatch match;
};


