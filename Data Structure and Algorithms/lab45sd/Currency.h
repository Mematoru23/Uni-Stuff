
#ifndef UNTITLED1_CURRENCY_H
#define UNTITLED1_CURRENCY_H


#include <ostream>

class Currency {
public:
    Currency(int value, int quantity);
    Currency();
    Currency(const Currency& currency);

    virtual ~Currency();

    int getValue() const;

    int getQuantity() const;

    void setValue(int value);

    void setQuantity(int quantity);

    friend std::ostream &operator<<(std::ostream &os, const Currency &currency);
    friend std::istream &operator>>(std::istream &is, Currency &currency);

    Currency& operator=(const Currency& rCurrency);
    bool operator==(const Currency& rCurrency);
    bool operator<(const Currency& rCurrency);

private:

    int value;
    int quantity;
};


#endif //UNTITLED1_CURRENCY_H
