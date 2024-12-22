#pragma once
#include <stdexcept>

class Quantity {
private:
    size_t value;

    void validate(size_t quantity) const {
        if (quantity < 1 || quantity > 240) {
            throw std::invalid_argument("Quantity must be between 1 and 240.");
        }
    }

public:
    explicit Quantity(size_t quantity) : value(quantity) {
        validate(quantity);
    }

    size_t getValue() const { return value; }
};