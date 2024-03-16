
#ifndef UNTITLED1_REPOSITORY_H
#define UNTITLED1_REPOSITORY_H

#include "vector"
#include "DoubleLinkedList.h"

template<typename Type>
class Repository {

private:
    DoubleLinkedList<Type> entityList;
    //std::vector<Type> entityList;

public:

    Repository() = default;
    ~Repository() = default;

    void add(Type& entity);
    void update(int& position,Type& entity);
    void del(int position);
    std::vector<Type> getAll()const;


};

template<typename Type>
std::vector<Type> Repository<Type>::getAll() const{

    return entityList.getAll();
    //return entityList;
}

template<typename Type>
void Repository<Type>::del(int position) {
entityList.erase(position);
}

template<typename Type>
void Repository<Type>::update(int &position, Type &entity) {
 entityList.at(position) = entity;
}

template<typename Type>
void Repository<Type>::add(Type &entity) {
    entityList.push_back(entity);
}


#endif //UNTITLED1_REPOSITORY_H
