#pragma once


#include <iostream>
#include <string>
#include <vector>

#include "simbol.h"
#include "relokacije.h"

using namespace std;

class Sekcija {
public:
	static int R_BR;

	Sekcija() {
		ime = "";
		ime_sekcije = "";
		vrednost = 0;
		vidljivost = 'l';
		redni_broj = R_BR++;
		simboli = {};
		kod = {};
	}

	Sekcija(string ime, string ime_sekcije) : ime(ime), ime_sekcije(ime_sekcije) {
		vidljivost = 'l';
		vrednost = 0;
		redni_broj = R_BR++;
		simboli = {};
		kod = {};
	}


	string ime;
	string ime_sekcije;
	int vrednost;
	char vidljivost;
	int redni_broj;

	vector<Simbol*> simboli;
	vector<string> kod;
	vector<Relokacija*> relokacije;
};