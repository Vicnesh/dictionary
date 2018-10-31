//NOUN.H
//DERIVED CLASS -> WORD

#ifndef NOUN_H
#define NOUN_H

#include "Word.h"
#include <string>


using namespace std;

//NOUN CLASS INHERITED FROM WORD CLASS.
class Noun : virtual public Word
{

	public:
		Noun();	//DEFAULT CONSTRUCTOR
		Noun(string wordIn, string definitionIn);
		string getWord();
		string getDefinition();

	private:
		static string wordType; // type string (n.)

};





















#endif // !NOUN_H
