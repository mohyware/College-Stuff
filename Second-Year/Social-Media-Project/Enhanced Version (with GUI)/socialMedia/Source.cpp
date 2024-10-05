﻿// اللهم صل وسلم وبارك علي سيدنا محمد صلي الله عليه وسلم
#define _CRT_SECURE_NO_WARNINGS
#include "Browse.h"

using namespace std;

void color(int cnt) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cnt);
}

void menu(int pos) {
    int mx_size = 4;
    vector<string> v = { "Manage users .", "Browse users .", "Statistics activity of users .","EXIT ."};

    cout << "Menu list" << endl;
    cout << "*********" << endl;
    for (auto i = 0; i < mx_size; ++i) {
        if (pos == i) {
            color(31);
            cout << v[i] << endl;
            color(7);
        }
        else {
            cout << v[i] << endl;
        }
    }
}

int Menu() {
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
            i = (i - 1 + 4) % 4;
            menu(i);
            break;
        case 80: // DOWN
            system("cls");
            i = (i + 1) % 4;
            menu(i);
            break;
        case '\r': // Enter
            return i;
        default:
            break;
        }
    }
}

void Main_menu() {
    Browse* b = new Browse();

    while (true) {
        system("cls");

        int i = Menu();

        switch (i) {
        case 0:
            b->get_reference_manger()->Handle_users();
            break;
        case 1:
            b->Browse_user();
            break;
        case 2:
            b->Statistics();
            break;
        default:
            cout << "------> THANK YOU ! <-----" << endl;
            return;
        }
    }
}

int main()
{
   Main_menu();
   return 0;
}