//ADVERB.CPP
//IMPLEMENTATION SECTION

#include <iostream>
#include <string>
#include "Word.h"
#include "Adverb.h"

using namespace std;

string Adverb::wordType = "(adv.)";


//DEFAULT
Adverb::Adverb() {

}

Adverb::Adverb(string wordIn, string definitionIn) {

	word = wordIn;
	definition = definitionIn;
	definition.insert(0, wordType);

}

string Adverb::getWord() {
	return word;
}

string Adverb::getDefinition() {

	return definition;

}