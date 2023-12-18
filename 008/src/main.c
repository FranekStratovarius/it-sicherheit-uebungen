#include <stdio.h>

int modulo(int x, int modulo) {
	int result = x % modulo;
	if (result < 0) {
		result += modulo;
	}
	return result;
}

int isEquivalent(int x, int y, int m) {
	if (m == 0) {
		return x == y;
	}
	return modulo(x, m) == modulo(y, m);
}

/*
 * possible optimizations: only go till root of x
 * only step in steps of 2 after i = 3 or 3 or 6...
 */
int isPrime(int x) {
	if (x < 2) {
		return 0;
	}
	for (int i = 2; i < x; i++) {
		int divided = x / i;
		if (divided * i == x) {
			return i;
			// return 0;
		}
	}
	return 1;
}

int euklid(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		return euklid(b, modulo(a, b));
	}
}

int main() {
	printf("modulo: %i\n", isEquivalent( 15,  3,  4));
	printf("modulo: %i\n", isEquivalent( 15,  2,  4));
	printf("modulo: %i\n", isEquivalent(-19, 11, 15));

	printf("---\n");

	printf("isPrime: %i\n", isPrime(9239897));
	printf("isPrime: %i\n", isPrime(   9277));

	printf("---\n");

	printf("euklid: %i\n", euklid(22, 33));
	return 0;
}