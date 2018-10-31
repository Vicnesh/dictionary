//ADJECTIVE.CPP

//IMPLEMENTATION SECTION

#include <iostream>
#include <string>
#include "Word.h"
#include "Adjective.h"


string Adjective::wordType = "(adj.)";

//DEFAULT
Adjective::Adjective() {

}

Adjective::Adjective(string wordIn, string definitionIn) {

	word = wordIn;
	definition = definitionIn;
	definition.insert(0, wordType);

}

string Adjective::getWord() {
	return word;
}

string Adjective::getDefinition() {

	return definition;

}