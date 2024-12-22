#include "Order.h"

void Order::validateItem(const OrderItem& item) const {
    if (item.getQuantity().getValue() == 0) {
        throw std::invalid_argument("OrderItem quantity cannot be zero.");
    }
}

void Order::addItem(const OrderItem& item) {
    validateItem(item);
    items.push_back(item);
}

void Order::removeItem(const Book& book) {
    auto it = std::remove_if(items.begin(), items.end(), [&book](const OrderItem& item) {
        return item.getBook().getIsbn() == book.getIsbn();
        });
    items.erase(it, items.end());
}

size_t Order::getTotal() const {
    size_t total = 0.0;
    for (const auto& item : items) {
        total += item.getTotal();
    }
    return total;
}

bool Order::isEmpty() const {
    return items.empty();
}

const std::vector<OrderItem>& Order::getItems() const {
    return items;
}
