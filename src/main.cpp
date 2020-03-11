#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include <iomanip>

#include "asembler.h"

using namespace std;

int main(int argc, char** argv) {

	Asembler* as = new Asembler("ulaz.txt");
	as->prvi_prolaz();
	as->drugi_prolaz();
	as->ispisi();

	return 0;
}

