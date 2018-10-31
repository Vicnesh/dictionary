// Word.cpp

#include <iostream>
#include <string>
#include "Word.h"
#include "Noun.h"
#include "Verb.h"

using namespace std;


//DEFAULT CONSTRUCTOR
//@PARAM -
//@RETURN -
Word::Word() {

}



//CONSTRUCTOR
//@PARAM - WORD,DEFINITION, WORD TYPE
//@RETURN - 
Word::Word(string wordIn, string definitionIn) {
	word = wordIn;
	definition = definitionIn;
}

//RETURN WORD
//@PARAM - 
//@RETURN - WORD
string Word::getWord() {
	return word;
}

//RETURN DEFINITION
//@PARAM - 
//@RETURN - DEFINITION
string Word::getDefinition() {
	return definition;
}

//CHECK IF WORD IS PALINDROME
//@PARAM - 
//@RETURN - BOOLEAN
bool Word::isPalindrome() {
	string temp = this->getWord();
	if (temp.size() % 2 != 1 || temp.size() == 1) { //check if word is even number in size or a single letter
		return false;
	}
	else {

		for (int k = 0; k != (temp.size() - 1) / 2; ) { //loop forward through string characters
			for (int i = temp.size() - 1; i != k; i--, k++) { // loop backward through character until middle.

				if (temp[k] != temp[i]) {
					return false;

				}
			}
		}
		return true;
	}
}

//CHECK IF NOUN
//@PARAM - 
//@RETURN - BOOLEAN
bool Word::isNoun() {
	if (dynamic_cast<Noun*>(this) != NULL) {
		return true;
	}
	else {
		return false;
	}
}

//CHECK IF VERB
//@PARAM - 
//@RETURN - BOOLEAN
bool Word::isVerb() {
	if (dynamic_cast<Verb*>(this) != NULL) {
		return true;
	}
	else {
		return false;
	}
}

//CHECK IF ANAGRAM
//@PARAM - WORD TO CHECK FOR ANAGRAM
//@RETURN - BOOL
bool Word::isAnagram(string wordIn) {
	string temp = this->getWord();
	size_t found;

	if (temp.size() == wordIn.size() && temp != wordIn) {
		for (int k = 0; k < wordIn.size(); k++) {
			found = temp.find(tolower(wordIn[k]));
			if (found == string::npos) {
				return false;
			}
			else {
				temp.erase(found, 1);
			}
		}
		if (temp.empty()) {
			return true;
		}
	}
	else
	{
		return false;
	}
}
