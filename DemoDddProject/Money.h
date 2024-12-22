#pragma once

#include <iomanip>
#include <sstream>
#include <stdexcept>

class Money {
private:
    size_t cents; // Зберігаємо в копійках для точності

public:
    explicit Money(size_t cents) : cents(cents) {
        if (cents < 0) {
            throw std::invalid_argument("Price cannot be negative");
        }
    }

    static Money fromDollars(double dollars) {
        if (dollars < 0) {
            throw std::invalid_argument("Price cannot be negative");
        }
        // Переводимо долари в копійки з округленням
        return Money(static_cast<size_t>(dollars * 100 + 0.5));
    }

    size_t getCents() const { return cents; }

    std::string toString() const {
        std::ostringstream oss;
        oss << "$" << cents / 100 << "." << std::setw(2) << std::setfill('0') << cents % 100;
        return oss.str();
    }
};
