#include <stdio.h>
#include "largeInt.h"

// Verstehen Sie die untige main-Funktion bitte als Anstoß zum 
// Testen Ihres Codes. Fügen Sie weitere, sinnvolle Tests hinzu!
int main() {
	LargeInt* x = InitLargeIntWithUint32(31, 2);
	LargeInt* y = InitLargeIntWithUint32(2, 2);
	//LargeInt* x = InitLargeIntWithUint32(70035, 5);
	//LargeInt* y = InitLargeIntWithUint32(80002, 5);
	printLargeInt(x);
	//printf("%i\n", IsEven(x));
	//printf("%i\n", IsOdd(x));
	printLargeInt(y);
	LargeInt* z = Add(x, y);
	printLargeInt(z);
	return 0;
}