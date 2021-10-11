#include "tim.h"
#include "mec.h"


template<typename T, typename U, class Par>
Mec<T, U, Par>::Mec(T* home, U* guest) {
	game->firstElem = home;
	game->secondElem = guest;
	isPlayed = false;
}

template<typename T, typename U, class Par>
Par* Mec<T, U, Par>::getGame() {
	return game;
}


template<typename T, typename U, class Par>
void Mec<T, U, Par>::playGame() {
	if (game->firstElem->teamValue() > game->secondElem->teamValue()) {
		std::cout << "POBEDA_DOMACIN" << std::endl;
		
		for (int i = 0; i < game->firstElem->numOfPlayers(); i++) {
			game->firstElem[i]->increaseValue(10);
		}

		for (int i = 0; i < game->secondElem->numOfPlayers(); i++) {
			game->secondElem[i]->reduceValue(10);
		}

		outcome = "POBEDA_DOMACIN";
	}
		
	else
		if (game->firstElem->teamValue() < game->secondElem->teamValue()) {
			std::cout << "POBEDA_GOST" << std::endl;
			outcome = "POBEDA_GOST";

			for (int i = 0; i < game->firstElem->numOfPlayers(); i++) {
				game->firstElem[i]->reduceValue(10);
			}

			for (int i = 0; i < game->secondElem->numOfPlayers(); i++) {
				game->secondElem[i]->increaseValue(10);
			}

		}
			
		else {
			std::cout << "NERESENO" << std::endl;
			outcome = "NERESENO";
		}
			

	
}

template<typename T, typename U, class Par>
bool Mec<T, U, Par>::isGamePlayed() {
	return isGamePlayed;
}

template<typename T, typename U, class Par>
Par Mec<T, U, Par>::getResult() {
	try {
		if (!isPlayed)
			throw NotPlayed();
	}
	catch (NotPlayed& e) {
		e.printMsg();
	}

	Par result;

	if (outcome == "POBEDA_DOMACIN") {
		
		int* won = new int;
		*won = 3;

		int* lost = new int;
		*lost = 0;

		result.setFirst(won);
		result.setSecond(lost);
		
	}
	else 
		if (outcome == "POBEDA_GOST") {
			int* won = new int;
			*won = 0;

			int* lost = new int;
			*lost = 3;

			result.setFirst(won);
			result.setSecond(lost);
		}
		else {
			int* won = new int;
			*won = 1;

			int* lost = new int;
			*lost = 1;

			result.setFirst(won);
			result.setSecond(lost);
		}

	return result;
	
}
template<typename T, typename U, class Par, class Mec>
std::ostream& operator<<(std::ostream& it, Mec& currGame) {
	it << currGame.game << std::endl;
	it << currGame.game << std::endl;

	if (currGame.isPlayed)
		it << currGame.outcome << std::cout;
}
