#ifndef BOOK_H
#define BOOK_H
#include "iostream"
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    string ISBN;
    string genre;
    bool available;
public:
    // Constructors
    Book();
    Book(const string& title, const string& author, const string& ISBN, const string& genre, bool available);

    // Setters
    void setTitle(const string& title);
    void setAuthor(const string& author);
    void setISBN(const string& ISBN);
    void setGenre(const string& genre);
    void setAvailability(bool available);

    // Getters
    string getTitle() const;
    string getAuthor() const;
    string getISBN() const;
    string getGenre() const;
    bool isAvailable() const;

    // Other methods
    void print() const ;

};



#endif // BOOK_H
