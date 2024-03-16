#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>
#include <vector>

#include <exception>
using namespace std;


int MDO::disp(TCheie c) const {
	if (c < 0) 
		c = -c;
	return c % m;
}

// O(m)
MDO::MDO(Relatie r) {
	/* de adaugat */
	relatie = r;
	m = MAX;
	n = 0;
	for (int i = 0; i < m; i++)
	{
		el[i].first = INIT;
		el[i].second = INIT;
		urm[i] = INIT;
	}
	primLiber = 0;
}

void MDO::actPrimLiber()
{
	primLiber++;
	while (primLiber < m && el[primLiber].first != INIT)
		primLiber++;
}

void MDO::adauga(TCheie c, TValoare v) {
	int i = disp(c), j;
	if (el[i].first == INIT)
	{
		el[i].first = c;
		el[i].second = v;

		if (i == primLiber)
			actPrimLiber();

		n++;
	}
	else
	{
		while (i != INIT)
		{
			if ((Relatie)(c, el[i].first) && disp(el[i].first) == i)
			{
				int aux1 = c;
				int aux2 = v;
				c = el[i].first;
				v = el[i].second;
				el[i].first = aux1;
				el[i].second = aux2;
			}
			j = i;
			i = urm[i];
		}

		el[primLiber].first = c;
		el[primLiber].second = v;
		urm[j] = primLiber;
		actPrimLiber();
		n++;
	}
}

// cd: theta(m)
// cf: theta(1)
// cm: O(m)
vector<TValoare> MDO::cauta(TCheie c) const {
	/* de adaugat */
	int poz = disp(c);

	vector<TValoare> v;
	while (poz != -1 && el[poz].first != c)
		poz = urm[poz];

	while (poz != -1 && el[poz].first == c)
	{
		v.push_back(el[poz].second);
		poz = urm[poz];
	}
	return v;
}

bool MDO::sterge(TCheie c, TValoare v) {
	/* de adaugat */
	TElem elem(c, v);
	int i = disp(c), j = INIT, k = 0, p, pp;
	bool gata;

	while (k < m && j == INIT)
	{
		if (urm[k] == i)	
			j = k;
		else 
			k++;
	}

	while (i != INIT && el[i] != elem)
	{
		j = i;
		i = urm[i];
	}

	if (i == INIT)
		return false;
	else
	{
		gata = false;
		do 
		{
			p = urm[i];
			pp = i;
			while (p != INIT && disp(el[p].first) != i)
			{
				pp = p;
				p = urm[p];
			}

			if (p == INIT) 
				gata = true;
			else 
			{
				el[i] = el[p];
				j = pp;
				i = p;
			}

		} while (!gata);

		if (j != INIT)	
			urm[j] = urm[i];

		el[i].first = INIT;
		urm[i] = INIT;

		if (primLiber > i) 
			primLiber = i;
		n--;
		return true;
	}
}

int MDO::dim() const {
	/* de adaugat */
	return n;
}

bool MDO::vid() const {
	/* de adaugat */
	return n == 0;
}

IteratorMDO MDO::iterator() const {
	return IteratorMDO(*this);
}

MDO::~MDO() {
	/* de adaugat */
}

