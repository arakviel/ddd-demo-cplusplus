#pragma once

#include <string>
#include <regex>
#include <stdexcept>

class Isbn {
private:
    std::string value;

    void validate(const std::string& isbn) const {
        const std::regex isbnPattern(R"(\b\d{3}-\d{1,5}-\d{1,7}-\d{1,7}-\d{1}\b)");
        if (!std::regex_match(isbn, isbnPattern)) {
            throw std::invalid_argument("Invalid ISBN format");
        }
    }

public:
    explicit Isbn(std::string value) : value(std::move(value)) {
        validate(this->value);
    }

    const std::string& getValue() const { return value; }

    bool operator==(const Isbn& other) const {
        return this->value == other.value;
    }
};
