#pragma once

#include <vector>
#include <stdexcept>
#include "OrderItem.h"

class Order {
private:
    std::vector<OrderItem> items;

    void validateItem(const OrderItem& item) const;

public:
    void addItem(const OrderItem& item);
    void removeItem(const Book& book);

    size_t getTotal() const;
    bool isEmpty() const;

    const std::vector<OrderItem>& getItems() const;
};
