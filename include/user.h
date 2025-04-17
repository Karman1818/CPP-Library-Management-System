#pragma once

#include <string>
#include <vector>
#include "book.h"
#include "constants.h"

namespace LibrarySystem {
    class User{
    private:
        UserId id;
        std::string name;
        std::string email;
        std::vector<Book> rentedBooks;

    public:
        User();
        User(UserId id, const std::string &name, const std::string& email);
    };
    
    User::User(/* args */)
    {
    }
    
    User::~User()
    {
    }
    
}