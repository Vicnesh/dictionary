//NOUNANDVERB.H
//DECLARATION SECTION

#ifndef NOUNANDVERB_H
#define NOUNANDVERB_H

#include "Word.h"
#include "Noun.h"
#include "Verb.h"
#include <string>

using namespace std;

class NounAndVerb : public Noun, public Verb {
	
	public:
		NounAndVerb();
		NounAndVerb(string wordIn, string definitionIn);
		string getWord();
		string getDefinition();

	private:
		static string wordType;

};

#endif // !
