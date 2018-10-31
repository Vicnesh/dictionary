//PREPOSITION.CPP
//IMPLEMENTATION SECTION

#include <iostream>
#include <string>
#include "Preposition.h"
#include "MiscWord.h"
#include "Word.h"

using namespace std;

string Preposition::wordType = "(prep.)";


Preposition::Preposition() {

}

Preposition::Preposition(string wordIn, string definitionIn) {
	word = wordIn;
	definition = definitionIn;
	definition.insert(0, wordType);
}


string Preposition::getWord() {
	return word;
}

string Preposition::getDefinition() {
	return definition;
}