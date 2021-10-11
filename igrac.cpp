#include "igrac.h"

Igrac::Igrac(std::string newName, double newValue) {
	playerName = newName;
	playerValue = newValue;
}

Igrac::Igrac(Igrac& toCopy) {
	playerName = toCopy.playerName;
	playerValue = toCopy.playerValue;
}

std::string Igrac::getName() {
	return playerName;
}

double Igrac::getPlayerValue() {
	return playerValue;
}

void Igrac::increaseValue(int percent) {

	playerValue = playerValue + playerValue / percent;
}

void Igrac::reduceValue(int percent) {
	playerValue = playerValue - playerValue / percent;
}

bool Igrac::operator==(Igrac& second) {
	if (playerName == second.playerName && playerValue == second.playerValue)
		return true;
	else
		return false;
}

std::ostream& operator<<(std::ostream& out, const Igrac& player) {
	out << player.playerName << '#';
	out << player.playerValue;

	return out;
}

