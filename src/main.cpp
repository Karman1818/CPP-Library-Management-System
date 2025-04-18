#include <iostream>
#include <string>
#include "../include/library.h"
#include "../include/utils.h"

using namespace LibrarySystem;

void displayMainMenu();
void handleBookManagement(Library& library);
void handleUserManagement(Library& library);
void handleRentals(Library& library);
void handleReports(Library& library);

int main(int argc, char* argv[]) {

    std::string dataPath = DEAFULT_DATA_PATH;
    bool adminMode = false;

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "--admin"){
            adminMode = true;
        } else if (arg == "--data-path" && i + 1 < argc) {
            dataPath = argv[++i];
        } else {
            std::cout << "Unknown argument: " << arg << std::endl;
            return 1;
        }
    }

    Library library(dataPath);

    if(!library.loadBooksFromFile(dataPath + "/books.txt")){
        std::cout << "Failed to load books from file." << std::endl;
        return 1;
    }

    if(!library.loadUsersFromFile(dataPath + "/users.txt")){
        std::cout << "Failed to load users from file." << std::endl;
        return 1;
    }

    bool running = true;
    while (running)
    {
        displayMainMenu();
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
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

    library.saveBooksToFile(dataPath + "/books.txt");
    library.saveUsersToFile(dataPath + "/users.txt");

    std::cout << "Goodbye!" << std::endl;
    return 0;
    
}