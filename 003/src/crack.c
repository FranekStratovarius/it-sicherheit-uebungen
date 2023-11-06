#include <math.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

#include "crack.h"
#include "sha1.h"

/**
 * Initializes the word vector with a capacity of 16 words.
 */
wordVec *initWordVec(void) {
    wordVec *wv = (wordVec*)calloc(1, sizeof(wordVec));
    wv->wordCount = 0;
    wv->capacity = 16;
    wv->words = (char**)calloc(wv->capacity, sizeof(char*));
    return wv;
}

/**
 * Frees all memory used in the word vector including the 
 * memory allocated for the strings of the vector.
 */
void freeWordVec(wordVec *wv) {
    uint32 i;
    for (i = 0; i < wv->wordCount; i++) {
        free(wv->words[i]);
    }
    free(wv->words);
    free(wv);
}

/**
 * Doubles the capacity of the word vector.
 */
void doubleCapacity(wordVec *wv) {
    char** newWordsPointer = (char**)realloc(wv->words, wv->capacity * 2 * sizeof(char*));
    if (newWordsPointer != NULL) {
        wv->capacity = wv->capacity * 2;
        wv->words = newWordsPointer;
        return;
    }
    fprintf(stderr, "Could not double capacity of wordVec.");
    exit(1);
}

/**
 * Adds the given word to the word vector. The capacity of 
 * the vector is increased, if necessary. The word is not
 * copied, so do not free the memory occupied by word unless
 * you know what you are doing.
 */
void add(wordVec *wv, char* word) {
    if (wv->wordCount >= wv->capacity) doubleCapacity(wv);
    wv->words[wv->wordCount] = word;
    wv->wordCount++;
}


/**
 * Copies the content of the 0-terminated string line into
 * a new 0-terminated string that occupies exactly as much
 * memory as is needed to hold the content.
 */
char* copyLine(char* line) {
    uint32 count = 0;
    uint32 i;
    char* s;
    while (line[count] != 0) count++;
    count++;
    s = (char*)calloc(count, sizeof(char));
    for (i = 0; i < count; i++) {
        s[i] = line[i];
    }
    return s;
}


/**
 * Loads a list of passwords from the file implied by the
 * given fileName. This file has to contain a list of words
 * all terminated by a line-break. All of the words in the
 * list have to have at most 39 chars, otherwise this function
 * is prone to buffer-overflows. You have been warned.
 */
wordVec *loadPasswordList(char* fileName) {
    FILE *f;
    wordVec *wv = initWordVec();
    uint32 err;
    char* line = (char*)calloc(40, sizeof(char));
    f = fopen(fileName, "r");
    err = fscanf(f, "%s", line);
    while (err != EOF) {
        add(wv, copyLine(line));
        err = fscanf(f, "%s", line);
    }
    return wv;
}

/*
 * Print all words in word vector.
 */
void print(wordVec *wv) {
    uint32 i;
    printf("wordCount: %d", wv->wordCount);
    for (i = 0; i < wv->wordCount; i++) {
        printf("%s\n", wv->words[i]);
    }
}

/**
 * Returns TRUE if and only if the two given hashes equal.
 * The hashes have to be stored in uint32-arrays of size 5.
 */
boolean hashesEqual(uint32 *h1, uint32 *h2) {
    uint32 i;
    for (i = 0; i < 5; i++) {
        if (h1[i] != h2[i]) return FALSE;
    }
    return TRUE;
}

/*
 * Get index and alphabet and return word created from alphabet.
 */
char* createWordFromAlphabet(
	char* alphabet, uint8 alphabetSize, uint32 index, uint32 length
) {
	char* word = (char*)calloc(length + 1, sizeof(char));

	for (uint32 i = 0; i < length; i++) {
		uint8 letter = index % alphabetSize;
		word[i] = alphabet[letter];
		index = index / alphabetSize;
	}

	word[length] = '\0';
	return word;
}

/*
 * Create hash from word and compare it with the given hash.
 */
boolean checkHash(char* word, uint32* sha1Hash) {
	bitBlock* currentWordBitBlock = forChars(word);
	
	// uint32* currentHash = sha1(currentWordBitBlock);
	bitBlock* currentWordBitBlockPadded = pad(currentWordBitBlock);
	freeBitBlock(currentWordBitBlock);
	uint32* currentHash = sha1Faster(currentWordBitBlockPadded);
	freeBitBlock(currentWordBitBlockPadded);

	if (hashesEqual(sha1Hash, currentHash)) {
		for (int i = 0; i < 5; i++) {
			printf("%x", currentHash[i]);
		}
		printf("\n");
		free(currentHash);
		return 1;
	} else {
		free(currentHash);
		return 0;
	}
}

/*
 * Try to find string to given hash with brute force in given alphabet.
 */
char* bruteForceCrack(uint32* sha1Hash, char* alphabet, uint8 alphabetSize) {
	// loop over possible lengthes of words
	for (uint32 length = 1; length < 10; length++) {
		// calculate max index of words to be generated
		uint32 maxIndex = (int)pow(alphabetSize, length);
		for (uint32 i = 0; i < maxIndex; i++) {
			// generate word from index in given alphabet
			char* word = createWordFromAlphabet(
				alphabet,
				alphabetSize,
				i,
				length
			);
			// and check word with hash
			if (checkHash(word, sha1Hash)) {
				return word;
			}
			free(word);
		}
	}
	return "could not find password";
}

/*
 * This function runs in the extra threads and tries to find the right word.
 */
void *bruteForceCrackThread(void *argument) {
	thread_data *tdata = (thread_data*)argument;

	for (uint32 length = 1; length < 16; length++) {
		// calculate max index of words to be generated
		uint64 maxIndex = (int)pow(tdata->alphabetSize, length);
		for (uint64 i = 0; i < maxIndex; i += tdata->threadCount) {
			if (*tdata->finished == TRUE) {
				pthread_exit(NULL);
			}
			// generate word from index in given alphabet
			char* word = createWordFromAlphabet(
				tdata->alphabet,
				tdata->alphabetSize,
				i - tdata->threadId,
				length
			);
			// and check word with hash
			if (checkHash(word, tdata->sha1Hash)) {
				*tdata->finished = TRUE;
				*tdata->wordpointer = word;
				pthread_exit(NULL);
			}
			free(word);
		}
	}
	pthread_exit(NULL);
}

/*
 * Try to find string to given hash with brute force in given alphabet.
 */
char* bruteForceCrackThreaded(uint32* sha1Hash, char* alphabet, uint8 alphabetSize) {
	pthread_t* threads = calloc(THREADS, sizeof(pthread_t));
	thread_data** tdatas = calloc(THREADS, sizeof(thread_data*));
	char* word = NULL;
	boolean finished = FALSE;
	for (int i = 0; i < THREADS; i++) {
		tdatas[i] = malloc(sizeof(thread_data));
		tdatas[i]->sha1Hash = sha1Hash;
		tdatas[i]->alphabet = alphabet;
		tdatas[i]->alphabetSize = alphabetSize;
		tdatas[i]->threadCount = THREADS;
		tdatas[i]->threadId = i;
		tdatas[i]->wordpointer = &word;
		tdatas[i]->finished = &finished;

		pthread_create(
			&threads[i],
			NULL,
			bruteForceCrackThread,
			(void*)tdatas[i]
		);
	}

	for (int i = 0; i < THREADS; i++) {
		pthread_join(threads[i], NULL);
		free(tdatas[i]);
	}
	free(tdatas);

	free(threads);

	return word;
}

/*
 * Try to find string to given hash from list of given words.
 */
char *dictCrack1(uint32 *sha1Hash, wordVec *dictionary) {
	// loop through dictionary
	for (int i = 0; i < dictionary->wordCount; i++) {
		// get word
		char* word = dictionary->words[i];
		// and check word with hash
		if (checkHash(word, sha1Hash)) {
			return word;
		}
	}
	return "could not find password in dictionary";
}