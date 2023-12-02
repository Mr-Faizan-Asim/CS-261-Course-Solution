#include<iostream>

using namespace std;

class Node{
public:
    int value;
    Node* LeftSubTree;
    Node* RightSubTree;
    int height;
    Node(int value)
    {
        this->value = value;
        this->LeftSubTree = nullptr;
        this->RightSubTree = nullptr;
        this->height = 1;
    }
};

class AVL{
public:
    Node *root;
    int Height(Node* n)
    {
        if(n == nullptr)
        return 0;
        int left = Height(n->LeftSubTree);
        int right = Height(n->RightSubTree);
        if(left > right)
        {
            return (left+1);
        }
        else
        {
            return (right + 1);
        }

    }
    int height(Node* node)
    {
        return (node == nullptr) ? 0 :node->height;
    }
    int HeightDifference(Node* node)
    {
        return Height(node->LeftSubTree) - Height(node->RightSubTree);
    }
    Node* right_rotate(Node* y)
    {
        Node* x = y->LeftSubTree;
        Node* T2 = y->RightSubTree;

        x->RightSubTree = y;
        y->LeftSubTree = T2;
        y->height = 1 + max(height(y->LeftSubTree),height(y->RightSubTree));
        x->height = 1 + max(height(x->LeftSubTree),height(x->RightSubTree));

        return x;
    }
    Node* left_rotate(Node* x)
    {
        Node* y = x->RightSubTree;
        Node* T2 = x->LeftSubTree;

        y->LeftSubTree = x;
        x->RightSubTree = T2;

        x->height = 1 + max(height(x->LeftSubTree),height(x->RightSubTree));
        y->height = 1 + max(height(y->LeftSubTree),height(y->RightSubTree));

        return y;
    }
    Node* insert(Node* root,int key)
    {
        if(root == nullptr)
        {
            return new Node(key);
        }
        if(key < root->value)
        {
            root->LeftSubTree = insert(root->LeftSubTree,key);
        }
        else
        {
            root->RightSubTree = insert(root->LeftSubTree,key);
        }
        root->height = 1 + max(height(root->LeftSubTree),height(root->RightSubTree));
        int balance = HeightDifference(root);
        if(balance > 1 && key < root->LeftSubTree->value)
        {
            return right_rotate(root);
        }
        if(balance < -1 && key > root->RightSubTree->value)
        {
            return left_rotate(root);
        }
        if(balance > 1 && key > root->LeftSubTree->value)
        {
            root->LeftSubTree = left_rotate(root->LeftSubTree);
            return right_rotate(root);
        }
        if(balance < -1 && key < root->RightSubTree->value)
        {
            root->RightSubTree  = right_rotate(root->RightSubTree);
            return left_rotate(root);
        }
        return root;
    }
    bool IsBalanced(Node* n){
        if(n == nullptr)
        {
            return true;
        }
        int leftHeight = height(n->LeftSubTree);
        int rightHeight = height(n->RightSubTree);
        int balanceFactor = abs(leftHeight - rightHeight);
        return (balanceFactor <= 1) && IsBalanced(n->LeftSubTree) && IsBalanced(n->RightSubTree);
    }
    Node* find_min(Node* node) {
    while (node->LeftSubTree != nullptr) {
        node = node->LeftSubTree;
    }
    return node;
}
    // Delete AVL
    Node* delete_node(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->value) {
        root->LeftSubTree = delete_node(root->LeftSubTree, value);
    } else if (value > root->value) {
        root->RightSubTree = delete_node(root->RightSubTree, value);
    } else {
        if (root->LeftSubTree == nullptr || root->RightSubTree == nullptr) {
            Node* temp = (root->LeftSubTree != nullptr) ? root->LeftSubTree : root->RightSubTree;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }

            delete temp;
        } else {
            Node* temp = find_min(root->RightSubTree);
            root->value = temp->value;
            root->RightSubTree = delete_node(root->RightSubTree, temp->value);
        }
    }

    if (root == nullptr) {
        return root;
    }

    root->height = 1 + std::max(height(root->LeftSubTree), height(root->RightSubTree));

    int balance = height(root->LeftSubTree) - height(root->RightSubTree);

    // Left-Left case
    if (balance > 1 && height(root->LeftSubTree->LeftSubTree) - height(root->LeftSubTree->RightSubTree) >= 0) {
        return right_rotate(root);
    }

    // Left-Right case
    if (balance > 1 && height(root->LeftSubTree->LeftSubTree) - height(root->LeftSubTree->RightSubTree) < 0) {
        root->LeftSubTree = left_rotate(root->LeftSubTree);
        return right_rotate(root);
    }

    // Right-Right case
    if (balance < -1 && height(root->RightSubTree->LeftSubTree) - height(root->RightSubTree->RightSubTree) <= 0) {
        return left_rotate(root);
    }

    // Right-Left case
    if (balance < -1 && height(root->RightSubTree->LeftSubTree) - height(root->RightSubTree->RightSubTree) > 0) {
        root->RightSubTree = right_rotate(root->RightSubTree);
        return left_rotate(root);
    }

    return root;
}

void DelFromAVL(Node*& root, int value) {
    root = delete_node(root, value);
}
    
};

int mian()
{

}


