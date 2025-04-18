#include "../include/user.h"
#include <sstream>
#include <algorithm>

namespace LibrarySystem {

    // Implementujemy konstruktory 
    
    User::User() : id(0), name(""), email("") {}

    User::User(UserId id, const std::string &name, const std::string &email) : id(id), name(name), email(email) {}

    // implementujemy gettery i settery

    UserId User::getId() const { return id; }
    std::string User::getName() const { return name; }
    void User::setName(const std::string &name) { this->name = name; }

    std::string User::getEmail() const { return email; }
    void User::setEmail(const std::string &email) { this->email = email; }

    // implementujemy metody do wypozyczania i zwracania ksiazek

    bool User::rentBook(Book &book) {
        if (book.isAvailable()) {
            book.setAvailable(false);
            rentedBooks.push_back(book);
            return true;
        }
        return false;
    }

    bool User::returnBook(Book &book) {
        auto it = std::find(rentedBooks.begin(), rentedBooks.end(), book);
        if (it != rentedBooks.end()) {
            book.setAvailable(true);
            rentedBooks.erase(it);
            return true;
        }
        return false;
    }

    const std::vector<Book>& User::getRentedBooks() const { return rentedBooks; }

    // implementujemy metode toString

    std::string User::toString() const {
        std::stringstream ss;
        ss << "User ID: " << id << ", Name: " << name << ", Email: " << email << ", Rented Books: " << rentedBooks.size();
        return ss.str();
    }

}