#include "Book.h"
// Default Constructor
Book::Book() : available(false) {}

// Parameterized Constructor
Book::Book(const string& title, const string& author, const string& ISBN, const string& genre, bool available)
    : title(title), author(author), ISBN(ISBN), genre(genre), available(available) {}

// Setters
void Book::setTitle(const string& title)
{
    this->title = title;
}

void Book::setAuthor(const string& author)
{
    this->author = author;
}

void Book::setISBN(const string& ISBN)
{
    this->ISBN = ISBN;
}

void Book::setGenre(const string& genre)
{
    this->genre = genre;
}

void Book::setAvailability(bool available)
{
    this->available = available;
}

// Getters
string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{
    return author;
}

string Book::getISBN() const
{
    return ISBN;
}

string Book::getGenre() const
{
    return genre;
}

bool Book::isAvailable() const
{
    return available;
}

// Other methods
void Book::print() const
{
    cout << "--------------------------------------" << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Genre: " << genre << endl;
    cout << "Availability: " << (available ? "Available" : "Borrowed") << endl;
    cout << "--------------------------------------" << endl;

}
