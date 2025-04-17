#pragma once 

#include <string>
#include <vector>
#include "constants.h"

namespace LibrarySystem {
    class Book {
        private:
            std::string title;
            std::string author;
            std::string isbn;
            std::string category;
            bool avaliable;
            int year;

        public:
            Book();
            Book(const std::string &title, const std::string &author, const std::string &isbn, const std::string& category, int year );

            
    }
;