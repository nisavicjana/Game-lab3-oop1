#ifndef PRIVILEGOVANIH
#define PRIVILEGOVANIH
#include "tim.h"

//destruktor??

class invalidValue {	 //radi
public:
	void printMsg() {
		std::cout << "nije moguce ubaciti igraca jer mu je vrednost ispod trazene";
	}
};

class Privilegovani:public Tim {
public:
	//konstruktori
	Privilegovani(std::string name, int maxNumber, int minValue);	//radi
	Privilegovani(Privilegovani& toCopy);

	void addPlayer(Igrac* newPlayer, int position);		  //radi

	friend std::ostream& operator<<(std::ostream& it, Privilegovani& team);	  //radi

	//~Privilegovani();


private:
	int minPlayerValue;

};


#endif