#ifndef CUSTOMDS_H
#define CUSTOMDS_H

#include <iostream>
#include <algorithm>
#include <stdexcept>
using namespace std;
template <typename T>
class customDs
{
private:
    size_t capacity;
    size_t size;
    T* elements;
public:
    customDs()
    {
        capacity = 10; // Initial capacity
        size = 0;
        elements = new T[capacity];
    }

    ~customDs()
    {
        delete[] elements;
    }

    void insert_front(const T& value)
    {
        insert_at(0, value);
    }

    void insert_back(const T& value)
    {
        if (size == capacity)
        {
            resize();
        }
        elements[size++] = value;
    }

    void insert_at(size_t position, const T& value)
    {
        if (position > size)
        {
            throw out_of_range("Index out of range");
        }

        if (size == capacity)
        {
            resize();
        }

        for (size_t i = size; i > position; i--)
        {
            elements[i] = elements[i - 1];
        }

        elements[position] = value;
        size++;
    }

    void remove(const T& value)
    {
        int delIndex = find(value);
        remove_at(delIndex);
    }

    void remove_at(size_t position)
    {
        if (position >= size)
        {
            throw out_of_range("Index out of range");
        }

        for (size_t i = position; i < size - 1; i++)
        {
            elements[i] = elements[i + 1];
        }

        size--;
    }

    size_t find(const T& value)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (elements[i] == value)
            {
                return i;
            }
        }
        return size;
    }
//sort
    void sort(bool (*compare)(const T& a, const T& b))
    {
        std::sort(elements, elements + size, compare);
    }

    size_t get_size()
    {
        return size;
    }

    T& operator[](size_t index)
    {
        if (index >= size)
        {
            throw out_of_range("Index out of range");
        }
        return elements[index];
    }

    void resize(size_t new_capacity)
    {
        if (new_capacity < size)
        {
            cout << "Sorry, container is full with elements cannot change to a smaller size." << endl;
            return;
        }

        T* newElements = new T[new_capacity];
        for (size_t i = 0; i < size; i++)
        {
            newElements[i] = elements[i];
        }

        delete[] elements;
        elements = newElements;
        capacity = new_capacity;
        if (size > new_capacity)
        {
            size = new_capacity;
        }
    }

    void resize()
    {
        capacity *= 2;
        T* newElements = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }

    void reverse()
    {
        for (size_t i = 0; i < size / 2; i++)
        {
            swap(elements[i], elements[size - i - 1]);
        }
    }

    // Merge with another container
    void merge(const customDs& other)
    {
        if (size + other.size > capacity)
        {
            size_t new_capacity = max(size + other.size, capacity * 2);
            resize(new_capacity);
        }
        for (size_t i = 0; i < other.size; i++)
        {
            insert_back(other.elements[i]);
        }
    }
    class iterator
    {
    private:
        T* current;
    public:
        iterator(T* ptr) : current(ptr) {}

        T& operator*()
        {
            return *current;
        }

        iterator& operator++()
        {
            current++;
            return *this;
        }

        iterator& operator--()
        {
            current--;
            return *this;
        }

        bool operator==(const iterator& other) const
        {
            return current == other.current;
        }

        bool operator!=(const iterator& other) const
        {
            return current != other.current;
        }

    };

    iterator begin()
    {
        return iterator(elements);
    }

    iterator end()
    {
        return iterator(elements + size);
    }

    iterator next(iterator it)
    {
        return ++it;
    }

    iterator prev(iterator it)
    {
        return --it;
    }


};

#endif // CUSTOMDS_H
