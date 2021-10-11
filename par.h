#ifndef PARH
#define PARH
#include "igrac.h"
#include "tim.h"
#include "privilegovani.h"



template<class T, class U>
class Par {

public:
	Par(T* first, U* second);

	T* getFirst();
	U* getSecond();
	void setFirst(T* elem);
	void setSecond(U* elem);

	bool operator==(Par& second);
	friend std::ostream& operator<<(std::ostream& it, Par& pair);

	//~Par();


private:
	T* firstElem;
	U* secondElem;

};



#endif


