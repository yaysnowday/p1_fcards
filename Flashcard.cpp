#ifndef FLASHCARD_CPP
#define FLASHCARD_CPP

#include "Flashcard.h"
#include <string>

Flashcard::Flashcard() {
	front = "";
	back = "";
}

Flashcard::Flashcard(string a) {
	front = a;
}

Flashcard::Flashcard(string a, string b) {
	front = a;
	back = b;
}

bool Flashcard::operator==(const Flashcard& other) {
	if (front == other.front) {
		return true;
	}
	return false;
}

#endif