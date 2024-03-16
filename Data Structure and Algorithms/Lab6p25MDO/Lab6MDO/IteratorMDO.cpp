#include "IteratorMDO.h"
#include "MDO.h"
#include <iostream>

const std::pair<int, int> NIL(-1, -1);

// O(n + m)
vector<TElem> IteratorMDO::interclasare(vector<TElem> v1, vector<TElem> v2, Relatie r) {
	auto i = v1.begin();
	auto j = v2.begin();
	vector<TElem> rez;

	while (i != v1.end() && j != v2.end()) {
		if (r(i->first, j->first)) {
			rez.push_back(pair<int, int>(i->first, i->second));
			i++;
		}
		else {
			rez.push_back(pair<int, int>(j->first, j->second));
			j++;
		}
	}

	while (i < v1.end()) {
		rez.push_back(pair<int, int>(i->first, i->second));
		i++;
	}

	while (j != v2.end()) {
		rez.push_back(pair<int, int>(j->first, j->second));
		j++;
	}

	return rez;
}

// O(m ^ 2)
IteratorMDO::IteratorMDO(const MDO& d) : dict(d) {
	bool viz[501];
	for (int i = 0; i < dict.m; i++)
		viz[i] = false;

	vector<vector<TElem>> matr;
	for (int j = 0; j < dict.m; j++) 
	{
		vector<TElem> v;
		for (int i = 0; i < dict.m; i++) 
		{
			TElem crt = std::pair<int, int>(dict.el[j].first, 0);
			int k = dict.disp(crt.first);
			if (dict.el[k] != NIL && !viz[k]) 
			{
				if (!v.empty()) 
				{
					auto last = v.front();
					if ((Relatie)(last.first, dict.el[k].first) && dict.disp(last.first) == dict.disp(dict.el[k].first)) {
						v.push_back(dict.el[k]);
						viz[k] = true;
					}
					else
						break;
				}
				else 
				{
					v.push_back(dict.el[k]);
					viz[k] = true;
				}
			}
			if (dict.el[k] == NIL)
				break;
		}

		if (!v.empty()) {
			matr.push_back(v);
		}
	}

	vector<TElem> ordonat;
	//O(m)
	for (int i = 0; i < matr.size(); i++) {
		auto v1 = matr[i];
		ordonat = interclasare(v1, ordonat, dict.relatie);
	}

	elems = ordonat;
	pozcrt = elems.begin();
}


void IteratorMDO::prim() {
	/* de adaugat */
	pozcrt = elems.begin();
}

void IteratorMDO::urmator() {
	/* de adaugat */
	pozcrt++;
}

bool IteratorMDO::valid() const {
	/* de adaugat */
	return pozcrt != elems.end();
}

TElem IteratorMDO::element() const {
	/* de adaugat */
	return pair<int, int>(pozcrt->first, pozcrt->second);
}


