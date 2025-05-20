#include <iostream>
#include <string>
#include <filesystem>
#include "../include/library.h"
#include "../include/utils.h"
#include "menu.h"
#include "handlers.h"

using namespace LibrarySystem;
namespace fs = std::filesystem;


int main(int argc, char *argv[])
{
    std::string dataPath = DEFAULT_DATA_PATH;
    bool adminMode = false;

    // Przetwarzanie argumentow wiersza polecen
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

    // Sprawdź czy katalog istnieje jeśli nie to utwórz go
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