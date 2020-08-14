#pragma once

#include "card.h"
#include <random>
#include <array>
class deck
{
	//Varriables
private:
	size_t maxsize;
	//std::list<card> cards;
	std::vector<card> cards;

	//Getters
public:
	//Gets the remaining number of cards
	size_t GetCurrentSize() {
		return cards.size();
	}
	//The maximum size of the deck
	size_t GetMaxSize() {
		return maxsize;
	}

	//Constructor
public:
	deck(char types[], char series[], size_t length1, size_t length2) {
		CreateDeck(types, series, length1, length2);

		this->maxsize = cards.size();
	}

public:
	card Draw() {
		card output = cards.front();
		cards.erase(cards.begin() + FindIndex(output));
		return output;
	}

	//Shuffles the deck
	void shuffle() {
		size_t currsize = GetCurrentSize();

		for (size_t i = 0; i < currsize; i++)
		{
			//generate a random index
			int index = rand() % currsize;

			card temp = cards[index];
			cards[index] = cards[i];
			cards[i] = temp;
		}
	}

private:
	//Finds the index
	size_t FindIndex(card input) {
		int currsize = GetCurrentSize();
		for (size_t i = 0; i < currsize; i++)
		{
			if (cards[i].GetSerie() == input.GetSerie() && cards[i].GetType() == input.GetType()) {
				return i;
			}
		}
		return -1;
	}

	//Creates the deck
	void CreateDeck(char types[], char series[], size_t length1, size_t length2) {
		for (size_t i = 0; i < length2; i++)
		{
			for (size_t j = 0; j < length1; j++)
			{
				//	card mycard(series[j], types[i]);
				cards.push_back(card(series[i], types[j]));
			}
		}
	}
};
