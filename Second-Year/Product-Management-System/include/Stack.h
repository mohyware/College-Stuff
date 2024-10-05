#ifndef STACK_H
#define STACK_H
#include <algorithm> // for the copy
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Stack
{
private:
    T* arr;
    size_t capacity;
    int currtop;
    string name;

public:

    Stack() : name("Stack"), capacity(4), currtop(-1)
    {
        arr = new T[capacity];
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(T& element)
    {

        if(isFull())
        {
            resize();
        }
        arr[++currtop] = element;
    }

    T pop()
    {
        T topElement = arr[currtop--];
        return topElement;
    }

    bool isFull()
    {
        return currtop == static_cast<int>(capacity) - 1;
    }

    bool isEmpty()
    {
        return currtop == -1;
    }
    void resize()
    {
        // Double the capacity
        capacity *= 2;

        // Create a new array with the updated capacity
        T* newArr = new T[capacity];

        // Copy elements from the old array to the new array using copy from algorith
        copy(arr, arr + currtop + 1, newArr);

        // Delete the old array
        delete[] arr;

        // Point arr to the new array
        arr = newArr;
    }

    T top()
    {
        assert(!isEmpty() && "Error: Stack is empty. Cannot retrieve top element.\n");
        return arr[currtop];
    }
    void print()
    {
        int counter=0;
        for (int i = 0; i <= currtop; ++i)
        {
            cout << "\n\t\t\tAttribute ["<<++counter<<"] :"<<arr[i];
        }
        cout << "\n";
    }

    // Overloading << operator for printing
    friend std::ostream& operator<<(std::ostream& os, const Stack& stack)
    {
        for (int i = 0; i <= stack.currtop; ++i)
        {
            os  << stack.arr[i] << " ";
        }
        return os;
    }


};


#endif // STACK_H
