#pragma once

#include <string>
#include <stdexcept>
#include <algorithm>

class Title {
private:
    std::string value;

    void validate(const std::string_view& val) const {
        if (val.empty() || val.size() > 256) {
            throw std::invalid_argument("Title must be between 1 and 256 characters");
        }
        // Перевіряємо, чи лише англійські символи
        if (!std::all_of(val.begin(), val.end(),
            [](char c) { return std::isalpha(c) || std::isdigit(c) || std::isspace(c); })) {
            throw std::invalid_argument("Title must contain only English characters and spaces");
        }
    }

public:
    explicit Title(std::string value) : value(std::move(value)) {
        this->validate(this->value);
    }

    const std::string& getValue() const { return value; }
};
