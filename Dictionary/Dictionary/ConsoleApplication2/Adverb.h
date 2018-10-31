//ADVERB.H
//DERIVED CLASS ADVERB -> WORD

#ifndef ADVERB_H
#define ADVERB_H

#include "Word.h"



//DERIVED CLASS ADVERB
//BASE CLASS WORD
class Adverb : public Word
{
	public:
		Adverb();
		Adverb(string wordIn, string definitionIn);
		string getWord();
		string getDefinition();

	private:
		static string wordType;

};




#endif // !ADVERB_H
