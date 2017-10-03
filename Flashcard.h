#ifndef FLASH_CARD_H
#define FLASH_CARD_H

//#include <iostream>
#include <string>

using namespace std;

struct Flashcard {
	Flashcard();
	Flashcard(string f);
	Flashcard(string f, string b);
	bool operator==(const Flashcard& other);
	string front;
	string back;
};



#endif
