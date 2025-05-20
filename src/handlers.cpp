#include "handlers.h"
#include "menu.h"
#include "../include/utils.h"
#include <iostream>
#include <string>

using namespace LibrarySystem;

void handleBookManagement(Library &library)
{
    bool returnToMain = false;
    while (!returnToMain)
    {
        displayBookMenu();
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        clearInputBuffer();

        switch (choice)
        {
        case 1:
        { // Dodaj ksiazke
            std::string title, author, isbn, category;
            int year;

            std::cout << "Enter book title: ";
            std::getline(std::cin, title);

            std::cout << "Enter author: ";
            std::getline(std::cin, author);

            std::cout << "Enter ISBN (13 digits): ";
            std::getline(std::cin, isbn);

            if (!LibraryUtils::isValidISBN(isbn))
            {
                std::cout << "Invalid ISBN. Must be " << ISBN_LENGTH << " digits." << std::endl;
                break;
            }

            std::cout << "Enter category: ";
            std::getline(std::cin, category);

            std::cout << "Enter publication year: ";
            std::cin >> year;
            clearInputBuffer();

            Book newBook(title, author, isbn, category, year);
            library.addBook(newBook);
            std::cout << "Book added successfully." << std::endl;
            break;
        }
        case 2:
        { // Usun ksiazke
            std::string isbn;
            std::cout << "Enter ISBN of the book to remove: ";
            std::getline(std::cin, isbn);

            if (library.removeBook(isbn))
            {
                std::cout << "Book removed successfully." << std::endl;
            }
            else
            {
                std::cout << "Book not found." << std::endl;
            }
            break;
        }
        case 3:
        { // Znajdz ksiazke po isbn
            std::string isbn;
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, isbn);

            const Book *book = library.findBookByISBN(isbn);
            if (book)
            {
                std::cout << "Book found: " << book->toString() << std::endl;
            }
            else
            {
                std::cout << "Book not found." << std::endl;
            }
            break;
        }
        case 4:
        { // Znajdz ksiazki po tytule
            std::string title;
            std::cout << "Enter title: ";
            std::getline(std::cin, title);

            BookCollection books = library.findBooksByTitle(title);
            if (books.empty())
            {
                std::cout << "No books found with this title." << std::endl;
            }
            else
            {
                std::cout << "Found " << books.size() << " books:" << std::endl;
                for (const auto &book : books)
                {
                    std::cout << book.toString() << std::endl;
                }
            }
            break;
        }
        case 5:
        { // Znajdz ksiazki po autorze
            std::string author;
            std::cout << "Enter author: ";
            std::getline(std::cin, author);

            BookCollection books = library.findBooksByAuthor(author);
            if (books.empty())
            {
                std::cout << "No books found by this author." << std::endl;
            }
            else
            {
                std::cout << "Found " << books.size() << " books:" << std::endl;
                for (const auto &book : books)
                {
                    std::cout << book.toString() << std::endl;
                }
            }
            break;
        }
        case 6:
        { // Znajdz ksiazki po kategorii
            std::string category;
            std::cout << "Enter category: ";
            std::getline(std::cin, category);

            BookCollection books = library.findBooksByCategory(category);
            if (books.empty())
            {
                std::cout << "No books found in this category." << std::endl;
            }
            else
            {
                std::cout << "Found " << books.size() << " books:" << std::endl;
                for (const auto &book : books)
                {
                    std::cout << book.toString() << std::endl;
                }
            }
            break;
        }
        case 7:
        { // Wyswietl wszystkie ksiazki
            BookCollection books = library.getAllBooks();
            if (books.empty())
            {
                std::cout << "No books in the library." << std::endl;
            }
            else
            {
                std::cout << "All books in the library (" << books.size() << "):" << std::endl;
                for (const auto &book : books)
                {
                    std::cout << book.toString() << std::endl;
                }
            }
            break;
        }
        case 8:
        { // Sortuj ksiazki
            bool returnToBookMenu = false;
            while (!returnToBookMenu)
            {
                displaySortBookMenu();
                int sortChoice;
                std::cout << "Enter your choice: ";
                std::cin >> sortChoice;
                clearInputBuffer();

                switch (sortChoice)
                {
                case 1: // Sortuj po tytule (metoda Library)
                    library.sortBooksByTitle();
                    std::cout << "Books sorted by title." << std::endl;
                    break;
                case 2: // Sortuj po autorze (metoda Library)
                    library.sortBooksByAuthor();
                    std::cout << "Books sorted by author." << std::endl;
                    break;
                case 3: // Sortuj po roku (metoda Library)
                    library.sortBooksByYear();
                    std::cout << "Books sorted by year." << std::endl;
                    break;
                case 4: // Sortuj po tytule (Bubble Sort)
                    {
                    BookCollection books = library.getAllBooks();
                    LibraryUtils::bubbleSortBooksByTitle(books);
                    std::cout << "Books sorted by title using bubble sort." << std::endl;
                    for (const auto &book : books)
                    {
                        std::cout << book.toString() << std::endl;
                    }
                    break;
                }
                case 5: // Sortuj po autorze (Bubble Sort)
                    {
                    BookCollection books = library.getAllBooks();
                    LibraryUtils::bubbleSortBooksByAuthor(books);
                    std::cout << "Books sorted by author using bubble sort." << std::endl;
                    for (const auto &book : books)
                    {
                        std::cout << book.toString() << std::endl;
                    }
                    break;
                }
                case 6: // Powrot do menu ksiazek
                    returnToBookMenu = true;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                }
            }
            break;
        }
        case 9: // Powrot do menu glownego
            returnToMain = true;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void handleUserManagement(Library &library)
{
    bool returnToMain = false;
    while (!returnToMain)
    {
        displayUserMenu();
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        clearInputBuffer();

        switch (choice)
        {
        case 1:
        { // Dodaj uzytkownika
            std::string name, email;
            UserId id;

            std::cout << "Enter user name: ";
            std::getline(std::cin, name);

            std::cout << "Enter email: ";
            std::getline(std::cin, email);

            if (!LibraryUtils::isValidEmail(email))
            {
                std::cout << "Invalid email address." << std::endl;
                break;
            }

            std::cout << "Enter user ID: ";
            std::cin >> id;
            clearInputBuffer();

            // Sprawdz czy ID juz istnieje
            if (library.findUserById(id))
            {
                std::cout << "User ID already exists." << std::endl;
                break;
            }

            User newUser(id, name, email);
            library.addUser(newUser);
            std::cout << "User added successfully." << std::endl;
            break;
        }
        case 2:
        { // Usun uzytkownika
            UserId id;
            std::cout << "Enter ID of the user to remove: ";
            std::cin >> id;
            clearInputBuffer();

            if (library.removeUser(id))
            {
                std::cout << "User removed successfully." << std::endl;
            }
            else
            {
                std::cout << "User not found." << std::endl;
            }
            break;
        }
        case 3:
        { // Znajdz uzytkownika po ID
            UserId id;
            std::cout << "Enter ID: ";
            std::cin >> id;
            clearInputBuffer();

            const User *user = library.findUserById(id);
            if (user)
            {
                std::cout << "User found: " << user->toString() << std::endl;
            }
            else
            {
                std::cout << "User not found." << std::endl;
            }
            break;
        }
        case 4:
        { // Znajdz uzytkownika po emailu
            std::string email;
            std::cout << "Enter email: ";
            std::getline(std::cin, email);

            User *user = library.findUserByEmail(email);
            if (user)
            {
                std::cout << "User found: " << user->toString() << std::endl;
            }
            else
            {
                std::cout << "User not found." << std::endl;
            }
            break;
        }
        case 5:
        { // wyswietl wszystkich uzytkownikow
            UserCollection users = library.getAllUsers();
            if (users.empty())
            {
                std::cout << "No users in the system." << std::endl;
            }
            else
            {
                std::cout << "All users in the system (" << users.size() << "):" << std::endl;
                for (const auto &user : users)
                {
                    std::cout << user.toString() << std::endl;
                }
            }
            break;
        }
        case 6:
        { // Sortuj uzytkownikow
            bool returnToUserMenu = false;
            while (!returnToUserMenu)
            {
                displaySortUserMenu();
                int sortChoice;
                std::cout << "Enter your choice: ";
                std::cin >> sortChoice;
                clearInputBuffer();

                switch (sortChoice)
                {
                case 1: // Sortuj po nazwie
                    library.sortUsersByName();
                    std::cout << "Users sorted by name." << std::endl;
                    break;
                case 2: // Sortuj po email
                    library.sortUsersByEmail();
                    std::cout << "Users sorted by email." << std::endl;
                    break;
                case 3: // Sortuj po liczbie wypozyczonych ksiazek
                    library.sortUsersByRentedBooksCount();
                    std::cout << "Users sorted by rented books count." << std::endl;
                    break;
                case 4: // Powrot do menu uzytkownikow
                    returnToUserMenu = true;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                }
            }
            break;
        }
        case 7: // Powrot do menu glownego
            returnToMain = true;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void handleRentals(Library &library)
{
    bool returnToMain = false;
    while (!returnToMain)
    {
        displayRentalMenu();
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        clearInputBuffer();

        switch (choice)
        {
        case 1:
        { // Wypożycz ksiazke
            UserId userId;
            std::string isbn;

            std::cout << "Enter user ID: ";
            std::cin >> userId;
            clearInputBuffer();

            std::cout << "Enter book ISBN: ";
            std::getline(std::cin, isbn);

            if (library.rentBook(userId, isbn))
            {
                std::cout << "Book rented successfully." << std::endl;
            }
            else
            {
                std::cout << "Failed to rent book. Check if the user exists, the book exists, and the book is available." << std::endl;
            }
            break;
        }
        case 2:
        { // Zwróć ksiazke
            UserId userId;
            std::string isbn;

            std::cout << "Enter user ID: ";
            std::cin >> userId;
            clearInputBuffer();

            std::cout << "Enter book ISBN: ";
            std::getline(std::cin, isbn);

            if (library.returnBook(userId, isbn))
            {
                std::cout << "Book returned successfully." << std::endl;
            }
            else
            {
                std::cout << "Failed to return book. Check if the rental exists." << std::endl;
            }
            break;
        }
        case 3:
        { // Wyswietl aktywne wypozyczenia
            RentalCollection rentals = library.getActiveRentals();
            if (rentals.empty())
            {
                std::cout << "No active rentals." << std::endl;
            }
            else
            {
                std::cout << "Active rentals (" << rentals.size() << "):" << std::endl;
                for (const auto &rental : rentals)
                {
                    std::cout << "User: " << rental.first->getName()
                              << " (ID: " << rental.first->getId() << ") - Book: "
                              << rental.second->getTitle()
                              << " (ISBN: " << rental.second->getIsbn() << ")" << std::endl;
                }
            }
            break;
        }
        case 4: // Powrót do menu głównego
            returnToMain = true;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void handleReports(Library &library)
{
    bool returnToMain = false;
    while (!returnToMain)
    {
        displayReportMenu();
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        clearInputBuffer();

        switch (choice)
        {
        case 1: // Popularne ksiazki
            std::cout << library.generateReport(ReportType::POPULAR_BOOKS) << std::endl;
            break;
        case 2: // Aktywnosc uzytkownikow
            std::cout << library.generateReport(ReportType::USER_ACTIVITY) << std::endl;
            break;
        case 3: // Powrot do menu glownego
            returnToMain = true;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}