#ifndef CRACK_H
#define CRACK_H

#include "sha1.h"

typedef struct {
    char** words;
    // number of words that can be stored in the words array
    uint32 capacity;
    // number of words that really are stored in the words array
    uint32 wordCount;
} wordVec;

/**
 * Loads a list of passwords from the file implied by the
 * given fileName. This file has to contain a list of words
 * all terminated by a line-break. All of the words in the
 * list have to have at most 39 chars, otherwise this function
 * is prone to buffer-overflows. You have been warned.
 */
wordVec *loadPasswordList(char* fileName);

/**
 * Frees all memory used in the word vector including the 
 * memory allocated for the strings of the vector.
 */
void freeWordVec(wordVec *wv);

/*
 * Try to find string to given hash with brute force in given alphabet.
 */
char* bruteForceCrack(uint32* sha1Hash, char* alphabet, uint8 alphabetSize);

/*
 * Try to find string to given hash from list of given words.
 */
char *dictCrack1(uint32 *sha1Hash, wordVec *wv);

#endif // CRACK_H