#pragma once

#include <chrono>
#include <stdexcept>

class ReleaseDate {
private:
    std::chrono::system_clock::time_point date;

public:
    explicit ReleaseDate(std::chrono::system_clock::time_point date)
        : date(date) {
        if (date > std::chrono::system_clock::now()) {
            throw std::invalid_argument("Release date cannot be in the future");
        }
    }

    std::chrono::system_clock::time_point getDate() const { return date; }
};
