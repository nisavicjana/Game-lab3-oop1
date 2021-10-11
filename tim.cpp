
#include "tim.h"

Tim::Tim() {

}

Tim::Tim(std::string name, int maxNumber) {
	teamName = name;
	maxPlayers = maxNumber;

	players = new Igrac * [maxNumber];

	for (int i = 0; i < maxNumber; i++)
		players[i] = nullptr;

}

Tim::Tim(Tim& toCopy) {
	teamName = toCopy.teamName;
	maxPlayers = toCopy.maxPlayers;
	currPlayers = toCopy.currPlayers;

	players = new Igrac * [maxPlayers];

	for (int i = 0; i < maxPlayers; i++) {
		players[i] = toCopy.players[i];
	}
}

void Tim::addPlayer(Igrac* newPlayer, int position) {
	try {
		if (currPlayers >= maxPlayers)
			throw FullTeam();
		players[position] = newPlayer;
		++currPlayers;
	}
	catch (FullTeam& exception) {
		exception.printMsg();
	}

}

int Tim::numOfPlayers() {
	return currPlayers;
}

double Tim::teamValue() {
	double value = 0;
	for (int i = 0; i < maxPlayers; i++) {
		if (players[i]) {
			value += players[i]->getPlayerValue();
		}
			
	}

	value = value / currPlayers;

	return value;
}

Igrac* Tim::operator[](int position) {
	return players[position];
}

bool Tim::operator==(Tim& second) {
	bool isEqual = false;
	if (currPlayers != second.currPlayers || teamName != second.teamName)
		return false;

	for (int i = 0; i < currPlayers; i++) {
		if (*players[i] == *second.players[i])
			continue;
		return false;
	}

	return true;
}



std::ostream& operator<<(std::ostream& it, Tim& team) {
	it << team.teamName << '[';
	for (int i = 0; i < team.maxPlayers; i++) {
		if(team.players[i])
		it << *team.players[i] << ',';
	}
	it << ']' << std::endl;

	return it;
}

Tim::~Tim() {
	delete[]players;

}
