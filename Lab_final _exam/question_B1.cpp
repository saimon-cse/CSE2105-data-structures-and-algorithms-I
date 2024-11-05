#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    Node *left, *right, *parent;

    Node(int key);
    
};

Node::Node(int key){
    this->key = key;
    left = right = parent = nullptr;
}

class BST{
public:
    Node *root;

    BST() : root(nullptr){}
    
    void insert(int key);
    void inorder(Node *node);
};


void BST::insert(int key){
    Node* node = new Node(key);
    if(root == nullptr){ root = node; return;}
    
    Node *fast = root;
    Node* parent = nullptr;

    while(fast){
        parent = fast;
        if(key < fast->key) fast = fast->left;
        else fast = fast->right;
    }

    if(key < parent->key) parent->left = node;
    else parent->right = node;

    node->parent = parent;

}

void BST::inorder(Node* node){
    if(node == nullptr) return;
    inorder(node->right);
    cout << node->key << " ";
    inorder(node->left);
}


int main(){

    BST tree;

    int n; cin >> n;

    for(int i = 0; i < n; i++){
        
        int value; cin >> value;
        tree.insert(value);
    }

    cout << " Reverse Inorder Traversal: ";
    tree.inorder(tree.root);

}

/*

8
2 1 1 5 3 4 2 6

*/