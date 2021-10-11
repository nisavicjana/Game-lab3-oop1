#ifndef TIMH
#define TIMH
#include <string>
#include "igrac.h"
#include <iostream>


class FullTeam {   //radi
public:
	void printMsg() {
		std::cout << "tim je pun\n";
	}
};


class Tim {
public:
	//konstruktori
	Tim();
	Tim(std::string name, int maxNumber);	  //radi
	Tim(Tim& toCopy);


	//metode
	virtual void addPlayer(Igrac* newPlayer, int position);	 //radi
	virtual int numOfPlayers();			//radi
	virtual double teamValue();			//radi

	//operatori

	Igrac* operator[](int position);	 //radi
	bool operator==(Tim& second);		 //radi
	friend std::ostream& operator<<(std::ostream& it, Tim& team);	  //radi


	//destruktori
	~Tim();		 //radi


protected:

	std::string teamName;
	int maxPlayers, currPlayers;
	Igrac** players;


};



#endif
