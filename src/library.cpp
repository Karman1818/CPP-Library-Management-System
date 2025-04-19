#include "../include/Library.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

namespace LibrarySystem {

    // Implementujemy konstruktory

    Library::Library():dataPath(DEAFULT_DATA_PATH) {}

    Library::Library(const std::string& dataPath):dataPath(dataPath) {}

    // Implementujemy metody do dodawania i usuwania ksiazek

    void Library::addBook(const Book& book) {
        books.push_back(book);
    }

    bool Library::removeBook(const std::string &isbn){
        auto it = std::find_if(books.begin(), books.end(),
        [&isbn](const Book &book) { return book.getIsbn() == isbn; });
        if (it != books.end())
        {
            books.erase(it);
            return true;
        }
        return false;
    }

    // Implementujemy metody do wyszukiwania ksiazek

    Book *Library::findBookByISBN(const std::string &isbn){
        auto it = std::find_if(books.begin(), books.end(),
                               [&isbn](const Book &book)
                               { return book.getIsbn() == isbn; });
        if (it != books.end())
        {
            return &(*it);
        }
        return nullptr;
    }

    const Book *Library::findBookByISBN(const std::string &isbn) const
    {
        auto it = std::find_if(books.begin(), books.end(),
                               [&isbn](const Book &book)
                               { return book.getIsbn() == isbn; });
        if (it != books.end())
        {
            return &(*it);
        }
        return nullptr;
    }

    BookCollection Library::findBooksByTitle(const std::string &title) {
        BookCollection result;
        std::copy_if(books.begin(), books.end(), std::back_inserter(result),
        [&title](const Book &book) { return book.getTitle() == title; });
        return result;
    }

    BookCollection Library::findBooksByAuthor(const std::string &author) {
        BookCollection result;
        std::copy_if(books.begin(), books.end(), std::back_inserter(result),
        [&author](const Book &book) { return book.getAuthor() == author; });
        return result;
    }

    BookCollection Library::findBooksByCategory(const std::string &category) {
        BookCollection result;
        std::copy_if(books.begin(), books.end(), std::back_inserter(result),
        [&category](const Book &book) { return book.getCategory() == category; });
        return result;
    }

    BookCollection Library::getAllBooks() const {
        return books;
    }

    // Implementujemy metody do dodawania i usuwania uzytkownikow

    void Library::addUser(const User &user) {
        users.push_back(user);
    }

    bool Library::removeUser(UserId id) {
        auto it = std::find_if(users.begin(), users.end(),
        [&id](const User &user) { return user.getId() == id; });
        if (it != users.end())
        {
            users.erase(it);
            return true;
        }
        return false;
    }

    // Implementujemy metody do wyszukiwania uzytkownikow

    User *Library::findUserById(UserId id)
    {
        auto it = std::find_if(users.begin(), users.end(),
                               [&id](const User &user)
                               { return user.getId() == id; });
        if (it != users.end())
        {
            return &(*it);
        }
        return nullptr;
    }

    const User* Library::findUserById(UserId id) const {
        auto it = std::find_if(users.begin(), users.end(),
        [&id](const User &user) { return user.getId() == id; });
        if (it != users.end())
        {
            return &(*it);
        }
        return nullptr;
    }

   

    User* Library::findUserByEmail(const std::string &email) {
        auto it = std::find_if(users.begin(), users.end(),
        [&email](const User &user) { return user.getEmail() == email; });
        if (it != users.end())
        {
            return &(*it);
        }
        return nullptr;
    }

    UserCollection Library::getAllUsers() const {
        return users;
    }

    // Implementujemy metody do wypozyczania i zwracania ksiazek

    bool Library::rentBook(UserId userId, const std::string &isbn) {
        User* user = findUserById(userId);
        Book* book = findBookByISBN(isbn);
        if (user && book && !book->isAvailable()) {
            activeRentals.push_back(std::make_pair(user, book));
            book->setAvailable(false);
            return true;
        }
        return false;
    }

    bool Library::returnBook(UserId userId, const std::string &isbn) {
        auto it = std::find_if(activeRentals.begin(), activeRentals.end(),
        [&userId, &isbn](const Rental &rental) {
            return rental.first->getId() == userId && rental.second->getIsbn() == isbn;
        });
        if (it != activeRentals.end()) {
            it->second->setAvailable(true);
            activeRentals.erase(it);
            return true;
        }
        return false;
    }

    RentalCollection Library::getActiveRentals() const {
        return activeRentals;
    }

    // Implementujemy metody do sortowania

    void Library::sortBooksByTitle() {
        std::sort(books.begin(), books.end(), [](const Book &a, const Book &b) {
            return a.getTitle() < b.getTitle();
        });
    }

    void Library::sortBooksByAuthor() {
        std::sort(books.begin(), books.end(), [](const Book &a, const Book &b) {
            return a.getAuthor() < b.getAuthor();
        });
    }

    void Library::sortBooksByYear() {
        std::sort(books.begin(), books.end(), [](const Book &a, const Book &b) {
            return a.getYear() < b.getYear();
        });
    }

    void Library::sortUsersByName() {
        std::sort(users.begin(), users.end(), [](const User &a, const User &b) {
            return a.getName() < b.getName();
        });
    }

    void Library::sortUsersByEmail() {
        std::sort(users.begin(), users.end(), [](const User &a, const User &b) {
            return a.getEmail() < b.getEmail();
        });
    }
    void Library::sortUsersByRentedBooksCount() {
        std::sort(users.begin(), users.end(), [](const User &a, const User &b) {
            return a.getRentedBooks().size() < b.getRentedBooks().size();
        });
    }

    // Implementujemy metody do wczytywania i zapisywania danych do pliku
    bool Library::loadBooksFromFile(const std::string &filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error opening file: " << filename << std::endl;
            return false;
        }

        books.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string title, author, isbn, category, yearStr;

            std::getline(ss, title, ';');
            std::getline(ss, author, ';');
            std::getline(ss, isbn, ';');
            std::getline(ss, category, ';');
            std::getline(ss, yearStr, ';');

            int year = std::stoi(yearStr);
            books.push_back(Book(title, author, isbn, category, year));
        }
        

        file.close();
        return true;
    }

    bool Library::saveBooksToFile(const std::string &filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error opening file: " << filename << std::endl;
            return false;
        }

        for (const auto &book : books) {
            file << book.getTitle() << ";"
                 << book.getAuthor() << ";"
                 << book.getIsbn() << ";"
                 << book.getCategory() << ";"
                 << book.getYear() << std::endl;
        }
        file.close();
        return true;

    }

    bool Library::loadUsersFromFile(const std::string &filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error opening file: " << filename << std::endl;
            return false;
        }
        users.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string name, email, idStr;
            std::getline(ss, name, ';');
            std::getline(ss, email, ';');
            std::getline(ss, idStr, ';');
            UserId id = std::stoi(idStr);
            users.push_back(User(id, name, email));
        }

        file.close();
        return true;
    }

    bool Library::saveUsersToFile(const std::string &filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error opening file: " << filename << std::endl;
            return false;
        }
        for (const auto &user : users) {
            file << user.getName() << ";"
                 << user.getEmail() << ";"
                 << user.getId() << std::endl;
        }
        file.close();
        return true;
    }

    // Implementujemy metode do generowania raportow

    std::string Library::generateReport(ReportType type) const
    {
        std::stringstream report;
        switch (type)
        {
        case ReportType::POPULAR_BOOKS:
        {
            report << "=== REPORT: POPULAR BOOKS ===" << std::endl;
            std::map<std::string, int> bookRentals;
            for (const auto &rental : activeRentals)
            {
                bookRentals[rental.second->getIsbn()]++;
            }
            std::vector<std::pair<std::string, int>> rentalCounts(
                bookRentals.begin(), bookRentals.end());
            std::sort(rentalCounts.begin(), rentalCounts.end(),
                      [](const auto &a, const auto &b)
                      {
                          return a.second > b.second;
                      });
        
            for (const auto &item : rentalCounts)
            {
                const Book *book = findBookByISBN(item.first); 
                if (book)
                {
                    report << book->getTitle() << " by " << book->getAuthor()
                           << " - rented " << item.second << " times" << std::endl;
                }
            }
            break;
        }
        case ReportType::OVERDUE_RENTALS:
            report << "=== REPORT: OVERDUE RENTALS ===" << std::endl;
            report << "This functionality requires implementation of rental date tracking." << std::endl;
            break;
        case ReportType::USER_ACTIVITY:
        {
            report << "=== REPORT: USER ACTIVITY ===" << std::endl;
            std::map<UserId, int> userRentals;
            for (const auto &rental : activeRentals)
            {
                userRentals[rental.first->getId()]++;
            }
            std::vector<std::pair<UserId, int>> rentalCounts(
                userRentals.begin(), userRentals.end());
            std::sort(rentalCounts.begin(), rentalCounts.end(),
                      [](const auto &a, const auto &b)
                      {
                          return a.second > b.second;
                      });
            for (const auto &item : rentalCounts)
            {
                const User *user = findUserById(item.first); 
                if (user)
                {
                    report << user->getName() << " (" << user->getEmail()
                           << ") - rented " << item.second << " books" << std::endl;
                }
            }
            break;
        }
        }
        return report.str();
    }
}
