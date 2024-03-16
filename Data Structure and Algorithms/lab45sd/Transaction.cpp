
#include "Transaction.h"

const std::string &Transaction::getType() const {
    return type;
}

void Transaction::setType(const std::string &type) {
    Transaction::type = type;
}

const std::vector<Currency> &Transaction::getCurrency() const {
    return currency;
}

void Transaction::setCurrency(const std::vector<Currency> &currency) {
    Transaction::currency = currency;
}

Transaction::Transaction(const std::string &type, const std::vector<Currency> &currency) : type(type),
                                                                                           currency(currency) {}

std::ostream &operator<<(std::ostream &os, const Transaction &transaction) {

    os << transaction.type << " ";
    os << transaction.currency.size() << " ";

    for (const auto &banknote: transaction.currency) {

        os << banknote << " ";

    }
    return os;
}

std::istream &operator>>(std::istream &is, Transaction &transaction) {

    std::vector<Currency> currencyList;
    std::string nrOfBills;

    is >> transaction.type;
    is >> nrOfBills;

    if (nrOfBills != "") {
        int length = std::stoi(nrOfBills);

        for (int i = 0; i < length; i++) {

            Currency currency;

            is >> currency;

            currencyList.push_back(currency);
        }

        transaction.setCurrency(currencyList);


    }


    return is;
}

Transaction::Transaction() {

    this->setType("N/a");
}

Transaction::Transaction(const Transaction &transaction) {

    this->setType(transaction.getType());
    this->setCurrency(transaction.getCurrency());
}

Transaction &Transaction::operator=(const Transaction &rTransaction) {

    if (this != &rTransaction) {

        this->setType(rTransaction.getType());
        this->setCurrency(rTransaction.getCurrency());
    }

    return *this;
}

int Transaction::sum() const {

    int sum=0;

    for(auto currency: this->getCurrency()){

        sum+=currency.getValue()*currency.getQuantity();
    }

    return sum;
}

void Transaction::addCurrency(Currency currency) {
    this->currency.push_back(currency);

}
