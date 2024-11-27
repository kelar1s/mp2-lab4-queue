#include <iostream>
using namespace std;

const int MAX_QUEUE_SIZE = 1000;

template <class T>
class Queue {
	T* pMem;
	int count, maxSize;
	int head, tail;
public:
	Queue(int size = 10);
	Queue(const Queue& oth);
	~Queue();

	int GetMaxSize() { return maxSize; }

	Queue<T>& operator=(const Queue& oth);

	bool operator==(const Queue& oth);
	bool operator!=(const Queue& oth);
	
	bool isEmpty() { return count == 0; }
	bool isFull() { return count == maxSize; }

	void clear();
	void push(T value);
	T pop();
	T front() { return pMem[head]; }
	T back() { return pMem[tail]; }
};

template <class T>
Queue<T>::Queue(int size) {
	if (size > MAX_QUEUE_SIZE || size < 0) {
		throw -1;
	}
	maxSize = size;
	pMem = new T[maxSize];
	count = 0;
	tail = -1, head = 0;
}

template <class T>
Queue<T>::Queue(const Queue& oth) {
	maxSize = oth.maxSize;
	pMem = new T[maxSize];
	count = oth.count;
	head = oth.head;
	tail = oth.tail;
	int i = head;
	while (i != tail) {
		pMem[i] = oth.pMem[i];
		i = (i + 1) % maxSize;
	}
	pMem[i] = oth.pMem[i];
}

template <class T>
Queue<T>::~Queue() {
	delete[] pMem;
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue& oth) {
	if (this == &oth) {
		return *this;
	}
	if (this->maxSize != oth.maxSize) {
		maxSize = oth.maxSize;
		delete[] pMem;
		pMem = new T[maxSize];
	}
	count = oth.count;
	head = oth.head; 
	tail = oth.tail;
	int i = head;
	while (i != tail) {
		pMem[i] = oth.pMem[i];
		i = (i + 1) % maxSize;
	}
	pMem[i] = oth.pMem[i];
	return *this;
}

template <class T>
bool Queue<T>::operator==(const Queue& oth) {
	if (this->maxSize != oth.maxSize || this->count != oth.count || this->head != oth.head || this->tail != oth.tail) {
		return false;
	}
	if (count == 0) {
		return true;
	}
	for (int i = 0; i < count; i++) {
		if (pMem[(head + i) % maxSize] != oth.pMem[(head + i) % maxSize]) {
			return false;
		}
	}
	return true;
}

template <class T>
bool Queue<T>::operator!=(const Queue& oth) {
	return !(*this == oth);
}

template <class T>
void Queue<T>::push(T value) {
	if (this->isFull()) {
		throw -1;
	}
	if (tail == maxSize - 1) {
		tail = 0;
	}
	else {
		tail++;
	}
	pMem[tail] = value;
	count++;
}

template <class T>
T Queue<T>::pop() {
	if (this->isEmpty()) {
		throw -1;
	}
	int ind = head;
	head = (head + 1) % maxSize;
	count--;
	return pMem[ind];
}

template <class T>
void Queue<T>::clear() {
	count = 0;
	head = 0;
	tail = -1;
}




