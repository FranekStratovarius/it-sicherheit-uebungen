#include <stdio.h>
#include <stdlib.h>


int g(int x) {
    // Bitte ausprogrammieren
    // Bitte nichts außerhalb dieser Funktion verändern.
    // Auch die Deklaration von g darf nicht verändert werden.

	// bessere lösung?: nach der 7 im speiche rper loop suchen,
	// i auf -2000000 setzen und die 0 überspringen
	int evil = 0;
	int* ptri = &evil + 12;
	int* ptry = &evil + 11;

	if (*ptry < 999999999) {
		(*ptry)++;
		*ptri = 1;
	} else {
		*ptri = 10;
	}

	return 0;
}


void f() {
    int y = 7;
    int i = 0;
    for (i = 0; i < 10; i++) {
        printf("i: %d, g(i): %d\n", i, g(i));
    }
    printf("value of y: %d\n", y);
}



int main()
{
    f();
    return 0;
}