//Dictionary.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <random>
#include <ctime>
#include <thread>
#include "Dictionary.h"
#include "Word.h"
#include "Noun.h"
#include "Verb.h"
#include "Adverb.h"
#include "Adjective.h"
#include "MiscWord.h"
#include "Preposition.h"
#include "ProperNoun.h"
#include "NounAndVerb.h"

using namespace std;


//LOADS EACH RECORD INTO AN APPROPRIATE CLASS
//@PARAM - 
//@RETURN - 
void Dictionary::loadDictionary() {

	ifstream file;
	string line;
	string word;
	string definition;
	string wordType;
	file.open("dictionary.txt");

	if (file.is_open()) {

		while (!file.eof()) {

			getline(file, word);
			getline(file, definition);
			getline(file, wordType);
			getline(file, line);
			determineWordType(word, definition, wordType);
			wordCounter++;
		}
	}
	file.close();
}


//CHECKS THE WORD TYPE AND STORES INTO THE DICTIONARY VECTOR
//@PARAM - WORD, DEFINITION AND WORD TYPE 
//@RETURN - 
void Dictionary::determineWordType(string wordIn, string definitionIn, string wordTypeIn) {

	//NOUN
	if (wordTypeIn == "n") {
		dictionary.push_back(new Noun(wordIn, definitionIn));
	}

	//VERB
	if (wordTypeIn == "v") {
		dictionary.push_back(new Verb(wordIn, definitionIn));
	}

	//ADVERB
	if (wordTypeIn == "adv") {
		dictionary.push_back(new Adverb(wordIn, definitionIn));
	}

	//ADJECTIVE
	if (wordTypeIn == "adj") {
		dictionary.push_back(new Adjective(wordIn, definitionIn));
	}

	//PREPOSITION
	if (wordTypeIn == "prep") {
		dictionary.push_back(new Preposition(wordIn, definitionIn));
	}

	//PROPER NOUN
	if (wordTypeIn == "pn") {
		dictionary.push_back(new ProperNoun(wordIn, definitionIn));
	}

	//NOUN AND VERB
	if (wordTypeIn == "n_and_v") {
		dictionary.push_back(new NounAndVerb(wordIn, definitionIn));
	}

	//MISC WORD
	if (wordTypeIn == "misc") {
		dictionary.push_back(new MiscWord(wordIn, definitionIn));
	}

}


//GET TOTAL NUMBER OF WORD OBJECT IN VECTOR
//@PARAM -
//@RETURN - SIZE OF DICTIONARY VECTOR
int Dictionary::getTotalNumberofWords() {
	return dictionary.size();
}


//DISPLAYS DICTIONARY
//@PARAM - 
//@RETURN - 
void Dictionary::displayDictionary() {
	for (unsigned int i = 0; i < dictionary.size(); i++) {
		cout << dictionary[i]->getWord() << endl;
	}
}


//FIND IF WORD EXIST IN DICTIONARY VECTOR
//@PARAM - WORD TO FIND
//@RETURN - WORD OBJECT IF EXIST, ELSE NULLPTR
Word* Dictionary::findWord(string wordIn) {

	//COMPARES CURRENT ARRAY ELEMENT WITH THE INPUT WORD
	for (unsigned int i = 0; i < dictionary.size(); i++) {
		string temp = dictionary[i]->getWord();
		transform(wordIn.begin(), wordIn.end(), wordIn.begin(), ::tolower);
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if (temp == wordIn) {
			return dictionary[i];
		}
	}
	return NULL;
}


//PERFORMS TASK 2: FIND ALL THE WORD(S) WITH MORE THAN 3 "Z"
//@PARAM - NONE
//@RETURN - OBJECT OF WORD THAT HAS MORE THAN 3 "Z"
void Dictionary::findWordWithZ() {
	int listCounter = 1;
	for (unsigned int i = 0; i < dictionary.size(); i++) {
		if (wordhas3Z(dictionary[i]->getWord())) {
			cout << listCounter << ": " << dictionary[i]->getWord() << endl;
			listCounter++;
		}
	}
}

//HELPS TASK 2: CHECK IF WORD HAS MORE THAN 3 Z
//@PARAM - WORD OBJECT: WORD OF DICTIONARY
//@RETURN - TRUE IF WORD HAS MORE THAN 3 Z, ELSE FALSE
bool Dictionary::wordhas3Z(string wordIn) {
	int countZ = 0;
	for (unsigned int k = 0; k < wordIn.size(); k++) {
		if (tolower(wordIn[k]) == 'z') {
			countZ++;
		}
	}
	if (countZ >= 3) {
		return true;
	}
	else {
		return false;
	}
}


//PERFORMS TASK 3: FIND ALL WORDS THAT HAVE A 'Q' WITHOUT A FOLLOWING 'U'
//@PARAM - 
//@RETURN - WORD OBJECT 
void Dictionary::findWordWithQNoU() {
	int listCounter = 1;
	for (unsigned int i = 0; i < dictionary.size(); i++) {
		if (wordCheckQNoU(dictionary[i]->getWord())) {
			cout << listCounter << ": " << dictionary[i]->getWord() << endl;
			listCounter++;
		}
	}
}


//HELPS TASK 3: CHECK IF WORD HAS "Q" WITHOUT A FOLLOWING "U"
//@PARAM - WORD OBJECT: WORD  OF DICTIONARY
//@RETURN - RETURN TRUE IF WORD HAS Q AND NO U, ELSE FALSE
bool Dictionary::wordCheckQNoU(string wordIn) {
	for (unsigned int k = 0; k < wordIn.size(); k++) {
		if (tolower(wordIn[k]) == 'q' && tolower(wordIn[k+1]) != 'u') {
				return true;
		}
		else {
			return false;
		}
	}
	return false;
}


//DISPLAYS NOUNS AND VERBS
//@PARAM - 
//@RETURN - 
void Dictionary::listNounAndVerbs() {
	int listCounter = 1;
	for (unsigned int k = 0; k < dictionary.size(); k++) {
		if (dictionary[k]->isNoun() && dictionary[k]->isVerb()) {
			cout << listCounter << ": " << dictionary[k]->getWord() << endl;
			listCounter++;
		}
	}
}


//DISPLAYS PALINDROMES
//@PARAM - 
//@RETURN - 
void Dictionary::listPalindromes() {
	int listCounter = 1;
	for (unsigned int k = 0; k < dictionary.size(); k++) {
		if (dictionary[k]->isPalindrome()) {
			cout << listCounter << ": " << dictionary[k]->getWord() << endl;
			listCounter++;
		}
	}
}


//DISPLAYS ANAGRAMS OF A WORD
//@PARAM - WORD TO FIND ANAGRAMS OF
//@RETURN - 
void Dictionary::listAnagrams(string wordIn) {
	int listCounter = 0;
	string inputWord = wordIn;
	for (unsigned int k = 0; k < dictionary.size(); k++) {
		if (dictionary[k]->isAnagram(inputWord) == true) {
			listCounter++;
			cout << listCounter << ": " << dictionary[k]->getWord() << endl;
		}
	}
	if (listCounter == 0) {
		cout << "No anagrams could be found." << endl;
	}
}


//PERFORMS TASK 4: GUESSING GAME
//@PARAM - 
//@RETURN - 
void Dictionary::guessingGame() {
	int randomElement;
	srand((unsigned int)time(NULL));
	string userGuess;
	int livesLeft = 3;
	int showLetter = 0;
	string wordReveal;
	//char letterReveal;

	//FIND A RANDOM NOUN
	do {
		randomElement = rand() % dictionary.size();
	} while (dictionary[randomElement]->isNoun() == false);

	//GAME BEGINS HERE
	cout << "Definition: " << dictionary[randomElement]->getDefinition() << endl;
	cout << "Word length: " << dictionary[randomElement]->getWord().size() << " characters\n" << endl;

	//LOOP TILL 0 LIVES
	while (livesLeft != 0) {
		//PROMPTS USER FOR GUESS INPUT
		cout << "Guess the word: ";
		cin >> userGuess;
		transform(userGuess.begin(), userGuess.end(), userGuess.begin(), tolower);
		//CHECKS CURRENT GUESS
		if (userGuess != dictionary[randomElement]->getWord()) {
			//SHOW LIVES LEFT
			livesLeft--;
			cout << "Wrong guess! Lives left: " << livesLeft << endl;
			//REVEAL NEXT LETTER
			if (showLetter != 2) {
				wordReveal.push_back(dictionary[randomElement]->getWord().at(showLetter));
				cout << "\nHint: " << wordReveal << endl;
				showLetter++;
			}
		}
		//IF GUESS IS CORRECT
		else {
			cout << "WELL DONE YOU MAGNIFICENT BASTARD!" << endl;
			break;
		}
	}
	//IF GUESS IS WRONG
	cout << "\nBetter luck next time!" << endl;
	cout << "Answer: " << dictionary[randomElement]->getWord() << endl;
}


//TASK 6: EDITABLE DICTIONARY - ADD WORD TO DICTIONARY
//@PARA - 
//@RETURN - 
void Dictionary::addDictionary() {
	string inputWord;
	string inputDefinition;
	string inputWordType;

	cout << "Please enter the word to be added into the dictionary: " << endl;
	cin >> inputWord;

	//PROMPT USER FOR THE WORD
	while (findWord(inputWord) != nullptr) {
		cout << "Word exist in Dictionary!" << endl;
		cout << "Please enter the word to be added into the dictionary: " << endl;
		cin >> inputWord;
		inputWord.erase(remove_if(inputWord.begin(), inputWord.end(), isspace));
	}

	
	
	//PROMPT USER FOR THE DEFINITION OF THE WORD
	cout << "Please enter the definition to be added into the dictionary: \n";
	cin >> inputDefinition;

	//PROMPT USER FOR THE WORD TYPE TO BE ADDED?
	//WORD TYPE HAS TO BE SPECIFIC?
	//NEED TO CHECK THE INPUT OF THE WORD TYPE?
	while (inputWordType != "v" && inputWordType != "n" && inputWordType != "adv" && inputWordType != "adj" && inputWordType != "prep" && inputWordType != "pn" && inputWordType != "n_and_v" && inputWordType != "misc") {	
		cout << "'v' - verb" << endl;
		cout << "'n' - noun" << endl;
		cout << "'adv' - adverb" << endl;
		cout << "'adj' - adjective" << endl;
		cout << "'prep' - preposition" << endl;
		cout << "'pn' - proper noun" << endl;
		cout << "'n_and_v' - noun and a verb" << endl;
		cout << "'misc' - other words and prefixes, none of the above." << endl;
		cout << "\nPlease enter the word Type using one of the following : " << endl;
		cin >> inputWordType;
	}
	determineWordType(inputWord, inputDefinition, inputWordType);


}


//WRITES TO FILE
	//@PARAM - WORD, DEFINITION, WORDTYPE TO ADDED
	//@RETURN -
void Dictionary::writeToFile() {

	ofstream myfile;
	string word;
	string definition;
	string wordType;
	string blank;

	myfile.open("dictionary.txt", ios::trunc);
	if (myfile.is_open()) {
		//FOR EACH WORD OBJECT LOOP
		for (unsigned int i = 0; i < dictionary.size(); i++) {

			//get word.
			word = dictionary[i]->getWord();

			//get definition.
			definition = dictionary[i]->getDefinition();

			//get the wordtype
			wordType.clear();
			size_t found = definition.find_first_of(")");
			for (unsigned int i = 1; i < found - 1; i++) {
				wordType.push_back(definition[i]);
			}
			if (wordType == "n.v.") {
				wordType = "n_and_v";
			}
			definition.erase(0, found + 1);

			//write to file
			//myfile.seekp(0, ios_base::end);
			myfile << word << "\n" << definition << "\n" << wordType << "\n" << endl;
			//cout << "word added into the dictionary" << endl;
		}
		myfile.close();
	}
	else {
		cout << "unable to open the file" << endl;
	}
}

//TASK 6 - DELETE DICTIONARY
//@PARAM - WORD TO BE DELETED FROM DICTIONARY
//@RETURN -
void Dictionary::deleteDictionary(string wordIn) {
	for (unsigned int i = 0; i < dictionary.size(); i++) {
		string temp = dictionary[i]->getWord();
		transform(wordIn.begin(), wordIn.end(), wordIn.begin(), ::tolower);
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		if (temp == wordIn) {
			dictionary.erase(dictionary.begin() + i);
			break;
		}
	}

	cout << "Word deleted from dictionary!" << endl;
}
