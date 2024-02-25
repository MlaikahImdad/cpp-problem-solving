#include <iostream>
#include <cstring>
using namespace std;

template <class Object>
class TreeNode {
private:
    Object *object;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode()
    {
        this->object = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }

    TreeNode(Object *object)
    {
        this->object = object;
        this->left = nullptr;
        this->right = nullptr;
    }

    Object *getInfo() { return this->object; }

    void setInfo(Object *object) { this->object = object; }

    TreeNode *getLeft() { return this->left; }

    void setLeft(TreeNode *left) { this->left = left; }

    TreeNode *getRight() { return this->right; }

    void setRight(TreeNode *right) { this->right = right; }

    int isLeaf()
    {
        if (this->left == nullptr && this->right == nullptr)
        {
            return 1;
        }
        return 0;
    }
};

template <class Object>
void insert(TreeNode<Object> *root, Object *info)
{
    TreeNode<Object> *node = new TreeNode<Object>(info);
    TreeNode<Object> *p, *q;
    p = q = root;
    while (info != p->getInfo() && q != nullptr)
    {
        p = q;
        if (info < p->getInfo())
        {
            q = p->getLeft();
        }
        else
        {
            q = p->getRight();
        }
    }
    if (info == p->getInfo())
    {
        cout << "Attempt to insert duplicate." << endl;
        delete node;
    }
    else if (info < p->getInfo())
    {
        p->setLeft(node);
    }
    else
    {
        p->setRight(node);
    }
}

template <class Object>
void inorder(TreeNode<Object> *treeNode)
{ // L N R
    if (treeNode != nullptr)
    {
        inorder(treeNode->getLeft());
        cout << *(treeNode->getInfo()) << " ";
        inorder(treeNode->getRight());
    }
}

template <class Object>
void preorder(TreeNode<Object> *treeNode)
{ // N L R
    if (treeNode != nullptr)
    {
        cout << *(treeNode->getInfo()) << " ";
        preorder(treeNode->getLeft());
        preorder(treeNode->getRight());
    }
}

template <class Object>
void postorder(TreeNode<Object> *treeNode)
{ // L R N
    if (treeNode != nullptr)
    {
        postorder(treeNode->getLeft());
        postorder(treeNode->getRight());
        cout << *(treeNode->getInfo()) << " ";
    }
}

int main()
{
    int length;
    TreeNode<char> *root = new TreeNode<char>();
    cout << "Enter the length of a name: ";
    cin >> length;
    char *word = new char[length + 1]; // Increase the size to accommodate nullptr terminator

    cout << "Enter the name: ";
    for (int i = 0; i < length; i++)
    {
        cin >> word[i];
    }
    word[length] = '\0'; // Add nullptr terminator to make it a proper C-string

    root->setInfo(&word[0]);
    for (int i = 0; i < strlen(word); ++i)
    {
        insert(root, &word[i]);
    }
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    cout << "\nPostorder: ";
    postorder(root);

    delete[] word; // Free the dynamically allocated memory
    return 0;
}