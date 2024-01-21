#include <iostream>
using namespace std;

class Heap {
  private:
  int capacity;
  int * array; // heap array
  int currentSize;
  public:
  Heap(int capacity) {
    array = new int[capacity + 1];
    currentSize = 0;
  }
  bool insert(const int &x);
  bool isEmpty() {return currentSize == 0;}
  bool isFull() { return currentSize == capacity;}
  void traverse();
};

bool Heap::insert(const int &x) {
  if(isFull()) { cout << "Can't insert, Heap is full!" << endl;}
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

int main() {
  int size = 16;
  int arr[size] = {18, 31, 82, 85, 37, 20, 23, 79, 47, 51, 96, 97, 42, 94, 57, 29};
  Heap heap(size);

  for (int i=0; i < size; ++i) {
    heap.insert(arr[i]);
  }

  cout << "Min heap using insert method" << endl;
  heap.traverse();
  return 0;
}