#include <stdio.h>
#include <stdlib.h>

#include "crack.h"

int main() {
	//*
	{
		uint32 hash0[] = {
			0x65caa18f,
			0x6f33d5e8,
			0x9493dc60,
			0x8eb00551,
			0x26c34997
		};
		// = kurz

		uint32 hash1[] = {
			0xd27eb556,
			0x73c666c0,
			0xc12873cc,
			0x6ed592bf,
			0xe59ff958
		};
		// = 0177812630

		uint32 hash2[] = {
			0xfe5f8164,
			0x1092ee46,
			0xc40e84c4,
			0x493a757a,
			0xadc3e65e
		};
		// = G1mpelh4us

		uint32 hash3[] = {
			0xf017feec,
			0x7a814d6b,
			0x74eb0a55,
			0x3f97c702,
			0x1b5528ef
		};
		// = 970211

		uint32 hash4[] = {
			0x47ab9979,
			0x443fb7ed,
			0x1c193d06,
			0x773333ba,
			0x7876094f
		};
		// = 010

		// char* word = bruteForceCrackThreaded(hash4, "01", 2);
		char* word = bruteForceCrackThreaded(hash1, "0123456789", 10);
		// char* word = bruteForceCrackThreaded(hash0, "abcdefghijklmnopqrstuvwxyz", 26);
		// char* word = bruteForceCrack(hash0, "abcdefghijklmnopqrstuvwxyz0123456789", 36);
		// char* word = bruteForceCrackThreaded(hash0, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", 62);

		printf(
			"password found: %s\n",
			word
		);
		free(word);
	}
	//*/

	// dict crack
	/*
	{
		uint32 hash0[] = {
			0xde145a20,
			0x3f49e2ef,
			0x682b434d,
			0x4e9d241d,
			0xfe7c4b4f
		};
		// = recurvate

		uint32 hash1[] = {
			0xc2ba2660,
			0x15990e82,
			0x29267fbb,
			0x1121568b,
			0x4a5e981d
		};
		// = SynWorksDemoAGA

		uint32 hash2[] = {
			0xdd3deb7b,
			0x9e98f6d1,
			0x89e5c365,
			0x08b0c55e,
			0x1697195a
		};
		// = overnighter

		wordVec* dictionary = loadPasswordList("assets/dic-0294.txt");

		char* word = dictCrack1(hash2, dictionary);

		printf(
			"password found: %s\n",
			word
		);

		free(word);
		freeWordVec(dictionary);
	}
	//*/

	return 0;
}