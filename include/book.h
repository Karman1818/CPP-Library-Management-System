#pragma once 

#include <string>
#include <vector>
#include "constants.h"

// robimy przestrzeń nazw LibrarySystem
namespace LibrarySystem {

    // tworzymy klase Book
    class Book {
        private:
            std::string title;
            std::string author;
            std::string isbn;
            std::string category;
            bool available;
            int year;

        public:
            Book();
            Book(const std::string& title, const std::string& author, const std::string& isbn, const std::string& category, int year );

            // dodajemy metody do klasy book
            std::string getTitle() const;
            void setTitle(const std::string& title);
            std::string getAuthor() const;
            void setAuthor(const std::string& author);
            std::string getIsbn() const;
            void setIsbn(const std::string& isbn);
            std::string getCategory() const;
            void setCategory(const std::string& category);
            int getYear() const;
            void setTitle(int year);

            std::string toString() const;
            bool operator==(const Book& other) const;
    };
    // dodajemy alias dla kolekcji z ksiazkami
    typedef std::vector<Book> BookCollection;
}
