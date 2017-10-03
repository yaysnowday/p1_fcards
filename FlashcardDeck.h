#ifndef FLASH_CARD_DECK_H
#define FLASH_CARD_DECK_H

#include "UniqueVector.h"
#include "Flashcard.h"

class FlashcardDeck {
public:
	FlashcardDeck();

	bool addCard(const string& front, const string& back);
	bool removeCard(const string& front);
	bool containsCard(const string& front);
	string listFlashcards();

private:
	UniqueVector<Flashcard> FCD;
	int deckSize;
};

#endif