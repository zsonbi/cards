// cards.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "deck.h"
#include "hand.h"
#include <array>
int handsize = 5;
int decksize = 30;
char series[] = { 'C','D','H','S' };
char types[] = { '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K', 'A' };
size_t seriesSize = 4;
size_t typesSize = 13;
deck Deck(types, series, typesSize, seriesSize);
hand Hand(handsize);

//Fills the hand with cards
hand FillHand(hand input) {
	size_t size = input.GetMaxSize();

	for (size_t i = input.GetCurrentSize(); i < size; i++)
	{
		//Draws the front card from the deck
		input.Draw(Deck.Draw());
	}
	return input;
}

//Draws one card
hand DrawOne(hand input) {
	if (input.GetCurrentSize() < input.GetMaxSize()) {
		input.Draw(Deck.Draw());
	}
	return input;
}

int main()
{
	//Shuffles the deck
	Deck.shuffle();

	Hand = FillHand(Hand);
	Hand.Gethand();

	std::cout << "Hello World!\n";
}