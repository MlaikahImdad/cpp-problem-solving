#include <iostream>
using namespace std;

template <class T>
void swapping_by_value(T obj1, T obj2) {
    T temp = obj1;
    obj1 = obj2;
    obj2 = temp;
}

template <class T>
void swapping_by_reference(T & obj1, T & obj2) {
    T temp = obj1;
    obj1 = obj2;
    obj2 = temp;
}

template <class T>
void swapping_by_pointers(T * obj1, T * obj2) {
    T temp = *obj1;
    *obj1 = *obj2;
    *obj2 = temp;
}

int main() {
    int a=5, b=10;
    cout << "============ Function call by value ============\n" << endl;
    cout << "Before swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swapping_by_value(a, b);
    cout << "After swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl; 

    cout << "============ Function call by reference ============\n" << endl;
    cout << "Before swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swapping_by_reference(a, b);
    cout << "After swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl; 

    cout << "============ Function call by pointers ============\n" << endl;
    cout << "Before swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swapping_by_pointers(&a, &b);
    cout << "After swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl; 

    return 0;
}