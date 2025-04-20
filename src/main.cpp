#include <iostream>
#include <string>
#include <limits>
#include <filesystem>
#include "../include/library.h"
#include "../include/utils.h"

using namespace LibrarySystem;
namespace fs = std::filesystem;

// Deklaracje funkcji
void displayMainMenu();
void displayBookMenu();
void displayUserMenu();
void displayRentalMenu();
void displayReportMenu();
void displaySortBookMenu();
void displaySortUserMenu();
void clearInputBuffer();
void handleBookManagement(Library &library);
void handleUserManagement(Library &library);
void handleRentals(Library &library);
void handleReports(Library &library);

void displayMainMenu()
{
    std::cout << "\n===== Library Management System =====\n";
    std::cout << "1. Book Management\n";
    std::cout << "2. User Management\n";
    std::cout << "3. Rental Management\n";
    std::cout << "4. Reports\n";
    std::cout << "5. Exit\n";
    std::cout << "===================================\n";
}

void displayBookMenu()
{
    std::cout << "\n===== Book Management =====\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Remove Book\n";
    std::cout << "3. Find Book by ISBN\n";
    std::cout << "4. Find Books by Title\n";
    std::cout << "5. Find Books by Author\n";
    std::cout << "6. Find Books by Category\n";
    std::cout << "7. Display All Books\n";
    std::cout << "8. Sort Books\n";
    std::cout << "9. Return to Main Menu\n";
    std::cout << "===========================\n";
}

void displayUserMenu()
{
    std::cout << "\n===== User Management =====\n";
    std::cout << "1. Add User\n";
    std::cout << "2. Remove User\n";
    std::cout << "3. Find User by ID\n";
    std::cout << "4. Find User by Email\n";
    std::cout << "5. Display All Users\n";
    std::cout << "6. Sort Users\n";
    std::cout << "7. Return to Main Menu\n";
    std::cout << "===========================\n";
}

void displayRentalMenu()
{
    std::cout << "\n===== Rental Management =====\n";
    std::cout << "1. Rent Book\n";
    std::cout << "2. Return Book\n";
    std::cout << "3. Display Active Rentals\n";
    std::cout << "4. Return to Main Menu\n";
    std::cout << "=============================\n";
}

void displayReportMenu()
{
    std::cout << "\n===== Reports =====\n";
    std::cout << "1. Popular Books\n";
    std::cout << "2. Overdue Rentals\n";
    std::cout << "3. User Activity\n";
    std::cout << "4. Return to Main Menu\n";
    std::cout << "===================\n";
}

void displaySortBookMenu()
{
    std::cout << "\n===== Sort Books =====\n";
    std::cout << "1. Sort by Title (Library method)\n";
    std::cout << "2. Sort by Author (Library method)\n";
    std::cout << "3. Sort by Year (Library method)\n";
    std::cout << "4. Sort by Title (Bubble Sort)\n";
    std::cout << "5. Sort by Author (Bubble Sort)\n";
    std::cout << "6. Return to Book Menu\n";
    std::cout << "=====================\n";
}

void displaySortUserMenu()
{
    std::cout << "\n===== Sort Users =====\n";
    std::cout << "1. Sort by Name\n";
    std::cout << "2. Sort by Email\n";
    std::cout << "3. Sort by Rented Books Count\n";
    std::cout << "4. Return to User Menu\n";
    std::cout << "=====================\n";
}

void clearInputBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

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
        { // Dodaj książkę
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
        { // Usuń książkę
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
        { // Znajdź książkę po ISBN
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
        { // Znajdź książki po tytule
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
        { // Znajdź książki po autorze
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
        { // Znajdź książki po kategorii
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
        { // Wyświetl wszystkie książki
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
        { // Sortuj książki
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
                case 6: // Powrót do menu książek
                    returnToBookMenu = true;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                }
            }
            break;
        }
        case 9: // Powrót do menu głównego
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
        { // Dodaj użytkownika
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

            // Sprawdź czy ID już istnieje
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
        { // Usuń użytkownika
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
        { // Znajdź użytkownika po ID
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
        { // Znajdź użytkownika po email
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
        { // Wyświetl wszystkich użytkowników
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
        { // Sortuj użytkowników
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
                case 3: // Sortuj po liczbie wypożyczonych książek
                    library.sortUsersByRentedBooksCount();
                    std::cout << "Users sorted by rented books count." << std::endl;
                    break;
                case 4: // Powrót do menu użytkowników
                    returnToUserMenu = true;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                }
            }
            break;
        }
        case 7: // Powrót do menu głównego
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
        { // Wypożycz książkę
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
        { // Zwróć książkę
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
        { // Wyświetl aktywne wypożyczenia
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
        case 1: // Popularne książki
            std::cout << library.generateReport(ReportType::POPULAR_BOOKS) << std::endl;
            break;
        case 2: // Przeterminowane wypożyczenia
            std::cout << library.generateReport(ReportType::OVERDUE_RENTALS) << std::endl;
            break;
        case 3: // Aktywność użytkowników
            std::cout << library.generateReport(ReportType::USER_ACTIVITY) << std::endl;
            break;
        case 4: // Powrót do menu głównego
            returnToMain = true;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

int main(int argc, char *argv[])
{
    std::string dataPath = DEFAULT_DATA_PATH;
    bool adminMode = false;

    // Przetwarzanie argumentów wiersza poleceń
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        if (arg == "--admin")
        {
            adminMode = true;
        }
        else if (arg == "--data-path" && i + 1 < argc)
        {
            dataPath = argv[++i];
        }
        else
        {
            std::cout << "Unknown argument: " << arg << std::endl;
            return 1;
        }
    }

    Library library(dataPath);

    // Sprawdź czy katalog istnieje, jeśli nie - utwórz go
    fs::path dataDir(dataPath);
    if (!fs::exists(dataDir)) {
        fs::create_directories(dataDir);
        std::cout << "Created data directory: " << dataDir.string() << std::endl;
    }

    // ladowanie ksiazek i uzytkownikow z plikow
    std::cout << "Loading data from " << dataPath << "..." << std::endl;

    fs::path booksPath = dataDir / "books.txt";
    fs::path usersPath = dataDir / "users.txt";

    if (!library.loadBooksFromFile(booksPath.string()))
    {
        std::cout << "Failed to load books from file. Starting with empty book collection." << std::endl;
    }
    else
    {
        std::cout << "Successfully loaded books from file." << std::endl;
    }

    if (!library.loadUsersFromFile(usersPath.string()))
    {
        std::cout << "Failed to load users from file. Starting with empty user collection." << std::endl;
    }
    else
    {
        std::cout << "Successfully loaded users from file." << std::endl;
    }

    bool running = true;
    while (running)
    {
        displayMainMenu();
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        clearInputBuffer();

        switch (choice)
        {
        case 1:
            handleBookManagement(library);
            break;
        case 2:
            handleUserManagement(library);
            break;
        case 3:
            handleRentals(library);
            break;
        case 4:
            handleReports(library);
            break;
        case 5:
            running = false;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    // zapisanie danych do plikow przed wyjściem
    std::cout << "Saving data to " << dataPath << "..." << std::endl;

    if (library.saveBooksToFile(booksPath.string()))
    {
        std::cout << "Books saved successfully." << std::endl;
    }
    else
    {
        std::cout << "Failed to save books." << std::endl;
    }

    if (library.saveUsersToFile(usersPath.string()))
    {
        std::cout << "Users saved successfully." << std::endl;
    }
    else
    {
        std::cout << "Failed to save users." << std::endl;
    }

    std::cout << "Goodbye!" << std::endl;
    return 0;
}