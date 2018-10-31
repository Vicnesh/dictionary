//PREPOSITION.H
//DECLARATION SECTION


#ifndef PREPOSITION_H
#define PREPOSITION_H
#include <string>
#include "MiscWord.h"

using namespace std;

class Preposition : public MiscWord
{
	public:
		Preposition();
		Preposition(string wordIn, string definitionIn);
		string getWord();
		string getDefinition();

	private:
		static string wordType;

};



#endif // !PREPOSITION_H

