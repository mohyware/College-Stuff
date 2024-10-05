#include "Manger.h"
Manger::Manger() : at(new AVLTree()) {}
Manger::~Manger() { delete at; }


AVLTree* Manger::get_reference_tree() { return at; }

bool Manger::IsValidChoice(string num)
{
    bool IsNotValid = false;
    IsNotValid = false;
    try
    {
        for (int i = 0; i < num.size(); i++)
            if (!isdigit(num[i]))
            {
                IsNotValid = true;
                break;
            }

        if (IsNotValid)
            throw "Error";
    }
    catch (const char* str)
    {
        cerr << "Please, don't write letter. type only numbers :)\n";
        return false;
    }

    return true;
}

void Manger::checkVlidUser(string& userName , int& code , string message , string check) {
    
    do
    {
        getline(cin, userName);
        code = at->hashCode(userName);

        if (check == "addUser") {
            if (!at->search(code, at->ROOT())) return;
        }
        else {
            if (at->search(code, at->ROOT())) return;
        }
        
        cout << message;
    } while (true);
}

void Manger::addUser()
{
    AVLNode* an = new AVLNode();

    string userName;
    int code;

    cout << "Enter your user name: ";
    cin.ignore();

    checkVlidUser(userName , code , "this user name is already taken please enter new one : " , "addUser");

    an->hashValue = code;
    an->user->setUserName(userName);
    cin >> *an->user;

    at->Insert(an);
}

void Manger::removeUser()
{
    string userName;
    int code;

    cout << "Enter The user name you want to delete: ";
    cin.ignore();
    
    checkVlidUser(userName, code, "No users found with this name please enter new one : " , "removeUser");

    char choice;
    bool validInput = false;

    do
    {
        cout << "ARE YOU SURE YOU WANT TO DELETE THIS USER? Y/N ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
            cout << *at->search(code, at->ROOT())->user;
            at->Delete(code);
            cout << "--------->This User deleted successfully." << endl;
            validInput = true;
            system("pause");
        }
        else if (choice == 'N' || choice == 'n')
        {
            cout << "Deletion canceled." << endl;
            validInput = true;
            system("pause");
        }
        else
        {
            cout << "Invalid choice. Please enter Y or N." << endl;
        }
    } while (!validInput);

}

void Manger::updateUser()
{
    string userName;
    int code;

    cout << "Enter The user name you want to update: ";
    cin.ignore();
    
    checkVlidUser(userName, code, "No users found to update with this name please enter new one: " , "updateUser");

    string email;
    string password;
    string gender;
    string birthday;
    string phoneNumber;

    char choice;

    cout << "Edit email? (Y/N): ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        cout << "Enter the email: ";
        cin >> email;

        at->search(code, at->ROOT())->user->setEmail(email);
    }

    cout << "Edit password? (Y/N): ";
    cin >> choice;
    if (choice == 'Y' || choice == 'y')
    {
        char ch;
        cout << "Enter the password: ";
        while ((ch = _getch()) != '\r')
        {
            cout << '*';
            password += ch;
        }
        cout << endl;

        at->search(code, at->ROOT())->user->setPassword(password);
    }

    cout << "Edit gender? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        cout << "Enter the gender: ";
        cin >> gender;

        at->search(code, at->ROOT())->user->setGendre(gender);
    }

    cout << "Edit birthday? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        cout << "Enter the birthday: ";
        cin >> birthday;

        at->search(code, at->ROOT())->user->setBirth(birthday);
    }

    cout << "Edit phoneNumber? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        cout << "Enter the phoneNumber: ";
        cin >> phoneNumber;
        at->search(code, at->ROOT())->user->setPhoneNumber(phoneNumber);

    }
}

void Manger::searchUser()
{
    string userName;
    int code;

    cout << "Enter The user name to search :";
    cin.ignore();
   
    checkVlidUser(userName, code, "No users found with this name please enter new one: ", "searchUser");

    cout << *at->search(code, at->ROOT())->user;
}


void Manger::printAllUser()
{
    at->print();
}


void Manger::Handle_users() {
    string choice;
    bool exitMenu = false;

    
    while (!exitMenu) {
        system("cls");
        cout << "Handle Users:" << endl;
        cout << "*************" << endl;
        cout << "1) Add User ." << endl;
        cout << "2) Remove User" << endl;
        cout << "3) Update User" << endl;
        cout << "4) Search User" << endl;
        cout << "5) Print All Users" << endl;
        cout << "6) Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        if (!IsValidChoice(choice)) {
            system("pause");
            continue;
        }

        int cho = stoi(choice);

        if (at->isEmpty() && (cho >= 2 && cho <= 5)) {
            cout << "-> Manager is empty. Please add users first." << endl;
            system("pause");
            continue;
        }
        switch (cho) {
        case 1:
            addUser();
            break;
        case 2:
            removeUser();
            break;
        case 3:
            updateUser();
            break;
        case 4:
            searchUser();
            break;
        case 5:
            system("cls");
            cout << " =================================  " << endl;
            cout << "|                                  |" << endl;
            cout << "|      Info Of All Users           |" << endl;
            cout << "|                                  |" << endl;
            cout << " ================================== " << endl;
            printAllUser();
            system("pause");
            break;
        case 6:
            exitMenu = true;
            cout << "-> Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "-> Invalid choice. Please enter a number between 1 and 6." << endl;
            system("pause");
        }
    }
}