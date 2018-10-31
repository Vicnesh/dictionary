//ADJECTIVE.H
//DERIVED CLASS ADJECTIVE -> WORD


#ifndef ADJECTIVE_H
#define ADJECTIVE_H

#include "Word.h"

//DERIVED CLASS ADJECTIVE
//BASE CLASS WORD
class Adjective : public Word
{
	public:
		Adjective();
		Adjective(string wordIn, string definitionIn);
		string getWord();
		string getDefinition();

	private:
		static string wordType;

};

#endif // !ADJECTIVE_H
