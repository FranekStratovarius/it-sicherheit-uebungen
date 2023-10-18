
#include <stdio.h>
#include <stdlib.h>
#include "largeInt.h"

/**
 ** Returns the number of leading zeroes of the given argument.
 **
 ** A leading zero is a binary digit of the given arg that is set
 ** to 0 and to the left of which only appear 0's.
 **/
uint8 GetNumberOfLeadingZeroes(uint32 arg) {
	uint32 mask = 0x80000000U;
	uint8 count = 0;

	while (((arg & mask) == 0) && (count < 32)) {
		mask = mask >> 1;
		count++;
	}
	return count;
}

/**
 ** \brief Checks for leading zeroes and, based on the number of these,
 **		computes b->usedWords and b->bitSize.
 **
 ** \param[in] b The BigInt, for which to compute the usage values.
 **/
void RecomputeUsageVariables(LargeInt* b) {
	uint32 i;
	uint32* dataPointer;

	i = b->wordSize - 1;
	dataPointer = &(b->data[i]);

	while (((*dataPointer) == 0) && (i>0)) {
		i--;
		dataPointer--;
	}
	
	b->bitSize = 32 - GetNumberOfLeadingZeroes((*dataPointer)) + (i * BITSPERWORD);
	if (b->bitSize == 0) {
		b->usedWords = 0;
	} else {
		b->usedWords = i + 1;
	}
}

/**
 ** Returns TRUE if and only if the given LargeInt is even.
 **/
boolean IsEven(const LargeInt* b) {
	// Bitte implementieren!
	return (b->data[0]+1) & 1;
}

/**
 ** Returns TRUE if and only if the given LargeInt is odd.
 **/
boolean IsOdd(const LargeInt* b) {
	// Bitte implementieren!
	return b->data[0] & 1;
}

/**
 ** Initializes a new LargeInt with the given integer value.
 **
 ** \param[in] value The value that is to be passed to the new LargeInt.
 ** \param[wordSize] The number of 32-Bit-words that shall used in the new LargeInt.
 ** \return A LargeInt that has been initialized with the given value.
 **/
LargeInt* InitLargeIntWithUint32(uint32 value, uint8 wordSize) {
	LargeInt* x = (LargeInt*)calloc(1, sizeof(LargeInt));
	x->data = (uint32*)calloc(wordSize, sizeof(uint32));
	x->wordSize = wordSize;
	
	if (value == 0) {
		x->usedWords = 0;
		x->bitSize = 0;
	} else {
		x->usedWords = 0;
		x->bitSize = 32 - GetNumberOfLeadingZeroes(value);
		while (value > 0) {
			x->data[x->usedWords] = value & STANDARD_USEBIT_MASK;   
			x->usedWords++;
			value = value >> BITSPERWORD;
		} 
	}
	return x;
}

/**
 * Frees the memory of the given LargeInt.
 */
void freeLargeInt(LargeInt* x) {
	free(x->data);
	free(x);
}

/**
 ** \brief Adds the two given summands and returns the result.
 **
 ** This algorithm treats the arguments as if they were both
 ** positive, i.e. the sign of the integers is ignored.
 **
 ** \param[in] s1 The first summand.
 ** \param[in] s2 The second summand.
 ** \result The sum of s1 and s2. The word size of the result
 **		 is exactly as large as needed to hold the sum.
 **
 **/
LargeInt* Add(LargeInt* s1, LargeInt* s2) {
	// unterschiedliche wordsizes werden nicht gehandhabt!
	// Bitte implementieren!

	uint8 wordSize = 0;
	// word size überprüfen
	if (s1->wordSize == s2->wordSize) {
		// berechnen ob extrawordsize benötigt
		uint32 result = s1->data[s1->wordSize - 1] + s2->data[s2->wordSize - 1];
		boolean carry = (result & (1 << (BITSPERWORD))) != 0;
		if (carry) {
			wordSize = s1->wordSize + 1;
		} else {
			wordSize = s1->wordSize;
		}
	} else {
		// wordsize auf größeren wert setzen
		wordSize = s1->wordSize > s2->wordSize ? s1->wordSize : s2->wordSize;
	}

	// LargeInt initialisieren
	LargeInt* out = (LargeInt*)calloc(1, sizeof(LargeInt));
	out->data = (uint32*)calloc(wordSize, sizeof(uint32));
	out->wordSize = wordSize;
	out->usedWords = wordSize;

	// carry ist anfangs 0
	boolean carry = 0;
	// über alle teile aus data iterieren
	for (int wordIndex = 0; wordIndex < wordSize; wordIndex++) {
		// TODO: check ob ein data leer ist
		// beide zahlen addieren
		uint32 result = s1->data[wordIndex] + s2->data[wordIndex] + carry;
		// carry auslesen
		carry = (result & (1 << BITSPERWORD)) != 0;
		// ergebnis in data schreiben
		out->data[wordIndex] = carry ? result - (1 << BITSPERWORD) : result;
	}
	// index der vordersten zahl ausrechnen
	out->bitSize = (wordSize - 1)
		* BITSPERWORD
		+ 32 - GetNumberOfLeadingZeroes(out->data[wordSize - 1]);
	return out;
}

void printLargeInt(LargeInt *x) {
	int i = x->bitSize - 1;
	while (i >= 0) {
		int wordIndex = i / BITSPERWORD;
		int bitIndex = i % BITSPERWORD;
		uint32 testBit = 1 << bitIndex;
		if ((x->data[wordIndex] & testBit) != 0) {
			printf("1");
		} else {
			printf("0");
		}
		i--;
	}
	printf("\n");
}