#pragma once

#include <string>
#include <regex>
#include <stdexcept>

class Email {
private:
    const std::regex emailPattern{ R"((\w+)(\.{1}\w+)*@(\w+)(\.\w{2,})+)" };
    std::string value;

    void validate(const std::string& email) const {
        if (!std::regex_match(email, emailPattern)) {
            throw std::invalid_argument("Invalid email format");
        }
    }

public:
    explicit Email(std::string value) : value(std::move(value)) {
        validate(this->value);
    }

    const std::string& getValue() const { return value; }
};
