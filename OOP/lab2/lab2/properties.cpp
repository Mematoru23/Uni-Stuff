#include <iostream>
#include <string.h>
#include <vector>
#include "properties.h"

using namespace std;

int n, cpn;
int* arr;
void menu()
{
	string m = "";
	m += "1. read list\n";
	m += "2. show list\n";
	m += "3. longest seq of consec prime nums\n";
	m += "4. longest seq of consec contraty sign nums\n";
	m += "x. exit app\n";
	cout << m;
}

void alloc(int* &arr)
{
	arr = new int[n + 1];
}

void showList(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

void readList(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void dealloc(int* arr)
{
	if (arr != NULL)
	{
		delete[] arr;
		arr = NULL;
	}
}

bool isPrime(int n) 
{
	if (n <= 1) 
	{
		return false;
	}
	for (int i = 2; i * i <= n; i++) 
	{
		if (n % i == 0) 
		{
			return false;
		}
	}
	return true;
}

int* maxPrimeSeq(int* arr, int& n)
{
	int* p1 = arr;
	int* p2 = arr;
	int maxLen = 1;
	int* maxStart = arr;
	
	while (p2 < arr + n) 
	{
		if (isPrime(*p2)) 
		{ 
			int len = p2 - p1 + 1;
			if (len > maxLen) 
			{
				maxLen = len;
				maxStart = p1;
			}
			++p2;
		}
		else 
		{
			++p2;
			p1 = p2;
		}
	}

	cpn = maxLen;
	return maxStart;
}

int* maxPrimeDiffSequence(int* arr, int& n) {
	int start = 0, end = 0;
	int maxLength = 1, currentLength = 1;

	for (int i = 1; i < n; i++) {
		if (isPrime(abs(*(arr + i) - *(arr + i - 1)))) {
			currentLength++;
		}
		else {
			if (currentLength > maxLength) {
				maxLength = currentLength;
				end = i - 1;
				start = end - maxLength + 1;
			}
			currentLength = 1;
		}
	}

	if (currentLength > maxLength) {
		maxLength = currentLength;
		end = n - 1;
		start = end - maxLength + 1;
	}

	cpn = end - start + 1;
	int* result = new int[maxLength];
	for (int i = start; i <= end; i++) {
		*(result + i - start) = *(arr + i);
	}
	return result;
}

int* maxContrarySignsSeq(int* arr, int& n)
{
	int maxLength = 0;
	int currentLength = 1;
	int maxStart = 0;
	int currentStart = 0;

	for (int i = 1; i < n; i++) {
		if ((arr[i] > 0 && arr[i - 1] < 0) || (arr[i] < 0 && arr[i - 1] > 0)) {
			currentLength++;
		}
		else {
			if (currentLength > maxLength) {
				maxLength = currentLength;
				maxStart = currentStart;
			}
			currentLength = 1;
			currentStart = i;
		}
	}

	if (currentLength > maxLength) {
		maxLength = currentLength;
		maxStart = currentStart;
	}

	cpn = maxLength;
	int* result = new int[maxLength];
	for (int i = 0; i < maxLength; i++) {
		result[i] = arr[maxStart + i];
	}
	return result;
}

void console()
{
	int cmd;
	while (true)
	{
		menu();
		cout << ">> ";
		cin >> cmd;
		if (cmd == 1)
		{
			cout << "num of numbers: ";
			cin >> n;
			alloc(arr);
			readList(arr, n);
		}
		else if (cmd == 2)
			showList(arr, n);
		else if (cmd == 3)
		{
			showList(maxPrimeSeq(arr, n), cpn);
		}
		else if (cmd == 4)
		{
			showList(maxContrarySignsSeq(arr, n), cpn);
		}
		else if (cmd == 5)
		{
			showList(maxPrimeDiffSequence(arr, n), cpn);
		}
		else if (cmd == 'x')
		{
			dealloc(arr);
		}
	}
}