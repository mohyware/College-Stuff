#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Stack.h"
#include"Queue.h"
#include <iostream>

template <typename T>
struct Node
{
public:
    Queue<T> data;
    Node* next;
    Node() : next(nullptr) {}
};
template <typename T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList()
    {
        head= nullptr;
        tail= nullptr;
    }

    void addQueue(T& stack)
    {
        if (tail == nullptr || tail->data.isFullQ())
        {
            Node<T>* newNode = new Node<T>;
            newNode->next = nullptr;
            newNode->data.enqueue();

            if (tail == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }
        else
        {
            // Enqueue the element to the tail queue
            tail->data.enqueue();
        }
    }
    void print() const
    {
        if (head == nullptr)
        {
            std::cout << "Linked List is empty. No items to print." << std::endl;
            return;
        }
        Node<T>* current = head;
        size_t queueIndex = 1;
        cout << "Product List : \n";
        while (current != nullptr)
        {

            cout << "\t->Queue " << queueIndex++ << ": \n";
            current->data.print();
            current = current->next;
        }
    }
    void popQueue()
    {
        if (head == nullptr)
        {
            cerr << "Error: Queue is empty. Cannot pop.\n";
            return;
        }

        // Save the front node and its data (stack)
        Node<T>* frontNode = head;
        Queue<T>& frontStack = frontNode->data;

        // Print the content of the front stack
        frontStack.print();

        // Pop a single element from the front stack
        frontStack.dequeue();

        // If the front stack is now empty, remove the front node
        if (frontStack.isEmpty())
        {
            // Move the head to the next node
            head = frontNode->next;

            // Clean up the popped node
            delete frontNode;
        }
    }


    ~LinkedList()
    {
        Node<T>* current = head;
        while (current != nullptr)
        {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

};
#endif // LINKEDLIST_H
