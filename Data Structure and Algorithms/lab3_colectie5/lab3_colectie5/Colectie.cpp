#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

Nod::Nod(TElem e, PNod urm) {
	this->el = e;
	this->urm = urm;
	this->freq = 1;
}

TElem Nod::element() {
	return el;
}

PNod Nod::urmator() {
	return urm;
}

TElem Nod::getFreq() {
	return freq;
}

bool rel(TElem e1, TElem e2) {
	return e1 <= e2;
}

Colectie::Colectie() {
	prim = nullptr;
}

void Colectie::adauga(TElem e) {
	if (cauta(e) == true)
	{
		PNod current;
		current = prim;
		while (rel(e, current->el) == false)
			current = current->urm;
		current->freq++;
	}
	else
	{
		if (dim() == 0)
		{
			PNod n = new Nod(e, nullptr);
			prim = n;
		}
		else
		{
			PNod current, anterior;
			current = prim;
			anterior = prim;
			while (rel(e, current->el) == false && current->urm != nullptr)
			{
				anterior = current;
				current = current->urm;
			}
			if (rel(e, current->el) == true)
			{
				PNod n = new Nod(e, nullptr);
				if (current == prim)
				{
					n->urm = prim;
					prim = n;
				}
				else
				{
					n->urm = current;
					anterior->urm = n;
				}
			}
			else if (current->urm == nullptr)
			{
				PNod n = new Nod(e, nullptr);
				current->urm = n;
			}
		}
	}
}

void Colectie::adaugaAparitiiMultiple(int nr, TElem elem)
{
	if (nr < 0)
		throw std::exception();

	//if (cauta(elem) == true)
	//{
		for (int i = 0; i < nr; i++)
			adauga(elem);
	//}
}

bool Colectie::sterge(TElem e) {
	if (nrAparitii(e) > 0)
	{
		IteratorColectie it = iterator();
		while (it.element() != e)
			it.urmator();
		if (nrAparitii(e) == 1)
		{
			if (it.current == prim)
			{
				prim = prim->urmator();
				delete it.current;
			}
			else
			{
				IteratorColectie pred = iterator();
				while (pred.current->urm->element() != e)
					pred.urmator();
				PNod sters = pred.current->urm;
				pred.current->urm = pred.current->urm->urm;
				delete sters;
			}
		}
		else it.current->freq--;
		return true;
	}
	return false;
}


bool Colectie::cauta(TElem elem) const {
	if (prim == nullptr)
		return false;
	PNod current = prim;
	while (current != nullptr)
	{
		if (current->el == elem)
			return true;
		current = current->urm;
	}
	return false;
}

int Colectie::nrAparitii(TElem elem) const {
	if (cauta(elem) == false)
		return 0;

	PNod current = prim;
	while (current->urm != nullptr && current->el != elem)
		current = current->urm;
	return current->freq;
}

int Colectie::dim() const {
	int dim = 0;
	IteratorColectie it = iterator();
	while (it.valid() == true)
	{
		dim = dim + it.current->getFreq();
		it.urmator();
	}
	return dim;
}

bool Colectie::vida() const {
	if (prim == nullptr)
		return true;
	return false;
}


IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	while (prim != nullptr) {
		PNod n = prim;
		prim = prim->urm;
		delete n;
	}
}
