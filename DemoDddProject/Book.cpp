#include "Book.h"

void Book::displayBookInfo() const {
    std::cout << "Title: " << title.getValue() << "\n"
        << "Author: " << author->getName() << " (" << author->getEmail().getValue() << ")\n"
        << "ISBN: " << isbn.getValue() << "\n"
        << "Price: " << price.toString() << "\n";
}