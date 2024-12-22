#include <iostream>
#include <memory>
#include <chrono>
#include "Book.h"
#include "Order.h"

void newBookTestCase()
{
    try {
        auto author = std::make_shared<Author>(1, "J.K. Rowling", Email("jk.rowling@example.com"));
        Isbn isbn{ "978-3-16-148410-0" };
        Title title{ "Harry Potter and the Philosophers Stone" };
        ReleaseDate releaseDate{ std::chrono::system_clock::now() - std::chrono::hours(24 * 365) };
        Money money{ 1999 }; // 19.99 USD

        Book book(isbn, title, releaseDate, author, money);

        book.displayBookInfo();

        // Зміна ціни
        book.updatePrice(2499); // 24.99 USD
        std::cout << "\nUpdated Price:\n";
        book.displayBookInfo();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}

int main() {
    //newBookTestCase();

    // Створення авторів
    auto author = std::make_shared<Author>(1, "J.K. Rowling", Email("jk.rowling@example.com"));

    // Створення книг
    ReleaseDate releaseDate{ std::chrono::system_clock::now() - std::chrono::hours(24 * 365) };

    Book book1(Isbn("978-3-16-148410-0"), Title("Book Title 1"), releaseDate, author, Money::fromDollars(19.99));
    Book book2(Isbn("978-1-61-729494-5"), Title("Book Title 2"), releaseDate, author, Money::fromDollars(29.99));

    // Створення замовлень
    Order order;

    // Додавання товарів до замовлення
    order.addItem(OrderItem(book1, Quantity(3)));  // Додаємо 3 одиниці першої книги
    order.addItem(OrderItem(book2, Quantity(2)));  // Додаємо 2 одиниці другої книги

    // Виведення інформації про замовлення
    std::cout << "Order Total: " << order.getTotal() << " cents" << std::endl;
    std::cout << "Order Details: " << std::endl;

    for (const auto& item : order.getItems()) {
        item.getBook().displayBookInfo();
        std::cout << "Quantity: " << item.getQuantity().getValue() << std::endl;
        std::cout << "Total for this item: $" << item.getTotal() / 100.0 << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }

    return 0;
}