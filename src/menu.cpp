#include "menu.h"
#include <iostream>
#include <limits>

void displayMainMenu()
{
    std::cout << "  _________.__                        .____    ._____." << std::endl;
    std::cout << " /   _____/|__| ____   _____ _____    |    |   |__\\_ |______________ _______ ___.__." << std::endl;
    std::cout << " \\_____  \\ |  |/ ___\\ /     \\\\__  \\   |    |   |  || __ \\_  __ \\__  \\\\_  __ <   |  |" << std::endl;
    std::cout << " /        \\|  / /_/  >  Y Y  \\/ __ \\_ |    |___|  || \\_\\ \\  | \\// __ \\|  | \\/\\___  |" << std::endl;
    std::cout << "/_______  /|__\\___  /|__|_|  (____  / |_______ \\__||___  /__|  (____  /__|   / ____|" << std::endl;
    std::cout << "        \\/   /_____/       \\/     \\/          \\/       \\/           \\/       \\/" << std::endl;

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
    std::cout << "2. User Activity\n";
    std::cout << "3. Return to Main Menu\n";
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