
#ifndef UNTITLED1_DOUBLELINKEDLIST_H
#define UNTITLED1_DOUBLELINKEDLIST_H

#include <iostream>
#include <vector>
#include "Node.h"

template<typename Type>
class DoubleLinkedList {
public:
    explicit DoubleLinkedList(Node<Type> *first) : first(first) {}

    explicit DoubleLinkedList() : first(nullptr) {}

    DoubleLinkedList(const DoubleLinkedList<Type> &list);

    /*Method List:
    todo:
        *destructor():
        *insert(): To insert a new node at a specified position in the doubly linked list.
        *sort():
    */

    void insert(int position, Type element) {

        Node<Type> *node = first;

        if(position==0){
            this->push_front(element);
        }
        if(position== this->size()-1){
            this->push_back(element);

        } else{



            for (int i = 0; i < position; i++) {
                node = node->getNextNode();

            }

            Node<Type>* newNode= new Node<Type>(node->getPrevNode(),element,node);

            node->setPrevNode(newNode);
            node->getPrevNode()->setNextNode(newNode);
        }


    }

    void erase(int position) {

        Node<Type> *node = first;

        for (int i = 0; i < position; i++) {
            node = node->getNextNode();
        }

        if (node->getPrevNode() == nullptr) {
            node->getNextNode()->setPrevNode(nullptr);
            first = node->getNextNode();
        }

        if (node->getNextNode() == nullptr) {
            node->getPrevNode()->setNextNode(nullptr);
        }

        if (node->getPrevNode() != nullptr && node->getNextNode() != nullptr) {
            node->getNextNode()->setPrevNode(node->getPrevNode());
            node->getPrevNode()->setNextNode(node->getNextNode());
        }

        delete[] node;


    }

    void push_back(Type &element) {

        if (first == nullptr) {
            first = new Node<Type>(nullptr, element, nullptr);
        } else {
            Node<Type> *lastNode = first;

            while (lastNode->getNextNode() != nullptr) {
                lastNode = lastNode->getNextNode();
            }

            Node<Type> *newNode = new Node<Type>(lastNode, element, nullptr);
            lastNode->setNextNode(newNode);
        }
    }

    void push_front(Type element) {

        if (first == nullptr) {
            first = new Node<Type>(nullptr, element, nullptr);
        } else {

            first->setPrevNode(new Node<Type>(nullptr, element, first));
            first = first->getPrevNode();
        }


    }

    int size() {

        int size = 0;

        Node<Type> *lastNode = first;

        while (lastNode->getNextNode() != nullptr || first != nullptr) {

            size++;
            lastNode = lastNode->getNextNode();

            if (lastNode == nullptr) {
                return size;
            }
        }

        return size;
    }

    bool empty() {

        if (first == nullptr) {
            return true;
        }

        return false;
    }

    Type &front() {

        return first->getInfo();
    }

    std::vector<Type> getAll()const {

        std::vector<Type> list;
        Node<Type> *node = first;


        while ( node != nullptr) {
           list.push_back(node->getInfo());


            node = node->getNextNode();
        }

        return list;
    }

    Type &back() {

        Node<Type> *lastNode = first;

        while (lastNode->getNextNode() != nullptr && first != nullptr) {
            lastNode = lastNode->getNextNode();
        }

        return lastNode->getInfo();

    }


    Type &at(int position) {

        Node<Type> *node = first;

        for (int i = 0; i < position; i++) {
            node = node->getNextNode();
        }

        return node->getInfo();
    }


    DoubleLinkedList<Type> &operator=(const DoubleLinkedList<Type> &rList) {

        if (this != rList) {


        }

    }

private:
    Node<Type> *first;
};

template<typename Type>
DoubleLinkedList<Type>::DoubleLinkedList(const DoubleLinkedList<Type> &list) {

    for (int i = 0; i < list.size(); i++) {
        this->push_back(list.at(i));
    }
}


#endif //UNTITLED1_DOUBLELINKEDLIST_H
