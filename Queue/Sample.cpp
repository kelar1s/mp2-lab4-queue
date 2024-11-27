#include "Queue.cpp"
#include <iostream>

using namespace std;

int main() {
	Queue<int> a(10), b(12);
	for (int i = 0; i < 10; i++) {
		a.push(i);
	}
	b = a;
	while (!(a.isEmpty())) {
		cout << a.pop() << " " << b.pop() << endl;
	}
	return 0;
}