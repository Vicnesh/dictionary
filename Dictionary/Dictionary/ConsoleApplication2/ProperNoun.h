//PROPERNOUN.H
//DECLARATION SECTION


#ifndef PROPERNOUN_H
#define PROPERNOUN_H


#include <iostream>
#include <string>
#include "Noun.h"


using namespace std;

class ProperNoun : public Noun {

	public:
		ProperNoun(string wordIn, string definitionIn);
		string getWord();
		string getDefinition();

	private:
		static string wordType;

};

#endif // ! PROPERNOUN_H