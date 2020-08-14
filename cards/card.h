#pragma once
class card
{
private:
	//The varriables
	char serie;
	char type;

	//Getters
public:
	//The number of the card
	char GetSerie() {
		return serie;
	}
	//The type of the card
	char GetType() {
		return type;
	}

	//Constructor
public:
	card(char serie, char type) {
		this->serie = serie;
		this->type = type;
	}
};
