
#ifndef UNTITLED1_CONSOLE_H
#define UNTITLED1_CONSOLE_H


#include "Service.h"

class Console {

private:
    Service service;

    void printMenu();
    void add();
    void showTransactions();
    void showCurrency();
    void withdraw();

public:
    void run();
};


#endif //UNTITLED1_CONSOLE_H
