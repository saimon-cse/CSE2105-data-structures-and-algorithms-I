#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    Node *parent, *left, *right;

    Node();
    Node(int key);


    
};

Node::Node(){
        left = right = parent = nullptr;
}

Node::Node(int key){
    this->key = key;
    left = right = parent = nullptr;
}

class BST{
private:
    Node *root;
    int len;

public:
    BST(){
        root = nullptr;
        len = 0;
    }

    void insert(int key);
    void find(int key);
    Node* findMin(Node* root);
    Node* findMax(Node* root);
    void inorder(Node* root);
    int height(Node* root);
    int size(Node* root);
    Node* findSuccessor(Node* tmp);
    bool deleteElement(int key);
    void print();

    
};

void BST::insert(int key) {
    Node* node = new Node(key);

    if(root == nullptr){
        root = node;
        return;
    }


    Node* fast = root, *slow = nullptr;

    while(fast){
        slow = fast;
        if(key < fast->key) fast = fast->left;
        else fast = fast->right;
    }

    if(slow->key <= key)  slow->right = node;
    else slow->left = node;

    node->parent = slow; 

    len++;
}

Node* BST::findMax(Node* root){
    if(root->right == nullptr) return root;
    return findMax(root->right);
}


void BST::inorder(Node* node){
    if(node == nullptr) return;
    
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}


int BST::height(Node* node){
    if(node == nullptr) return 0;
    return 1 + max(height(node->left), height(node->right));
}

Node* BST::findSuccessor(Node* node){
    if(node->right) findMin(node->right);

    Node* parent = node->parent;

    if(parent == nullptr or parent->left == node)
        return parent;
    
    return findSuccessor(parent);
}


int main(){
    
}