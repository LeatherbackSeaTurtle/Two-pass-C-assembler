#include "asembler.h"

using namespace std;

Asembler::Asembler(const char* dat) {
	linija = "";
	greska = "";
	brojac_lokacija = 0;
	uspesno = true;
	datoteka = dat;
	sekcije = {};
	trenutna_sekcija = new Sekcija("", "UND");
	sekcije.push_back(trenutna_sekcija);
	trenutna_sekcija = nullptr;
	novi_simbol = nullptr;
}

void Asembler::prvi_prolaz() {

	if (!uspesno) return;

	ulaz.open(datoteka);
	if (!ulaz.is_open()) {
		cout << "Datoteka nije otvorena";
		uspesno = false;
		return;
	}

	while (!ulaz.eof()) {
		getline(ulaz, linija);
		greska = linija;

		reg.assign("^\\s*");
		linija = regex_replace(linija, reg, "");

		//Prazan red
		if (linija.empty()) continue;

		string pom;

		//.global
		reg.assign("^\\.global\\s+[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			continue;
		}

		//.extern
		reg.assign("^\\.extern\\s+[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			continue;
		}

		//Sekcija text, data i bss
		reg.assign("^(\\.text|\\.data|\\.bss)");
		if (regex_search(linija, match, reg)) {
			pom = match.str(0);
			brojac_lokacija = 0;
			trenutna_sekcija = new Sekcija(pom, pom);
			pom = pom.erase(0,1);
			trenutna_sekcija->ime_sekcije = pom;
			sekcije.push_back(trenutna_sekcija);
			continue;
		}

		//sekcija section
		reg.assign("^\\.section\\s+[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			pom = match.str(0);
			brojac_lokacija = 0;
			reg.assign("^\\.section\\s+");
			pom = regex_replace(pom, reg, "");
			trenutna_sekcija = new Sekcija(pom, pom);
			pom = "." + pom;
			trenutna_sekcija->ime = pom;
			sekcije.push_back(trenutna_sekcija);
			continue;
		}

		//Labela
		reg.assign("^[a-zA-Z_]+\\w*:");
		if (regex_search(linija, match, reg)) {
			//ako je simbol definisan van sekcije
			if (trenutna_sekcija == sekcije[0]) {
				cout << "Simbol definisan van sekcije";
				uspesno = false;
				break;
			}

			//obrisi : na kraju
			pom = match.str(0);
			pom.erase(pom.length() - 1);

			//obrisi sve pre znaka : (i taj znak) unutar linije i sve bele znakove posle
			linija = match.suffix().str();
			reg.assign("^\\s*");
			linija = regex_replace(linija, reg, "");

			//ubaci simbol u datu sekciju
			novi_simbol = new Simbol(pom, trenutna_sekcija->R_BR++, brojac_lokacija);
			trenutna_sekcija->simboli.push_back(novi_simbol);

			//ako je ostatak linije prazan ucitaj novu
			if (linija.empty()) continue;
		}

		//.equ
		reg.assign("^\\.equ\\s+[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			pom = match.str(0);
			linija = match.suffix().str();
			reg.assign("^\\.equ\\s+");
			pom = regex_replace(pom, reg, "");

			reg.assign("^,\\s*-?\\d+");
			if (regex_search(linija, match, reg)) {
				string vr = match.str(0);
				reg.assign("^,\\s*");
				vr = regex_replace(vr, reg, "");
				int vred = stoi(vr);
				novi_simbol = new Simbol(pom, trenutna_sekcija->R_BR++, vred);
				trenutna_sekcija->simboli.push_back(novi_simbol);
			}
			else {
				cout << "Potrebno je definisati vrednost za simbol : " + pom;
				uspesno = false;
				break;
			}

			continue;
		}

		//byte
		reg.assign("^\\.byte\\s+[a-zA-Z0-9]+");
		if (regex_search(linija, match, reg)) {
			if (trenutna_sekcija == sekcije[0]) {
				cout << "Direktiva byte mora biti definisana unutar sekcije";
				uspesno = false;
				break;
			}
			brojac_lokacija += 1;
			continue;
		}

		//word
		reg.assign("^\\.word\\s+[a-zA-Z0-9]+");
		if (regex_search(linija, match, reg)) {
			if (trenutna_sekcija == sekcije[0]) {
				cout << "Direktiva word mora biti definisana unutar sekcije";
				uspesno = false;
				break;
			}
			brojac_lokacija += 2;
			continue;
		}
		//align
		reg.assign("^\\.align\\s+\\d+");
		if (regex_search(linija, match, reg)) {
			if (trenutna_sekcija == sekcije[0]) {
				cout << "Direktiva align mora biti definisana unutar sekcije";
				uspesno = false;
				break;
			}
			pom = match.str(0);
			reg.assign("^\\.align\\s+");
			pom = regex_replace(pom, reg, "");
			int i = stoi(pom); //stoi - string to integer
			i = pow(2, i);
			if (brojac_lokacija % i != 0) {
				brojac_lokacija += (i - (brojac_lokacija % i));
			}
			continue;
		}

		//skip
		reg.assign("^\\.skip\\s+\\d+");
		if (regex_search(linija, match, reg)) {
			if (trenutna_sekcija == sekcije[0]) {
				cout << "Direktiva skip mora biti definisana unutar sekcije";
				uspesno = false;
				break;
			}
			pom = match.str(0);
			reg.assign("^\\.skip\\s+");
			pom = regex_replace(pom, reg, "");
			int i = stoi(pom);
			brojac_lokacija += i;
			continue;
		}
		//instrukcija
		int n = Instrukcije::broj_bajtova(linija);
		if (n > 0) { 
			if (trenutna_sekcija == sekcije[0]) {
				cout << "Instrukcija mora biti definisana unutar sekcije";
				uspesno = false;
				break;
			}
			brojac_lokacija += n;
		}

		//.end
		reg.assign("^\\.end");
		if (regex_search(linija, match, reg)) {

			break;
		}
	}

	ulaz.close();
}

void Asembler::drugi_prolaz() {
	if (!uspesno) return;
	trenutna_sekcija = sekcije[0];

	ulaz.open(datoteka);
	if (!ulaz.is_open()) {
		cout << "Datoteka nije otvorena";
		uspesno = false;
		return;
	}

	while (!ulaz.eof()) {

		getline(ulaz, linija);
		greska = linija;

		reg.assign("^\\s*");
		linija = regex_replace(linija, reg, "");

		//Prazan red
		if (linija.empty()) continue;

		string pom;

		//.global
		reg.assign("^\\.global\\s+[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			pom = match.str(0);
			linija = match.suffix().str();
			reg.assign("^\\.global\\s+");
			pom = regex_replace(pom, reg, "");
			bool uspeh = false;
			Sekcija* pom_sekcija = nullptr;
			Simbol* pom_simbol = nullptr;
			for (int i = 1; i < sekcije.size(); i++) {
				pom_sekcija = sekcije[i];
				for (int j = 0; j < pom_sekcija->simboli.size(); j++) {
					pom_simbol = pom_sekcija->simboli[j];
					if (pom_simbol->ime == pom) {
						pom_simbol->vidljivost = 'g';
						uspeh = true;
						break;
					}
				}
				if (uspeh) break;
			}
			if (!uspeh) {
				cout << "Simbol: " + pom + " nije definisan pa ne moze da postane globalni!";
				uspesno = false;
				break;
			}
			while (true) {
				reg.assign("^,\\s*[a-zA-Z_]+\\w*\\s*");
				if (regex_search(linija, match, reg)) {
					pom = match.str(0);
					pom.erase(0,1);
					linija = match.suffix().str();
					reg.assign("\\s*");
					pom = regex_replace(pom, reg, "");
					uspeh = false;
					for (int i = 1; i < sekcije.size(); i++) {
						pom_sekcija = sekcije[i];
						for (int j = 0; j < pom_sekcija->simboli.size(); j++) {
							pom_simbol = pom_sekcija->simboli[j];
							if (pom_simbol->ime == pom) {
								pom_simbol->vidljivost = 'g';
								uspeh = true;
								break;
							}
						}
						if (uspeh) break;
					}
					if (!uspeh) {
						cout << "Simbol: " + pom + " nije definisan pa ne moze da postane globalni!";
						uspesno = false;
						break;
					}
				}
				else {
					break;
				}
			}
			continue;
		}

		//.extern
		reg.assign("^\\.extern\\s+[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			pom = match.str(0);
			linija = match.suffix().str();
			reg.assign("^\\.extern\\s+");
			pom = regex_replace(pom, reg, "");
			novi_simbol = new Simbol(pom, Sekcija::R_BR++, 0);
			novi_simbol->vidljivost = 'g';
			sekcije[0]->simboli.push_back(novi_simbol);

			while (true) {
				reg.assign("^,\\s*[a-zA-Z_]+\\w*\\s*");
				if (regex_search(linija, match, reg)) {
					pom = match.str(0);
					pom.erase(0,1);
					linija = match.suffix().str();
					reg.assign("\\s*");
					pom = regex_replace(pom, reg, "");
					novi_simbol = new Simbol(pom, Sekcija::R_BR++, 0);
					novi_simbol->vidljivost = 'g';
					sekcije[0]->simboli.push_back(novi_simbol);

				}
				else {
					break;
				}
			}
			continue;
		}

		//Sekcija text, data i bss
		reg.assign("^(\\.text|\\.data|\\.bss)");
		if (regex_search(linija, match, reg)) {
			pom = match.str(0);
			brojac_lokacija = 0;
			for (int i = 1; i < sekcije.size(); i++) {
				if (sekcije[i]->ime == pom) {
					trenutna_sekcija = sekcije[i];
					break;
				}
			}
			continue;
		}

		//sekcija section
		reg.assign("^\\.section\\s+[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			pom = match.str(0);
			brojac_lokacija = 0;
			reg.assign("^\\.section\\s+");
			pom = regex_replace(pom, reg, "");
			for (int i = 1; i < sekcije.size(); i++) {
				if (sekcije[i]->ime_sekcije == pom) {
					trenutna_sekcija = sekcije[i];
					break;
				}
			}
			continue;
		}

		//labela
		reg.assign("^[a-zA-Z_]+\\w*:");
		if (regex_search(linija, match, reg)) {
			linija = match.suffix().str();
			reg.assign("^\\s*");
			linija = regex_replace(linija, reg, "");

			//ako je ostatak linije prazan ucitaj novu
			if (linija.empty()) continue;


		}

		//.equ
		reg.assign("^\\.equ\\s+[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			continue;
		}

		//byte
		reg.assign("^\\.byte\\s+([a-zA-Z_]+\\w*|-?\\d+)");
		if (regex_search(linija, match, reg)) {
			if (trenutna_sekcija == sekcije[0]) {
				cout << "Direktiva byte mora biti definisana unutar sekcije";
				uspesno = false;
				break;
			}
			int vred = 0;
			reg.assign("^\\.byte\\s+");
			linija = regex_replace(linija, reg, "");
			reg.assign("^-?\\d+");
			if (regex_search(linija, match, reg)) {
				pom = match.str(0);
				linija = match.suffix().str();
				vred = stoi(pom);
			}
			reg.assign("^[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				pom = match.str(0);
				linija = match.suffix().str();
				bool nadjen = false;
				int adr = 0;
				for (int i = 0; i < sekcije.size(); i++) {
					for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
						if (sekcije[i]->simboli[j]->ime == pom) {
							nadjen = true;
							string offset = "";
							adr = brojac_lokacija;
							offset = to_string(adr);
							string tip = "R_386_8";
							int vrednost = 0;
							if (sekcije[i]->simboli[j]->vidljivost == 'l') {
								vrednost = sekcije[i]->redni_broj;
								pom = to_string(sekcije[i]->simboli[j]->vrednost);
							}
							else {
								vrednost = sekcije[i]->simboli[j]->redni_broj;
								pom = "0";
							}
							Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
							trenutna_sekcija->relokacije.push_back(nova_relokacija);
							i = sekcije.size();
							break;
						}
					}
				}
				if (!nadjen) {
					cout << "Ne postoji simbol: " << pom << endl;
					uspesno = false;
					break;
				}
				vred = stoi(pom);
			}
			if (vred >= 127 || vred <= -128) {
				cout << "Prevelika vrednost za 1B kod direktive byte: " << greska << endl;
				uspesno = false;
				break;
			}
			stringstream sstream;
			if (vred >= 0) {
				sstream << std::setfill('0') << setw(2) << hex << vred;
			}
			else {
				vred = 256 + vred;
				sstream << setw(2) << hex << vred;
			}
			string pom = sstream.str();
			trenutna_sekcija->kod.push_back(pom);
			brojac_lokacija += 1;
			reg.assign("^\\s*");
			linija = regex_replace(linija, reg, "");
			bool nadjen = false;
			while (true) {
				reg.assign("^,\\s*-?\\d+\\s*");
				if (regex_search(linija, match, reg)) {
					pom = match.str(0);
					linija = match.suffix().str();
					pom.erase(0, 1);
					reg.assign("\\s*");
					pom = regex_replace(pom, reg, "");
					vred = stoi(pom);
					if (vred >= 127 || vred <= -128) {
						cout << "Prevelika vrednost za 1B kod direktive byte: " << greska << endl;
						uspesno = false;
						break;
					}
					stringstream sstream;
					if (vred >= 0) {
						sstream << std::setfill('0') << setw(2) << hex << vred;
					}
					else {
						vred = 256 + vred;
						sstream << setw(2) << hex << vred;
					}
					string pom = sstream.str();
					trenutna_sekcija->kod.push_back(pom);
					brojac_lokacija += 1;
				}
				reg.assign("^,\\s*[a-zA-Z_]+\\w*\\s*");
				if (regex_search(linija, match, reg)) {
					pom = match.str(0);
					linija = match.suffix().str();
					pom.erase(0, 1);
					reg.assign("\\s*");
					pom = regex_replace(pom, reg, "");
					nadjen = false;
					int adr = 0;
					for (int i = 0; i < sekcije.size(); i++) {
						for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
							if (sekcije[i]->simboli[j]->ime == pom) {
								nadjen = true;
								string offset = "";
								adr = brojac_lokacija;
								offset = to_string(adr);
								string tip = "R_386_8";
								int vrednost = 0;
								if (sekcije[i]->simboli[j]->vidljivost == 'l') {
									vrednost = sekcije[i]->redni_broj;
									pom = to_string(sekcije[i]->simboli[j]->vrednost);
								}
								else {
									vrednost = sekcije[i]->simboli[j]->redni_broj;
									pom = "0";
								}
								Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
								trenutna_sekcija->relokacije.push_back(nova_relokacija);
								i = sekcije.size();
								break;
							}
						}
					}
					if (!nadjen) {
						cout << "Ne postoji simbol: " << pom << endl;
						uspesno = false;
						break;
					}
					vred = stoi(pom);
					if (vred >= 127 || vred <= -128) {
						cout << "Prevelika vrednost za 1B kod direktive byte: " << greska << endl;
						uspesno = false;
						break;
					}
					stringstream sstream;
					if (vred >= 0) {
						sstream << std::setfill('0') << setw(2) << hex << vred;
					}
					else {
						vred = 256 + vred;
						sstream << setw(2) << hex << vred;
					}
					string pom = sstream.str();
					trenutna_sekcija->kod.push_back(pom);
					brojac_lokacija += 1;
				}
				else {
					break;
				}
			}

			continue;
		}

		//word
		reg.assign("^\\.word\\s+([a-zA-Z_]+\\w*|-?\\d+)");
		if (regex_search(linija, match, reg)) {
			if (trenutna_sekcija == sekcije[0]) {
				cout << "Direktiva word mora biti definisana unutar sekcije";
				uspesno = false;
				break;
			}
			int vred = 0;
			reg.assign("^\\.word\\s+");
			linija = regex_replace(linija, reg, "");
			reg.assign("^-?\\d+");
			if (regex_search(linija, match, reg)) {
				pom = match.str(0);
				linija = match.suffix().str();
				vred = stoi(pom);
			}
			reg.assign("^[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				pom = match.str(0);
				linija = match.suffix().str();
				bool nadjen = false;
				int adr = 0;
				for (int i = 0; i < sekcije.size(); i++) {
					for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
						if (sekcije[i]->simboli[j]->ime == pom) {
							nadjen = true;
							string offset = "";
							adr = brojac_lokacija;
							offset = to_string(adr);
							string tip = "R_386_16";
							int vrednost = 0;
							if (sekcije[i]->simboli[j]->vidljivost == 'l') {
								vrednost = sekcije[i]->redni_broj;
								pom = to_string(sekcije[i]->simboli[j]->vrednost);
							}
							else {
								vrednost = sekcije[i]->simboli[j]->redni_broj;
								pom = "0";
							}
							Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
							trenutna_sekcija->relokacije.push_back(nova_relokacija);
							i = sekcije.size();
							break;
						}
					}
				}
				if (!nadjen) {
					cout << "Ne postoji simbol: " << pom << endl;
					uspesno = false;
					break;
				}
				vred = stoi(pom);
			}
			if (vred >= 32767 || vred <= -32768) {
				cout << "Prevelika vrednost za 2B kod direktive word: " << greska << endl;
				uspesno = false;
				break;
			}
			stringstream sstream;
			if (vred >= 0) {
				sstream << std::setfill('0') << setw(4) << hex << vred;
			}
			else {
				vred = 65536 + vred;
				sstream << setw(4) << hex << vred;
			}
			string pom = sstream.str();
			string pom1 = pom.substr(0, 2);
			string pom2 = pom.substr(2, 2);
			trenutna_sekcija->kod.push_back(pom2);
			trenutna_sekcija->kod.push_back(pom1);
			brojac_lokacija += 2;
			reg.assign("^\\s*");
			linija = regex_replace(linija, reg, "");
			bool nadjen = false;
			while (true) {
				reg.assign("^,\\s*-?\\d+\\s*");
				if (regex_search(linija, match, reg)) {
					pom = match.str(0);
					linija = match.suffix().str();
					pom.erase(0, 1);
					reg.assign("\\s*");
					pom = regex_replace(pom, reg, "");
					vred = stoi(pom);
					if (vred >= 32767 || vred <= -32768) {
						cout << "Prevelika vrednost za 2B kod direktive word: " << greska << endl;
						uspesno = false;
						break;
					}
					stringstream sstream;
					if (vred >= 0) {
						sstream << std::setfill('0') << setw(4) << hex << vred;
					}
					else {
						vred = 65536 + vred;
						sstream << setw(4) << hex << vred;
					}
					string pom = sstream.str();
					string pom1 = pom.substr(0, 2);
					string pom2 = pom.substr(2, 2);
					trenutna_sekcija->kod.push_back(pom2);
					trenutna_sekcija->kod.push_back(pom1);
					brojac_lokacija += 2;
				}
				reg.assign("^,\\s*[a-zA-Z_]+\\w*\\s*");
				if (regex_search(linija, match, reg)) {
					pom = match.str(0);
					linija = match.suffix().str();
					pom.erase(0, 1);
					reg.assign("\\s*");
					pom = regex_replace(pom, reg, "");
					nadjen = false;
					int adr = 0;
					for (int i = 0; i < sekcije.size(); i++) {
						for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
							if (sekcije[i]->simboli[j]->ime == pom) {
								nadjen = true;
								string offset = "";
								adr = brojac_lokacija;
								offset = to_string(adr);
								string tip = "R_386_16";
								int vrednost = 0;
								if (sekcije[i]->simboli[j]->vidljivost == 'l') {
									vrednost = sekcije[i]->redni_broj;
									pom = to_string(sekcije[i]->simboli[j]->vrednost);
								}
								else {
									vrednost = sekcije[i]->simboli[j]->redni_broj;
									pom = "0";
								}
								Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
								trenutna_sekcija->relokacije.push_back(nova_relokacija);
								i = sekcije.size();
								break;
							}
						}
					}
					if (!nadjen) {
						cout << "Ne postoji simbol: " << pom << endl;
						uspesno = false;
						break;
					}
					vred = stoi(pom);
					if (vred >= 32767 || vred <= -32768) {
						cout << "Prevelika vrednost za 2B kod direktive word: " << greska << endl;
						uspesno = false;
						break;
					}
					stringstream sstream;
					if (vred >= 0) {
						sstream << std::setfill('0') << setw(4) << hex << vred;
					}
					else {
						vred = 65536 + vred;
						sstream << setw(4) << hex << vred;
					}
					string pom = sstream.str();
					string pom1 = pom.substr(0, 2);
					string pom2 = pom.substr(2, 2);
					trenutna_sekcija->kod.push_back(pom2);
					trenutna_sekcija->kod.push_back(pom1);
					brojac_lokacija += 2;
				}
				else {
					break;
				}
			}
			continue;
		}
		//align
		reg.assign("^\\.align\\s+\\d+");
		if (regex_search(linija, match, reg)) {
			if (trenutna_sekcija == sekcije[0]) {
				cout << "Direktiva align mora biti definisana unutar sekcije";
				uspesno = false;
				break;
			}
			pom = match.str(0);
			reg.assign("^\\.align\\s+");
			pom = regex_replace(pom, reg, "");
			int i = stoi(pom); //stoi - string to integer
			i = pow(2, i);
			if (brojac_lokacija % i != 0) {
				i = i - (brojac_lokacija % i);
				brojac_lokacija += i;
			}

			for (int j = 0; j < i; j++) {
				trenutna_sekcija->kod.push_back("00");
			}
			continue;
		}

		//skip
		reg.assign("^\\.skip\\s+\\d+");
		if (regex_search(linija, match, reg)) {
			if (trenutna_sekcija == sekcije[0]) {
				cout << "Direktiva skip mora biti definisana unutar sekcije";
				uspesno = false;
				break;
			}
			pom = match.str(0);
			reg.assign("^\\.skip\\s+");
			pom = regex_replace(pom, reg, "");
			int i = stoi(pom);
			brojac_lokacija += i;
			for (int j = 0; j < i; j++) {
				trenutna_sekcija->kod.push_back("00");
			}
			continue;
		}

		//instrukcija
		int n = Instrukcije::broj_bajtova(linija);
		if (n > 0) {
			if (trenutna_sekcija == sekcije[0]) {
				cout << "Instrukcija mora biti definisana unutar sekcije";
				uspesno = false;
				break;
			}
			int povratna = Instrukcije::kod_instrukcije(linija, trenutna_sekcija, sekcije, brojac_lokacija, brojac_lokacija + n);
			if (povratna <= 0) {
				cout << "Greska u liniji: " << greska << endl;
			}
			brojac_lokacija += n;
			continue;
		}


		//.end
		reg.assign("^\\.end");
		if (regex_search(linija, match, reg)) {

			break;
		}

		reg.assign("^\\s*");
		linija = regex_replace(linija, reg, "");

		//nekorektna instrukcija
		if (!linija.empty()) {
			cout << "Nekorektna instrukcija/direktiva: " << greska << endl;
			uspesno = false;
			break;
		}
	}

	ulaz.close();
}

void Asembler::ispisi() {
	if (uspesno) {
		int i = 0, j = 0;
		izlaz.open("izlaz.txt");
		izlaz << "Tabela simbola:" << endl;
		izlaz << "Ime\t" << "Sekcija\t" << "Vrednost\t" << "Vidljivost\t" << "Redni broj" << endl;
		for (i = 0; i < sekcije.size(); i++) {
			izlaz << sekcije[i]->ime << '\t' << sekcije[i]->ime_sekcije << '\t' << sekcije[i]->vrednost << '\t' << sekcije[i]->vidljivost << '\t' << sekcije[i]->redni_broj << endl;
			for (j = 0; j < sekcije[i]->simboli.size(); j++) {
				izlaz << sekcije[i]->simboli[j]->ime << '\t' << sekcije[i]->ime_sekcije << '\t' << sekcije[i]->simboli[j]->vrednost << '\t' << sekcije[i]->simboli[j]->vidljivost << '\t' << sekcije[i]->simboli[j]->redni_broj << endl;
			}
		}
		izlaz << endl;
		izlaz << "Relokacioni zapisi:" << endl;
		for (i = 1; i < sekcije.size(); i++) {
			izlaz << ".ret." << sekcije[i]->ime_sekcije << endl;
			izlaz << "Offset" << '\t' << "Tip" << '\t' << "Vrednost" << endl;
			for (j = 0; j < sekcije[i]->relokacije.size(); j++) {
				izlaz << sekcije[i]->relokacije[j]->offset << '\t' << sekcije[i]->relokacije[j]->tip << '\t' << sekcije[i]->relokacije[j]->vrednost << endl;
			}
			izlaz << endl;
		}
		izlaz << endl;
		izlaz << "Sekcije:" << endl;
		for (i = 1; i < sekcije.size(); i++) {
			izlaz << sekcije[i]->ime_sekcije << endl;
			for (j = 0; j < sekcije[i]->kod.size(); j++) {
				izlaz << sekcije[i]->kod[j] << " ";
			}
			izlaz << endl << endl;
		}
		izlaz.close();
	}
}