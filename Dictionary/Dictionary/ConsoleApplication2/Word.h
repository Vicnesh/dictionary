//	WORD.H
//	DECLARATION SECTION


#ifndef WORD_H
#define WORD_H

#include <string>
using namespace std;


class Word {

public:
	Word();
	Word(string wordIn, string definitionIn);
	string getWord();
	virtual string getDefinition();
	bool isPalindrome();
	bool isVerb();
	bool isNoun();
	bool isAnagram(string wordIn);

protected:
	string word;
	string definition;

};

#endif