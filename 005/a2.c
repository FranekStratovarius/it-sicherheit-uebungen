#include <stdio.h>

void evil() {
	printf("i am evil\n");
}

void q() {
	// bitte modifizieren Sie nur im Bereich unterhalb dieser Zeile
    
	// Toben Sie sich hier aus!
	// bessere Lösung?: Auf dem Stack nach einer Adresse suchen, die in der Nähe von q ist
	// __builtin_return_address
	int evil_int = 0;
	*(&evil_int + 3) = (int)&evil;
    
	// bitte modifizieren Sie nur im Bereich oberhalb dieser Zeile
	printf("q is done \n");
}

void harmless() {
	q();
}

int main() {
	harmless();
	return 0;
}