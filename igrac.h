#ifndef IGRACH
#define IGRACH

#include <string>
#include <ostream>


class Igrac {
public:
	//konstruktori
	Igrac(std::string newName, double newValue = 1000);	//radi
	Igrac(Igrac& toCopy);

	//metode
	std::string getName();	//radi
	double getPlayerValue();	//radi
	void increaseValue(int percent);	//radi
	void reduceValue(int percent);		//radi

	//operatori

	bool operator==(Igrac& second);		//radi
	friend std::ostream& operator<< (std::ostream& out, const Igrac& player);	//radi




private:
	std::string playerName;
	double playerValue;
};






#endif