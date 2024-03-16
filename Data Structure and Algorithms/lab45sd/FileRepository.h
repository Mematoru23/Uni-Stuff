
#ifndef UNTITLED1_FILEREPOSITORY_H
#define UNTITLED1_FILEREPOSITORY_H

#include <string>
#include <fstream>
#include "typeinfo"
#include "Repository.h"

template<typename Type>
class FileRepository : public Repository<Type> {
public:

    FileRepository() {

        filePath = typeid(Type).name();
        filePath.append(".txt");
    }

    ~FileRepository() = default;

    void fileLoad();

    void fileUnload();

private:

    std::string filePath;

};

template<typename Type>
void FileRepository<Type>::fileUnload() {

    std::vector<Type> entityList;

    entityList = this->getAll();

    std::ofstream file(filePath);

    for (auto entity: entityList) {
        file << entity << "\n";
    }

    file.close();
}

template<typename Type>
void FileRepository<Type>::fileLoad() {

    std::ifstream file(filePath);

    Type e;

    //todo: debug this
    while (file>>e) {

        this->add(e);
    }

    file.close();

}

#endif //UNTITLED1_FILEREPOSITORY_H
