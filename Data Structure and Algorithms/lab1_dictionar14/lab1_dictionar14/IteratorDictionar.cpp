#include "IteratorDictionar.h"
#include "Dictionar.h"
#include <exception>

using namespace std;

IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d) {
	currPos = 0;
}


void IteratorDictionar::prim() {
	currPos = 0;
}


void IteratorDictionar::urmator() {
	if (!valid())
		throw std::exception();
	currPos++;
}


TElem IteratorDictionar::element() const {
	if (valid())
		return pair<TCheie, TValoare>(dict.elems[currPos].first, dict.elems[currPos].second);
	return pair <TCheie, TValoare>(-1, -1);
}


bool IteratorDictionar::valid() const {
	return currPos < this->dict.dim() ? true : false;
}

