// لا إله إلا الله
#pragma once
#include<iostream>

template<typename T>
class Queue {
	int front;
	int rear;
	int size;
	T* arr;

public:
	int cnt;
	Queue(int size = 6);
	~Queue();

	int next(int pos);
	int prv(int pos);
	T* get_reference_arr() { return arr; }
	int idx_front() { return front; }
	int idx_rear() { return rear; }

	bool isEmpty();
	bool isFull();
	int getSize();

	void resize();

	void enqueue(const T& value);
	void push_front(const T& value);

	T& dequeue();
	T& pop_back();

	T& Front();
	T& back();

	void print();
};

template<typename T>
Queue<T>::Queue(int size) : size(size), front(0), rear(0),cnt(0), arr(new T[size]) {}
template<typename T>
Queue<T>::~Queue() { delete[] arr; }

template<typename T>
int Queue<T>::next(int pos) { return (pos + 1) % size; }
template<typename T>
int Queue<T>::prv(int pos) { return  (pos - 1 + size) % size; }

template<typename T>
bool Queue<T>::isEmpty() { return front == rear; }
template<typename T>
bool Queue<T>::isFull() {
	return cnt>=size-1;
}
template<typename T>
int Queue<T>::getSize() { return this->size; }

template<typename T>
void Queue<T>::resize() {
	int new_size = std::max(2, 2 * size);
	int t_rear = 0;

	T* temp = new T[new_size];
	for (auto i = front; i != rear; i = (i + 1) % size)
		temp[t_rear++] = arr[i];

	delete[] arr;
	arr = temp;
	front = 0;
	rear = t_rear;
	size = new_size;
}

template<typename T>
void Queue<T>::enqueue(const T& value) {

	arr[rear] = value;
	rear = next(rear);
	cnt++;
}
template<typename T>
void Queue<T>::push_front(const T& value) {


	front = prv(front);
	arr[front] = value;
	cnt++;
}

template<typename T>
T& Queue<T>::dequeue() {
	assert(!isEmpty());

	cnt--;
	T value = arr[front];
	front = next(front);
	return value;
}
template<typename T>
T& Queue<T>::pop_back() {
	assert(!isEmpty());

	cnt--;
	rear = prv(rear);
	return arr[rear];
}

template<typename T>
T& Queue<T>::Front() {
	assert(!isEmpty());
	return arr[front];
}
template<typename T>
T& Queue<T>::back() {
	assert(!isEmpty());
	return arr[rear - 1];
}

template<typename T>
void Queue<T>::print() {
	if (isEmpty()) {
		cerr << "The queue is empty ." << endl;
		return;
	}
	for (auto i = front; i != rear; i = (i + 1) % size)
		cout << arr[i] << ' ';
}
