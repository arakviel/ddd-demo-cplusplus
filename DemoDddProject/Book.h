#pragma once

#include <memory>
#include <iostream>
#include "ISBN.h"
#include "Title.h"
#include "ReleaseDate.h"
#include "Money.h"
#include "Author.h"

class Book {
private:
    Isbn isbn;
    Title title;
    ReleaseDate releaseDate;
    std::shared_ptr<Author> author;
    Money price;

public:
    Book(Isbn isbn, Title title, ReleaseDate releaseDate, std::shared_ptr<Author> author, Money price)
        : isbn(std::move(isbn)),
        title(std::move(title)),
        releaseDate(std::move(releaseDate)),
        author(std::move(author)),
        price(price) {}

    const Isbn& getIsbn() const { return isbn; }
    const Title& getTitle() const { return title; }
    const ReleaseDate& getReleaseDate() const { return releaseDate; }
    const std::shared_ptr<Author>& getAuthor() const { return author; }
    const Money& getPrice() const { return price; }

    void updatePrice(int newCents) {
        price = Money(newCents);
    }

    void displayBookInfo() const;
};