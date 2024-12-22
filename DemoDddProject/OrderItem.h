#pragma once
#include "Book.h"
#include "Quantity.h"

class OrderItem {
private:
    Book book;
    Quantity quantity;

public:
    OrderItem(const Book& book, Quantity quantity);

    const Book& getBook() const;
    Quantity getQuantity() const;

    size_t getTotal() const;
};