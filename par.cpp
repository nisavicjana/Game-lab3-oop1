#include "par.h"

template<class T, class U>
Par<T, U>::Par(T* first, U* second) {
	firstElem = first;
	secondElem = second;
}

template<typename T, typename U>
T* Par<T, U>::getFirst() {
	return firstElem;
}

template<typename T, typename U>
U* Par<T, U>::getSecond() {
	return secondElem;
}

template<class T, class U>
void Par<T, U>::setFirst(T* elem) {
	firstElem = elem;
}

template<class T, class U>
void Par<T, U>::setSecond(U* elem) {
	secondElem = elem;
}

template<typename T, typename U>
bool Par<T, U>::operator==(Par& second) {
	return (firstElem == second.firstElem && secondElem == second.secondElem);
}

//template<typename T, typename U>
/*Par<T, U>::~Par() {
	delete firstElem;
	delete secondElem;
} */

template<typename T, typename U, class Par>
std::ostream& operator<<(std::ostream& it, Par& pair) {

	it << '[' << pair.firstElem << '-' << pair.secondElem << ']' << std::endl;

}
