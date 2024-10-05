// اللهم صل وسلم وبارك علي سيدنا محمد صلي الله عليه وسلم
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include <windows.h>
#include<unordered_map>
#include <utility>
#include "Browse.h"

using namespace std;

template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun&& fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream& os, const T_container& v) { os << '{'; string sep; for (const T& x : v) os << sep << x, sep = ", "; return os << '}'; }

#define AMAR_MOHY_MAHMOUD_DEBUG
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef AMAR_MOHY_MAHMOUD_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

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

/*void Main_menu() {
    Browse* b = new Browse();
    
    string ch;
    while(true) {
        system("cls");
        cout << "Menu list" << endl;
        cout << "*********" << endl;
        cout << "1) Manage users" << endl;
        cout << "2) Browse users" << endl;
        cout << "3) Statistics activity of users" << endl;
        cout << "0) EXIT" << endl;
        cout << "Enter your choice : ";
        cin >> ch;

        if (!b->get_reference_manger()->IsValidChoice(ch)) {
            system("pause");
            continue;
        }

        int cha = stoi(ch);
        switch (cha) {
        case 1:
            b->get_reference_manger()->Handle_users();
            break;
        case 2:
            b->Browse_user();
            break;
        case 3:
            b->Statistics();
            break;
        case 0:
            cout << "------> THANK YOU ! <-----" << endl;
            return;
        default:
            cout << "-> Invalid chioce ." << endl;
            system("pause");
            break;
        }
    }

}*/


int main()
{
    
    Main_menu();
   return 0;
}