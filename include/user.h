#pragma once

#include <string>
#include <vector>
#include "book.h"
#include "constants.h"

// uzywamy przestrzeni nazw LibrarySystem
namespace LibrarySystem {
    // tworzymy klase User
    class User{
    private:
        UserId id;
        std::string name;
        std::string email;
        std::vector<Book> rentedBooks;

    public:
        User();
        User(UserId id, const std::string &name, const std::string& email);

        // dodajemy metody do klasy User
        UserId getId() const;
        std::string getName() const;
        void setName(const std::string& name);
        std::string getEmail() const;
        void setEmail(const std::string& email);

        bool rentBook(Book& book);
        bool returnBook(Book &book);
        const std::vector<Book>& getRentedBooks() const;

        std::string toString() const;
    };
    // dodajemy alias dla kolekcji z uzytkownikami
    typedef std::vector<User> UserCollection;
    
    
}