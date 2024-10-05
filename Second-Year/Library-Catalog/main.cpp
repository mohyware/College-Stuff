#include <algorithm>
#include <stdexcept>
#include "customDs.h"
#include "Catalog.h"
#include <conio.h>

using namespace std;
Catalog catalog;
//sub menus
void searchMenu();

void arrangeMenu();

void statisticsMenu();
int main()
{
    int choice;
    do
    {
        cout << "---------> Main Menu" << endl;
        cout << "1. Add a Book" << endl;
        cout << "2. Remove a Book" << endl;
        cout << "3. Borrow a Book" << endl;
        cout << "4. Return a Book" << endl;
        cout << "5. Print Catalog" << endl;
        cout << "----> Sub Menus" << endl;
        cout << "   6. Search Menu" << endl;
        cout << "   7. Arrange Menu" << endl;
        cout << "   8. Statistics Menu" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            catalog.insertBook();
            break;
        case 2:
            catalog.print();
            catalog.removeBook();
            _getch();
            break;
        case 3:
            catalog.borrowBook();
            _getch();
            break;
        case 4:
            catalog.returnBook();
            _getch();
            break;
        case 5:
            catalog.print();
            _getch();
            break;
        case 6:
            system("CLS");
            searchMenu();
            break;
        case 7:
            system("CLS");
            arrangeMenu();
            break;
        case 8:
            system("CLS");
            statisticsMenu();
            break;
        case 9:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            _getch();
            break;
        }
        system("CLS");
    }
    while (choice != 9);

    return 0;

}
void searchMenu()
{
    int searchChoice;
    do
    {
        cout << "Search Menu" << endl;
        cout << "1. Search by Title" << endl;
        cout << "2. Search by Author" << endl;
        cout << "3. Search by ISBN" << endl;
        cout << "4. Search by Genre" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> searchChoice;

        switch (searchChoice)
        {
        case 1:
        {
            catalog.findBooksByTitle();
            _getch();
        }
        break;
        case 2:
            catalog.findBooksByAuthor();
            _getch();
            break;
        case 3:
            catalog.findBooksByISBN();
            _getch();
            break;
        case 4:
            catalog.findBooksByGenre();
            _getch();
            break;
        case 5:
            break;  // Back to the main menu
        default:
            cout << "Invalid choice. Please try again." << endl;
            _getch();
            break;
        }
        system("CLS");
    }
    while (searchChoice != 5);
}

void arrangeMenu()
{
    int arrangeChoice;
    do
    {
        cout << "Arrange Menu" << endl;
        cout << "1. Arrange by Title" << endl;
        cout << "2. Arrange by Author" << endl;
        cout << "3. Arrange by Genre" << endl;
        cout << "4. Print Catalog" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> arrangeChoice;

        switch (arrangeChoice)
        {
        case 1:
            catalog.arrangeByTitle();
            break;
        case 2:
            catalog.arrangeByAuthor();
            break;
        case 3:
            catalog.arrangeByGenre();
            break;
        case 4:
            catalog.print();
            _getch();
            break;
        case 5:
            break;  // Back to the main menu
        default:
            cout << "Invalid choice. Please try again." << endl;
            _getch();
            break;
        }
        system("CLS");
    }
    while (arrangeChoice != 5);
}

void statisticsMenu()
{
    int statisticsChoice;
    do
    {
        cout << "Statistics Menu" << endl;
        cout << "1. Total Books" << endl;
        cout << "2. Available Books" << endl;
        cout << "3. Borrowed Books" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> statisticsChoice;

        switch (statisticsChoice)
        {
        case 1:
            catalog.getTotalBooks();
            _getch();
            break;
        case 2:
            catalog.getAvailableBooks();
            _getch();
            break;
        case 3:
            catalog.getBorrowedBooks();
            _getch();
            break;
        case 4:
            break;  // Back to the main menu
        default:
            cout << "Invalid choice. Please try again." << endl;
            _getch();
            break;
        }
        system("CLS");
    }
    while (statisticsChoice != 4);
}
