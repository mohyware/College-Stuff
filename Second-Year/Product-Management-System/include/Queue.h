#ifndef QUEUE_H
#define QUEUE_H

#include "Stack.h"
#include <iostream>


template <typename T>
class Queue
{
private:
    Stack<string>* stacks;  // Array of three stacks
    size_t capacity;
    size_t size;
    size_t stackSize;
    int currentStackIndex;
public:
    // Constructor
    Queue(size_t initialCapacity = 3, size_t stackCapacity = 3)
    {
        currentStackIndex=0;
        capacity = initialCapacity;
        stackSize = stackCapacity;
        stacks = new Stack<string>[stackSize];
        size = 0;
    }

    // Destructor
    ~Queue()
    {
        delete[] stacks;
    }

    // Function to enqueue an element into one of the stacks
    void enqueue( )
    {

        while (true)
        {
            cout << "Enter an operation to store. Enter 'N' to finish: ";
            string element;
            cin >> element;
            if (element == "N" || element =="n")
            {
                break; // exit the loop if the user enters 'n'
            }
            size_t stackIndex = size % stackSize;
            stacks[stackIndex].push(element);


        }
        size++;
    }

    // Function to dequeue an element from the front stack
    void dequeue()
    {

        // Determine the current stack index to dequeue from
        int stackIndex = currentStackIndex % 3;

        // Print and pop elements from the current stack until it's empty
        while (!stacks[stackIndex].isEmpty())
        {
            string element = stacks[stackIndex].top();
            cout << "\tPopping from Stack " << stackIndex + 1 << ": " << element <<"\n";
            stacks[stackIndex].pop();
        }
        cout<<"\n\n\n";
        size--;

        // Switch to the next stack for the next dequeue operation
        currentStackIndex++;
    }

    // Function to check if the queue is empty
    bool isEmpty() const
    {
        return size == 0;
    }

    // Function to check if the queue is full
    bool isFullS() const
    {
        // Check if all stacks in the array are full
        for (size_t i = 0; i < stackSize; ++i)
        {
            if (!stacks[i].isFull())
            {
                return false;
            }
        }
        return true;
    }

    bool isFullQ() const
    {
        return size ==capacity;
    }

    void print() const
    {
        for (size_t i = 0; i < stackSize; ++i)
        {
            if(!stacks[i].isEmpty())
            {
                cout << "\t\t->Stack "<<i + 1 << ": ";
                stacks[i].print();
            }
        }
        cout << "\n";
    }

};
#endif // QUEUE_H


/*
1
mohy
stop

1
bye
stop

2

*/

