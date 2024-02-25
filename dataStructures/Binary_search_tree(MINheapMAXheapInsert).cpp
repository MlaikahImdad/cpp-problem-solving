#include <iostream>
#include <string>
using namespace std;

template <class Object>
class BSTNode {
    private:
    Object * object;
    BSTNode * left;
    BSTNode * right;
    public:
    BSTNode();
    BSTNode(Object * object);
    Object * getInfo();
    void setInfo(Object * object);
    BSTNode * getLeft();
    void setLeft(BSTNode * left);
    BSTNode * getRight();
    void setRight(BSTNode * Right);
    int isLeaf();
};

template <class Object>
BSTNode<Object>::BSTNode() {
    this->object = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}
template <class Object>
BSTNode<Object>::BSTNode(Object * object) {
    this->object = object;
    this->left = nullptr;
    this->right = nullptr;
}
template<class Object>
Object * BSTNode<Object>::getInfo() {
    return this->object;
}
template <class Object>
void BSTNode<Object>::setInfo(Object * object) {
    this->object = object;
}
template <class Object>
BSTNode<Object> * BSTNode<Object>::getLeft() {
    return left;
}
template <class Object>
void BSTNode<Object>::setLeft(BSTNode * left) {
    this->left = left;
}
template <class Object>
BSTNode<Object> * BSTNode<Object>::getRight() {
    return right;
}
template <class Object>
void BSTNode<Object>::setRight(BSTNode * right) {
    this->right = right;
}
template <class Object>
int BSTNode<Object>::isLeaf() {
    if (this->left == nullptr && this->right == nullptr) {return 1;}
    return 0;
}

void insert(BSTNode<int> * root, int * info) {
    BSTNode<int> * node = new BSTNode<int> (info);
    BSTNode<int> *p, *q;
    p = q = root;
    while (*info != *(p->getInfo()) && q != nullptr) {
        p = q;
        if (*info < *(p->getInfo())) {
            q = p->getLeft();
        } else {
            q = p->getRight();
        }
    }
    if (*info == *(p->getInfo())) {
        cout << endl << *info << " is duplicate in this Binary Search Tree (BST). Can not be inserted....";
        // getch();
        delete node;
    } else if (*info < *(p->getInfo())) {
        p->setLeft(node);
    } else {
        p->setRight(node);
    }
    cout << endl;
}
int minNode(BSTNode<int> * treeNode){
    while (treeNode->getLeft() != nullptr) {
        treeNode = treeNode->getLeft();
    }
    return *treeNode->getInfo();
}
int maxNode(BSTNode<int> * treeNode) {
    while (treeNode->getRight() != nullptr) {
        treeNode = treeNode->getRight();
    }
    return *treeNode->getInfo();
}

int main() {
    string names[] = {"Saleh", "Ali", "Umar", "Musaddiq", "Rehman", "Hassaan"};
    int totalNames = sizeof(names)/sizeof(names[0]); // sizeof(names) --> 144, obtained by (6 * 24) || sizeof(names[0]) --> 24
    BSTNode <int> *NTree = new BSTNode <int>(); // so, totalNames = 6
    int treeData[totalNames];
    totalNames++; // 7
    for (int a=0; a < totalNames; a++) {
        if (a == 6) { treeData[a] = -1; }
        else { treeData[a] = names[a].length(); }
    }

    NTree->setInfo(&treeData[0]);
    cout << "Inserting the length of names in BST Nodes one by one" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Length of " << names[0] << " is: " << *NTree->getInfo() << endl;
    for (int i=1; treeData[i] > 0; i++) {
        cout << "Length of " << names[i] << " is: " << treeData[i];
        insert(NTree, &treeData[i]);
    }
    cout << "\nValue of BST minimum node is: " << minNode(NTree) << endl;
    cout << "\nValue of BST maximum node is: " << maxNode(NTree) << endl;
    return 0;
}