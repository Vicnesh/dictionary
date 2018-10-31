//MISCWORD.CPP
//IMPLEMENTATION SECTION

#include <iostream>
#include <string>
#include "Word.h"
#include "MiscWord.h"

using namespace std;

string MiscWord::wordType = "(misc.)";

MiscWord::MiscWord() {

}

MiscWord::MiscWord(string wordIn, string definitionIn) {
	word = wordIn;
	definition = definitionIn;
	definition.insert(0, wordType);
}

string MiscWord::getWord() {
	return word;
}

string MiscWord::getDefinition() {
	return definition;
}