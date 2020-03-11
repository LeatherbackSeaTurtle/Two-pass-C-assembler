#include "instrukcije.h"

string Instrukcije::linija = "";
regex Instrukcije::reg("");
smatch Instrukcije::match;

int Instrukcije::broj_bajtova(string l) {
	linija = l;
	reg.assign("^(halt|ret|iret)");
	if (regex_search(linija, match, reg)) {
		return 1;
	}

	reg.assign("^(not|pop|jmp|jeq|jne|jgt|call)\\s+");
	if (regex_search(linija, match, reg)) {
		linija = regex_replace(linija, reg, "");
		//reg indirektno
		reg.assign("^\\[(r[0-7]|sp|pc|psw)\\]");
		if (regex_search(linija, match, reg)) {
			return 2;
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[-?\\d+\\]");
		if (regex_search(linija, match, reg)) {
			return 4;
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[[a-zA-Z_]+\\w*\\]");
		if (regex_search(linija, match, reg)) {
			return 4;
		}
		//pc relativno sa pom
		reg.assign("^\\$[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			return 4;
		}
		//reg direktno
		reg.assign("^(r[0-7]|sp|pc|psw)");
		if (regex_search(linija, match, reg)) {
			return 2;
		}
		//memorijsko adr
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
		if (regex_search(linija, match, reg)) {
			return 4;
		}
	}

	reg.assign("^(notw|popw|jmpw|jeqw|jnew|jgtw|callw)\\s+");
	if (regex_search(linija, match, reg)) {
		linija = regex_replace(linija, reg, "");
		//reg indirektno
		reg.assign("^\\[(r[0-7]|sp|pc|psw)\\]");
		if (regex_search(linija, match, reg)) {
			return 2;
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[-?\\d+\\]");
		if (regex_search(linija, match, reg)) {
			return 4;
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[[a-zA-Z_]+\\w*\\]");
		if (regex_search(linija, match, reg)) {
			return 4;
		}
		//pc relativno sa pom
		reg.assign("^\\$[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			return 4;
		}
		//reg direktno
		reg.assign("^(r[0-7]|sp|pc|psw)");
		if (regex_search(linija, match, reg)) {
			return 2;
		}
		//memorijsko adr
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
		if (regex_search(linija, match, reg)) {
			return 4;
		}
	}

	reg.assign("^(notb|popb|jmpb|jeqb|jneb|jgtb|callb)\\s+");
	if (regex_search(linija, match, reg)) {
		linija = regex_replace(linija, reg, "");
		//reg indirektno
		reg.assign("^\\[(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\]");
		if (regex_search(linija, match, reg)) {
			return 2;
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswl|pswh)\\[-?\\d+\\]");
		if (regex_search(linija, match, reg)) {
			return 3;
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[[a-zA-Z_]+\\w*\\]");
		if (regex_search(linija, match, reg)) {
			return 3;
		}
		//pc relativno sa pom
		reg.assign("^\\$[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			return 3;
		}
		//reg direktno
		reg.assign("^(r[0-7]l|r[0-7]h|spl|sph|pcl|pch|pswh|pswl)");
		if (regex_search(linija, match, reg)) {
			return 2;
		}
		//memorijsko adr
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
		if (regex_search(linija, match, reg)) {
			return 4;
		}
	}

	reg.assign("^(push|pushw|int|intw)\\s+");
	if (regex_search(linija, match, reg)) {
		linija = regex_replace(linija, reg, "");
		//neposredno
		reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)");
		if (regex_search(linija, match, reg)) {
			return 4;
		}
		//reg indirektno
		reg.assign("^\\[(r[0-7]|sp|pc|psw)\\]");
		if (regex_search(linija, match, reg)) {
			return 2;
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[-?\\d+\\]");
		if (regex_search(linija, match, reg)) {
			return 4;
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[[a-zA-Z_]+\\w*\\]");
		if (regex_search(linija, match, reg)) {
			return 4;
		}
		//pc relativno sa pom
		reg.assign("^\\$[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			return 4;
		}
		//reg direktno
		reg.assign("^(r[0-7]|sp|pc|psw)");
		if (regex_search(linija, match, reg)) {
			return 2;
		}
		//memorijsko adr
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
		if (regex_search(linija, match, reg)) {
			return 4;
		}
	}

	reg.assign("^(pushb|intb)\\s+");
	if (regex_search(linija, match, reg)) {
		linija = regex_replace(linija, reg, "");
		//neposredno
		reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)");
		if (regex_search(linija, match, reg)) {
			return 3;
		}
		//reg indirektno
		reg.assign("^\\[(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\]");
		if (regex_search(linija, match, reg)) {
			return 2;
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswl|pswh)\\[-?\\d+\\]");
		if (regex_search(linija, match, reg)) {
			return 3;
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[[a-zA-Z_]+\\w*\\]");
		if (regex_search(linija, match, reg)) {
			return 3;
		}
		//pc relativno sa pom
		reg.assign("^\\$[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			return 3;
		}
		//reg direktno
		reg.assign("^(r[0-7]l|r[0-7]h|spl|sph|pcl|pch|pswh|pswl)");
		if (regex_search(linija, match, reg)) {
			return 2;
		}
		//memorijsko adr
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
		if (regex_search(linija, match, reg)) {
			return 4;
		}
	}

	reg.assign("^(mov|add|sub|mul|div|and|or|xor|shl|shr)\\s+");
	if (regex_search(linija, match, reg)) {
		linija = regex_replace(linija, reg, "");
		int n = 1;
		bool uspesno = false;
		//reg indirektno
		reg.assign("^\\[(r[0-7]|sp|pc|psw)\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 1;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[-?\\d+\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[[a-zA-Z_]+\\w*\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//pc relativno sa pom
		reg.assign("^\\$[a-zA-Z_]+\\w*\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg direktno
		reg.assign("^(r[0-7]|sp|pc|psw)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 1;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//memorijsko adr
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}

		if (uspesno) {
			//neposredno
			reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}
			//reg indirektno
			reg.assign("^\\[(r[0-7]|sp|pc|psw)\\]");
			if (regex_search(linija, match, reg)) {
				n += 1;
				return n;
			}
			//reg indirektno sa pom
			reg.assign("^(r[0-7]|sp|pc|psw)\\[-?\\d+\\]");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}
			//reg indirektno sa pom
			reg.assign("^(r[0-7]|sp|pc|psw)\\[[a-zA-Z_]+\\w*\\]");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}
			//pc relativno sa pom
			reg.assign("^\\$[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}
			//reg direktno
			reg.assign("^(r[0-7]|sp|pc|psw)");
			if (regex_search(linija, match, reg)) {
				n += 1;
				return n;
			}
			//memorijsko adr
			reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}

		}
		
		return -1;
	}

	reg.assign("^(movw|addw|subw|mulw|divw|andw|orw|xorw|shlw|shrw)\\s+");
	if (regex_search(linija, match, reg)) {
		linija = regex_replace(linija, reg, "");
		int n = 1;
		bool uspesno = false;
		//reg indirektno
		reg.assign("^\\[(r[0-7]|sp|pc|psw)\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 1;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[-?\\d+\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[[a-zA-Z_]+\\w*\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//pc relativno sa pom
		reg.assign("^\\$[a-zA-Z_]+\\w*\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg direktno
		reg.assign("^(r[0-7]|sp|pc|psw)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 1;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//memorijsko adr
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}

		if (uspesno) {
			//neposredno
			reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}
			//reg indirektno
			reg.assign("^\\[(r[0-7]|sp|pc|psw)\\]");
			if (regex_search(linija, match, reg)) {
				n += 1;
				return n;
			}
			//reg indirektno sa pom
			reg.assign("^(r[0-7]|sp|pc|psw)\\[-?\\d+\\]");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}
			//reg indirektno sa pom
			reg.assign("^(r[0-7]|sp|pc|psw)\\[[a-zA-Z_]+\\w*\\]");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}
			//pc relativno sa pom
			reg.assign("^\\$[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}
			//reg direktno
			reg.assign("^(r[0-7]|sp|pc|psw)");
			if (regex_search(linija, match, reg)) {
				n += 1;
				return n;
			}
			//memorijsko adr
			reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}

		}

		return -1;
	}

	reg.assign("^(movb|addb|subb|mulb|divb|andb|orb|xorb|shlb|shrb)\\s+");
	if (regex_search(linija, match, reg)) {
		linija = regex_replace(linija, reg, "");
		int n = 1;
		bool uspesno = false;
		//reg indirektno
		reg.assign("^\\[(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 1;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[-?\\d+\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 2;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[[a-zA-Z_]+\\w*\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 2;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//pc relativno sa pom
		reg.assign("^\\$[a-zA-Z_]+\\w*\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 2;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg direktno
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 1;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//memorijsko adr
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}

		if (uspesno) {
			//neposredno
			reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)");
			if (regex_search(linija, match, reg)) {
				n += 2;
				return n;
			}
			//reg indirektno
			reg.assign("^\\[(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\]");
			if (regex_search(linija, match, reg)) {
				n += 1;
				return n;
			}
			//reg indirektno sa pom
			reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswl|pswh)\\[-?\\d+\\]");
			if (regex_search(linija, match, reg)) {
				n += 2;
				return n;
			}
			//reg indirektno sa pom
			reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[[a-zA-Z_]+\\w*\\]");
			if (regex_search(linija, match, reg)) {
				n += 2;
				return n;
			}
			//pc relativno sa pom
			reg.assign("^\\$[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				n += 2;
				return n;
			}
			//reg direktno
			reg.assign("^(r[0-7]l|r[0-7]h|spl|sph|pcl|pch|pswh|pswl)");
			if (regex_search(linija, match, reg)) {
				n += 1;
				return n;
			}
			//memorijsko adr
			reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}

		}

		return -1;
	}

	reg.assign("^(xchg|xchgw)\\s+");
	if (regex_search(linija, match, reg)) {
		linija = regex_replace(linija, reg, "");
		int n = 1;
		bool uspesno = false;
		//reg indirektno
		reg.assign("^\\[(r[0-7]|sp|pc|psw)\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 1;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[-?\\d+\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[[a-zA-Z_]+\\w*\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//pc relativno sa pom
		reg.assign("^\\$[a-zA-Z_]+\\w*\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg direktno
		reg.assign("^(r[0-7]|sp|pc|psw)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 1;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//memorijsko adr
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}

		if (uspesno) {
			//reg indirektno
			reg.assign("^\\[(r[0-7]|sp|pc|psw)\\]");
			if (regex_search(linija, match, reg)) {
				n += 1;
				return n;
			}
			//reg indirektno sa pom
			reg.assign("^(r[0-7]|sp|pc|psw)\\[-?\\d+\\]");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}
			//reg indirektno sa pom
			reg.assign("^(r[0-7]|sp|pc|psw)\\[[a-zA-Z_]+\\w*\\]");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}
			//pc relativno sa pom
			reg.assign("^\\$[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}
			//reg direktno
			reg.assign("^(r[0-7]|sp|pc|psw)");
			if (regex_search(linija, match, reg)) {
				n += 1;
				return n;
			}
			//memorijsko adr
			reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}

		}
		return -1;
	}

	reg.assign("^xchgb\\s+");
	if (regex_search(linija, match, reg)) {
		linija = regex_replace(linija, reg, "");
		int n = 1;
		bool uspesno = false;
		//reg indirektno
		reg.assign("^\\[(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 1;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[-?\\d+\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 2;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[[a-zA-Z_]+\\w*\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 2;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//pc relativno sa pom
		reg.assign("^\\$[a-zA-Z_]+\\w*\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 2;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg direktno
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 1;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//memorijsko adr
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}

		if (uspesno) {
			//reg indirektno
			reg.assign("^\\[(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\]");
			if (regex_search(linija, match, reg)) {
				n += 1;
				return n;
			}
			//reg indirektno sa pom
			reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswl|pswh)\\[-?\\d+\\]");
			if (regex_search(linija, match, reg)) {
				n += 2;
				return n;
			}
			//reg indirektno sa pom
			reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[[a-zA-Z_]+\\w*\\]");
			if (regex_search(linija, match, reg)) {
				n += 2;
				return n;
			}
			//pc relativno sa pom
			reg.assign("^\\$[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				n += 2;
				return n;
			}
			//reg direktno
			reg.assign("^(r[0-7]l|r[0-7]h|spl|sph|pcl|pch|pswh|pswl)");
			if (regex_search(linija, match, reg)) {
				n += 1;
				return n;
			}
			//memorijsko adr
			reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}

		}
		return -1;
	}

	reg.assign("^(cmp|cmpw|test|testw)\\s+");
	if (regex_search(linija, match, reg)) {
		linija = regex_replace(linija, reg, "");
		int n = 1;
		bool uspesno = false;
		//neposredno
		reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno
		reg.assign("^\\[(r[0-7]|sp|pc|psw)\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 1;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[-?\\d+\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[[a-zA-Z_]+\\w*\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//pc relativno sa pom
		reg.assign("^\\$[a-zA-Z_]+\\w*\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg direktno
		reg.assign("^(r[0-7]|sp|pc|psw)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 1;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//memorijsko adr
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}

		if (uspesno) {
			//neposredno
			reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}
			//reg indirektno
			reg.assign("^\\[(r[0-7]|sp|pc|psw)\\]");
			if (regex_search(linija, match, reg)) {
				n += 1;
				return n;
			}
			//reg indirektno sa pom
			reg.assign("^(r[0-7]|sp|pc|psw)\\[-?\\d+\\]");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}
			//reg indirektno sa pom
			reg.assign("^(r[0-7]|sp|pc|psw)\\[[a-zA-Z_]+\\w*\\]");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}
			//pc relativno sa pom
			reg.assign("^\\$[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}
			//reg direktno
			reg.assign("^(r[0-7]|sp|pc|psw)");
			if (regex_search(linija, match, reg)) {
				n += 1;
				return n;
			}
			//memorijsko adr
			reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}

		}
		return -1;
	}

	reg.assign("^(cmpb|testb)\\s+");
	if (regex_search(linija, match, reg)) {
		linija = regex_replace(linija, reg, "");
		int n = 1;
		bool uspesno = false;
		//neposredno
		reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 2;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno
		reg.assign("^\\[(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 1;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[-?\\d+\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 2;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[[a-zA-Z_]+\\w*\\]\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 2;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//pc relativno sa pom
		reg.assign("^\\$[a-zA-Z_]+\\w*\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 2;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//reg direktno
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 1;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}
		//memorijsko adr
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)\\s*,\\s*");
		if (regex_search(linija, match, reg)) {
			n += 3;
			uspesno = true;
			linija = regex_replace(linija, reg, "");
		}

		if (uspesno) {
			//neposredno
			reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)");
			if (regex_search(linija, match, reg)) {
				n += 2;
				return n;
			}
			//reg indirektno
			reg.assign("^\\[(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\]");
			if (regex_search(linija, match, reg)) {
				n += 1;
				return n;
			}
			//reg indirektno sa pom
			reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswl|pswh)\\[-?\\d+\\]");
			if (regex_search(linija, match, reg)) {
				n += 2;
				return n;
			}
			//reg indirektno sa pom
			reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[[a-zA-Z_]+\\w*\\]");
			if (regex_search(linija, match, reg)) {
				n += 2;
				return n;
			}
			//pc relativno sa pom
			reg.assign("^\\$[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				n += 2;
				return n;
			}
			//reg direktno
			reg.assign("^(r[0-7]l|r[0-7]h|spl|sph|pcl|pch|pswh|pswl)");
			if (regex_search(linija, match, reg)) {
				n += 1;
				return n;
			}
			//memorijsko adr
			reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
			if (regex_search(linija, match, reg)) {
				n += 3;
				return n;
			}

		}

		return -1;
	}

	return -1;
}

int Instrukcije::adresiranje_1B_1op(string l, Sekcija* trenutna_sekcija, vector<Sekcija*>& sekcije, int brojac_lokacija, int uslov, int sl_adr) {

	linija = l;
	if (uslov == 1) {
		//neposredno
		reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("00");
			reg.assign("^-?\\d+");
			if (regex_search(linija, match, reg)) {
				linija = match.str(0);
				int i = stoi(linija);
				if ( i >= 127 || i <= -128 ) {
					cout << "Prevelika vrednost za 1B!" << endl;
					return -3;
				}
				stringstream sstream;
				if (i >= 0) {
					sstream << std::setfill('0') << setw(2) << hex << i;
				}
				else {
					i = 256 + i;
					sstream << setw(2) << hex << i;
				}
				string pom = sstream.str();
				trenutna_sekcija->kod.push_back(pom);
				return 2;
			}
			reg.assign("^&[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				linija = match.str(0);
				reg.assign("^&");
				linija = regex_replace(linija, reg, "");
				bool nadjen = false;
				int i = 0, adr = 0;
				for (i = 0; i < sekcije.size(); i++) {
					for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
						if (sekcije[i]->simboli[j]->ime == linija) {
							nadjen = true;
							string offset = "";
							adr = brojac_lokacija + 2;
							offset = to_string(adr);
							string tip = "R_386_8";
							int vrednost = 0;
							if (sekcije[i]->simboli[j]->vidljivost == 'l') {
								vrednost = sekcije[i]->redni_broj;
								linija = to_string(sekcije[i]->simboli[j]->vrednost);
							}
							else {
								vrednost = sekcije[i]->simboli[j]->redni_broj;
								linija = "0";
							}
							Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
							trenutna_sekcija->relokacije.push_back(nova_relokacija);
							i = sekcije.size();
							break;
						}
					}
				}
				if (!nadjen) {
					cout << "Ne postoji simbol: " << linija << endl;
					return -3;
				}
				i = stoi(linija);
				stringstream sstream;
				if (i >= 0) {
					sstream << std::setfill('0') << setw(2) << hex << i;
				}
				else {
					i = 256 + i;
					sstream << setw(2) << hex << i;
				}
				string pom = sstream.str();
				trenutna_sekcija->kod.push_back(pom);
				return 2;
			}
		}
	}
	//reg indirektno
	reg.assign("^\\[(r[0-7]l|r[0-7]h|spl|sph|pcl|pch|pswl|pswh)\\]");
	if (regex_search(linija, match, reg)) {
		reg.assign("^\\[");
		linija = regex_replace(linija, reg, "");
		reg.assign("^r0l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("40");
			return 1;
		}
		reg.assign("^r0h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("41");
			return 1;
		}
		reg.assign("^r1l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("42");
			return 1;
		}
		reg.assign("^r1h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("43");
			return 1;
		}
		reg.assign("^r2l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("44");
			return 1;
		}
		reg.assign("^r2h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("45");
			return 1;
		}
		reg.assign("^r3l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("46");
			return 1;
		}
		reg.assign("^r3h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("47");
			return 1;
		}
		reg.assign("^r4l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("48");
			return 1;
		}
		reg.assign("^r4h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("49");
			return 1;
		}
		reg.assign("^r5l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4A");
			return 1;
		}
		reg.assign("^r5h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4B");
			return 1;
		}
		reg.assign("^(r6l|spl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4C");
			return 1;
		}
		reg.assign("^(r6h|sph)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4D");
			return 1;
		}
		reg.assign("^(r7l|pcl|pswl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4E");
			return 1;
		}
		reg.assign("^(r7h|pch|pswh)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4F");
			return 1;
		}
	}
	//reg indirektno sa pom
	reg.assign("^(r[0-7]l|r[0-7]h|spl|sph|pcl|pch|pswl|pswh)\\[-?\\d+\\]");
	if (regex_search(linija, match, reg)) {
		reg.assign("^r0l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("60");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r0h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("61");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r1l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("62");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r1h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("63");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r2l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("64");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r2h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("65");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r3l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("66");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r3h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("67");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r4l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("68");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r4h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("69");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r5l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6A");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r5h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6B");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r6l|spl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r6h|sph)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6D");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r7l|pcl|pswl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6E");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r7h|pch|pswh)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6F");
			linija = regex_replace(linija, reg, "");
		}

		reg.assign("^\\[");
		linija = regex_replace(linija, reg, "");
		reg.assign("^-?\\d+");
		regex_search(linija, match, reg);
		linija = match.str(0);
		int i = stoi(linija);
		if (i >= 127 || i <= -128) {
			cout << "Prevelika vrednost za 1B!" << endl;
			return -3;
		}
		stringstream sstream;
		if (i >= 0) {
			sstream << std::setfill('0') << setw(2) << hex << i;
		}
		else {
			i = 256 + i;
			sstream << setw(2) << hex << i;
		}
		string pom = sstream.str();
		trenutna_sekcija->kod.push_back(pom);
		return 2;
	}

	//reg indirektno sa pom
	reg.assign("^(r[0-7]l|r[0-7]h|spl|sph|pcl|pch|pswl|pswh)\\[[a-zA-Z_]+\\w*\\]");
	if (regex_search(linija, match, reg)) {
		bool pc = false;
		reg.assign("^r0l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("60");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r0h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("61");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r1l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("62");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r1h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("63");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r2l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("64");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r2h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("65");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r3l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("66");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r3h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("67");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r4l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("68");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r4h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("69");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r5l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6A");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r5h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6B");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r6l|spl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r6h|sph)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6D");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r7l|pswl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6E");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^pcl");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6E");
			linija = regex_replace(linija, reg, "");
			pc = true;
		}
		reg.assign("^(r7h|pswh)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6F");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^pch");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6F");
			linija = regex_replace(linija, reg, "");
			pc = true;
		}

		reg.assign("^\\[");
		linija = regex_replace(linija, reg, "");
		reg.assign("^[a-zA-Z_]+\\w*");
		regex_search(linija, match, reg);
		linija = match.str(0);
		bool nadjen = false;
		int i = 0, adr = 0;
		for (i = 0; i < sekcije.size(); i++) {
			for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
				if (sekcije[i]->simboli[j]->ime == linija) {
					nadjen = true;
					if (sekcije[i] == trenutna_sekcija && sekcije[i]->simboli[j]->vidljivost == 'l' && pc) {
						adr = sekcije[i]->simboli[j]->vrednost - sl_adr;
						linija = to_string(adr);
						i = sekcije.size();
						break;
					}
					string offset = "";
					adr = brojac_lokacija + 2;
					offset = to_string(adr);
					string tip = "R_386_PC8";
					int vrednost = 0;
					if (pc) {
						if (sekcije[i]->simboli[j]->vidljivost == 'l') {
							vrednost = sekcije[i]->redni_broj;
							adr = sekcije[i]->simboli[j]->vrednost;
							linija = to_string(adr);
						}
						else {
							vrednost = sekcije[i]->simboli[j]->redni_broj;
							adr = 0;
							linija = to_string(adr);
						}
					}
					else {
						tip = "R_386_8";
						if (sekcije[i]->simboli[j]->vidljivost == 'l') {
							vrednost = sekcije[i]->redni_broj;
							adr = sekcije[i]->simboli[j]->vrednost - 2;
							linija = to_string(adr);
						}
						else {
							vrednost = sekcije[i]->simboli[j]->redni_broj;
							adr = 0 - 2;
							linija = to_string(adr);
						}
					}
					Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
					trenutna_sekcija->relokacije.push_back(nova_relokacija);
					i = sekcije.size();
					break;
				}
			}
		}
		if (!nadjen) {
			cout << "Ne postoji simbol: " << linija << endl;
			return -3;
		}
		i = stoi(linija);
		stringstream sstream;
		if (i >= 0) {
			sstream << std::setfill('0') << setw(2) << hex << i;
		}
		else {
			i = 256 + i;
			sstream << setw(2) << hex << i;
		}
		string pom = sstream.str();
		trenutna_sekcija->kod.push_back(pom);
		return 2;
	}

	//pc relativno sa pom
	reg.assign("^\\$[a-zA-Z_]+\\w*");
	if (regex_search(linija, match, reg)) {
		reg.assign("^\\$");
		linija = regex_replace(linija, reg, "");
		reg.assign("^[a-zA-Z_]+\\w*");
		regex_search(linija, match, reg);
		linija = match.str(0);
		trenutna_sekcija->kod.push_back("6E");
		bool nadjen = false;
		int i = 0, adr = 0;
		for (i = 0; i < sekcije.size(); i++) {
			for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
				if (sekcije[i]->simboli[j]->ime == linija) {
					nadjen = true;
					if (sekcije[i] == trenutna_sekcija && sekcije[i]->simboli[j]->vidljivost == 'l') {
						adr = sekcije[i]->simboli[j]->vrednost - sl_adr;
						linija = to_string(adr);
						i = sekcije.size();
						break;
					}
					string offset = "";
					adr = brojac_lokacija + 2;
					offset = to_string(adr);
					string tip = "R_386_PC8";
					int vrednost = 0;
					if (sekcije[i]->simboli[j]->vidljivost == 'l') {
						vrednost = sekcije[i]->redni_broj;
						adr = sekcije[i]->simboli[j]->vrednost - 2;
						linija = to_string(adr);
					}
					else {
						vrednost = sekcije[i]->simboli[j]->redni_broj;
						adr = 0 - 2;
						linija = to_string(adr);
					}
					Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
					trenutna_sekcija->relokacije.push_back(nova_relokacija);
					i = sekcije.size();
					break;
				}
			}
		}
		if (!nadjen) {
			cout << "Ne postoji simbol: " << linija << endl;
			return -3;
		}
		i = stoi(linija);
		stringstream sstream;
		if (i >= 0) {
			sstream << std::setfill('0') << setw(2) << hex << i;
		}
		else {
			i = 256 + i;
			sstream << setw(2) << hex << i;
		}
		string pom = sstream.str();
		trenutna_sekcija->kod.push_back(pom);
		return 2;
	}

	//reg direktno
	reg.assign("^(r[0-7]l|r[0-7]h|spl|sph|pcl|pch|pswh|pswl)");
	if (regex_search(linija, match, reg)) {
		reg.assign("^r0l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("20");
			return 1;
		}
		reg.assign("^r0h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("21");
			return 1;
		}
		reg.assign("^r1l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("22");
			return 1;
		}
		reg.assign("^r1h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("23");
			return 1;
		}
		reg.assign("^r2l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("24");
			return 1;
		}
		reg.assign("^r2h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("25");
			return 1;
		}
		reg.assign("^r3l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("26");
			return 1;
		}
		reg.assign("^r3h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("27");
			return 1;
		}
		reg.assign("^r4l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("28");
			return 1;
		}
		reg.assign("^r4h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("29");
			return 1;
		}
		reg.assign("^r5l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2A");
			return 1;
		}
		reg.assign("^r5h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2B");
			return 1;
		}
		reg.assign("^(r6l|spl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2C");
			return 1;
		}
		reg.assign("^(r6h|sph)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2D");
			return 1;
		}
		reg.assign("^(r7l|pcl|pswl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2E");
			return 1;
		}
		reg.assign("^(r7h|pch|pswh)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2F");
			return 1;
		}
	}

	//memorijsko adr
	reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
	if (regex_search(linija, match, reg)) {
		trenutna_sekcija->kod.push_back("A0");
		reg.assign("^\\*-?\\d+");
		if (regex_search(linija, match, reg)) {
			linija = match.str(0);
			reg.assign("^\\*");
			linija = regex_replace(linija, reg, "");
			int i = stoi(linija);
			if (i >= 127 || i <= -128) {
				cout << "Prevelika vrednost za 1B!" << endl;
				return -3;
			}
			stringstream sstream;
			if (i >= 0) {
				sstream << std::setfill('0') << setw(4) << hex << i;
			}
			else {
				i = 65536 + i;
				sstream << setw(4) << hex << i;
			}
			string pom = sstream.str();
			string pom1 = pom.substr(0, 2);
			string pom2 = pom.substr(2, 2);
			trenutna_sekcija->kod.push_back(pom2);
			trenutna_sekcija->kod.push_back(pom1);
			return 3;
		}
		reg.assign("^[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			linija = match.str(0);
			bool nadjen = false;
			int i = 0, adr = 0;
			for (i = 0; i < sekcije.size(); i++) {
				for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
					if (sekcije[i]->simboli[j]->ime == linija) {
						nadjen = true;
						string offset = "";
						adr = brojac_lokacija + 2;
						offset = to_string(adr);
						string tip = "R_386_8";
						int vrednost = 0;
						if (sekcije[i]->simboli[j]->vidljivost == 'l'){
							vrednost = sekcije[i]->redni_broj;
							linija = to_string(sekcije[i]->simboli[j]->vrednost);
						}
						else {
							vrednost = sekcije[i]->simboli[j]->redni_broj;
							linija = "0";
						}
						Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
						trenutna_sekcija->relokacije.push_back(nova_relokacija);
						i = sekcije.size();
						break;
					}
				}
			}
			if (!nadjen) {
				cout << "Ne postoji simbol: " << linija << endl;
				return -3;
			}
			i = stoi(linija);
			stringstream sstream;
			if (i >= 0) {
				sstream << std::setfill('0') << setw(4) << hex << i;
			}
			else {
				i = 65536 + i;
				sstream << setw(4) << hex << i;
			}
			string pom = sstream.str();
			string pom1 = pom.substr(0, 2);
			string pom2 = pom.substr(2, 2);
			trenutna_sekcija->kod.push_back(pom2);
			trenutna_sekcija->kod.push_back(pom1);
			return 3;
		}
	}

	return -3;
}

int Instrukcije::adresiranje_1B_2op(string l, Sekcija* trenutna_sekcija, vector<Sekcija*>& sekcije, int brojac_lokacija, int uslov, int sl_adr) {

	bool uspesno = false;
	int vrati = 0;
	linija = l;

	if (uslov == 1) {
		//neposredno
		reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)\\s*,");
		if (regex_search(linija, match, reg)) {
			string l = linija;

			trenutna_sekcija->kod.push_back("00");
			vrati += 1;
			reg.assign("^-?\\d+");
			if (regex_search(linija, match, reg)) {
				linija = match.str(0);
				int i = stoi(linija);
				if (i >= 127 || i <= -128) {
					cout << "Prevelika vrednost za 1B!" << endl;
					return -3;
				}
				stringstream sstream;
				if (i >= 0) {
					sstream << std::setfill('0') << setw(2) << hex << i;
				}
				else {
					i = 256 + i;
					sstream << setw(2) << hex << i;
				}
				string pom = sstream.str();
				trenutna_sekcija->kod.push_back(pom);
				vrati += 1;
			}
			reg.assign("^&[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				linija = match.str(0);
				reg.assign("^&");
				linija = regex_replace(linija, reg, "");
				bool nadjen = false;
				int i = 0, adr = 0;
				for (i = 0; i < sekcije.size(); i++) {
					for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
						if (sekcije[i]->simboli[j]->ime == linija) {
							nadjen = true;
							string offset = "";
							adr = brojac_lokacija + 2;
							offset = to_string(adr);
							string tip = "R_386_8";
							int vrednost = 0;
							if (sekcije[i]->simboli[j]->vidljivost == 'l') {
								vrednost = sekcije[i]->redni_broj;
								linija = to_string(sekcije[i]->simboli[j]->vrednost);
							}
							else {
								vrednost = sekcije[i]->simboli[j]->redni_broj;
								linija = "0";
							}
							Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
							trenutna_sekcija->relokacije.push_back(nova_relokacija);
							i = sekcije.size();
							break;
						}
					}
				}
				if (!nadjen) {
					cout << "Ne postoji simbol: " << linija << endl;
					return -3;
				}
				i = stoi(linija);
				stringstream sstream;
				if (i >= 0) {
					sstream << std::setfill('0') << setw(2) << hex << i;
				}
				else {
					i = 256 + i;
					sstream << setw(2) << hex << i;
				}
				string pom = sstream.str();
				trenutna_sekcija->kod.push_back(pom);
				vrati += 1;
			}

			uspesno = true;
			reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)\\s*,\\s*");
			linija = regex_replace(l, reg, "");
		}
	}
	//reg direktno
	reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\s*,\\s*");
	if (regex_search(linija, match, reg)) {
		string l = linija;

		reg.assign("^r0l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("20");
		}
		reg.assign("^r0h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("21");
		}
		reg.assign("^r1l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("22");
		}
		reg.assign("^r1h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("23");
		}
		reg.assign("^r2l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("24");
		}
		reg.assign("^r2h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("25");
		}
		reg.assign("^r3l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("26");
		}
		reg.assign("^r3h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("27");
		}
		reg.assign("^r4l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("28");
		}
		reg.assign("^r4h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("29");
		}
		reg.assign("^r5l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2A");
		}
		reg.assign("^r5h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2B");
		}
		reg.assign("^(r6l|spl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2C");
		}
		reg.assign("^(r6h|sph)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2D");
		}
		reg.assign("^(r7l|pcl|pswl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2E");
		}
		reg.assign("^(r7h|pch|pswh)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2F");
		}

		vrati += 1;

		uspesno = true;
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\s*,\\s*");
		linija = regex_replace(l, reg, "");
	}
	//reg indirektno
	reg.assign("^\\[(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\]\\s*,\\s*");
	if (regex_search(linija, match, reg)) {
		string l = linija;

		reg.assign("^\\[");
		linija = regex_replace(linija, reg, "");
		reg.assign("^r0l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("40");
		}
		reg.assign("^r0h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("41");
		}
		reg.assign("^r1l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("42");
		}
		reg.assign("^r1h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("43");
		}
		reg.assign("^r2l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("44");
		}
		reg.assign("^r2h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("45");
		}
		reg.assign("^r3l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("46");
		}
		reg.assign("^r3h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("47");
		}
		reg.assign("^r4l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("48");
		}
		reg.assign("^r4h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("49");
		}
		reg.assign("^r5l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4A");
		}
		reg.assign("^r5h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4B");
		}
		reg.assign("^(r6l|spl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4C");
		}
		reg.assign("^(r6h|sph)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4D");
		}
		reg.assign("^(r7l|pcl|pswl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4E");
		}
		reg.assign("^(r7h|pch|pswh)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4F");
		}
		vrati += 1;

		uspesno = true;
		reg.assign("^\\[(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\]\\s*,\\s*");
		linija = regex_replace(l, reg, "");
	}
	//reg indirektno sa pom
	reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[-?\\d+\\]\\s*,\\s*");
	if (regex_search(linija, match, reg)) {
		string l = linija;

		reg.assign("^r0l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("60");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r0h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("61");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r1l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("62");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r1h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("63");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r2l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("64");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r2h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("65");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r3l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("66");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r3h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("67");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r4l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("68");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r4h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("69");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r5l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6A");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r5h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6B");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r6l|spl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r6h|sph)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6D");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r7l|pcl|pswl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6E");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r7h|pch|pswh)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6F");
			linija = regex_replace(linija, reg, "");
		}

		reg.assign("^\\[");
		linija = regex_replace(linija, reg, "");
		reg.assign("^-?\\d+");
		regex_search(linija, match, reg);
		linija = match.str(0);
		int i = stoi(linija);
		if (i >= 127 || i <= -128) {
			cout << "Prevelika vrednost za 1B!" << endl;
			return -3;
		}
		stringstream sstream;
		if (i >= 0) {
			sstream << std::setfill('0') << setw(2) << hex << i;
		}
		else {
			i = 256 + i;
			sstream << setw(2) << hex << i;
		}
		string pom = sstream.str();
		trenutna_sekcija->kod.push_back(pom);

		vrati += 2;

		uspesno = true;
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[-?\\d+\\]\\s*,\\s*");
		linija = regex_replace(l, reg, "");
	}
	//reg indirektno sa pom
	reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[[a-zA-Z_]+\\w*\\]\\s*,\\s*");
	if (regex_search(linija, match, reg)) {
		string l = linija;
		bool pc = false;
		reg.assign("^r0l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("60");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r0h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("61");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r1l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("62");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r1h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("63");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r2l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("64");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r2h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("65");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r3l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("66");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r3h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("67");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r4l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("68");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r4h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("69");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r5l");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6A");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r5h");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6B");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r6l|spl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r6h|sph)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6D");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r7l|pswl)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6E");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^pcl");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6E");
			linija = regex_replace(linija, reg, "");
			pc = true;
		}
		reg.assign("^(r7h|pswh)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6F");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^pch");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6F");
			linija = regex_replace(linija, reg, "");
			pc = true;
		}
		vrati += 1;
		reg.assign("^\\[");
		linija = regex_replace(linija, reg, "");
		reg.assign("^[a-zA-Z_]+\\w*");
		regex_search(linija, match, reg);
		linija = match.str(0);
		bool nadjen = false;
		int i = 0, adr = 0;
		for (i = 0; i < sekcije.size(); i++) {
			for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
				if (sekcije[i]->simboli[j]->ime == linija) {
					nadjen = true;
					if (sekcije[i] == trenutna_sekcija && sekcije[i]->simboli[j]->vidljivost == 'l' && pc) {
						adr = sekcije[i]->simboli[j]->vrednost - sl_adr;
						linija = to_string(adr);
						i = sekcije.size();
						break;
					}
					string offset = "";
					adr = brojac_lokacija + 2;
					offset = to_string(adr);
					string tip = "R_386_PC8";
					int vrednost = 0;
					if (pc) {
						if (sekcije[i]->simboli[j]->vidljivost == 'l') {
							vrednost = sekcije[i]->redni_broj;
							adr = sekcije[i]->simboli[j]->vrednost;
							linija = to_string(adr);
						}
						else {
							vrednost = sekcije[i]->simboli[j]->redni_broj;
							adr = 0;
							linija = to_string(adr);
						}
					}
					else {
						tip = "R_386_8";
						if (sekcije[i]->simboli[j]->vidljivost == 'l') {
							vrednost = sekcije[i]->redni_broj;
							adr = sekcije[i]->simboli[j]->vrednost - (brojac_lokacija - sl_adr + vrati);
							linija = to_string(adr);
						}
						else {
							vrednost = sekcije[i]->simboli[j]->redni_broj;
							adr = 0 - (brojac_lokacija - sl_adr + vrati);
							linija = to_string(adr);
						}
					}
					Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
					trenutna_sekcija->relokacije.push_back(nova_relokacija);
					i = sekcije.size();
					break;
				}
			}
		}
		if (!nadjen) {
			cout << "Ne postoji simbol: " << linija << endl;
			return -3;
		}
		i = stoi(linija);
		stringstream sstream;
		if (i >= 0) {
			sstream << std::setfill('0') << setw(2) << hex << i;
		}
		else {
			i = 256 + i;
			sstream << setw(2) << hex << i;
		}
		string pom = sstream.str();
		trenutna_sekcija->kod.push_back(pom);
		vrati += 1;

		uspesno = true;
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[[a-zA-Z_]+\\w*\\]\\s*,\\s*");
		linija = regex_replace(l, reg, "");
	}
	//pc relativno sa pom
	reg.assign("^\\$[a-zA-Z_]+\\w*\\s*,");
	if (regex_search(linija, match, reg)) {
		string l = linija;
		reg.assign("^\\$");
		linija = regex_replace(linija, reg, "");
		reg.assign("^[a-zA-Z_]+\\w*");
		regex_search(linija, match, reg);
		linija = match.str(0);
		trenutna_sekcija->kod.push_back("6E");
		vrati += 1;
		bool nadjen = false;
		int i = 0, adr = 0;
		for (i = 0; i < sekcije.size(); i++) {
			for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
				if (sekcije[i]->simboli[j]->ime == linija) {
					nadjen = true;
					if (sekcije[i] == trenutna_sekcija && sekcije[i]->simboli[j]->vidljivost == 'l') {
						adr = sekcije[i]->simboli[j]->vrednost - sl_adr;
						linija = to_string(adr);
						i = sekcije.size();
						break;
					}
					string offset = "";
					adr = brojac_lokacija + 2;
					offset = to_string(adr);
					string tip = "R_386_PC8";
					int vrednost = 0;
					if (sekcije[i]->simboli[j]->vidljivost == 'l') {
						vrednost = sekcije[i]->redni_broj;
						adr = sekcije[i]->simboli[j]->vrednost - (brojac_lokacija - sl_adr + vrati);
						linija = to_string(adr);
					}
					else {
						vrednost = sekcije[i]->simboli[j]->redni_broj;
						adr = 0 - (brojac_lokacija - sl_adr + vrati);
						linija = to_string(adr);
					}
					Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
					trenutna_sekcija->relokacije.push_back(nova_relokacija);
					i = sekcije.size();
					break;
				}
			}
		}
		if (!nadjen) {
			cout << "Ne postoji simbol: " << linija << endl;
			return -3;
		}
		i = stoi(linija);
		stringstream sstream;
		if (i >= 0) {
			sstream << std::setfill('0') << setw(2) << hex << i;
		}
		else {
			i = 256 + i;
			sstream << setw(2) << hex << i;
		}
		string pom = sstream.str();
		trenutna_sekcija->kod.push_back(pom);
		vrati += 1;

		uspesno = true;
		reg.assign("^\\$[a-zA-Z_]+\\w*\\s*,\\s*");
		linija = regex_replace(l, reg, "");
	}

	//memorijsko adr
	reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)\\s*,");
	if (regex_search(linija, match, reg)) {
		string l = linija;

		trenutna_sekcija->kod.push_back("A0");
		reg.assign("^\\*-?\\d+");
		if (regex_search(linija, match, reg)) {
			linija = match.str(0);
			reg.assign("^\\*");
			linija = regex_replace(linija, reg, "");
			int i = stoi(linija);
			if (i >= 127 || i <= -128) {
				cout << "Prevelika vrednost za 1B!" << endl;
				return -3;
			}
			stringstream sstream;
			if (i >= 0) {
				sstream << std::setfill('0') << setw(4) << hex << i;
			}
			else {
				i = 65536 + i;
				sstream << setw(4) << hex << i;
			}
			string pom = sstream.str();
			string pom1 = pom.substr(0, 2);
			string pom2 = pom.substr(2, 2);
			trenutna_sekcija->kod.push_back(pom2);
			trenutna_sekcija->kod.push_back(pom1);
		}
		reg.assign("^[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			linija = match.str(0);
			bool nadjen = false;
			int i = 0, adr = 0;
			for (i = 0; i < sekcije.size(); i++) {
				for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
					if (sekcije[i]->simboli[j]->ime == linija) {
						nadjen = true;
						string offset = "";
						adr = brojac_lokacija + 2;
						offset = to_string(adr);
						string tip = "R_386_8";
						int vrednost = 0;
						if (sekcije[i]->simboli[j]->vidljivost == 'l') {
							vrednost = sekcije[i]->redni_broj;
							linija = to_string(sekcije[i]->simboli[j]->vrednost);
						}
						else {
							vrednost = sekcije[i]->simboli[j]->redni_broj;
							linija = "0";
						}
						Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
						trenutna_sekcija->relokacije.push_back(nova_relokacija);
						i = sekcije.size();
						break;
					}
				}
			}
			if (!nadjen) {
				cout << "Ne postoji simbol: " << linija << endl;
				return -3;
			}
			i = stoi(linija);
			stringstream sstream;
			if (i >= 0) {
				sstream << std::setfill('0') << setw(4) << hex << i;
			}
			else {
				i = 65536 + i;
				sstream << setw(4) << hex << i;
			}
			string pom = sstream.str();
			string pom1 = pom.substr(0, 2);
			string pom2 = pom.substr(2, 2);
			trenutna_sekcija->kod.push_back(pom2);
			trenutna_sekcija->kod.push_back(pom1);
		}

		vrati += 3;

		uspesno = true;
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)\\s*,\\s*");
		linija = regex_replace(l, reg, "");
	}

	if (uspesno) {
		//neposredno
		reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("00");
			vrati += 1;
			reg.assign("^-?\\d+");
			if (regex_search(linija, match, reg)) {
				linija = match.str(0);
				int i = stoi(linija);
				if (i >= 127 || i <= -128) {
					cout << "Prevelika vrednost za 1B!" << endl;
					return -3;
				}
				stringstream sstream;
				if (i >= 0) {
					sstream << std::setfill('0') << setw(2) << hex << i;
				}
				else {
					i = 256 + i;
					sstream << setw(2) << hex << i;
				}
				string pom = sstream.str();
				trenutna_sekcija->kod.push_back(pom);
				vrati += 1;
			}
			reg.assign("^&[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				linija = match.str(0);
				reg.assign("^&");
				linija = regex_replace(linija, reg, "");
				bool nadjen = false;
				int i = 0, adr = 0;
				for (i = 0; i < sekcije.size(); i++) {
					for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
						if (sekcije[i]->simboli[j]->ime == linija) {
							nadjen = true;
							string offset = "";
							adr = brojac_lokacija + 1 + vrati;
							offset = to_string(adr);
							string tip = "R_386_8";
							int vrednost = 0;
							if (sekcije[i]->simboli[j]->vidljivost == 'l') {
								vrednost = sekcije[i]->redni_broj;
								linija = to_string(sekcije[i]->simboli[j]->vrednost);
							}
							else {
								vrednost = sekcije[i]->simboli[j]->redni_broj;
								linija = "0";
							}
							Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
							trenutna_sekcija->relokacije.push_back(nova_relokacija);
							i = sekcije.size();
							break;
						}
					}
				}
				if (!nadjen) {
					cout << "Ne postoji simbol: " << linija << endl;
					return -3;
				}
				i = stoi(linija);
				stringstream sstream;
				if (i >= 0) {
					sstream << std::setfill('0') << setw(2) << hex << i;
				}
				else {
					i = 256 + i;
					sstream << setw(2) << hex << i;
				}
				string pom = sstream.str();
				trenutna_sekcija->kod.push_back(pom);
				vrati += 1;
			}
			return vrati;
		}
		
		//reg indirektno
		reg.assign("^\\[(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\]");
		if (regex_search(linija, match, reg)) {
			reg.assign("^\\[");
			linija = regex_replace(linija, reg, "");
			reg.assign("^r0l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("40");
			}
			reg.assign("^r0h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("41");
			}
			reg.assign("^r1l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("42");
			}
			reg.assign("^r1h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("43");
			}
			reg.assign("^r2l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("44");
			}
			reg.assign("^r2h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("45");
			}
			reg.assign("^r3l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("46");
			}
			reg.assign("^r3h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("47");
			}
			reg.assign("^r4l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("48");
			}
			reg.assign("^r4h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("49");
			}
			reg.assign("^r5l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("4A");
			}
			reg.assign("^r5h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("4B");
			}
			reg.assign("^(r6l|spl)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("4C");
			}
			reg.assign("^(r6h|sph)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("4D");
			}
			reg.assign("^(r7l|pcl|pswl)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("4E");
			}
			reg.assign("^(r7h|pch|pswh)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("4F");
			}
			vrati += 1;
			return vrati;
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswl|pswh)\\[-?\\d+\\]");
		if (regex_search(linija, match, reg)) {
			reg.assign("^r0l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("60");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r0h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("61");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r1l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("62");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r1h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("63");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r2l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("64");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r2h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("65");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r3l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("66");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r3h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("67");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r4l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("68");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r4h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("69");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r5l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("6A");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r5h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("6B");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^(r6l|spl)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("6C");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^(r6h|sph)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("6D");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^(r7l|pcl|pswl)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("6E");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^(r7h|pch|pswh)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("6F");
				linija = regex_replace(linija, reg, "");
			}
			vrati += 1;

			reg.assign("^\\[");
			linija = regex_replace(linija, reg, "");
			reg.assign("^-?\\d+");
			regex_search(linija, match, reg);
			linija = match.str(0);
			int i = stoi(linija);
			if (i >= 127 || i <= -128) {
				cout << "Prevelika vrednost za 1B!" << endl;
				return -3;
			}
			stringstream sstream;
			if (i >= 0) {
				sstream << std::setfill('0') << setw(2) << hex << i;
			}
			else {
				i = 256 + i;
				sstream << setw(2) << hex << i;
			}
			string pom = sstream.str();
			trenutna_sekcija->kod.push_back(pom);
			vrati += 1;
			return vrati;
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswh|pswl)\\[[a-zA-Z_]+\\w*\\]");
		if (regex_search(linija, match, reg)) {
			bool pc = false;
			reg.assign("^r0l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("60");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r0h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("61");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r1l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("62");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r1h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("63");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r2l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("64");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r2h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("65");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r3l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("66");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r3h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("67");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r4l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("68");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r4h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("69");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r5l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("6A");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r5h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("6B");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^(r6l|spl)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("6C");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^(r6h|sph)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("6D");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^(r7l|pswl)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("6E");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^pcl");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("6E");
				linija = regex_replace(linija, reg, "");
				pc = true;
			}
			reg.assign("^(r7h|pswh)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("6F");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^pch");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("6F");
				linija = regex_replace(linija, reg, "");
				pc = true;
			}

			vrati += 1;

			reg.assign("^\\[");
			linija = regex_replace(linija, reg, "");
			reg.assign("^[a-zA-Z_]+\\w*");
			regex_search(linija, match, reg);
			linija = match.str(0);
			bool nadjen = false;
			int i = 0, adr = 0;
			for (i = 0; i < sekcije.size(); i++) {
				for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
					if (sekcije[i]->simboli[j]->ime == linija) {
						nadjen = true;
						if (sekcije[i] == trenutna_sekcija && sekcije[i]->simboli[j]->vidljivost == 'l' && pc) {
							adr = sekcije[i]->simboli[j]->vrednost - sl_adr;
							linija = to_string(adr);
							i = sekcije.size();
							break;
						}
						string offset = "";
						adr = brojac_lokacija + 2;
						offset = to_string(adr);
						string tip = "R_386_PC8";
						int vrednost = 0;
						if (pc) {
							if (sekcije[i]->simboli[j]->vidljivost == 'l') {
								vrednost = sekcije[i]->redni_broj;
								adr = sekcije[i]->simboli[j]->vrednost;
								linija = to_string(adr);
							}
							else {
								vrednost = sekcije[i]->simboli[j]->redni_broj;
								adr = 0;
								linija = to_string(adr);
							}
						}
						else {
							tip = "R_386_8";
							if (sekcije[i]->simboli[j]->vidljivost == 'l') {
								vrednost = sekcije[i]->redni_broj;
								adr = sekcije[i]->simboli[j]->vrednost - (brojac_lokacija - sl_adr + vrati + 1);
								linija = to_string(adr);
							}
							else {
								vrednost = sekcije[i]->simboli[j]->redni_broj;
								adr = 0 - (brojac_lokacija - sl_adr + vrati + 1);
								linija = to_string(adr);
							}
						}
						Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
						trenutna_sekcija->relokacije.push_back(nova_relokacija);
						i = sekcije.size();
						break;
					}
				}
			}
			if (!nadjen) {
				cout << "Ne postoji simbol: " << linija << endl;
				return -3;
			}
			i = stoi(linija);
			stringstream sstream;
			if (i >= 0) {
				sstream << std::setfill('0') << setw(2) << hex << i;
			}
			else {
				i = 256 + i;
				sstream << setw(2) << hex << i;
			}
			string pom = sstream.str();
			trenutna_sekcija->kod.push_back(pom);
			vrati += 1;
			return vrati;
		}
		//pc relativno sa pom
		reg.assign("^\\$[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			reg.assign("^\\$");
			linija = regex_replace(linija, reg, "");
			reg.assign("^[a-zA-Z_]+\\w*");
			regex_search(linija, match, reg);
			linija = match.str(0);
			trenutna_sekcija->kod.push_back("6E");
			vrati += 1;
			bool nadjen = false;
			int i = 0, adr = 0;
			for (i = 0; i < sekcije.size(); i++) {
				for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
					if (sekcije[i]->simboli[j]->ime == linija) {
						nadjen = true;
						if (sekcije[i] == trenutna_sekcija && sekcije[i]->simboli[j]->vidljivost == 'l') {
							adr = sekcije[i]->simboli[j]->vrednost - sl_adr;
							linija = to_string(adr);
							i = sekcije.size();
							break;
						}
						string offset = "";
						adr = brojac_lokacija + 2;
						offset = to_string(adr);
						string tip = "R_386_PC8";
						int vrednost = 0;
						if (sekcije[i]->simboli[j]->vidljivost == 'l') {
							vrednost = sekcije[i]->redni_broj;
							adr = sekcije[i]->simboli[j]->vrednost - (brojac_lokacija - sl_adr + vrati + 1);
							linija = to_string(adr);
						}
						else {
							vrednost = sekcije[i]->simboli[j]->redni_broj;
							adr = 0 - (brojac_lokacija - sl_adr + vrati + 1);
							linija = to_string(adr);
						}
						Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
						trenutna_sekcija->relokacije.push_back(nova_relokacija);
						i = sekcije.size();
						break;
					}
				}
			}
			if (!nadjen) {
				cout << "Ne postoji simbol: " << linija << endl;
				return -3;
			}
			i = stoi(linija);
			stringstream sstream;
			if (i >= 0) {
				sstream << std::setfill('0') << setw(2) << hex << i;
			}
			else {
				i = 256 + i;
				sstream << setw(2) << hex << i;
			}
			string pom = sstream.str();
			trenutna_sekcija->kod.push_back(pom);
			vrati += 1;
			return vrati;
		}
		//reg direktno
		reg.assign("^(r[0-7]h|r[0-7]l|spl|sph|pcl|pch|pswl|pswh)");
		if (regex_search(linija, match, reg)) {
			reg.assign("^r0l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("20");
			}
			reg.assign("^r0h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("21");
			}
			reg.assign("^r1l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("22");
			}
			reg.assign("^r1h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("23");
			}
			reg.assign("^r2l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("24");
			}
			reg.assign("^r2h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("25");
			}
			reg.assign("^r3l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("26");
			}
			reg.assign("^r3h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("27");
			}
			reg.assign("^r4l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("28");
			}
			reg.assign("^r4h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("29");
			}
			reg.assign("^r5l");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("2A");
			}
			reg.assign("^r5h");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("2B");
			}
			reg.assign("^(r6l|spl)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("2C");
			}
			reg.assign("^(r6h|sph)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("2D");
			}
			reg.assign("^(r7l|pcl|pswl)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("2E");
			}
			reg.assign("^(r7h|pch|pswh)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("2F");
			}
			vrati += 1;
			return vrati;
		}

		//memorijsko adr
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("A0");
			vrati += 1;
			reg.assign("^\\*-?\\d+");
			if (regex_search(linija, match, reg)) {
				linija = match.str(0);
				reg.assign("^\\*");
				linija = regex_replace(linija, reg, "");
				int i = stoi(linija);
				if (i >= 127 || i <= -128) {
					cout << "Prevelika vrednost za 1B!" << endl;
					return -3;
				}
				stringstream sstream;
				if (i >= 0) {
					sstream << std::setfill('0') << setw(4) << hex << i;
				}
				else {
					i = 65536 + i;
					sstream << setw(4) << hex << i;
				}
				string pom = sstream.str();
				string pom1 = pom.substr(0, 2);
				string pom2 = pom.substr(2, 2);
				trenutna_sekcija->kod.push_back(pom2);
				trenutna_sekcija->kod.push_back(pom1);
				vrati += 2;
			}
			reg.assign("^[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				linija = match.str(0);
				bool nadjen = false;
				int i = 0, adr = 0;
				for (i = 0; i < sekcije.size(); i++) {
					for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
						if (sekcije[i]->simboli[j]->ime == linija) {
							nadjen = true;
							string offset = "";
							adr = brojac_lokacija + 1 + vrati;
							offset = to_string(adr);
							string tip = "R_386_8";
							int vrednost = 0;
							if (sekcije[i]->simboli[j]->vidljivost == 'l') {
								vrednost = sekcije[i]->redni_broj;
								linija = to_string(sekcije[i]->simboli[j]->vrednost);
							}
							else {
								vrednost = sekcije[i]->simboli[j]->redni_broj;
								linija = "0";
							}
							Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
							trenutna_sekcija->relokacije.push_back(nova_relokacija);
							i = sekcije.size();
							break;
						}
					}
				}
				if (!nadjen) {
					cout << "Ne postoji simbol: " << linija << endl;
					return -3;
				}
				i = stoi(linija);
				stringstream sstream;
				if (i >= 0) {
					sstream << std::setfill('0') << setw(4) << hex << i;
				}
				else {
					i = 65536 + i;
					sstream << setw(4) << hex << i;
				}
				string pom = sstream.str();
				string pom1 = pom.substr(0, 2);
				string pom2 = pom.substr(2, 2);
				trenutna_sekcija->kod.push_back(pom2);
				trenutna_sekcija->kod.push_back(pom1);
				vrati += 2;
			}
			return vrati;
		}

	}

	return -3;
}

int Instrukcije::adresiranje_2B_1op(string l, Sekcija* trenutna_sekcija, vector<Sekcija*>& sekcije, int brojac_lokacija, int uslov, int sl_adr) {

	linija = l;
	if (uslov == 1) {
		//neposredno
		reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("00");
			reg.assign("^-?\\d+");
			if (regex_search(linija, match, reg)) {
				linija = match.str(0);
				int i = stoi(linija);
				if (i >= 32767 || i <= -32768) {
					cout << "Prevelika vrednost za 2B!" << endl;
					return -3;
				}
				stringstream sstream;
				if (i >= 0) {
					sstream << std::setfill('0') << setw(4) << hex << i;
				}
				else {
					i = 65536 + i;
					sstream << setw(4) << hex << i;
				}
				string pom = sstream.str();
				string pom1 = pom.substr(0, 2);
				string pom2 = pom.substr(2, 2);
				trenutna_sekcija->kod.push_back(pom2);
				trenutna_sekcija->kod.push_back(pom1);
				return 3;
			}
			reg.assign("^&[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				linija = match.str(0);
				reg.assign("^&");
				linija = regex_replace(linija, reg, "");
				bool nadjen = false;
				int i = 0, adr = 0;
				for (i = 0; i < sekcije.size(); i++) {
					for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
						if (sekcije[i]->simboli[j]->ime == linija) {
							nadjen = true;
							string offset = "";
							adr = brojac_lokacija + 2;
							offset = to_string(adr);
							string tip = "R_386_16";
							int vrednost = 0;
							if (sekcije[i]->simboli[j]->vidljivost == 'l') {
								vrednost = sekcije[i]->redni_broj;
								linija = to_string(sekcije[i]->simboli[j]->vrednost);
							}
							else {
								vrednost = sekcije[i]->simboli[j]->redni_broj;
								linija = "0";
							}
							Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
							trenutna_sekcija->relokacije.push_back(nova_relokacija);
							i = sekcije.size();
							break;
						}
					}
				}
				if (!nadjen) {
					cout << "Ne postoji simbol: " << linija << endl;
					return -3;
				}
				i = stoi(linija);
				stringstream sstream;
				if (i >= 0) {
					sstream << std::setfill('0') << setw(4) << hex << i;
				}
				else {
					i = 65536 + i;
					sstream << setw(4) << hex << i;
				}
				string pom = sstream.str();
				string pom1 = pom.substr(0, 2);
				string pom2 = pom.substr(2, 2);
				trenutna_sekcija->kod.push_back(pom2);
				trenutna_sekcija->kod.push_back(pom1);
				return 3;
			}
		}
	}

	//reg indirektno
	reg.assign("^\\[(r[0-7]|sp|pc|psw)\\]");
	if (regex_search(linija, match, reg)) {
		reg.assign("^\\[");
		linija = regex_replace(linija, reg, "");
		reg.assign("^r0");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("40");
			return 1;
		}
		reg.assign("^r1");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("42");
			return 1;
		}
		reg.assign("^r2");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("44");
			return 1;
		}
		reg.assign("^r3");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("45");
			return 1;
		}
		reg.assign("^r4");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("48");
			return 1;
		}
		reg.assign("^r5");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4A");
			return 1;
		}
		reg.assign("^(r6|sp)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4C");
			return 1;
		}
		reg.assign("^(r7|pc|psw)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4E");
			return 1;
		}
	}

	//reg indirektno sa pom
	reg.assign("^(r[0-7]|sp|pc|psw)\\[-?\\d+\\]");
	if (regex_search(linija, match, reg)) {
		reg.assign("^r0");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("80");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r1");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("82");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r2");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("84");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r3");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("85");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r4");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("88");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r5");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("8A");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r6|sp)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("8C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r7|pc|psw)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("8E");
			linija = regex_replace(linija, reg, "");
		}

		reg.assign("^\\[");
		linija = regex_replace(linija, reg, "");
		reg.assign("^-?\\d+");
		regex_search(linija, match, reg);
		linija = match.str(0);
		int i = stoi(linija);
		if (i >= 32767 || i <= -32768) {
			cout << "Prevelika vrednost za 2B!" << endl;
			return -3;
		}
		stringstream sstream;
		if (i >= 0) {
			sstream << std::setfill('0') << setw(4) << hex << i;
		}
		else {
			i = 65536 + i;
			sstream << setw(4) << hex << i;
		}
		string pom = sstream.str();
		string pom1 = pom.substr(0, 2);
		string pom2 = pom.substr(2, 2);
		trenutna_sekcija->kod.push_back(pom2);
		trenutna_sekcija->kod.push_back(pom1);
		return 3;
	}

	//reg indirektno sa pom
	reg.assign("^(r[0-7]|sp|pc|psw)\\[[a-zA-Z_]+\\w*\\]");
	if (regex_search(linija, match, reg)) {
		bool pc = false;
		reg.assign("^r0");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("80");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r1");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("82");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r2");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("84");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r3");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("85");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r4");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("88");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r5");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("8A");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r6|sp)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("8C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r7|psw)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("8E");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^pc");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("8E");
			linija = regex_replace(linija, reg, "");
			pc = true;
		}

		reg.assign("^\\[");
		linija = regex_replace(linija, reg, "");
		reg.assign("^[a-zA-Z_]+\\w*");
		regex_search(linija, match, reg);
		linija = match.str(0);
		bool nadjen = false;
		int i = 0, adr = 0;
		for (i = 0; i < sekcije.size(); i++) {
			for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
				if (sekcije[i]->simboli[j]->ime == linija) {
					nadjen = true;
					if (sekcije[i] == trenutna_sekcija && sekcije[i]->simboli[j]->vidljivost == 'l' && pc) {
						adr = sekcije[i]->simboli[j]->vrednost - sl_adr;
						linija = to_string(adr);
						i = sekcije.size();
						break;
					}
					string offset = "";
					adr = brojac_lokacija + 2;
					offset = to_string(adr);
					string tip = "R_386_PC16";
					int vrednost = 0;
					if (pc) {
						if (sekcije[i]->simboli[j]->vidljivost == 'l') {
							vrednost = sekcije[i]->redni_broj;
							adr = sekcije[i]->simboli[j]->vrednost;
							linija = to_string(adr);
						}
						else {
							vrednost = sekcije[i]->simboli[j]->redni_broj;
							adr = 0;
							linija = to_string(adr);
						}
					}
					else {
						tip = "R_386_16";
						if (sekcije[i]->simboli[j]->vidljivost == 'l') {
							vrednost = sekcije[i]->redni_broj;
							adr = sekcije[i]->simboli[j]->vrednost - 2;
							linija = to_string(adr);
						}
						else {
							vrednost = sekcije[i]->simboli[j]->redni_broj;
							adr = 0 - 2;
							linija = to_string(adr);
						}
					}
					Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
					trenutna_sekcija->relokacije.push_back(nova_relokacija);
					i = sekcije.size();
					break;
				}
			}
		}
		if (!nadjen) {
			cout << "Ne postoji simbol: " << linija << endl;
			return -3;
		}
		i = stoi(linija);
		stringstream sstream;
		if (i >= 0) {
			sstream << std::setfill('0') << setw(4) << hex << i;
		}
		else {
			i = 65536 + i;
			sstream << setw(4) << hex << i;
		}
		string pom = sstream.str();
		string pom1 = pom.substr(0, 2);
		string pom2 = pom.substr(2, 2);
		trenutna_sekcija->kod.push_back(pom2);
		trenutna_sekcija->kod.push_back(pom1);
		return 3;
	
	}

	//pc relativno sa pom
	reg.assign("^\\$[a-zA-Z_]+\\w*");
	if (regex_search(linija, match, reg)) {
		reg.assign("^\\$");
		linija = regex_replace(linija, reg, "");
		reg.assign("^[a-zA-Z_]+\\w*");
		regex_search(linija, match, reg);
		linija = match.str(0);
		trenutna_sekcija->kod.push_back("8E");
		bool nadjen = false;
		int i = 0, adr = 0;
		for (i = 0; i < sekcije.size(); i++) {
			for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
				if (sekcije[i]->simboli[j]->ime == linija) {
					nadjen = true;
					if (sekcije[i] == trenutna_sekcija && sekcije[i]->simboli[j]->vidljivost == 'l') {
						adr = sekcije[i]->simboli[j]->vrednost - sl_adr;
						linija = to_string(adr);
						i = sekcije.size();
						break;
					}
					string offset = "";
					adr = brojac_lokacija + 2;
					offset = to_string(adr);
					string tip = "R_386_PC16";
					int vrednost = 0;
					if (sekcije[i]->simboli[j]->vidljivost == 'l') {
						vrednost = sekcije[i]->redni_broj;
						adr = sekcije[i]->simboli[j]->vrednost - 2;
						linija = to_string(adr);
					}
					else {
						vrednost = sekcije[i]->simboli[j]->redni_broj;
						adr = 0 - 2;
						linija = to_string(adr);
					}
					Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
					trenutna_sekcija->relokacije.push_back(nova_relokacija);
					i = sekcije.size();
					break;
				}
			}
		}
		if (!nadjen) {
			cout << "Ne postoji simbol: " << linija << endl;
			return -3;
		}
		i = stoi(linija);
		stringstream sstream;
		if (i >= 0) {
			sstream << std::setfill('0') << setw(4) << hex << i;
		}
		else {
			i = 65536 + i;
			sstream << setw(4) << hex << i;
		}
		string pom = sstream.str();
		string pom1 = pom.substr(0, 2);
		string pom2 = pom.substr(2, 2);
		trenutna_sekcija->kod.push_back(pom2);
		trenutna_sekcija->kod.push_back(pom1);
		return 3;
	}

	//reg direktno
	reg.assign("^(r[0-7]|sp|pc|psw)");
	if (regex_search(linija, match, reg)) {
		reg.assign("^r0");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("20");
			return 1;
		}
		reg.assign("^r1");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("22");
			return 1;
		}
		reg.assign("^r2");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("24");
			return 1;
		}
		reg.assign("^r3");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("25");
			return 1;
		}
		reg.assign("^r4");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("28");
			return 1;
		}
		reg.assign("^r5");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2A");
			return 1;
		}
		reg.assign("^(r6|sp)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2C");
			return 1;
		}
		reg.assign("^(r7|pc|psw)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2E");
			return 1;
		}
	}

	//memorijsko adr
	reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
	if (regex_search(linija, match, reg)) {
		trenutna_sekcija->kod.push_back("A0");
		reg.assign("^\\*-?\\d+");
		if (regex_search(linija, match, reg)) {
			linija = match.str(0);
			reg.assign("^\\*");
			linija = regex_replace(linija, reg, "");
			int i = stoi(linija);
			if (i >= 32767 || i <= -32768) {
				cout << "Prevelika vrednost za 2B!" << endl;
				return -3;
			}
			stringstream sstream;
			if (i >= 0) {
				sstream << std::setfill('0') << setw(4) << hex << i;
			}
			else {
				i = 65536 + i;
				sstream << setw(4) << hex << i;
			}
			string pom = sstream.str();
			string pom1 = pom.substr(0, 2);
			string pom2 = pom.substr(2, 2);
			trenutna_sekcija->kod.push_back(pom2);
			trenutna_sekcija->kod.push_back(pom1);
			return 3;
		}
		reg.assign("^[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			linija = match.str(0);
			int i = 0, adr = 0;
			bool nadjen = false;
			for (i = 0; i < sekcije.size(); i++) {
				for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
					if (sekcije[i]->simboli[j]->ime == linija) {
						nadjen = true;
						string offset = "";
						adr = brojac_lokacija + 2;
						offset = to_string(adr);
						string tip = "R_386_16";
						int vrednost = 0;
						if (sekcije[i]->simboli[j]->vidljivost == 'l') {
							vrednost = sekcije[i]->redni_broj;
							linija = to_string(sekcije[i]->simboli[j]->vrednost);
						}
						else {
							vrednost = sekcije[i]->simboli[j]->redni_broj;
							linija = "0";
						}
						Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
						trenutna_sekcija->relokacije.push_back(nova_relokacija);
						i = sekcije.size();
						break;
					}
				}
			}
			if (!nadjen) {
				cout << "Ne postoji simbol: " << linija << endl;
				return -3;
			}
			i = stoi(linija);
			stringstream sstream;
			if (i >= 0) {
				sstream << std::setfill('0') << setw(4) << hex << i;
			}
			else {
				i = 65536 + i;
				sstream << setw(4) << hex << i;
			}
			string pom = sstream.str();
			string pom1 = pom.substr(0, 2);
			string pom2 = pom.substr(2, 2);
			trenutna_sekcija->kod.push_back(pom2);
			trenutna_sekcija->kod.push_back(pom1);
			return 3;
		}
	}

	return -3;
}

int Instrukcije::adresiranje_2B_2op(string l, Sekcija* trenutna_sekcija, vector<Sekcija*>& sekcije, int brojac_lokacija, int uslov, int sl_adr) {

	bool uspesno = false;
	int vrati = 0;
	linija = l;

	if (uslov == 1) {
		//neposredno
		reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)\\s*,");
		if (regex_search(linija, match, reg)) {
			string l = linija;

			trenutna_sekcija->kod.push_back("00");
			vrati += 1;
			reg.assign("^-?\\d+");
			if (regex_search(linija, match, reg)) {
				linija = match.str(0);
				int i = stoi(linija);
				if (i >= 32767 || i <= -32768) {
					cout << "Prevelika vrednost za 2B!" << endl;
					return -3;
				}
				stringstream sstream;
				if (i >= 0) {
					sstream << std::setfill('0') << setw(4) << hex << i;
				}
				else {
					i = 65536 + i;
					sstream << setw(4) << hex << i;
				}
				string pom = sstream.str();
				string pom1 = pom.substr(0, 2);
				string pom2 = pom.substr(2, 2);
				trenutna_sekcija->kod.push_back(pom2);
				trenutna_sekcija->kod.push_back(pom1);
				vrati += 2;
			}
			reg.assign("^&[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				linija = match.str(0);
				reg.assign("^&");
				linija = regex_replace(linija, reg, "");
				bool nadjen = false;
				int i = 0, adr = 0;
				for (i = 0; i < sekcije.size(); i++) {
					for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
						if (sekcije[i]->simboli[j]->ime == linija) {
							nadjen = true;
							string offset = "";
							adr = brojac_lokacija + 2;
							offset = to_string(adr);
							string tip = "R_386_16";
							int vrednost = 0;
							if (sekcije[i]->simboli[j]->vidljivost == 'l') {
								vrednost = sekcije[i]->redni_broj;
								linija = to_string(sekcije[i]->simboli[j]->vrednost);
							}
							else {
								vrednost = sekcije[i]->simboli[j]->redni_broj;
								linija = "0";
							}
							Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
							trenutna_sekcija->relokacije.push_back(nova_relokacija);
							i = sekcije.size();
							break;
						}
					}
				}
				if (!nadjen) {
					cout << "Ne postoji simbol: " << linija << endl;
					return -3;
				}
				i = stoi(linija);
				stringstream sstream;
				if (i >= 0) {
					sstream << std::setfill('0') << setw(4) << hex << i;
				}
				else {
					i = 65536 + i;
					sstream << setw(4) << hex << i;
				}
				string pom = sstream.str();
				string pom1 = pom.substr(0, 2);
				string pom2 = pom.substr(2, 2);
				trenutna_sekcija->kod.push_back(pom2);
				trenutna_sekcija->kod.push_back(pom1);
				vrati += 2;
			}

			uspesno = true;
			reg.assign("^(\\d+|&[a-zA-Z_]+\\w*)\\s*,\\s*");
			linija = regex_replace(l, reg, "");
		}
	}

	//reg direktno
	reg.assign("^(r[0-7]|sp|pc|psw)\\s*,");
	if (regex_search(linija, match, reg)) {
		string l = linija;

		reg.assign("^r0");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("20");
		}
		reg.assign("^r1");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("22");
		}
		reg.assign("^r2");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("24");
		}
		reg.assign("^r3");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("25");
		}
		reg.assign("^r4");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("28");
		}
		reg.assign("^r5");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2A");
		}
		reg.assign("^(r6|sp)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2C");
		}
		reg.assign("^(r7|pc|psw)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2E");
		}
		vrati += 1;
		uspesno = true;
		reg.assign("^(r[0-7]|sp|pc|psw)\\s*,\\s*");
		linija = regex_replace(l, reg, "");
	}
	//reg indirektno
	reg.assign("^\\[(r[0-7]|sp|pc|psw)\\]\\s*,");
	if (regex_search(linija, match, reg)) {
		string l = linija;

		reg.assign("^\\[");
		linija = regex_replace(linija, reg, "");
		reg.assign("^r0");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("40");
		}
		reg.assign("^r1");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("42");
		}
		reg.assign("^r2");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("44");
		}
		reg.assign("^r3");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("45");
		}
		reg.assign("^r4");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("48");
		}
		reg.assign("^r5");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4A");
		}
		reg.assign("^(r6|sp)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4C");
		}
		reg.assign("^(r7|pc|psw)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4E");
		}
		vrati += 1;
		uspesno = true;
		reg.assign("^\\[(r[0-7]|sp|pc|psw)\\]\\s*,\\s*");
		linija = regex_replace(l, reg, "");
	}
	//reg indirektno sa pom
	reg.assign("^(r[0-7]|sp|pc|psw)\\[-?\\d+\\]\\s*,");
	if (regex_search(linija, match, reg)) {
		string l = linija;

		reg.assign("^r0");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("80");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r1");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("82");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r2");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("84");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r3");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("85");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r4");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("88");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r5");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("8A");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r6|sp)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("8C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r7|pc|psw)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("8E");
			linija = regex_replace(linija, reg, "");
		}
		vrati += 1;
		reg.assign("^\\[");
		linija = regex_replace(linija, reg, "");
		reg.assign("^-?\\d+");
		regex_search(linija, match, reg);
		linija = match.str(0);
		int i = stoi(linija);
		if (i >= 32767 || i <= -32768) {
			cout << "Prevelika vrednost za 2B!" << endl;
			return -3;
		}
		stringstream sstream;
		if (i >= 0) {
			sstream << std::setfill('0') << setw(4) << hex << i;
		}
		else {
			i = 65536 + i;
			sstream << setw(4) << hex << i;
		}
		string pom = sstream.str();
		string pom1 = pom.substr(0, 2);
		string pom2 = pom.substr(2, 2);
		trenutna_sekcija->kod.push_back(pom2);
		trenutna_sekcija->kod.push_back(pom1);
		vrati += 2;
		uspesno = true;
		reg.assign("^(r[0-7]|sp|pc)\\[\\d+\\]\\s*,\\s*");
		linija = regex_replace(l, reg, "");
	}
	//reg indirektno sa pom
	reg.assign("^(r[0-7]|sp|pc|psw)\\[[a-zA-Z_]+\\w*\\]\\s*,");
	if (regex_search(linija, match, reg)) {
		string l = linija;
		bool pc = false;
		reg.assign("^r0");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("80");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r1");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("82");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r2");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("84");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r3");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("85");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r4");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("88");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^r5");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("8A");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r6|sp)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("8C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(r7|psw)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("8E");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^pc");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("8E");
			linija = regex_replace(linija, reg, "");
			pc = true;
		}
		vrati += 1;
		reg.assign("^\\[");
		linija = regex_replace(linija, reg, "");
		reg.assign("^[a-zA-Z_]+\\w*");
		regex_search(linija, match, reg);
		linija = match.str(0);
		bool nadjen = false;
		int i = 0, adr = 0;
		for (i = 0; i < sekcije.size(); i++) {
			for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
				if (sekcije[i]->simboli[j]->ime == linija) {
					nadjen = true;
					if (sekcije[i] == trenutna_sekcija && sekcije[i]->simboli[j]->vidljivost == 'l' && pc) {
						adr = sekcije[i]->simboli[j]->vrednost - sl_adr;
						linija = to_string(adr);
						i = sekcije.size();
						break;
					}
					string offset = "";
					adr = brojac_lokacija + 2;
					offset = to_string(adr);
					string tip = "R_386_PC16";
					int vrednost = 0;
					if (pc) {
						if (sekcije[i]->simboli[j]->vidljivost == 'l') {
							vrednost = sekcije[i]->redni_broj;
							adr = sekcije[i]->simboli[j]->vrednost;
							linija = to_string(adr);
						}
						else {
							vrednost = sekcije[i]->simboli[j]->redni_broj;
							adr = 0;
							linija = to_string(adr);
						}
					}
					else {
						tip = "R_386_16";
						if (sekcije[i]->simboli[j]->vidljivost == 'l') {
							vrednost = sekcije[i]->redni_broj;
							adr = sekcije[i]->simboli[j]->vrednost - 2;
							linija = to_string(adr);
						}
						else {
							vrednost = sekcije[i]->simboli[j]->redni_broj;
							adr = 0 - 2;
							linija = to_string(adr);
						}
					}
					Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
					trenutna_sekcija->relokacije.push_back(nova_relokacija);
					i = sekcije.size();
					break;
				}
			}
		}

		if (!nadjen) {
			cout << "Ne postoji simbol: " << linija << endl;
			return -3;
		}

		i = stoi(linija);
		stringstream sstream;
		if (i >= 0) {
			sstream << std::setfill('0') << setw(4) << hex << i;
		}
		else {
			i = 65536 + i;
			sstream << setw(4) << hex << i;
		}
		string pom = sstream.str();
		string pom1 = pom.substr(0, 2);
		string pom2 = pom.substr(2, 2);
		trenutna_sekcija->kod.push_back(pom2);
		trenutna_sekcija->kod.push_back(pom1);
		vrati += 2;
		uspesno = true;
		reg.assign("^(r[0-7]|sp|pc|psw)\\[[a-zA-Z_]+\\w*\\]\\s*,\\s*");
		linija = regex_replace(l, reg, "");
	}

	//pc relativno sa pom
	reg.assign("^\\$[a-zA-Z_]+\\w*\\s*,");
	if (regex_search(linija, match, reg)) {
		string l = linija;
		reg.assign("^\\$");
		linija = regex_replace(linija, reg, "");
		reg.assign("^[a-zA-Z_]+\\w*");
		regex_search(linija, match, reg);
		linija = match.str(0);
		trenutna_sekcija->kod.push_back("8E");
		bool nadjen = false;
		int i = 0, adr = 0;
		for (i = 0; i < sekcije.size(); i++) {
			for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
				if (sekcije[i]->simboli[j]->ime == linija) {
					nadjen = true;
					if (sekcije[i] == trenutna_sekcija && sekcije[i]->simboli[j]->vidljivost == 'l') {
						adr = sekcije[i]->simboli[j]->vrednost - sl_adr;
						linija = to_string(adr);
						i = sekcije.size();
						break;
					}
					string offset = "";
					adr = brojac_lokacija + 2;
					offset = to_string(adr);
					string tip = "R_386_PC16";
					int vrednost = 0;
					if (sekcije[i]->simboli[j]->vidljivost == 'l') {
						vrednost = sekcije[i]->redni_broj;
						adr = sekcije[i]->simboli[j]->vrednost - (brojac_lokacija - sl_adr + vrati + 1);
						linija = to_string(adr);
					}
					else {
						vrednost = sekcije[i]->simboli[j]->redni_broj;
						adr = 0 - (brojac_lokacija - sl_adr + vrati + 1);
						linija = to_string(adr);
					}
					Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
					trenutna_sekcija->relokacije.push_back(nova_relokacija);
					i = sekcije.size();
					break;
				}
			}
		}
		if (!nadjen) {
			cout << "Ne postoji simbol: " << linija << endl;
			return -3;
		}
		i = stoi(linija);
		stringstream sstream;
		if (i >= 0) {
			sstream << std::setfill('0') << setw(4) << hex << i;
		}
		else {
			i = 65536 + i;
			sstream << setw(4) << hex << i;
		}
		string pom = sstream.str();
		string pom1 = pom.substr(0, 2);
		string pom2 = pom.substr(2, 2);
		trenutna_sekcija->kod.push_back(pom2);
		trenutna_sekcija->kod.push_back(pom1);
		vrati += 2;
		uspesno = true;
		reg.assign("^\\$[a-zA-Z_]+\\w*\\s*,\\s*");
		linija = regex_replace(l, reg, "");
	}

	//memorijsko adr
	reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)\\s*,");
	if (regex_search(linija, match, reg)) {
		string l = linija;

		trenutna_sekcija->kod.push_back("A0");
		vrati += 1;
		reg.assign("^\\*-?\\d+");
		if (regex_search(linija, match, reg)) {
			linija = match.str(0);
			reg.assign("^\\*");
			linija = regex_replace(linija, reg, "");
			int i = stoi(linija);
			if (i >= 32767 || i <= -32768) {
				cout << "Prevelika vrednost za 2B!" << endl;
				return -3;
			}
			stringstream sstream;
			if (i >= 0) {
				sstream << std::setfill('0') << setw(4) << hex << i;
			}
			else {
				i = 65536 + i;
				sstream << setw(4) << hex << i;
			}
			string pom = sstream.str();
			string pom1 = pom.substr(0, 2);
			string pom2 = pom.substr(2, 2);
			trenutna_sekcija->kod.push_back(pom2);
			trenutna_sekcija->kod.push_back(pom1);
			vrati += 2;
		}
		reg.assign("^[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			linija = match.str(0);
			bool nadjen = false;
			int i = 0, adr = 0;
			for (i = 0; i < sekcije.size(); i++) {
				for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
					if (sekcije[i]->simboli[j]->ime == linija) {
						nadjen = true;
						string offset = "";
						adr = brojac_lokacija + 2;
						offset = to_string(adr);
						string tip = "R_386_16";
						int vrednost = 0;
						if (sekcije[i]->simboli[j]->vidljivost == 'l') {
							vrednost = sekcije[i]->redni_broj;
							linija = to_string(sekcije[i]->simboli[j]->vrednost);
						}
						else {
							vrednost = sekcije[i]->simboli[j]->redni_broj;
							linija = "0";
						}
						Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
						trenutna_sekcija->relokacije.push_back(nova_relokacija);
						i = sekcije.size();
						break;
					}
				}
			}
			if (!nadjen) {
				cout << "Ne postoji simbol: " << linija << endl;
				return -3;
			}
			i = stoi(linija);
			stringstream sstream;
			if (i >= 0) {
				sstream << std::setfill('0') << setw(4) << hex << i;
			}
			else {
				i = 65536 + i;
				sstream << setw(4) << hex << i;
			}
			string pom = sstream.str();
			string pom1 = pom.substr(0, 2);
			string pom2 = pom.substr(2, 2);
			trenutna_sekcija->kod.push_back(pom2);
			trenutna_sekcija->kod.push_back(pom1);
			vrati += 2;
		}

		uspesno = true;
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)\\s*,\\s*");
		linija = regex_replace(l, reg, "");
	}

	if (uspesno) {

		if (uslov == 0 || uslov == 1) {
			//neposredno
			reg.assign("^(-?\\d+|&[a-zA-Z_]+\\w*)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("00");
				vrati += 1;
				reg.assign("^-?\\d+");
				if (regex_search(linija, match, reg)) {
					linija = match.str(0);
					int i = stoi(linija);
					if (i >= 32767 || i <= -32768) {
						cout << "Prevelika vrednost za 2B!" << endl;
						return -3;
					}
					stringstream sstream;
					if (i >= 0) {
						sstream << std::setfill('0') << setw(4) << hex << i;
					}
					else {
						i = 65536 + i;
						sstream << setw(4) << hex << i;
					}
					string pom = sstream.str();
					string pom1 = pom.substr(0, 2);
					string pom2 = pom.substr(2, 2);
					trenutna_sekcija->kod.push_back(pom2);
					trenutna_sekcija->kod.push_back(pom1);
					vrati += 2;
				}
				reg.assign("^&[a-zA-Z_]+\\w*");
				if (regex_search(linija, match, reg)) {
					linija = match.str(0);
					reg.assign("^&");
					linija = regex_replace(linija, reg, "");
					bool nadjen = false;
					int i = 0, adr = 0;
					for (i = 0; i < sekcije.size(); i++) {
						for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
							if (sekcije[i]->simboli[j]->ime == linija) {
								nadjen = true;
								string offset = "";
								adr = brojac_lokacija + 1 + vrati;
								offset = to_string(adr);
								string tip = "R_386_16";
								int vrednost = 0;
								if (sekcije[i]->simboli[j]->vidljivost == 'l') {
									vrednost = sekcije[i]->redni_broj;
									linija = to_string(sekcije[i]->simboli[j]->vrednost);
								}
								else {
									vrednost = sekcije[i]->simboli[j]->redni_broj;
									linija = "0";
								}
								Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
								trenutna_sekcija->relokacije.push_back(nova_relokacija);
								i = sekcije.size();
								break;
							}
						}
					}
					if (!nadjen) {
						cout << "Ne postoji simbol: " << linija << endl;
						return -3;
					}
					i = stoi(linija);
					stringstream sstream;
					if (i >= 0) {
						sstream << std::setfill('0') << setw(4) << hex << i;
					}
					else {
						i = 65536 + i;
						sstream << setw(4) << hex << i;
					}
					string pom = sstream.str();
					string pom1 = pom.substr(0, 2);
					string pom2 = pom.substr(2, 2);
					trenutna_sekcija->kod.push_back(pom2);
					trenutna_sekcija->kod.push_back(pom1);
					vrati += 2;
				}
				return vrati;
			}
		}

		//reg indirektno
		reg.assign("^\\[(r[0-7]|sp|pc|psw)\\]");
		if (regex_search(linija, match, reg)) {
			reg.assign("^\\[");
			linija = regex_replace(linija, reg, "");
			reg.assign("^r0");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("40");
			}
			reg.assign("^r1");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("42");
			}
			reg.assign("^r2");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("44");
			}
			reg.assign("^r3");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("45");
			}
			reg.assign("^r4");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("48");
			}
			reg.assign("^r5");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("4A");
			}
			reg.assign("^(r6|sp)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("4C");
			}
			reg.assign("^(r7|pc|psw)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("4E");
			}
			vrati += 1;
			return vrati;
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[-?\\d+\\]");
		if (regex_search(linija, match, reg)) {
			reg.assign("^r0");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("80");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r1");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("82");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r2");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("84");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r3");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("85");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r4");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("88");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r5");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("8A");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^(r6|sp)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("8C");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^(r7|pc|psw)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("8E");
				linija = regex_replace(linija, reg, "");
			}
			vrati += 1;
			reg.assign("^\\[");
			linija = regex_replace(linija, reg, "");
			reg.assign("^-?\\d+");
			regex_search(linija, match, reg);
			linija = match.str(0);
			int i = stoi(linija);
			if (i >= 32767 || i <= -32768) {
				cout << "Prevelika vrednost za 2B!" << endl;
				return -3;
			}
			stringstream sstream;
			if (i >= 0) {
				sstream << std::setfill('0') << setw(4) << hex << i;
			}
			else {
				i = 65536 + i;
				sstream << setw(4) << hex << i;
			}
			string pom = sstream.str();
			string pom1 = pom.substr(0, 2);
			string pom2 = pom.substr(2, 2);
			trenutna_sekcija->kod.push_back(pom2);
			trenutna_sekcija->kod.push_back(pom1);
			vrati += 2;
			return vrati;
		}
		//reg indirektno sa pom
		reg.assign("^(r[0-7]|sp|pc|psw)\\[[a-zA-Z_]+\\w*\\]");
		if (regex_search(linija, match, reg)) {
			bool pc = false;
			reg.assign("^r0");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("80");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r1");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("82");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r2");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("84");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r3");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("85");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r4");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("88");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^r5");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("8A");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^(r6|sp)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("8C");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^(r7|psw)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("8E");
				linija = regex_replace(linija, reg, "");
			}
			reg.assign("^pc");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("8E");
				linija = regex_replace(linija, reg, "");
				pc = true;
			}
			vrati += 1;
			reg.assign("^\\[");
			linija = regex_replace(linija, reg, "");
			reg.assign("^[a-zA-Z_]+\\w*");
			regex_search(linija, match, reg);
			linija = match.str(0);
			bool nadjen = false;
			int i = 0, adr = 0;
			for (i = 0; i < sekcije.size(); i++) {
				for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
					if (sekcije[i]->simboli[j]->ime == linija) {
						nadjen = true;
						if (sekcije[i] == trenutna_sekcija && sekcije[i]->simboli[j]->vidljivost == 'l' && pc) {
							adr = sekcije[i]->simboli[j]->vrednost - sl_adr;
							linija = to_string(adr);
							i = sekcije.size();
							break;
						}
						string offset = "";
						adr = brojac_lokacija + 1 + vrati;
						offset = to_string(adr);
						string tip = "R_386_PC16";
						int vrednost = 0;
						if (pc) {
							if (sekcije[i]->simboli[j]->vidljivost == 'l') {
								vrednost = sekcije[i]->redni_broj;
								adr = sekcije[i]->simboli[j]->vrednost;
								linija = to_string(adr);
							}
							else {
								vrednost = sekcije[i]->simboli[j]->redni_broj;
								adr = 0;
								linija = to_string(adr);
							}
						}
						else {
							tip = "R_386_16";
							if (sekcije[i]->simboli[j]->vidljivost == 'l') {
								vrednost = sekcije[i]->redni_broj;
								adr = sekcije[i]->simboli[j]->vrednost - (brojac_lokacija - sl_adr + vrati + 1);
								linija = to_string(adr);
							}
							else {
								vrednost = sekcije[i]->simboli[j]->redni_broj;
								adr = 0 - (brojac_lokacija - sl_adr + vrati + 1);
								linija = to_string(adr);
							}
						}
						Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
						trenutna_sekcija->relokacije.push_back(nova_relokacija);
						i = sekcije.size();
						break;
					}
				}
			}
			if (!nadjen) {
				cout << "Ne postoji simbol: " << linija << endl;
				return -3;
			}
			i = stoi(linija);
			stringstream sstream;
			if (i >= 0) {
				sstream << std::setfill('0') << setw(4) << hex << i;
			}
			else {
				i = 65536 + i;
				sstream << setw(4) << hex << i;
			}
			string pom = sstream.str();
			string pom1 = pom.substr(0, 2);
			string pom2 = pom.substr(2, 2);
			trenutna_sekcija->kod.push_back(pom2);
			trenutna_sekcija->kod.push_back(pom1);
			vrati += 2;
			return vrati;
		}

		//pc relativno sa pom
		reg.assign("^\\$[a-zA-Z_]+\\w*");
		if (regex_search(linija, match, reg)) {
			string l = linija;
			reg.assign("^\\$");
			linija = regex_replace(linija, reg, "");
			reg.assign("^[a-zA-Z_]+\\w*");
			regex_search(linija, match, reg);
			linija = match.str(0);
			trenutna_sekcija->kod.push_back("8E");
			vrati += 1;
			bool nadjen = false;
			int i = 0, adr = 0;
			for (i = 0; i < sekcije.size(); i++) {
				for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
					if (sekcije[i]->simboli[j]->ime == linija) {
						nadjen = true;
						if (sekcije[i] == trenutna_sekcija && sekcije[i]->simboli[j]->vidljivost == 'l') {
							adr = sekcije[i]->simboli[j]->vrednost - sl_adr;
							linija = to_string(adr);
							i = sekcije.size();
							break;
						}
						string offset = "";
						adr = brojac_lokacija + 1 + vrati;
						offset = to_string(adr);
						string tip = "R_386_PC16";
						int vrednost = 0;
						if (sekcije[i]->simboli[j]->vidljivost == 'l') {
							vrednost = sekcije[i]->redni_broj;
							adr = sekcije[i]->simboli[j]->vrednost - (brojac_lokacija - sl_adr + vrati + 1);
							linija = to_string(adr);
						}
						else {
							vrednost = sekcije[i]->simboli[j]->redni_broj;
							adr = 0 - (brojac_lokacija - sl_adr + vrati + 1);
							linija = to_string(adr);
						}
						Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
						trenutna_sekcija->relokacije.push_back(nova_relokacija);
						i = sekcije.size();
						break;
					}
				}
			}
			if (!nadjen) {
				cout << "Ne postoji simbol: " << linija << endl;
				return -3;
			}
			i = stoi(linija);
			stringstream sstream;
			if (i >= 0) {
				sstream << std::setfill('0') << setw(4) << hex << i;
			}
			else {
				i = 65536 + i;
				sstream << setw(4) << hex << i;
			}
			string pom = sstream.str();
			string pom1 = pom.substr(0, 2);
			string pom2 = pom.substr(2, 2);
			trenutna_sekcija->kod.push_back(pom2);
			trenutna_sekcija->kod.push_back(pom1);
			vrati += 2;
			return vrati;
		}

		//reg direktno
		reg.assign("^(r[0-7]|sp|pc|psw)");
		if (regex_search(linija, match, reg)) {
			reg.assign("^r0");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("20");
			}
			reg.assign("^r1");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("22");
			}
			reg.assign("^r2");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("24");
			}
			reg.assign("^r3");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("25");
			}
			reg.assign("^r4");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("28");
			}
			reg.assign("^r5");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("2A");
			}
			reg.assign("^(r6|sp)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("2C");
			}
			reg.assign("^(r7|pc|psw)");
			if (regex_search(linija, match, reg)) {
				trenutna_sekcija->kod.push_back("2E");
			}
			vrati += 1;
			return vrati;
		}

		//memorijsko adr
		reg.assign("^([a-zA-Z_]+\\w*|\\*-?\\d+)");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("A0");
			vrati += 1;
			reg.assign("^\\*-?\\d+");
			if (regex_search(linija, match, reg)) {
				linija = match.str(0);
				reg.assign("^\\*");
				linija = regex_replace(linija, reg, "");
				int i = stoi(linija);
				if (i >= 32767 || i <= -32768) {
					cout << "Prevelika vrednost za 2B!" << endl;
					return -3;
				}
				stringstream sstream;
				if (i >= 0) {
					sstream << std::setfill('0') << setw(4) << hex << i;
				}
				else {
					i = 65536 + i;
					sstream << setw(4) << hex << i;
				}
				string pom = sstream.str();
				string pom1 = pom.substr(0, 2);
				string pom2 = pom.substr(2, 2);
				trenutna_sekcija->kod.push_back(pom2);
				trenutna_sekcija->kod.push_back(pom1);
				vrati += 2;
			}
			reg.assign("^[a-zA-Z_]+\\w*");
			if (regex_search(linija, match, reg)) {
				linija = match.str(0);
				bool nadjen = false;
				int i = 0, adr = 0;
				for (i = 0; i < sekcije.size(); i++) {
					for (int j = 0; j < sekcije[i]->simboli.size(); j++) {
						if (sekcije[i]->simboli[j]->ime == linija) {
							nadjen = true;
							string offset = "";
							adr = brojac_lokacija + 1 + vrati;
							offset = to_string(adr);
							string tip = "R_386_16";
							int vrednost = 0;
							if (sekcije[i]->simboli[j]->vidljivost == 'l') {
								vrednost = sekcije[i]->redni_broj;
								linija = to_string(sekcije[i]->simboli[j]->vrednost);
							}
							else {
								vrednost = sekcije[i]->simboli[j]->redni_broj;
								linija = "0";
							}
							Relokacija* nova_relokacija = new Relokacija(offset, tip, vrednost);
							trenutna_sekcija->relokacije.push_back(nova_relokacija);
							i = sekcije.size();
							break;
						}
					}
				}
				if (!nadjen) {
					cout << "Ne postoji simbol: " << linija << endl;
					return -3;
				}
				i = stoi(linija);
				stringstream sstream;
				if (i >= 0) {
					sstream << std::setfill('0') << setw(4) << hex << i;
				}
				else {
					i = 65536 + i;
					sstream << setw(4) << hex << i;
				}
				string pom = sstream.str();
				string pom1 = pom.substr(0, 2);
				string pom2 = pom.substr(2, 2);
				trenutna_sekcija->kod.push_back(pom2);
				trenutna_sekcija->kod.push_back(pom1);
				vrati += 2;
			}
			return vrati;
		}

	}
	return -3;
}

int Instrukcije::kod_instrukcije(string l, Sekcija* trenutna_sekcija, vector<Sekcija*>& sekcije, int brojac_lokacija, int sl_adr) {
	linija = l;
	reg.assign("^(halt|ret|iret)");
	if (regex_search(linija, match, reg)) {
		reg.assign("^halt");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("0C");
		}
		reg.assign("^ret");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("C4");
		}
		reg.assign("^iret");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("CC");
		}
		return 1;
	}

	reg.assign("^(not|pop|jmp|jeq|jne|jgt|call)\\s+");
	if (regex_search(linija, match, reg)) {
		
		reg.assign("^not\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("54");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^pop\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("94");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^jmp\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("9C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^jeq\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("A4");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^jne\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("AC");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^jgt\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("B4");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^call\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("BC");
			linija = regex_replace(linija, reg, "");
		}

		return (1 +  Instrukcije::adresiranje_2B_1op(linija, trenutna_sekcija, sekcije, brojac_lokacija,0, sl_adr));

	}

	reg.assign("^(notw|popw|jmpw|jeqw|jnew|jgtw|callw)\\s+");
	if (regex_search(linija, match, reg)) {
		
		reg.assign("^notw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("54");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^popw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("94");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^jmpw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("9C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^jeqw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("A4");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^jnew\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("AC");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^jgtw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("B4");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^callw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("BC");
			linija = regex_replace(linija, reg, "");
		}

		return (1 + Instrukcije::adresiranje_2B_1op(linija, trenutna_sekcija, sekcije, brojac_lokacija, 0, sl_adr));

	}

	reg.assign("^(notb|popb|jmpb|jeqb|jneb|jgtb|callb)\\s+");
	if (regex_search(linija, match, reg)) {
		
		reg.assign("^notb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("50");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^popb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("90");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^jmpb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("98");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^jeqb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("A0");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^jneb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("A8");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^jgtb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("B0");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^callb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("B8");
			linija = regex_replace(linija, reg, "");
		}

		return (1 + Instrukcije::adresiranje_1B_1op(linija, trenutna_sekcija, sekcije, brojac_lokacija, 0, sl_adr));
	}

	reg.assign("^(push|pushw|int|intw)\\s+");
	if (regex_search(linija, match, reg)) {

		reg.assign("^(intw|int)\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("1C");
			linija = regex_replace(linija, reg, "");
		}

		reg.assign("^(push|pushw)\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("8C");
			linija = regex_replace(linija, reg, "");
		}

		return (1 + Instrukcije::adresiranje_2B_1op(linija, trenutna_sekcija, sekcije, brojac_lokacija, 1, sl_adr));
	}

	reg.assign("^(pushb|intb)\\s+");
	if (regex_search(linija, match, reg)) {

		reg.assign("^intb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("18");
			linija = regex_replace(linija, reg, "");
		}

		reg.assign("^pushb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("88");
			linija = regex_replace(linija, reg, "");
		}
		
		return (1 + Instrukcije::adresiranje_1B_1op(linija, trenutna_sekcija, sekcije, brojac_lokacija, 1, sl_adr));
	}

	reg.assign("^(mov|add|sub|mul|div|and|or|xor|shl|shr)\\s+");
	if (regex_search(linija, match, reg)) {
		reg.assign("^mov\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("24");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^add\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^sub\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("34");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^mul\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("3C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^div\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("44");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^and\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("5C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^or\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("64");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^xor\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^shl\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("7C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^shr\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("84");
			linija = regex_replace(linija, reg, "");
		}

		return (1 + Instrukcije::adresiranje_2B_2op(linija, trenutna_sekcija, sekcije, brojac_lokacija, 0, sl_adr));
	}

	reg.assign("^(movw|addw|subw|mulw|divw|andw|orw|xorw|shlw|shrw)\\s+");
	if (regex_search(linija, match, reg)) {
		reg.assign("^movw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("24");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^addw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("2C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^subw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("34");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^mulw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("3C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^divw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("44");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^andw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("5C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^orw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("64");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^xorw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("6C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^shlw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("7C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^shrw\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("84");
			linija = regex_replace(linija, reg, "");
		}
		
		return (1 + Instrukcije::adresiranje_2B_2op(linija, trenutna_sekcija, sekcije, brojac_lokacija, 0, sl_adr));
	}

	reg.assign("^(movb|addb|subb|mulb|divb|andb|orb|xorb|shlb|shrb)\\s+");
	if (regex_search(linija, match, reg)) {
		reg.assign("^movb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("20");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^addb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("28");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^subb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("30");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^mulb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("38");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^divb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("40");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^andb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("58");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^orb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("60");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^xorb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("68");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^shlb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("78");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^shrb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("80");
			linija = regex_replace(linija, reg, "");
		}

		return (1 + Instrukcije::adresiranje_1B_2op(linija, trenutna_sekcija, sekcije, brojac_lokacija, 0, sl_adr));
	}

	reg.assign("^(xchg|xchgw)\\s+");
	if (regex_search(linija, match, reg)) {
		trenutna_sekcija->kod.push_back("14");
		linija = regex_replace(linija, reg, "");

		return (1 + Instrukcije::adresiranje_2B_2op(linija, trenutna_sekcija, sekcije, brojac_lokacija, 2, sl_adr));
	}

	reg.assign("^xchgb\\s+");
	if (regex_search(linija, match, reg)) {
		trenutna_sekcija->kod.push_back("10");
		linija = regex_replace(linija, reg, "");

		return (1 + Instrukcije::adresiranje_1B_2op(linija, trenutna_sekcija, sekcije, brojac_lokacija, 2, sl_adr));
	}

	reg.assign("^(cmp|cmpw|test|testw)\\s+");
	if (regex_search(linija, match, reg)) {
		reg.assign("^(cmp|cmpw)\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("4C");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^(test|testw)\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("74");
			linija = regex_replace(linija, reg, "");
		}

		return (1 + Instrukcije::adresiranje_2B_2op(linija, trenutna_sekcija, sekcije, brojac_lokacija, 1, sl_adr));
	}

	reg.assign("^(cmpb|testb)\\s+");
	if (regex_search(linija, match, reg)) {
		reg.assign("^cmpb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("48");
			linija = regex_replace(linija, reg, "");
		}
		reg.assign("^testb\\s+");
		if (regex_search(linija, match, reg)) {
			trenutna_sekcija->kod.push_back("70");
			linija = regex_replace(linija, reg, "");
		}

		return (1 + Instrukcije::adresiranje_1B_2op(linija, trenutna_sekcija, sekcije, brojac_lokacija, 1, sl_adr));
	}
}