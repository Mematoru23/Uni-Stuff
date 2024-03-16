#include "IteratorColectie.h"
#include "Colectie.h"
#include <exception>

IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
	current = col.prim;
}

TElem IteratorColectie::element() const {
	return current->element();
}

bool IteratorColectie::valid() const {
	return current == nullptr ? false : true;
}

void IteratorColectie::urmator() {
	current = current->urmator();
}

void IteratorColectie::prim() {
	current = col.prim;
}
