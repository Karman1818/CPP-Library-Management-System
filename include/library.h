#pragma once

#include <string>
#include <map>
#include "book.h"
#include "user.h"

namespace LibrarySystem {

    // tworzymy klase wyliczeniowa okreslajaca typy raportow

    enum class ReportType {
        POPULAR_BOOKS,
        OVERDUE_RENTALS,
        USER_ACTIVITY,
    };

    // dodajemy alias dla pary wskaznikow pokazujacy wypozyczenie
    typedef std::pair<User*, Book*> Rental;
    // kolekcja wypozyczen
    typedef std::vector<Rental> RentalCollection;

    // tworzymy klase Library
    class Library {
        private:
            BookCollection books;
            UserCollection users;
            RentalCollection activeRentals;
            std::string dataPath;

        public:
            // tworzymy konstruktory
            Library();
            explicit Library(const std::string& dataPath);

            // dodajemy metody do klasy Library
            void addBook(const Book& book);
            bool removeBook(const std::string& isbn);
            Book *findBookByISBN(const std::string &isbn);             
            const Book *findBookByISBN(const std::string &isbn) const; 
            BookCollection findBooksByTitle(const std::string& title);
            BookCollection findBooksByAuthor(const std::string& author);
            BookCollection findBooksByCategory(const std::string& category);
            BookCollection getAllBooks() const;

            void addUser(const User& user);
            bool removeUser(UserId id);
            User *findUserById(UserId id);            
            const User *findUserById(UserId id) const; 
            User* findUserByEmail(const std::string& email);
            UserCollection getAllUsers() const;

            bool rentBook(UserId userId, const std::string& isbn);
            bool returnBook(UserId userId, const std::string& isbn);
            RentalCollection getActiveRentals() const;

            void sortBooksByTitle();
            void sortBooksByAuthor();
            void sortBooksByYear();

            void sortUsersByName();
            void sortUsersByEmail();
            void sortUsersByRentedBooksCount();

            bool loadBooksFromFile(const std::string& filename);
            bool saveBooksToFile(const std::string& filename) const;
            bool loadUsersFromFile(const std::string& filename);
            bool saveUsersToFile(const std::string& filename) const;

            std::string generateReport(ReportType type) const;

    };

}
