#include "privilegovani.h"
#pragma once

Privilegovani::Privilegovani(std::string name, int maxNumber, int minValue) {
	minPlayerValue = minValue;
	maxPlayers = maxNumber;
	teamName = name;

	players = new Igrac * [maxNumber];
	
	for (int i = 0; i < maxNumber; i++)
		players[i] = nullptr;
}

Privilegovani::Privilegovani(Privilegovani& toCopy) {
	teamName = toCopy.teamName;
	maxPlayers = toCopy.maxPlayers;
	minPlayerValue = toCopy.minPlayerValue;
	currPlayers = toCopy.currPlayers;

	players = new Igrac * [maxPlayers];

	for (int i = 0; i < maxPlayers; i++) {
		players[i] = toCopy.players[i];
	}
}

void Privilegovani::addPlayer(Igrac* newPlayer, int position) {
	try {
		if (newPlayer->getPlayerValue() < minPlayerValue)
			throw invalidValue();
		players[position] = newPlayer;
		currPlayers++;
	}
	catch (invalidValue& e) {
		e.printMsg();
	}
	

}


/*Privilegovani::~Privilegovani() {
	delete[]players;
} */


std::ostream& operator<<(std::ostream& it, Privilegovani& team) {
	it << team.teamName <<'('<<team.minPlayerValue<<')' << '[';
	for (int i = 0; i < team.maxPlayers; i++) {
		if(team.players[i])
			it << *team.players[i] << ',';
	}
	it << ']' << std::endl;

	return it;
}



