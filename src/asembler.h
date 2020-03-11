#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <sstream>

#include "simbol.h"
#include "sekcija.h"
#include "instrukcije.h"
#include "relokacije.h"

using namespace std;

class Asembler {
public:
	Asembler(const char* dat);

	void prvi_prolaz();
	void drugi_prolaz();
	void ispisi();

	string datoteka;

	string linija;
	regex reg;
	smatch match;

	int brojac_lokacija;

	bool uspesno;
	string greska;

	ifstream ulaz;
	ofstream izlaz;

	vector<Sekcija*> sekcije;
	Sekcija* trenutna_sekcija;
	Simbol* novi_simbol;
};
