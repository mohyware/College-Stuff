#include "Manger.h"
Manger::Manger() : at(new AVLTree()) {}
Manger::~Manger() { delete at; }


AVLTree* Manger::get_reference_tree() { return at; }

bool Manger::IsValidChoice(std::string num)
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
        std::cerr << "-> Please, don't write letter. type only numbers :)\n";
        return false;
    }

    return true;
}

void Manger::checkVlidUser(std::string& userName , int& code , std::string message , std::string check) {
    
    do
    {
        getline(std::cin, userName);
        code = at->hashCode(userName);

        if (check == "addUser") {
            if (!at->search(code, at->ROOT())) return;
        }
        else {
            if (at->search(code, at->ROOT())) return;
        }
        
        std::cout << message;
    } while (true);
}

void Manger::addUser()
{
    AVLNode* an = new AVLNode();

    std::string userName;
    int code;

    std::cout << "Enter your user name: ";

    checkVlidUser(userName , code , "this user name is already taken please enter new one : " , "addUser");

    an->hashValue = code;
    an->user->setUserName(userName);
    std::cin >> *an->user;

    std::cin.ignore();

    at->Insert(an);
}

void Manger::removeUser()
{
    std::string userName;
    int code;

    std::cout << "Enter The user name you want to delete: ";
    
    checkVlidUser(userName, code, "No users found with this name please enter new one : " , "removeUser");

    char choice;
    bool validInput = false;

    do
    {
        std::cout << "ARE YOU SURE YOU WANT TO DELETE THIS USER? Y/N ";
        std::cin >> choice;

        std::cin.ignore();

        if (choice == 'Y' || choice == 'y')
        {
            std::cout << *at->search(code, at->ROOT())->user;
            at->Delete(code);
            std::cout << "--------->This User deleted successfully." << std::endl;
            validInput = true;
            system("pause");
        }
        else if (choice == 'N' || choice == 'n')
        {
            std::cout << "-> Deletion canceled." << std::endl;
            validInput = true;
            system("pause");
        }
        else
        {
            std::cout << "-> Invalid choice. Please enter Y or N." << std::endl;
        }
    } while (!validInput);
}

void Manger::updateUser()
{
    std::string userName;
    int code;

    std::cout << "Enter The user name you want to update: ";

    checkVlidUser(userName, code, "No users found to update with this name please enter new one : " , "updateUser");

    char ch;
    std::string pass = "";
    std::cout << "Enter the password: ";
    while ((ch = _getch()) != '\r')
    {
        if (ch == '\b' && !pass.empty()) {
            pass.pop_back();
            std::cout << "\b \b";
        }
        else if (ch != '\b') {
            std::cout << '*';
            pass += ch;
        }
    }
    std::cout << std::endl;

    if (at->search(code, at->ROOT())->user->getPassword() != pass) {
        std::cout << "-> Wrong password :(...Try again later." << std::endl;
        system("pause");
        return;
    }

    std::string email;
    std::string password;
    std::string gender;
    std::string birthday;
    std::string phoneNumber;

    // Handle menu
    auto color = [&](int cnt)-> void {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cnt);
    };

    auto menu = [&](int pos)-> void {
        int mx_size = 6;
        std::vector<std::string> v = { "Edit email .", "Edit password .", "Edit gender .","Edit birthday ." ,"Edit phone number ." , "Back ." };

        std::cout << "========================" << std::endl;
        std::cout << "                        " << std::endl;
        std::cout << "      Edit Menu         " << std::endl;
        std::cout << "                        " << std::endl;
        std::cout << "========================" << std::endl;
        for (auto i = 0; i < mx_size; ++i) {
            if (pos == i) {
                color(6);
                std::cout << "-->\t";
                std::cout << v[i] << std::endl;
                color(7);
            }
            else {
                std::cout << "\t" << v[i] << std::endl;
            }
        }
    };

    auto Menu = [&]()-> int {
        system("cls");
        int i = 0;
        char ch;
        menu(0);

        while (true) {

            ch = _getch();

            switch (ch) {
            case 27:
                exit(0);
                break;
            case 72: // UP
                system("cls");
                i = (i - 1 + 6) % 6;
                menu(i);
                break;
            case 80: // DOWN
                system("cls");
                i = (i + 1) % 6;
                menu(i);
                break;
            case '\r': // Enter
                return i;
            default:
                break;
            }
        }
        };

    while (true) {
        system("cls");

        int i = Menu();

        switch (i) {
        case 0:
            std::cout << "Enter the email: ";
            std::cin >> email;

            std::cin.ignore();
            at->search(code, at->ROOT())->user->setEmail(email);
            break;
        case 1:
            char ch;
            std::cout << "Enter the password: ";
            while ((ch = _getch()) != '\r')
            {
                if (ch == '\b' && !password.empty()) {
                    password.pop_back();
                    std::cout << "\b \b";
                }
                else if (ch != '\b') {
                    std::cout << '*';
                    password += ch;
                }
            }
            std::cout << std::endl;

            at->search(code, at->ROOT())->user->setPassword(password);
            break;
        case 2:
            char gen;
            do {
                std::cout << "Choose your gender (1-Male/2-Female) : ";
                std::cin >> gen;
                switch (gen)
                {
                case '1':
                    gender = "Male";
                    break;
                case '2':
                    gender = "Female";
                    break;
                case '3':
                    gender = "Civil Engineer";
                    break;
                default:
                    std::cout << "-> Invalid Choice...Please choose 1 or 2 only." << std::endl;
                    system("pause");
                    break;
                }
            } while (gen != '1' && gen != '2' && gen != '3');

            at->search(code, at->ROOT())->user->setGender(gender);
            break;
        case 3:
            std::cout << "Enter the birthday: ";
            std::cin >> birthday;

            std::cin.ignore();
            at->search(code, at->ROOT())->user->setBirth(birthday);
            break;
        case 4:
            std::cout << "Enter the phoneNumber: ";
            std::cin >> phoneNumber;

            std::cin.ignore();
            at->search(code, at->ROOT())->user->setPhoneNumber(phoneNumber);
            break;
        default:
            return;
        }
    }

    /*char choice;
    while (true) {
        system("cls");
        std::cout << "\t\t\t=======================" << std::endl;
        std::cout << "\t\t\t                           " << std::endl;
        std::cout << "\t\t\t\t  Edit menu  " << std::endl;
        std::cout << "\t\t\t                           " << std::endl;
        std::cout << "\t\t\t=======================" << std::endl;
        std::cout << "1- Edit email." << std::endl;
        std::cout << "2- Edit password." << std::endl;
        std::cout << "3- Edit gender." << std::endl;
        std::cout << "4- Edit birthday." << std::endl;
        std::cout << "5- Edit phone number." << std::endl;
        std::cout << "6- Back." << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
        case '1':
            std::cout << "Enter the email: ";
            std::cin >> email;

            at->search(code, at->ROOT())->user->setEmail(email);
            break;
        case '2':
            char ch;
            std::cout << "Enter the password: ";
            while ((ch = _getch()) != '\r')
            {
                if (ch == '\b' && !password.empty()) {
                    password.pop_back();
                    std::cout << "\b \b";
                }
                else if (ch != '\b') {
                    std::cout << '*';
                    password += ch;
                }
            }
            std::cout << std::endl;

            at->search(code, at->ROOT())->user->setPassword(password);
            break;
        case '3':
            char gen;
            do {
                std::cout << "Choose your gender (1-Male/2-Female) : ";
                std::cin >> gen;
                switch (gen)
                {
                case '1':
                    gender = "Male";
                    break;
                case '2':
                    gender = "Female";
                    break;
                case '3':
                    gender = "Civil Engineer";
                    break;
                default:
                    std::cout << "-> Invalid Choice...Please choose 1 or 2 only." << std::endl;
                    system("pause");
                    break;
                }
            } while (gen != '1' && gen != '2' && gen != '3'); 

            at->search(code, at->ROOT())->user->setGender(gender);

            break;
        case '4':
            std::cout << "Enter the birthday: ";
            std::cin >> birthday;

            at->search(code, at->ROOT())->user->setBirth(birthday);
            break;
        case '5':
            std::cout << "Enter the phoneNumber: ";
            std::cin >> phoneNumber;
            at->search(code, at->ROOT())->user->setPhoneNumber(phoneNumber);
            break;
        case '6':
            return;
        default:
            std::cout << "-> Invalid choice...please choose from the list.";
            break;
        }
    }*/
}

void Manger::searchUser()
{
    std::string userName;
    int code;

    std::cout << "Enter The user name to search :";
   
    checkVlidUser(userName, code, "No users found with this name please enter new one: ", "searchUser");

    std::cout << *at->search(code, at->ROOT())->user;
    system("pause");
}


void Manger::printAllUser()
{
    at->print();
}


void Manger::Handle_users() {
    std::string choice;
    bool exitMenu = false;

    auto color = [&](int cnt)-> void {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cnt);
    };

    auto menu = [&](int pos)-> void {
        int mx_size = 6;
        std::vector<std::string> v = { "Add User .", "Remove User .", "Update User .","Search User ." ,"Print All Users ." , "Exit ."};

        std::cout << "Handle Users:" << std::endl;
        std::cout << "*************" << std::endl;
        for (auto i = 0; i < mx_size; ++i) {
            if (pos == i) {
                color(4);
                std::cout << "-->\t";
                std::cout << v[i] << std::endl;
                color(7);
            }
            else {
                std::cout << "\t" << v[i] << std::endl;
            }
        }
    };

    
    auto Menu = [&]()-> int {
        system("cls");
        int i = 0;
        char ch;
        menu(0);

        while (true) {

            ch = _getch();

            switch (ch) {
            case 27:
                exit(0);
                break;
            case 72: // UP
                system("cls");
                i = (i - 1 + 6) % 6;
                menu(i);
                break;
            case 80: // DOWN
                system("cls");
                i = (i + 1) % 6;
                menu(i);
                break;
            case '\r': // Enter
                return i;
            default:
                break;
            }
        }
    };

    while (true) {
        system("cls");

        int i = Menu();

        switch (i) {
        case 0:
            addUser();
            break;
        case 1:
            if (at->isEmpty()) {
                std::cout << "--> No user found . Please enter users first ." << std::endl;
                system("pause");
                break;
            }
            removeUser();
            break;
        case 2:
            if (at->isEmpty()) {
                std::cout << "--> No user found . Please enter users first ." << std::endl;
                system("pause");
                break;
            }
            updateUser();
            break;
        case 3:
            if (at->isEmpty()) {
                std::cout << "--> No user found . Please enter users first ." << std::endl;
                system("pause");
                break;
            }
            searchUser();
            break;
        case 4:
            if (at->isEmpty()) {
                std::cout << "--> No user found . Please enter users first ." << std::endl;
                system("pause");
                break;
            }
            system("cls");
            std::cout << " =================================  " << std::endl;
            std::cout << "|                                  |" << std::endl;
            std::cout << "|      Info Of All Users           |" << std::endl;
            std::cout << "|                                  |" << std::endl;
            std::cout << " ================================== " << std::endl;
            printAllUser();
            system("pause");
            break;
        default:
            return;
        }
    }

    /*while (!exitMenu) {
        system("cls");
        std::cout << "Handle Users:" << std::endl;
        std::cout << "*************" << std::endl;
        std::cout << "1) Add User ." << std::endl;
        std::cout << "2) Remove User" << std::endl;
        std::cout << "3) Update User" << std::endl;
        std::cout << "4) Search User" << std::endl;
        std::cout << "5) Print All Users" << std::endl;
        std::cout << "6) Exit" << std::endl;
        std::cout << "Enter your choice (1-6): ";
        std::cin >> choice;

        if (!IsValidChoice(choice)) {
            system("pause");
            continue;
        }

        int cho = stoi(choice);

        if (at->isEmpty() && (cho >= 2 && cho <= 5)) {
            std::cout << "-> Manager is empty. Please add users first." << std::endl;
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
            std::cout << " =================================  " << std::endl;
            std::cout << "|                                  |" << std::endl;
            std::cout << "|      Info Of All Users           |" << std::endl;
            std::cout << "|                                  |" << std::endl;
            std::cout << " ================================== " << std::endl;
            printAllUser();
            system("pause");
            break;
        case 6:
            exitMenu = true;
            std::cout << "-> Exiting the program. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "-> Invalid choice. Please enter a number between 1 and 6." << std::endl;
            system("pause");
        }
    }*/
}