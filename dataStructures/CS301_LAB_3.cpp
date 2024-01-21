#include <iostream>
using namespace std;

class Node {
    private:
    int object;
    Node * nextNode;
    public:
    // setters
    void set_obj(int object) { this->object = object;}
    void set_nextNode(Node * nextNode) { this->nextNode = nextNode;}
    // getters
    int get_obj() { return object;}
    Node * get_nextNode() { return nextNode;}
};

class Queue {
    public:
    Node * front;
    Node * rear;
    void enqueue (int x);
    int dequeue();
    void display();
    int isEmpty() { return (front == nullptr);}
};
void Queue::enqueue(int x) {
    Node * newNode = new Node();
    newNode->set_obj(x);
    newNode->set_nextNode(nullptr);
    if (front == nullptr) {
        front = rear = newNode;
    } else {
        rear->set_nextNode(newNode);
        rear = newNode;
    }
}
int Queue::dequeue() {
    int x = front->get_obj();
    Node * p = front;
    front = front->get_nextNode();
    delete p;
    return x;
}
void Queue::display() {
    if (isEmpty()) { cout << "Queue is empty" << endl;}
    Node * temp = front;
    while (temp != nullptr) {
        cout << temp->get_obj() << endl;
        temp = temp->get_nextNode();
    } 
}

int main() {
    int n, k;
    Queue Q;
    cout << "Enter the total numbers you want to enter: ";
    cin >> k;
    cout << "Enter numbers randomly" << endl;
    for (int i=1; i<=k; ++i) {
        cin >> n;
        if (n % 2 == 0) {Q.enqueue(n);}
    }
    cout << "\nThe even numbers are \n";
    Q.display();
    Q.dequeue();
    cout << "\nAfter removing first Even number\n";
    Q.display();
    return 0;
}