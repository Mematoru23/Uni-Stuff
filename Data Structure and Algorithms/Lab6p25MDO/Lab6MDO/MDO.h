#pragma once
#include <vector>
#include <utility>

using namespace std;

typedef int TCheie;
typedef int TValoare;
typedef std::pair<TCheie, TValoare> TElem;

#define INIT -1
#define MAX 501 // nr max de locatii din td

class IteratorMDO;

typedef bool(*Relatie)(TCheie, TCheie);

class MDO {
	friend class IteratorMDO;
private:
	/* aici e reprezentarea */
	int n;
	int m; // nr de locatii din td
	TElem el[MAX]; // vect elem
	int urm[MAX]; // vect leg
	int primLiber; // locatia primei pozitii libere din td

	// actualizare primLiber
	void actPrimLiber();

	// functia de dispersie
	int disp(TCheie c) const;

public:
	Relatie relatie;

	// constructorul implicit al MultiDictionarului Ordonat
	MDO(Relatie r);

	// adauga o pereche (cheie, valoare) in MDO
	void adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza vectorul de valori asociate
	vector<TValoare> cauta(TCheie c) const;

	//sterge o cheie si o valoare 
	//returneaza adevarat daca s-a gasit cheia si valoarea de sters
	bool sterge(TCheie c, TValoare v);

	//returneaza numarul de perechi (cheie, valoare) din MDO 
	int dim() const;

	//verifica daca MultiDictionarul Ordonat e vid 
	bool vid() const;

	// se returneaza iterator pe MDO
	// iteratorul va returna perechile in ordine in raport cu relatia de ordine
	IteratorMDO iterator() const;

	// destructorul 	
	~MDO();

};
