//NOUNANDVERB.CPP
//IMPLMENTATION SECTION

#include <iostream>
#include <string>
#include "Word.h"
#include "Noun.h"
#include "Verb.h"
#include "NounAndVerb.h"

using namespace std;

string NounAndVerb::wordType = "(n.v.)";

NounAndVerb::NounAndVerb() {

}

//	CONSTRUCTOR IS THE SAME.
//	BEFORE A CHILD CLASS IS CREATED, THE PARENT CLASS MUST BE CREATED
NounAndVerb::NounAndVerb(string wordIn, string definitionIn) {
	word = wordIn;
	definition = definitionIn;
	definition.insert(0, wordType);
}

string NounAndVerb::getWord() {
	return word;
}

string NounAndVerb::getDefinition() {
	
	return Word::definition;

}