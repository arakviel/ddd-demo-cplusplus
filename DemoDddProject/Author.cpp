#include <string>
#include <stdexcept>
#include "Author.h"

void Author::validateName(const std::string_view& nameValue) const {
    if (nameValue.empty()) {
        throw std::invalid_argument("Author name cannot be empty");
    }
    if (nameValue.size() > 100) {
        throw std::invalid_argument("Author name cannot exceed 100 characters");
    }
}
