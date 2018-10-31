//NOUN.CPP
//	IMPLEMENTATION SECTION

//	CONSTRUCTOR FOR DERIVED CLASS NOUN CREATED


#include <iostream>
#include <string>
#include "Word.h"
#include "Noun.h"

using namespace std;

//	DEFINE WORD TYPE FOR NOUN CLASS
string Noun::wordType = "(n.)";

//DEFAULT CONSTRUCTOR
Noun::Noun() {

}

//MANAGER FUNCTION
//	CONSTRUCTOR FOR W0RD->NOUN OBJECT
Noun::Noun(string wordIn, string definitionIn) {

	word = wordIn;
	definition = definitionIn;
	definition.insert(0, wordType);

}

string Noun::getWord() {
	word[0] = toupper((unsigned char)word[0]);
	return word;
}

string Noun::getDefinition() {
	return definition;
}