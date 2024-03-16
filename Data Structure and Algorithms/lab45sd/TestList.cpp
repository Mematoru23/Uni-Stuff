
#include "TestList.h"


#include "assert.h"
#include "DoubleLinkedList.h"

void TestList::testPushBack() {

    DoubleLinkedList<int> list;

    int intZero = 0;
    int intOne = 1;


    list.push_back(intZero);
    list.push_back(intOne);

    assert(list.at(0) == 0);
    assert(list.at(1) == 1);
}

void TestList::testAt() {


    DoubleLinkedList<int> list;

    int intZero = 0;
    int intOne = 1;


    list.push_back(intZero);
    list.push_back(intOne);

    assert(list.at(0) == 0);
    assert(list.at(1) == 1);

}

void TestList::testErase() {

    DoubleLinkedList<int> list;

    int intZero = 0;
    int intOne = 1;


    list.push_back(intZero);
    list.push_back(intOne);

    list.erase(0);

    assert(list.size() == 1);

}

void TestList::testInsert() {

    DoubleLinkedList<int> list;


    int intZero = 0;
    int intOne = 1;
    int intTwo = 2;


    list.push_back(intZero);
    list.push_back(intOne);
    list.insert(0, intTwo);

    assert(list.at(0) == intTwo);

}

void TestList::testSize() {

    DoubleLinkedList<int> list;

    int intZero = 0;
    int intOne = 1;


    list.push_back(intZero);
    list.push_back(intOne);


    assert(list.size() == 2);

}

void TestList::testEmpty() {

    DoubleLinkedList<int> list;

    assert(list.empty() == true);

}

void TestList::testFront() {

    DoubleLinkedList<int> list;

    int intZero = 0;
    int intOne = 1;


    list.push_back(intZero);
    list.push_back(intOne);

    assert(list.front() == 0);
    assert(list.back() == 1);
}

void TestList::run() {

    this->testPushBack();
    this->testAt();
    this->testErase();
    this->testInsert();
    this->testSize();
    this->testEmpty();
    this->testFront();

}
