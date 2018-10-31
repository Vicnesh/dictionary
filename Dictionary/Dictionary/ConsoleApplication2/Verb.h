//VERB.H
//DERIVED CLASS VERB -> WORD

#ifndef VERB_H
#define VERB_H

#include "Word.h"
using namespace std;

//VERB CLASS INHERITED FROM WORD CLASS.
class Verb : virtual public Word
{

	public:
		Verb();
		Verb(string wordIn, string definitionIn);
		string getWord();
		string getDefinition();

	private:
		static string wordType;

};

#endif




