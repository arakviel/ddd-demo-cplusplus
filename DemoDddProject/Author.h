#pragma once

#include <string>
#include <stdexcept>
#include "Email.h"

class Author {
private:
    size_t id;
    std::string name;
    Email email;

    void validateName(const std::string_view& nameValue) const;
public:
    Author(size_t id, std::string name, Email email)
        : id(id), name(std::move(name)), email(std::move(email)) {
        validateName(this->name);
    }

    size_t getId() const { return id; }
    const std::string& getName() const { return name; }
    const Email& getEmail() const { return email; }

    // Оновлення імені
    void updateName(const std::string& newName) {
        validateName(newName);
        name = newName;
    }
};
