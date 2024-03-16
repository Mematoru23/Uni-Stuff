
#include "Service.h"
#include <algorithm>

void Service::load() {

    currencyList.fileLoad();
    transactionList.fileLoad();
}

void Service::unload() {

    currencyList.fileUnload();
    transactionList.fileUnload();
}

std::vector<Transaction> Service::getAllTransactions()  {
    return transactionList.getAll();
}

std::vector<Currency> Service::getAllCurrency()  {
    return currencyList.getAll();
}

void Service::add(Transaction &transaction) {

    std::vector<Currency> currencyVector;


    if (transaction.getType() == "in") {

        for (auto currency: transaction.getCurrency()) {

            currencyVector = currencyList.getAll();

            auto pos = std::find(currencyVector.begin(),
                                 currencyVector.end(),
                                 currency);

            if (pos != currencyVector.end()) {

                Currency newCurrency(currency.getValue(), pos->getQuantity() + currency.getQuantity());

                int index = std::distance(currencyVector.begin(), pos);
                currencyList.update(index, newCurrency);

            } else {
                currencyList.add(currency);
            }
        }
    } else {

        currencyVector = currencyList.getAll();

        for (auto currency: transaction.getCurrency()) {

            auto pos = std::find(currencyVector.begin(),
                                 currencyVector.end(),
                                 currency);

            if(pos == currencyVector.end() ||
            currency.getQuantity() > pos->getQuantity()){
                return;
            }
        }

        for (auto currency: transaction.getCurrency()) {

            currencyVector = currencyList.getAll();

            auto pos = std::find(currencyVector.begin(),
                                 currencyVector.end(),
                                 currency);

            if (pos != currencyVector.end()) {

                Currency newCurrency(currency.getValue(), pos->getQuantity() - currency.getQuantity());

                int index = std::distance(currencyVector.begin(), pos);
                currencyList.update(index, newCurrency);
            }
        }
    }
    transactionList.add(transaction);
}

std::vector<Transaction> Service::backTrack(int sum) {
    std::vector<Transaction> solutionList;



    return solutionList;
}

Transaction Service::withdraw(int sum) const {

    Transaction solution;
    solution.setType("out");

    std::vector<Currency> atmCurrency;

    atmCurrency= currencyList.getAll();

    std::sort(atmCurrency.begin(), atmCurrency.end());


    for(auto currency:atmCurrency){

        if(solution.sum()>sum){
            break;
        }

        int quantity=0;

        while (solution.sum()+currency.getValue()*(quantity+1)<=sum && quantity<currency.getQuantity()){
            quantity++;
        }

        if(quantity!=0){

            solution.addCurrency(Currency(currency.getValue(),quantity));
        }
    }


    return solution;
}


