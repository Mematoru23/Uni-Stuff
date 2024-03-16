
#ifndef UNTITLED1_NODE_H
#define UNTITLED1_NODE_H

template<typename Type>
class Node {
public:
    Node(Node<Type> *prevNode ,Type info ,Node<Type> *nextNode) : nextNode(nextNode), prevNode(prevNode), info(info) {}
    Node(){ nextNode= nullptr; prevNode= nullptr;}

    Node<Type> *getNextNode() const {
        return nextNode;
    }

    void setNextNode(Node<Type> *nextNode) {
        Node::nextNode = nextNode;
    }

    Node<Type> *getPrevNode() const {
        return prevNode;
    }

    void setPrevNode(Node<Type> *prevNode) {
        Node::prevNode = prevNode;
    }

    Type &getInfo() {
        return info;
    }

    void setInfo(Type info) {
        Node::info = info;
    }


private:
    Node<Type> *nextNode;
    Node<Type> *prevNode;
    Type info;
};


#endif //UNTITLED1_NODE_H
