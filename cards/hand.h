#pragma once
#include "card.h"
#include <random>

class hand
{
	//Varriables
private:
	int size;

	std::vector<card> inhand;

	//Getters
public:
	//Gets the cards in the hand
	std::vector<card> Gethand() {
		return inhand;
	}
	//The maximum size of the hand basicly the size varriable
	int GetMaxSize() {
		return size;
	}
	//The current size of the hand -,-
	int GetCurrentSize() {
		return	inhand.size();
	}

	//Constructor
public:
	hand(int size) {
		this->size = size;
	}

	//Methods
public:
	//Draw a card (ads it to the hand)
	void Draw(card input) {
		if (inhand.size() < size)
			inhand.push_back(input);
	}

	//Removes the card
	void RemoveCard(card input) {
		inhand.erase(inhand.begin() + FindIndex(input));
	}

private:
	//Finds the index
	size_t FindIndex(card input) {
		int currsize = GetCurrentSize();
		for (size_t i = 0; i < currsize; i++)
		{
			if (inhand[i].GetSerie() == input.GetSerie() && inhand[i].GetType() == input.GetType()) {
				return i;
			}
		}
		return -1;
	}
};
