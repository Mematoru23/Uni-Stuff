#include <iostream>
#include "program.h"

using namespace std;

int isPrime(int n)
{
	if (n == 2) return true;
	if (n % 2 == 0 || n < 2) return false;
	for (int i = 2; i <= n / 2; i++)
		if (n % i == 0)
			return false;
	return true;
}

int answer(int n, int &p1, int &p2)
{
	int v[4] = { 2, 3, 5, 7 };

	for (int i = 0; i < 4; i++)
	{
		p1 = v[i];
		p2 = n - p1;
		if (isPrime(p2))
			return true;
		else continue;
	}
	p1 = 0;
	p2 = 0;
	return false;
}

void run()
{
	int n, p1 = 0, p2 = 0;
	cin >> n;
	if (answer(n, p1, p2))
		cout << p1 << " " << p2;
	else
		cout << "nu se poate";
}