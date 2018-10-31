//VERB.CPP
//	IMPLEMENTATION SECTION

#include <iostream>
#include <string>
#include "Word.h"
#include "Verb.h"

using namespace std;

//DEFINE WORDTYPE FOR NOUN
string Verb::wordType = "(v.)";


//DEFAULT CONSTRUCTOR FOR VERB

Verb::Verb() {

}

Verb::Verb(string wordIn, string definitionIn) {
	word = wordIn;
	definition = definitionIn;
	definition.insert(0, wordType);
}

string Verb::getWord() {
	return word;
}

string Verb::getDefinition() {
	return definition;
}