//MISCWORD.H
//DERIVED CLASS MISCWORD -> WORD

#ifndef MISCWORD_H
#define MISCWORD_H

#include "Word.h"


class MiscWord : public Word
{
	//statements here
	public:
		MiscWord();
		MiscWord(string wordIn, string definitionIn);
		string getWord();
		string getDefinition();

	private:
		static string wordType;

};



#endif // !MISCWORD_H