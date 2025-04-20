# System Zarządzania Biblioteką (C++)

Zaawansowany system zarządzania biblioteką napisany w C++, umożliwiający zarządzanie książkami, użytkownikami i wypożyczeniami.

## Funkcje

### Zarządzanie Książkami
- Dodawanie i usuwanie książek
- Wyszukiwanie książek po:
  - Tytule
  - Autorze
  - ISBN
  - Kategorii
- Sortowanie książek według:
  - Tytułu
  - Autora
  - Roku wydania

### Zarządzanie Użytkownikami
- Dodawanie i usuwanie użytkowników
- Wyszukiwanie użytkowników po:
  - ID
  - Adresie email
- Sortowanie użytkowników według:
  - Imienia i nazwiska
  - Adresu email
  - Liczby wypożyczonych książek

### System Wypożyczeń
- Wypożyczanie książek
- Zwracanie książek
- Przeglądanie aktywnych wypożyczeń

### Raporty
- Lista popularnych książek (według liczby wypożyczeń)
- Aktywność użytkowników

## Format Danych

### Książki (books.txt)
```
tytuł;autor;isbn;kategoria;rok
```

### Użytkownicy (users.txt)
```
imię_nazwisko;email;id
```

## Kompilacja i Uruchomienie

1. Sklonuj repozytorium:
```bash
git clone https://github.com/Karman1818/CPPLibrary.git
```

2. Przejdź do katalogu projektu:
```bash
cd CPPLibrary
```

3. Skompiluj projekt:
```bash
g++ src/*.cpp -o library
```

4. Uruchom program:
```bash
./library
```

## Wymagania Systemowe
- Kompilator C++ obsługujący C++17
- System plików z uprawnieniami do odczytu/zapisu
- Minimum 50MB wolnego miejsca na dysku

## Struktura Projektu
```
CPPLibrary/
├── src/
│   ├── main.cpp
│   ├── library.cpp
│   ├── book.cpp
│   ├── user.cpp
│   └── utils.cpp
├── include/
│   ├── library.h
│   ├── book.h
│   ├── user.h
│   ├── utils.h
│   └── constants.h
└── data/
    ├── books.txt
    └── users.txt
```

## Autor
- Marceli Karman
