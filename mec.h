#ifndef MECH
#define MECH
#include "par.h"

class NotPlayed {
public:
	void printMsg() {
		std::cout << "mec nije odigran" << std::endl;
	}
};

template<typename T, typename U, class Par>
class Mec {
public:
	Mec(T* home, U* guest);
	Par* getGame();							  
	void playGame();
	bool isGamePlayed();
	Par getResult();

	friend std::ostream& operator<<(std::ostream& it, Mec& currGame);

private:
	
	Par* game;
	std::string outcome;
	bool isPlayed;

};


#endif


