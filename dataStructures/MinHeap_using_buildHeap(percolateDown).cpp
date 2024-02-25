#include <iostream>
using namespace std;

class Heap {
	private:
	int currentSize;
	int *array;
	int capacity;
	public:
	Heap (int capacity);
	bool isEmpty();
	bool isFull();
	void buildHeap(int *anArray, int n);
	void traverse();
	void percolateDown(int hole);
};
Heap::Heap(int capacity) {
	array = new int[capacity + 1];
	currentSize = 0;
}
bool Heap::isEmpty() {
	return currentSize==0;
}
bool Heap::isFull() {
	return currentSize==capacity;
}
void Heap::buildHeap(int *anArray, int n) {
	for (int i=1; i <= n; ++i) {
		array[i] = anArray[i];
	}
	currentSize = n;
	for (int i = currentSize/2; i > 0; --i) {
		percolateDown(i);
	}
}
void Heap::percolateDown(int hole) {
	int child;
	int temp = array[hole];
	for (; hole * 2 <= currentSize; hole = child) {
		child = hole * 2;
		if (child != currentSize && array[child + 1] < array[child]) {
			child++;
		}
		if (array[child] < temp) {
			array[hole] = array[child];
		} else { break; }
	}
	array[hole] = temp;
}
void Heap::traverse() {
	for (int i=1; i <= currentSize; i++) {
		cout << " " << array[i] << " ";
	}
}

int main() {
	int size = 16;
	int arr[size] = {18, 31, 82, 85, 37, 20, 23, 79, 47, 51, 96, 97, 42, 94, 57, 29};
	Heap heap(size);
	heap.buildHeap(&arr[0], size);
	cout << "\nMin heap using build method\n";
	heap.traverse();
	return 0;
}