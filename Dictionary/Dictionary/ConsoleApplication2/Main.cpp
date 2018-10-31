// Main.cpp
//Vicnesh Ragunath (10375213)

#include <iostream>
#include <string>
#include <algorithm>
#include <thread>
#include "Dictionary.h"
#include "Word.h"
#include "Noun.h"
#include "ProperNoun.h"

using namespace std;

Dictionary myDictionary;

int main() {

	string userMenuIn;
	string userWordIn;
	void displayMenu(); 
	void checkMenuInput(string userMenuIn); 

	cout << "Welcome to the Dictionary program!\n\n"  << "Loading Dictionary...\nPlease wait\n" << endl;

	//LOAD DICTIONARY, DISPLAY NUMBER OF WORDS
	myDictionary.loadDictionary();
	cout << "Dictionary Loaded.\nDictionary contains " << myDictionary.getTotalNumberofWords() << " words." << endl;
	
	displayMenu();

	while (userMenuIn != "0") {
		cout << "\nPlease enter a task to perform (Enter 'Menu' to display): ";
		cin >> userMenuIn;
		transform(userMenuIn.begin(), userMenuIn.end(), userMenuIn.begin(), ::tolower);
		checkMenuInput(userMenuIn);
	}

	cout << "Goodbye!" << endl;
	system("pause");
	return 0;
}

//DISPLAY MENU FOR PROGRAM.
void displayMenu() {
	cout << "\nMenu:\n1) Display definition of a word." << endl;
	cout << "2) Display words with more than 3 'z'." << endl;
	cout << "3) List the words that have a 'q' without a following 'u'." << endl;
	cout << "4) List all words that a noun and a verb." << endl;
	cout << "5) List all words that are a palindrome." << endl;
	cout << "6) Report anagrams of a word." << endl;
	cout << "7) Guessing Game" << endl;
	cout << "8) Add to Dictionary" << endl;
	cout << "9) Delete Dictionary" << endl;
	cout << "0) Exit" << endl;

}

//CHECKS THE USER INPUT OF MENU OPTION
void checkMenuInput(string userMenuIn) {

		//TASK 1 - DEFINITION OF A WORD
		if (userMenuIn == "1") {
			string userWordIn;

			//INPUT FOR WORD
			cout << "\n1) Display definition of a word" << endl;
			cout << "Please enter a word to display its definition: ";
			cin >> userWordIn;

			//FIND WORD. IF NULL THEN ERROR ELSE DISPLAY WORD
			cout << "Searching for " << userWordIn << "..." << endl;
			if (myDictionary.findWord(userWordIn) == nullptr) {
				cout << "\nError. \nWord does not exist in the dictionary" << endl;
			}
			else {
				cout << "\n" << myDictionary.findWord(userWordIn)->getWord() << endl;
				cout << myDictionary.findWord(userWordIn)->getDefinition() << "\n" << endl;	
			}
		}

		//TASK 2 - WORDS WITH MORE THAN 3 Z
		else if (userMenuIn == "2") {
			cout << "\n2) Display words with more than 3 'z'." << endl;
			myDictionary.findWordWithZ();
		}

		//TASK 3 - WORD WITH Q WITHOUT U
		else if (userMenuIn == "3") {
			cout << "\n3) List the words that have a 'q' without a following 'u'." << endl;
			myDictionary.findWordWithQNoU();
		}

		//TASK 4 - LIST NOUNS AND VEBS
		else if (userMenuIn == "4") {
			cout << "\n4) List all words that a noun and a verb." << endl;
			myDictionary.listNounAndVerbs();
		}

		//TASK 5 - LIST ALL PALINDROMES
		else if (userMenuIn == "5") {
			cout << "\n5) List all words that are a palindrome." << endl;
			myDictionary.listPalindromes();
		}

		//TASK 6 - LIST ANAGRAMS OF A WORD
		else if (userMenuIn == "6") {
			string wordIn;
			cout << "\n6) Report anagrams of a word." << endl;
			cout << "Please enter a word to display its anagram: ";
			cin >> wordIn;
			transform(wordIn.begin(), wordIn.end(), wordIn.begin(), ::tolower);
			myDictionary.listAnagrams(wordIn);
		}

		//TASK 7 - GUESSING GAME
		else if (userMenuIn == "7") {
			cout << "7) Guessing Game" << endl;
			myDictionary.guessingGame();
		}

		//TASK 8 - ADD WORD TO DICTIONARY
		else if (userMenuIn == "8") {
			cout << "8) Add to Dictionary" << endl;
			myDictionary.addDictionary();
			thread a(&Dictionary::writeToFile, myDictionary);
			a.detach();
			//cout << "Updating Dictionary" << endl;
			//myDictionary.loadDictionary();
			//cout << "Done!" << endl;
		}

		//TASK 9 - DELETE WORD FROM DICTIONARY
		else if (userMenuIn == "9") {
			cout << "9) Delete Dictionary" << endl;
			
			string userWordIn;
			cout << "Please enter the word to be deleted from the dictionary: ";
			cin >> userWordIn;
			if (myDictionary.findWord(userWordIn) == nullptr) {
				cout << "\nError. \nWord does not exist in the dictionary" << endl;
			}
			else {
				myDictionary.deleteDictionary(userWordIn);
				thread a(&Dictionary::writeToFile, myDictionary);
				a.detach();
			}
		}

		//DISPLAY MENU
		else if (userMenuIn == "menu") {
			displayMenu();
		}
	}