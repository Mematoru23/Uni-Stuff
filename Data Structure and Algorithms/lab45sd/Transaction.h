
#ifndef UNTITLED1_TRANSACTION_H
#define UNTITLED1_TRANSACTION_H

#include <ostream>
#include "Currency.h"
#include "string"
#include "vector"

class Transaction {
public:
    Transaction(const std::string &type, const std::vector<Currency> &currency);
    Transaction();
    Transaction(const Transaction& transaction);

    ~Transaction() = default;

    const std::string &getType() const;

    void setType(const std::string &type);

    const std::vector<Currency> &getCurrency() const;

    int sum()const;

    void addCurrency(Currency currency);

    void setCurrency(const std::vector<Currency> &currency);

    friend std::ostream &operator<<(std::ostream &os, const Transaction &transaction);

    friend std::istream &operator>>(std::istream &is, Transaction &transaction);

    Transaction& operator=(const Transaction& rTransaction);

private:
    std::string type;
    std::vector<Currency> currency;
};


#endif //UNTITLED1_TRANSACTION_H
