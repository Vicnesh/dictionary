//DICTIONARY.H

#ifndef Dictionary_H
#define Dictionary_H

#include <iostream>
#include <string>
#include <vector>
#include "Word.h"

using namespace std;

//declaration
class Dictionary {

public:
	void loadDictionary();
	void determineWordType(string wordIn, string definitionIn, string wordTypeIn);
	int getTotalNumberofWords();
	Word* findWord(string wordIn);
	void findWordWithZ();
	bool wordhas3Z(string wordIn);
	void findWordWithQNoU();
	bool wordCheckQNoU(string wordIn);
	void listNounAndVerbs();
	void listPalindromes();
	void listAnagrams(string wordIn);
	void guessingGame();
	void addDictionary();
	void writeToFile();
	void deleteDictionary(string wordIn);
	void displayDictionary();

public:

	static const long int MAX_WORDS = 106184;
	int wordCounter = 0;
	vector<Word*> dictionary;

};

#endif
