#include "../include/book.h"
#include <sstream>

namespace LibrarySystem {


    // Implementujemy konstruktory 
    
    Book::Book() : available(true), year(0) {}

    Book :: Book(const std::string &title, const std::string &author, const std::string &isbn, const std::string &category, int year)
    : title(title), author(author), isbn(isbn), category(category), available(true), year(year) {}

    // implementujemy gettery i settery

    std::string Book::getTitle() const { return title; }
    void Book::setTitle(const std::string &title) { this->title = title; }

    std::string Book::getAuthor() const { return author; }
    void Book::setAuthor(const std::string &author) { this->author = author; }

    std::string Book::getIsbn() const { return isbn; }
    void Book::setIsbn(const std::string &isbn) { this->isbn = isbn; }

    std::string Book::getCategory() const { return category; }
    void Book::setCategory(const std::string &category) { this->category = category; }

    bool Book::isAvailable() const { return available; }
    void Book::setAvailable(bool available) { this->available = available; }

    int Book::getYear() const { return year; }
    void Book::setYear(int year) { this->year = year; }

    // implementujemy metode toString i metode porowywania
    
    std::string Book::toString() const {
        std::stringstream ss;
        ss << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn
            << ", Category: " << category << ", Year: " << year
            << ", Available: " << (available ? "Yes" : "No");

        return ss.str();
    }

    bool Book::operator==(const Book &other) const {
        return isbn == other.isbn;
    }
    
}

