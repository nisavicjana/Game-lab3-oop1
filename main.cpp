#include "igrac.h"
#include "tim.h"
#include "privilegovani.h"
#include "par.h"
#include "mec.h"


int main() {
	Igrac gamer1("Marko", 50);
	Igrac gamer2("Janko", 30);
	Igrac gamer3("Sofija", 40);
	Igrac gamer4("Ana", 20);
	Igrac gamer5("Nevena", 10);



	Tim firstTeam("prvi", 4);
	firstTeam.addPlayer(&gamer1, 0);
	firstTeam.addPlayer(&gamer2, 1);
	firstTeam.addPlayer(&gamer3, 2);
	firstTeam.addPlayer(&gamer4, 3);

	Tim secondTeam("prvi", 4);
	secondTeam.addPlayer(&gamer1, 0);
	secondTeam.addPlayer(&gamer2, 1);
	secondTeam.addPlayer(&gamer3, 2);
	secondTeam.addPlayer(&gamer5, 3);

	Par<Igrac, Tim> prviPar(&gamer1, &firstTeam);



	return 0;
}
