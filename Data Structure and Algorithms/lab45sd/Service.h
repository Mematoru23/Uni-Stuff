
#ifndef UNTITLED1_SERVICE_H
#define UNTITLED1_SERVICE_H

#include "FileRepository.h"
#include "Currency.h"
#include "Transaction.h"


class Service {

private:
    FileRepository<Currency> currencyList;
    FileRepository<Transaction> transactionList;

public:

    Service() = default;
    ~Service() = default;

    void add(Transaction& transaction);

    void load();
    void unload();

    std::vector<Transaction> getAllTransactions();
    std::vector<Currency> getAllCurrency();

    Transaction withdraw(int sum)const;

    std::vector<Transaction> backTrack(int sum);

};


#endif //UNTITLED1_SERVICE_H
