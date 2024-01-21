#include <iostream>
using namespace std;

class Heap {
    private:
    int currentSize;
    int *array;
    int capacity;
    public:
    Heap(int capacity);
    bool insert(const int &x);
    bool isEmpty();
    bool isFull();
    void traverse();
};
Heap::Heap(int capacity) {
    array = new int[capacity + 1];
    currentSize = 0;
}
bool Heap::insert(const int &x) {
    if(isFull()) {
        cout << "Can't insert, Heap is full." << endl;
        return 0;
    }
    int hole = ++currentSize;
    for (; hole > 1 && x < array[hole/2]; hole /= 2) {
        array[hole] = array[hole/2];
    }
    array[hole] = x;
}
void Heap::traverse() {
    for (int i=1; i <= currentSize; ++i) {
        cout << " " << array[i] << " ";
    }
}
bool Heap::isEmpty() {
    return currentSize==0;
}
bool Heap::isFull() {
    return currentSize==capacity;
}

int main() {
    int size = 16;
    int arr[size] = {18, 31, 82, 85, 37, 20, 23, 79, 47, 51, 96, 97, 42, 94, 57, 29};
    Heap heap(size);
    for (int i=0; i<size; i++) {
        heap.insert(arr[i]);
    }
    cout << "Min heap using insert method" << endl;
    heap.traverse();
    return 0;
}