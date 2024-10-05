# Library Catalog System in C++

## Overview
This C++ program implements a **Library Catalog System** where users can manage book information, borrow and return books, and generate statistics. The system provides multiple functionalities to interact with the catalog, including adding/removing books, searching, arranging the catalog, and viewing statistics.

The program uses a `Catalog` class to handle these operations, which are accessible through a menu-driven interface.

## Features
The Library Catalog System offers the following features:

### Main Menu:
1. **Add a Book**: Add a new book to the catalog.
2. **Remove a Book**: Remove a book from the catalog.
3. **Borrow a Book**: Mark a book as borrowed by a user.
4. **Return a Book**: Mark a borrowed book as returned.
5. **Print Catalog**: Display the current list of books in the catalog.

### Sub Menus:
- **Search Menu**:
    - Search for books by title, author, ISBN, or genre.
  
- **Arrange Menu**:
    - Arrange the catalog by title, author, or genre, and print the catalog.

- **Statistics Menu**:
    - View statistics such as total books, available books, and borrowed books.

### Search Menu:
The `Search Menu` allows the user to search for books based on different attributes:
- **Search by Title**
- **Search by Author**
- **Search by ISBN**
- **Search by Genre**

### Arrange Menu:
The `Arrange Menu` allows the user to arrange and view books in the catalog:
- **Arrange by Title**
- **Arrange by Author**
- **Arrange by Genre**
- **Print Catalog**

### Statistics Menu:
The `Statistics Menu` provides options for viewing various statistics:
- **Total Books**: Shows the total number of books in the catalog.
- **Available Books**: Shows the number of books available for borrowing.
- **Borrowed Books**: Displays the number of books currently borrowed.