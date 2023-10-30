#include <stdio.h>
#include "largeInt.h"

// Verstehen Sie die untige main-Funktion bitte als Anstoß zum 
// Testen Ihres Codes. Fügen Sie weitere, sinnvolle Tests hinzu!
int main() {
	LargeInt* x = InitLargeIntWithUint32(206, 2);
	LargeInt* y = InitLargeIntWithUint32(21, 2);
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
	return 0;
}