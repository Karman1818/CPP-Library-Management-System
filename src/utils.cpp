#include "../include/utils.h"
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>


namespace LibraryUtils {

    // Implementujemy funkcje do parsowania

    std::vector<std::string> splitString(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::stringstream ss(str);
        std::string token;
        while (std::getline(ss, token, delimiter)) {
            tokens.push_back(trimString(token));
        }
        return tokens;
    }

    std::string trimString(const std::string& str) {
        size_t first = str.find_first_not_of(' ');
        size_t last = str.find_last_not_of(' ');
        return str.substr(first, (last - first + 1));
    }

    // Implementujemy funkcje do walidacji

    bool isValidISBN(const std::string& isbn) {
        // Prosta walidacja ISBN (sprawdzamy długość)
        return isbn.length() == 13;
    }

    bool isValidEmail(const std::string& email) {
        // Prosta walidacja adresu e-mail
        return email.find('@') != std::string::npos && email.find('.') != std::string::npos;
    }

    // Implementujemy funkcje do sortowania

    void bubbleSortBooksByTitle(LibrarySystem::BookCollection& books) {
        for (size_t i = 0; i < books.size() - 1; ++i) {
            for (size_t j = 0; j < books.size() - i - 1; ++j) {
                if (books[j].getTitle() > books[j + 1].getTitle()) {
                    std::swap(books[j], books[j + 1]);
                }
            }
        }
    }

    void bubbleSortBooksByAuthor(LibrarySystem::BookCollection& books) {
        for (size_t i = 0; i < books.size() - 1; ++i) {
            for (size_t j = 0; j < books.size() - i - 1; ++j) {
                if (books[j].getAuthor() > books[j + 1].getAuthor()) {
                    std::swap(books[j], books[j + 1]);
                }
            }
        }
    }


}