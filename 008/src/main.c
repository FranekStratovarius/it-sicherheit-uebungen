#include <stdio.h>

int modulo(int x, int modulo) {
	int result = x % modulo;
	if (result < 0) {
		result = modulo + result;
	}
	return result;
}

int isEquivalent(int x, int y, int m) {
	return modulo(x, m) == y;
}

int isPrime(int x) {
	for (int i = 2; i < x; i++) {
		float result = x / (float)i;
		if (result - (int)result == 0) {
			return i;
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
	printf("modulo: %i\n", isEquivalent(15, 3, 4));
	printf("modulo: %i\n", isEquivalent(15, 2, 4));
	printf("modulo: %i\n", isEquivalent(-19, 11, 15));

	printf("---\n");

	printf("isPrime: %i\n", isPrime(9239897));
	printf("isPrime: %i\n", isPrime(9277));

	printf("---\n");

	printf("euklid: %i\n", euklid(22, 33));
	return 0;
}