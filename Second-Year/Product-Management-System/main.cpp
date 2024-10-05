#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <conio.h>
#include <cstdlib>
#include "Stack.h"
#include "Queue.h"
#include "LinkedList.h"

using namespace std;
/** ASSISTANT INLINE FUNCTIONS **/
inline void wait_or_clear(unsigned int sec, bool clear_screen = false)
{
    for (unsigned int i = sec; i > 0; --i)
    {
        cout << "Starting in " << i << " seconds" << std::endl;
        this_thread::sleep_for(chrono::seconds(1));
        if (clear_screen)
        {
            system("cls");
        }
    }
    if (clear_screen)
    {
        system("cls");
    }
}

inline bool IsValid(string num)
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

    catch (const char *str)
    {
        cerr << "Please, don't write letter. type only numbers :)\n";
        return false;
    }

    return true;
}
int main()
{
    LinkedList<Stack<string>> linked;

    while (true)
    {
        wait_or_clear(0,1);
        cout << "\n\tMain Menu:\n";
        cout << "1. New Product\n";
        cout << "2. Print All Products\n";
        cout << "3. Remove a Product\n";
        cout << "0. Quit\n";
        cout << "Enter Your Choice: ";
k:
        string c;
        cin>>c;
        wait_or_clear(0,1);
        int choice;
        if(!IsValid(c))
            goto k;
        choice=stoi(c);

        switch (choice)
        {
        case 1:
        {

            Stack<string> newStack;
            // Enqueue the stack onto the queue in the linked list
            linked.addQueue(newStack);
            system("pause");
            break;
        }
        case 2:
            linked.print();
            system("pause");
            break;
        case 3:
            linked.popQueue();
            system("pause");
            break;
        case 0:
            cout << "Program Ended...Thank You ^^\n";
            return 0;
        default:
            cout << "Invalid Choice. Please Try Again...\n";
            system("pause");
            break;
        }

    }
    return 0;

}
