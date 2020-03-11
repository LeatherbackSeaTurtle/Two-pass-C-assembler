#pragma once

#include <string>

using namespace std;

class Relokacija {
public:

	Relokacija(string o, string t, int v) : offset(o), tip(t), vrednost(v) {}

	string offset;
	string tip;
	int vrednost;
};