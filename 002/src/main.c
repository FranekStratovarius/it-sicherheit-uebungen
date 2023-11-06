#include <stdio.h>
#include "largeInt.h"

// Verstehen Sie die untige main-Funktion bitte als Anstoß zum 
// Testen Ihres Codes. Fügen Sie weitere, sinnvolle Tests hinzu!
int main() {
	int n1 = 1023;
	int n2 = 2047;
	LargeInt* x = InitLargeIntWithUint32(n1, 5);
	LargeInt* y = InitLargeIntWithUint32(n2, 3);
	//LargeInt* x = InitLargeIntWithUint32(70035, 5);
	//LargeInt* y = InitLargeIntWithUint32(80002, 5);
	printLargeInt(x);
	//printf("%i\n", IsEven(x));
	//printf("%i\n", IsOdd(x));
	printLargeInt(y);
	LargeInt* z1 = Add(x, y);
	printLargeInt(z1);
	LargeInt* z2 = Multiply(x, y);
	printLargeInt(z2);
	printf("%b %i\n", n1 * n2, n1 * n2);
	return 0;
}
