#include <iostream>
using namespace std;

class Node {
    private:
    int object;
    Node * nextNode;
    public:
    int get_obj() { return object;}
    void set_obj(int object) { this->object = object;}
    Node * getNext() { return nextNode;}
    void setNext(Node * nextNode) { this->nextNode = nextNode;}
};

class Stack_array {
    private:
    int object;
    int current;
    int size;
    int A[5];
    public:
    Stack_array() { 
        size = 5;
        current = -1;
    }
    int pop_array() {return A[current--];}
    void push_array(int x) {A[++current] = x;}
    int isFull() { return current==size-1;}
    int isEmpty() { return current==-1;}
};

class Stack_linkedList {
    private:
    Node * head;
    public:
    void push_list(int n) {
        Node * newNode = new Node();
        newNode->set_obj(n);
        newNode->setNext(head);
        head = newNode;
    }
    int pop_list() {
        if (head == nullptr) { cout << "List is empty!" << endl;}
        int x = head->get_obj();
        Node * p = head;
        head = head->getNext();
        delete p;
        cout << "\n" << x;
        return x;
    }
};

int main() {
    int n=0, k, j, m;
    Stack_linkedList sl;
    Stack_array sa;
    while (n < 5) {
        cout << "\nEnter your choice\n";
        cout << "1: Add stack element in the linked list.\n";
        cout << "2: Add stack element in the array.\n";
        cout << "3: Pop stack elements in linked list and display.\n";
        cout << "4: Pop stack elements in array and display.\n";
        cout << "Enter any other number to close the program.\n";
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            cout << "Enter the number of elements that you want to add: ";
            cin >> k;
            cout << "\nAdd elements in the linked list\n";
            for (int i=1; i<=k; ++i) { 
                cin >> j;
                sl.push_list(j); // push the element at the top
            } cout << "Numbers added in the linked list successfully\n";
            break;
        case 2:
            if (sa.isFull()) { cout << "Stack is full, can't insert new elements.";}
            else {
                cout << "You can enter only 5 elements in the list.\n";
                for (int i=1; i<=5; ++i) {
                    cin >> m;
                    sa.push_array(m); // push the element at the top
                }
            } break;
        case 3:
            cout << "The reverse of input in the linked list is the following\n";
            for (int i=1; i<=k; ++i) { sl.pop_list();}
            break;
        case 4:
            cout << "The reverse input in the array is\n";
            for (int i=1; i<=5; ++i) {
                if (!sa.isEmpty()) {
                    cout << sa.pop_array();
                } else { cout << "stack is empty, can't pop.\n";}
            } break;    
        default:
            break;
        }
    } return 0;
}