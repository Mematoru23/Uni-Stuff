#include "Currency.h"

Currency::Currency(int value, int quantity) : value(value), quantity(quantity) {}

Currency::~Currency() = default;

int Currency::getValue() const {
    return value;
}

int Currency::getQuantity() const {
    return quantity;
}

void Currency::setValue(int value) {
    Currency::value = value;
}

void Currency::setQuantity(int quantity) {
    Currency::quantity = quantity;
}

std::ostream &operator<<(std::ostream &os, const Currency &currency) {
    os << currency.value << " " << currency.quantity;
    return os;
}

std::istream &operator>>(std::istream &is, Currency &currency) {

    std::string strValue;
    std::string strQuantity;

    is >> strValue;
    is >> strQuantity;

    if (strValue != "" && strQuantity != "") {

        int value = std::stoi(strValue);
        int quantity = std::stoi(strQuantity);

        currency.setValue(value);
        currency.setQuantity(quantity);
    }


    return is;
}

Currency::Currency() {

    this->setValue(0);
    this->setQuantity(0);
}

Currency::Currency(const Currency &currency) {

    this->setValue(currency.getValue());
    this->setQuantity(currency.getQuantity());

}

Currency &Currency::operator=(const Currency &rCurrency) {

    if (this != &rCurrency) {

        this->setValue(rCurrency.getValue());
        this->setQuantity(rCurrency.getQuantity());

    }

    return *this;
}

bool Currency::operator==(const Currency &rCurrency) {
    return this->getValue() == rCurrency.getValue();
}

bool Currency::operator<(const Currency &rCurrency) {
    return this->getValue()>rCurrency.getValue();
}


