#pragma once

const int MAX_QUEUE_SIZE = 1000;

template <class T>
class TQueue {
	T* pMem;
	int count, maxSize;
	int head, tail;
public:
	TQueue(int size = 10);
	TQueue(const TQueue& oth);
	~TQueue();

	int GetHead() { return head; }
	int GetTail() { return tail; }
	int GetMaxSize() { return maxSize; }
	int GetCurrentSize() { return count; }

	TQueue<T>& operator=(const TQueue& oth);

	bool operator==(const TQueue& oth) const;
	bool operator!=(const TQueue& oth) const;

	bool isEmpty() { return count == 0; }
	bool isFull() { return count == maxSize; }

	void clear();
	void push(T value);
	T pop();
	T front() { return pMem[head]; }
	T back() { return pMem[tail]; }
};

template <class T>
TQueue<T>::TQueue(int size) {
	if (size > MAX_QUEUE_SIZE || size < 0) {
		throw - 1;
	}
	maxSize = size;
	pMem = new T[maxSize];
	count = 0;
	tail = -1;
	head = 0;
}

template <class T>
TQueue<T>::TQueue(const TQueue& oth) {
	maxSize = oth.maxSize;
	pMem = new T[maxSize];
	count = oth.count;
	head = oth.head;
	tail = oth.tail;
	if (tail >= head) {
		for (int i = 0; head + i <= tail; i++) {
			pMem[head + i] = oth.pMem[head + i];
		}
	}
	else {
		for (int i = 0; i <= tail; i++) {
			pMem[i] = oth.pMem[i];
		}
		for (int i = head; i < maxSize; i++) {
			pMem[i] = oth.pMem[i];
		}
	}
}

template <class T>
TQueue<T>::~TQueue() {
	delete[] pMem;
}

template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue& oth) {
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
	if (tail >= head) {
		for (int i = 0; head + i <= tail; i++) {
			pMem[head + i] = oth.pMem[head + i];
		}
	}
	else {
		for (int i = 0; i <= tail; i++) {
			pMem[i] = oth.pMem[i];
		}
		for (int i = head; i < maxSize; i++) {
			pMem[i] = oth.pMem[i];
		}
	}
	return *this;
}

template <class T>
bool TQueue<T>:: operator==(const TQueue& oth) const {
	if (maxSize != oth.maxSize || count != oth.count) return false;
	if (count == 0) return true;
	for (int i = 0; i < count; i++) {
		if (pMem[(head + i) % maxSize] != oth.pMem[(oth.head + i) % maxSize]) return false;
	}
	return true;
}

template <class T>
bool TQueue<T>::operator!=(const TQueue& oth) const {
	return !(*this == oth);
}

template <class T>
void TQueue<T>::push(T value) {
	if (this->isFull()) {
		throw - 1;
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
T TQueue<T>::pop() {
	if (this->isEmpty()) {
		throw - 1;
	}
	int ind = head;
	head = (head + 1) % maxSize;
	count--;
	return pMem[ind];
}

template <class T>
void TQueue<T>::clear() {
	count = 0;
	head = 0;
	tail = -1;
}