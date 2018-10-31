//PROPERNOUN.CPP
//IMPLEMENTATION SECTION



#include <iostream>
#include <string>
#include "Noun.h"
#include "ProperNoun.h"

using namespace std;


string ProperNoun::wordType = "(pn.)";

ProperNoun::ProperNoun(string wordIn, string definitionIn) {

	word = wordIn;
	word[0] = toupper(word[0]);
	definition = definitionIn;
	definition.insert(0, wordType);

}

string ProperNoun::getWord() {
	return word;
}

string ProperNoun::getDefinition() {
	return definition;
}