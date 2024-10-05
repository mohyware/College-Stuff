#ifndef CATALOG_H
#define CATALOG_H
#include <conio.h>

#include "customDs.h"
#include "Book.h"

class Catalog
{
private:
    customDs<Book> books;
    size_t bookCount;

public:
    // Constructors
    Catalog();

    // Book operations
    void insertBook();
    bool removeBook();
    bool borrowBook();
    bool returnBook();

    // Search books
    void findBooksByTitle() ;
    void findBooksByAuthor() ;
    void findBooksByISBN() ;
    void findBooksByGenre() ;

    // Arrange books
    void arrangeByTitle();
    void arrangeByAuthor();
    void arrangeByGenre();

    // Book statistics
    void getTotalBooks() ;
    void getAvailableBooks() ;
    void getBorrowedBooks() ;

    // Other methods
    void print() ;

};


#endif // CATALOG_H
