
#include <vector>
#include <iostream>
#include "Console.h"
#include "Currency.h"

void Console::add() {

    std::string type;
    std::vector<Currency> currencyVector;

    std::cout << "Type: ";
    std::cin >> type;
    std::cout << "\n";

    int n;

    std::cout << "Number of unique bills: ";
    std::cin >> n;
    std::cout << "\n";

    for (int i = 0; i < n; ++i) {

        Currency currency;

        std::cout << "Enter value and quantity: ";
        std::cin >> currency;
        std::cout << "\n";

        currencyVector.push_back(currency);
    }

    Transaction transaction(type, currencyVector);

    service.add(transaction);

}

void Console::showTransactions() {

    for (auto transaction: service.getAllTransactions()) {

        std::cout << "Type: " << transaction.getType() << "\n";

        for (auto currency: transaction.getCurrency()) {

            std::cout << "    Value: " << currency.getValue();
            std::cout << " Quantity: " << currency.getQuantity() << "\n";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void Console::showCurrency() {

    for (auto currency: service.getAllCurrency()) {

        std::cout << "Value: " << currency.getValue();
        std::cout << " Quantity: " << currency.getQuantity() << "\n";
    }
    std::cout << "\n";
}

void Console::printMenu() {

    std::cout << "1. Add transaction. \n";
    std::cout << "2. Show transactions. \n";
    std::cout << "3. Show currency. \n";
    std::cout << "4. withdraw sum. \n";
    std::cout << "\n";

}

void Console::run() {

    service.load();

    while (true) {

        int option;

        this->printMenu();

        std::cout << "Enter option: ";
        std::cin >> option;
        std::cout << "\n";

        switch (option) {

            case 1:
                this->add();
                break;
            case 2:
                this->showTransactions();
                break;
            case 3:
                this->showCurrency();
                break;
            case 4:
                this->withdraw();
                break;
            default:
                service.unload();
                return;
                break;

        }
    }
}

void Console::withdraw() {

    int sum;

    std::cout << "Input sum you wish to withraw: ";
    std::cin >> sum;
    std::cout << "\n";

    Transaction transaction = service.withdraw(sum);

    if(transaction.sum()!=sum){
        std::cout<<"Transaction could not be created!\n";
        return;
    }

    std::cout<<transaction<<"\n";

    char option;
    std::cout<<"Do you wish to continue with ths transaction? (y/n) ";
    std::cin>>option;
    std::cout<<"\n";



    switch (option) {

        case'y':
            service.add(transaction);
            break;
        case'n':
            std::cout<<"transaction has been cancelled! \n";
            break;
    }

}
