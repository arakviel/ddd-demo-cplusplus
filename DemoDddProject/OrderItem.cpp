#include "OrderItem.h"

OrderItem::OrderItem(const Book& book, Quantity quantity)
    : book(book), quantity(std::move(quantity)) {}

const Book& OrderItem::getBook() const {
    return book;
}

Quantity OrderItem::getQuantity() const {
    return quantity;
}

size_t OrderItem::getTotal() const {
    return book.getPrice().getCents() * quantity.getValue();
}