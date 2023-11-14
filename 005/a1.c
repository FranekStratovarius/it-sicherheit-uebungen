#include <stdio.h>
#include <stdlib.h>


int g(int x) {
    // Bitte ausprogrammieren
    // Bitte nichts außerhalb dieser Funktion verändern.
    // Auch die Deklaration von g darf nicht verändert werden.
	volatile int evil = 0;
	volatile int* ptri = &evil + 12;
	volatile int* ptry = &evil + 11;
	
	if (*ptry < 3000000) {
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