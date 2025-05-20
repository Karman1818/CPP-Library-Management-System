#ifndef HANDLERS_H
#define HANDLERS_H

#include "../include/library.h"

// Deklaracje funkcji obsługujących poszczególne moduły
void handleBookManagement(LibrarySystem::Library &library);
void handleUserManagement(LibrarySystem::Library &library);
void handleRentals(LibrarySystem::Library &library);
void handleReports(LibrarySystem::Library &library);

#endif // HANDLERS_H