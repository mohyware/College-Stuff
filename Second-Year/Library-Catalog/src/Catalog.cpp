#include "Catalog.h"

// Constructor
Catalog::Catalog(): bookCount(0) {}

// Book operations
void Catalog::insertBook()
{
    string title, author, ISBN, genre;
    bool available;

    // Ask the user to enter book information
    cout << "Enter Book Title: ";
    cin.ignore(); // Ignore any previous newline characters in the input buffer
    getline(cin, title);

    cout << "Enter Book Author: ";
    getline(cin, author);

    cout << "Enter ISBN: ";
    cin >> ISBN;

    cout << "Enter Genre: ";
    cin.ignore(); // Ignore any previous newline characters in the input buffer
    getline(cin, genre);

    // Ask the user for availability (1 for available, 0 for borrowed)
    int availableChoice;
    do
    {
        cout << "Is the book available? (1 for available, 0 for borrowed): ";
        cin >> availableChoice;
    }
    while (availableChoice != 0 && availableChoice != 1);

    available = (availableChoice == 1);

    // Create a Book object with the entered information
    Book newBook(title, author, ISBN, genre, available);

    // Add the new book to the catalog
    books.insert_back(newBook);
    bookCount++;
}

bool Catalog::removeBook()
{

    string ISBN;
    cout << "Enter ISBN: ";
    cin >> ISBN;
    for (size_t i = 0; i < books.get_size(); ++i)
    {
        if (books[i].getISBN() == ISBN)
        {
            books.remove_at(i);
            cout << "Book Removed successfully!";
            return true;
        }
    }
    cout << "Book Not Found!";
    return false;
}

bool Catalog::borrowBook()
{
    cout << "--------------------------------------" << endl;
    cout << "Available Books:" << endl;
    for (size_t i = 0; i < books.get_size(); ++i)
    {
        const Book& book = books[i];
        if(!book.isAvailable())
            continue;
        cout << "--------------------------------------" << endl;
        cout << "(Book  ------->   " << (i + 1) << ")   Details:" << endl;
        cout << "Title: " << book.getTitle() << endl;
        cout << "Author: " << book.getAuthor() << endl;
        cout << "ISBN: " << book.getISBN() << endl;
        cout << "Genre: " << book.getGenre() << endl;
    }
    cout << "--------------------------------------" << endl;
    string ISBN;
    cout << "Enter ISBN: ";
    cin >> ISBN;
    for (size_t i = 0; i < books.get_size(); ++i)
    {
        if (books[i].getISBN() == ISBN)
        {
            if (books[i].isAvailable())
            {
                books[i].setAvailability(false);
                cout << "Book Borrowed successfully!";
                return true;
            }
            cout << "This Book is not available!";
            return false;
        }
    }
    cout << "Book Not Found!";
    return false;
}

bool Catalog::returnBook()
{
    string ISBN;
    cout << "Enter ISBN: ";
    cin >> ISBN;
    for (size_t i = 0; i < books.get_size(); ++i)
    {
        if (books[i].getISBN() == ISBN)
        {
            if (!books[i].isAvailable())
            {
                books[i].setAvailability(true);
                cout << "Book Returned successfully!";
                return true;
            }
            return false;
        }
    }
    cout << "Book Not Found!";
    return false;
}

// Search books
void Catalog::findBooksByTitle()
{
    string title;
    int count=0;
    cout << "Enter Book title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Books Matched"<<endl;
    for (size_t i = 0; i < books.get_size(); ++i)
    {
        if (books[i].getTitle() == title)
        {
            books[i].print();
            count++;
        }
    }
    cout <<"("<< count << ")  Found";
}

void Catalog::findBooksByAuthor()
{
    string author;
    int count=0;
    cout << "Enter Book Author: ";
    cin.ignore();
    getline(cin, author);
    cout << "Books Matched"<<endl;
    for (size_t i = 0; i < books.get_size(); ++i)
    {
        if (books[i].getAuthor() == author)
        {
            books[i].print();
            count++;
        }
    }
    cout <<"("<< count << ")  Found";
}

void Catalog::findBooksByISBN()
{
    string is;
    int count=0;
    cout << "Enter Book ISBN: ";
    cin.ignore();
    getline(cin, is);
    cout << "Books Matched"<<endl;
    for (size_t i = 0; i < books.get_size(); ++i)
    {
        if (books[i].getISBN() == is)
        {
            books[i].print();
            count++;
        }
    }
    cout <<"("<< count << ")  Found";
}

void Catalog::findBooksByGenre()
{
    string genre;
    int count=0;
    cout << "Enter Book Genre: ";
    cin.ignore();
    getline(cin, genre);
    cout << "Books Matched"<<endl;
    for (size_t i = 0; i < books.get_size(); ++i)
    {
        if (books[i].getGenre() == genre)
        {
            books[i].print();
            count++;
        }
    }
    cout <<"("<< count << ")  Found";
}

// compare functions
bool sortByTitle(const Book& a, const Book& b)
{
    return a.getTitle() < b.getTitle();
}

bool sortByAuthor(const Book& a, const Book& b)
{
    return a.getAuthor() < b.getAuthor();
}
bool sortByGenre(const Book& a, const Book& b)
{
    return a.getGenre() < b.getGenre();
}
// Arrange books

void Catalog::arrangeByTitle()
{
    books.sort(sortByTitle);
    if(books.get_size()>1)
    {
        cout<<"Catalog arranged successfully!"<<endl;
        _getch();
    }
    else if(books.get_size()==1)
    {
        cout<<"There is only one book in the catalog!"<<endl;
        _getch();
    }
    else
    {
        cout<<"Catalog is empty!"<<endl;
        _getch();
    }
}

void Catalog::arrangeByAuthor()
{
    books.sort(sortByAuthor);
    if(books.get_size()>1)
    {
        cout<<"Catalog arranged successfully!"<<endl;
        _getch();
    }
    else if(books.get_size()==1)
    {
        cout<<"There is only one book in the catalog!"<<endl;
        _getch();
    }
    else
    {
        cout<<"Catalog is empty!"<<endl;
        _getch();
    }
}

void Catalog::arrangeByGenre()
{
    books.sort(sortByGenre);
    if(books.get_size()>1)
    {
        cout<<"Catalog arranged successfully!"<<endl;
        _getch();
    }
    else if(books.get_size()==1)
    {
        cout<<"There is only one book in the catalog!"<<endl;
        _getch();
    }
    else
    {
        cout<<"Catalog is empty!"<<endl;
        _getch();
    }
}

// Book statistics
void Catalog::getTotalBooks()
{
    cout<<"Total Books: "<<books.get_size();
}

void Catalog::getAvailableBooks()
{
    int availableCount = 0;
    for (size_t i = 0; i < books.get_size(); ++i)
    {
        if (books[i].isAvailable())
        {
            availableCount++;
        }
    }
    cout<<"Available Books: "<<availableCount;
}

void Catalog::getBorrowedBooks()
{
    int borrowedCount = 0;
    for (size_t i = 0; i < books.get_size(); ++i)
    {
        if (!books[i].isAvailable())
        {
            borrowedCount++;
        }
    }
    cout<<"Borrowed Books: "<<borrowedCount;}



void Catalog::print()
{
    cout << "Catalog Content:" << endl;
    for (size_t i = 0; i < books.get_size(); ++i)
    {
        const Book& book = books[i];
        cout << "--------------------------------------" << endl;
        cout << "(Book  ------->   " << (i + 1) << ")   Details:" << endl;
        cout << "Title: " << book.getTitle() << endl;
        cout << "Author: " << book.getAuthor() << endl;
        cout << "ISBN: " << book.getISBN() << endl;
        cout << "Genre: " << book.getGenre() << endl;
        cout << "Availability: " << (book.isAvailable() ? "Available" : "Borrowed") << endl;
    }
    cout << "--------------------------------------" << endl;
}



