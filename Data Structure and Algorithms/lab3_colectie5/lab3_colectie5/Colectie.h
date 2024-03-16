#pragma once
//#include "IteratorColectie.h"

typedef int TElem;

typedef bool(*Relatie)(TElem, TElem);

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem, TElem);

class IteratorColectie;

class Nod;

typedef Nod* PNod;

class Nod
{
public:
	friend class Colectie;

	//constructor

	Nod(TElem e, PNod urm);

	TElem element();
	PNod urmator();
	TElem getFreq();

private:
	TElem el;
	TElem freq;
	PNod urm;
};

class Colectie {

	friend class IteratorColectie;

private:
	PNod prim;

public:
	//constructorul implicit
	Colectie();

	//adauga un element in colectie
	void adauga(TElem e);

	void adaugaAparitiiMultiple(int nr, TElem elem);

	//sterge o aparitie a unui element din colectie
	//returneaza adevarat daca s-a putut sterge
	bool sterge(TElem e);

	//verifica daca un element se afla in colectie
	bool cauta(TElem elem) const;

	//returneaza numar de aparitii ale unui element in colectie
	int nrAparitii(TElem elem) const;


	//intoarce numarul de elemente din colectie;
	int dim() const;

	//verifica daca colectia e vida;
	bool vida() const;

	//returneaza un iterator pe colectie
	IteratorColectie iterator() const;

	// destructorul colectiei
	~Colectie();


};

