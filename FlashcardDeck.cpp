#ifndef FLASH_CARD_DECK_CPP
#define FLASH_CARD_DECK_CPP

#include "FlashcardDeck.h"
#include "UniqueVector.h"
#include "Flashcard.h"
#include <iostream>
#include <string>

FlashcardDeck::FlashcardDeck() {
	deckSize = 0;
}

bool FlashcardDeck::addCard(const string& front, const string& back) {
	bool isAdded = false;

	if (!containsCard(front)) {
		Flashcard newCard(front, back);
		FCD.insert(newCard);
		++deckSize;
		isAdded = true;
	}

	return isAdded;
}

bool FlashcardDeck::removeCard(const string& front) {
	Flashcard remCard(front);
	bool isRemoved = false;

	if (containsCard(front)) {
		FCD.remove(remCard);
		--deckSize;
		isRemoved = true;
	}

	return isRemoved;
}

bool FlashcardDeck::containsCard(const string& front) {
	Flashcard containsCard(front);

	for (int i = 0; i < deckSize; ++i) {
		if (FCD.contains(containsCard)) {
			return true;
		}
	}
	return false;
}

string FlashcardDeck::listFlashcards() {
	Flashcard listCard;
	string list;

	for (int i = 0; i < deckSize; ++i) {
		if (FCD.at(i, listCard)) {
			list += listCard.front;
			list += "\n";
			list += listCard.back;
			list += "\n\n";
		}
	}

	return list;
}

#endif
