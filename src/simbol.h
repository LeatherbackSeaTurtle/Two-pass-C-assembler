#pragma once

#include <iostream>
#include <string>

using namespace std;

class Simbol {
public:
	//Simbol() {}

	Simbol(string i, int r_b, int v) : ime(i), redni_broj(r_b), vrednost(v) {
		vidljivost = 'l';
	}



	string ime;
	int vrednost;
	char vidljivost;
	int redni_broj;
};