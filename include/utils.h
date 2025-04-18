#pragma once

#include <string>
#include <vector>
#include "book.h"

// tworzymy przestrzeń nazw LibraryUtils
namespace LibraryUtils {

    // funkcje do parsowania
    std::vector<std::string> splitString(const std::string& str, char delimiter);
    std::string trimString(const std::string& str);

    // funkcje do walidacji
    bool isValidISBN(const std::string& isbn);
    bool isValidEmail(const std::string& email);

    // funkcje do sortowania
    void bubbleSortBooksByTitle(LibrarySystem::BookCollection& books);
    void bubbleSortBooksByAuthor(LibrarySystem::BookCollection& books);
}