#pragma once
#include <vector>

void readList(int* arr, int n);
void showList(int* arr, int n);
void alloc(int* &arr);
void menu();
void console();
int* maxPrimeSeq(int* arr, int& n);
int* maxContrarySignsSeq(int* arr, int& n);
int* maxPrimeDiffSequence(int* arr, int& n);
void dealloc(int* arr);